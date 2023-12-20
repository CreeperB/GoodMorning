#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ask_for_mode();
void guess_randomly();
void guess_binary_search(int);
void guess_user();
void guess_god_mode(int);
int correct_or_wrong(int, int);
void time_count(int);

int main() {
    srand(time(NULL));  // make random more random
    while (1) {
        ask_for_mode();
    }
}

void ask_for_mode() {
    int choice;
    int answer_user;
    printf("------------------------------------------------------\n");
    printf("| Choose which mode to guess...                      |\n");
    printf("| 1 for random answer and random guess               |\n");
    printf("| 2 for random answer but guess in binary search     |\n");
    printf("| 3 for random answer but guess by you               |\n");
    printf("| 4 for setting answer by you for computer to guess  |\n");
    printf("| 5 for setting answer by you but against with god   |\n");
    printf("| 0 to quit                                          |\n");
    printf("------------------------------------------------------\n");
    printf("Mode : ");
    scanf("%d", &choice);  // choose which mode do process
    puts("");
    if (choice == 0) {
        printf("See you later~\n");
        exit(1);  // quit
    } else if (choice == 1) {
        guess_randomly();
    } else if (choice == 2) {
        guess_binary_search(1 + rand() % 1000);  // set random answer for binary search
    } else if (choice == 3) {
        guess_user();
    } else if (choice == 4) {
        printf("Enter your answer from 1 to 1000 : ");
        scanf("%d", &answer_user);
        if (answer_user > 0 && answer_user <= 1000) {
            puts("");
            guess_binary_search(answer_user);
        } else {
            printf("\nUnknown input\n\n");
        }
    } else if (choice == 5) {
        printf("Input your answer : ");
        scanf("%d", &answer_user);
        puts("");
        guess_god_mode(answer_user);
    } else {
        printf("\nUnknown input\n\n");
        ask_for_mode();  // return function if scan unknown
    }
}

void guess_randomly() {
    int times = 0;
    int answer = 1 + rand() % 1000;  // random answer
    int guess = 1 + rand() % 1000;   // random guess
    int range;
    int lowest = 0, highest = 1000;
    printf("The answer is %d\n", answer);
    while (1) {
        times++;  // calculate times of guess
        printf("Guess %d\n", guess);
        range = correct_or_wrong(answer, guess);  // judge big or small
        if (range == 0) {
            time_count(times);
            break;
        }
        if (range == 1) {
            lowest = guess;                                // set the lowest point
            guess += 1 + rand() % (highest - lowest - 1);  //+1 for not too low -1 for not too high
        } else if (range == 2) {
            highest = guess;                               // set the highest point
            guess -= 1 + rand() % (highest - lowest - 1);  //+1 for not too low -1 for not too high
        }
    }
}

void guess_binary_search(int answer) {
    int times = 0;
    int guess = 500;
    int range;
    int lowest = 0, highest = 1000;
    printf("The answer is %d\n", answer);
    while (1) {
        times++;  // calculate times of guess
        printf("Guess %d\n", guess);
        range = correct_or_wrong(answer, guess);  // judge big or small
        if (range == 0) {
            time_count(times);
            break;
        } else if (range == 1) {
            lowest = guess;                   // set the lowest point
            guess += (highest - lowest) / 2;  // divide range in 2
        } else if (range == 2) {
            highest = guess;                  // set the highest point
            guess -= (highest - lowest) / 2;  // divide range in 2
        }
    }
}

void guess_user() {
    int answer = 1 + rand() % 1000;
    int times = 0;
    int guess;
    int range;
    int lowest = 0, highest = 1000;
    printf("Guess from 1 to 1000...\n");
    while (1) {
        times++;  // calculate times of guess
        printf("Guess ");
        scanf("%d", &guess);
        range = correct_or_wrong(answer, guess);  // judge big or small
        if (range == 0) {
            time_count(times);
            break;
        }
        if (range == 1) {
            if (guess < lowest)  // guess outside the range
            {
                puts("");
                printf("You're guessing below the lowest number %d , come on.\n", lowest);
                printf("Guess again\n\n");
            } else {
                lowest = guess;  // set the lowest point
            }
        } else if (range == 2) {
            if (guess > highest)  // guess outside the range
            {
                printf("You're guessing above the highest number %d , come on.\n", highest);
                printf("Guess again\n");
            } else {
                highest = guess;  // set the highest point
            }
        }
    }
}

void guess_god_mode(int answer) {
    int times = 1;
    int guess = answer;
    printf("Guess %d\n", guess);
    correct_or_wrong(answer, guess);
    time_count(times);
    printf("It's just too easy\n\n");
}

int correct_or_wrong(int answer, int guess) {
    if (answer == guess) {
        printf("Correct answer!!\n\n");
        printf(
            "ILOVEYOUILOVEYOUILOVEYOUILOVEYOUILOVEYOUILOVEYOUILOVEYOU\n"
            "ILOVEYOUILO ****** VEYOU ****** ILOVEYOUILOVEYOUILOVEYOU\n"
            "ILOVEYOU *********** I *********** LOVEYOUILOVEYOUILOVEY\n"
            "OUIUI *************** *************** VEYOUILOVEYOUILOVE\n"
            "YOUI ********************************** LOVEYOUILOVEYOUI\n"
            "IL ************************************* OVEYOUILOVEYOUI\n"
            "L *************I**LOVE**YOU*!************ OVEYOUILOVEYOU\n"
            "I *************************************** LOVEYOUILOVEYO\n"
            "U *************************************** ILOVEYOUILOVEY\n"
            "OU ************************************* ILOVEYOUILOVEYO\n"
            "UIL *********************************** OVEYOUILOVEYOUIL\n"
            "OVEYO ******************************* ULOVEYOUILOVEYOUIL\n"
            "OVEYOUI **************************** LOVEYOUILOVEYOUILOV\n"
            "EYOUILOVE *********************** YOUILOVEYOUILOVEYOUILO\n"
            "VEYOUILOVEYOU ***************** ILOVEYOUILOVEYOUILOVEYOU\n"
            "ILOVEYOUILOVEYO ************* LOVEYOUILOVEYOUILOVEYOUILO\n"
            "UILOVEYOUILOVEYOU ********* LOVEYOUILOVEYOUILOVEYOUILOVE\n"
            "LOVEYOUILOVEYOUILOV ***** ILOVEYOUILOVEYOUILOVEYOUILOVEY\n"
            "EYOUILOVEYOUILOVEYOU *** YOULOVEYOUILOVEYOUILOVEYOUILOVE\n"
            "VEYOUILOVEYOUILOVEYOU * VEYOUILOVEYOUILOVEYOUILOVEYOUILO\n"
            "OVEYOUILOVEYOUILOVEYOUILOVEYOUILOVEYOUILOVEYOUILOVEYOUIL\n\n");
        return 0;
    } else if (answer > guess) {
        printf("Higher!!\n");
        return 1;
    } else if (answer < guess) {
        printf("Lower!!\n");
        return 2;
    }
}

void time_count(int times) {
    if (times == 1) {
        printf("Guess 1 time in total\n\n");
    } else {
        printf("Guess %d times in total\n\n", times);
    }
}
