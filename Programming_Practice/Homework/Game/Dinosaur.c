#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
#define CANVAS 50
#define PLAYERPOS 6
void display(char[], int, int);
void shiftLeft(char *, int);
int isDead(char *, int, int);
void changemode(int);
int kbhit(void);

int main() {
    int times = 0;
    srand(time(NULL));
    printf("\e[?25l");  // hide cursor
    while (++times) {   // Infinite loop for game init
        int sleeptime = 80000;
        int jump_time = 0;
        int score = 0;
        int ammo = 5;
        int speed = 1;
        int delay = 0;
        int exit = 0;
        int dead = 0;
        char floor1[CANVAS], floor2[CANVAS];
        for (int i = 0; i < CANVAS; i++) {  // Initialize the floor
            floor1[i] = '_';
            floor2[i] = ' ';
        }
        int current_floor = 1;
        bool stop = false;
        changemode(1);  // Change the terminal mode to raw
        if (times == 1) {
            printf("\tPress 'p' to pause the game\n");  // Pause the game
            printf("\tPress 'w' to jump\n");            // Jump
            printf("\tPress 'd' to speed up\n");        // Speed up
            printf("\tPress space to fire\n");          // Fire
            printf("\tPress any key to start\n");       // Start the game
            getc(stdin);                                // Wait for the user to press a key
        }
        while (1) {
            while (!kbhit()) {  // If the user didn't press a key
                changemode(1);
                sleeptime = 80000 - speed * 1000;                                      // Change the sleep time
                printf("\n\tScore: %d\tAmmo: %d\t\tSpeed: %d\n", score, ammo, speed);  // Display the score and ammo and speed

                if (!(score++ % 10)) {  // Create a barrier if the score is divisible by 10
                    floor1[CANVAS - (rand() % 5 + 1)] = 'X';
                }
                if (!(score % 50)) {  // Increase the speed if the score is divisible by 50
                    speed++;
                }
                if (!(score % 50) && ammo <= 10) {  // Add ammo if the score is divisible by 50
                    ammo++;
                }
                dead = isDead(floor1, current_floor, score);
                if (dead == 1) {  // Check if the player is dead
                    return 0;
                } else if (dead == 2) {
                    break;
                }
                if (current_floor == 1 || (current_floor == 2 && delay)) {
                    printf("\n\n\t");
                    display(floor2, 0, CANVAS);
                    printf("\n\t");
                    display(floor1, 0, PLAYERPOS);
                    printf("\033[36m0\033[0m");
                    display(floor1, PLAYERPOS + 1, CANVAS);
                    printf("\n\n");
                    if (delay) {  // Jump cd
                        delay--;
                    }
                } else if (current_floor == 2 && delay == 0) {
                    if (jump_time++ > 4) {  // Jump
                        jump_time = 0;
                        current_floor = 1;
                        delay = 2;
                    }
                    printf("\n\n\t");
                    display(floor2, 0, PLAYERPOS);
                    printf("\033[36m0\033[0m");
                    display(floor2, PLAYERPOS + 1, CANVAS);
                    printf("\n\t");
                    display(floor1, 0, CANVAS);
                    printf("\n\n");
                }
                if (stop) {
                    printf("\n\t\t\t\033[31mZa\033[32mWa\033[33mru\033[34mdo\033[35m!!\033[0m\n");  // Pause
                    getc(stdin);
                    stop = false;  // Resume the game
                }
                shiftLeft(floor1, CANVAS);  // Shift the floor
                usleep(sleeptime);          // Speed
                system("clear");            // Clear the screen
            }
            if (dead) {
                break;
            }
            sleeptime = 80000 - speed * 1000;  // Change the sleep time
            char temp = getc(stdin);           // Get the pressed key
            if (temp == 'w') {                 // Jump
                current_floor = 2;
            } else if (temp == ' ') {              // Fire
                if (ammo && current_floor == 1) {  // If the player has ammo and is on the ground
                    floor1[PLAYERPOS + 1] = '-';
                    ammo--;
                }
            } else if (temp == 'd') {  // Speed up
                speed++;
            } else if (temp == 'p') {  // Pause
                stop = true;
            }
        }
        changemode(0);  // Change the terminal mode to cooked
    }
}

void display(char *floor, int lowerlimit, int upperlimit) {  // Display the floor
    for (int i = lowerlimit; i < upperlimit; i++) {
        if (floor[i] == 'X') {
            printf("\033[31m%c\033[0m", floor[i]);
        } else if (floor[i] == '-') {
            printf("%c", floor[i]);
        } else {
            printf("\033[32m%c\033[0m", floor[i]);
        }
    }
}

void shiftLeft(char *floor, int upperlimit) {  // Shift the floor
    for (int i = 0; i < upperlimit - 1; i++) {
        if (floor[i] == '-' && floor[i + 1] == 'X') {  // If the player hit a barrier
            floor[i] = '_';
            floor[i + 1] = '_';
        } else if (floor[i] == '-' || floor[i + 1] == '-') {  // Skip if it's ammo
            continue;
        } else {
            floor[i] = floor[i + 1];  // Shift the floor
        }
    }
    for (int i = upperlimit - 2; i > 0; i--) {
        if (floor[i] == '-' && floor[i + 1] == 'X') {  // If the player hit a barrier
            floor[i] = '_';
            floor[i + 1] = '_';
        } else if (floor[i] == '-') {  // Skip if it's ammo
            floor[i + 1] = '-';
            floor[i] = '_';
        }
    }
    floor[upperlimit - 1] = '_';  // Make the floor end with a floor
}
int isDead(char *floor, int current_floor, int score) {
    if (current_floor == 1 && floor[PLAYERPOS] == 'X') {
        system("clear");
        printf("\n\t\tScore: %d\n", score);
        printf("\n\t\tGame Over!\n\n");
        while (1) {
            printf("  Press any key to restart or ESC to leave\n\n");
            char temp = getchar();
            if (temp == 27) {
                return 1;
            } else {
                return 2;
            }
        }
    }
    return 0;
}

void changemode(int dir) {
    static struct termios oldt, newt;
    if (dir == 1) {
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    } else
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

int kbhit(void) {
    struct timeval tv;
    fd_set rdfs;

    tv.tv_sec = 0;
    tv.tv_usec = 0;

    FD_ZERO(&rdfs);
    FD_SET(STDIN_FILENO, &rdfs);

    select(STDIN_FILENO + 1, &rdfs, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &rdfs);
}