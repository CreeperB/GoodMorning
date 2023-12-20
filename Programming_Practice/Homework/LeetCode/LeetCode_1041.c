#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void x_plus(int *x, int *y) { (*x)++; }   // x plus
void y_plus(int *x, int *y) { (*y)++; }   // y plus
void x_minus(int *x, int *y) { (*x)--; }  // x minus
void y_minus(int *x, int *y) { (*y)--; }  // y minus
typedef struct ROBOT {                    // typedef robot
    int dir;
    int x, y;
} ROBOT;

bool isRobotBounded(char *instructions) {
    ROBOT robot = {0, 0, 0};                                             // initialization
    void (*func[4])(int *, int *) = {y_plus, x_plus, y_minus, x_minus};  // set function array
    for (int times = 0; times < 4; times++)                              // loop 4 times to check if circling
        for (int i = 0; instructions[i] != '\0'; i++)
            switch (instructions[i]) {
                case 'G':
                    (*func[robot.dir % 4])(&robot.x, &robot.y);  // forward with direction
                    break;
                case 'L':
                    if (--robot.dir < 0)  // turn back
                        robot.dir = 3;
                    break;
                case 'R':
                    if (++robot.dir > 3)  // turn back
                        robot.dir = 0;
                    break;
            }
    if (robot.x == 0 && robot.y == 0)  // judge if circled back the origin point
        return true;
    return false;
}

int main() {
    printf("%s", isRobotBounded("GGLLGG") ? "true" : "false");
}