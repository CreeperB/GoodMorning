/*
 * @lc app=leetcode id=1041 lang=c
 *
 * [1041] Robot Bounded In Circle
 */

// @lc code=start

void x_plus(int *x, int *y) { (*x)++; }   // x plus
void y_plus(int *x, int *y) { (*y)++; }   // y plus
void x_minus(int *x, int *y) { (*x)--; }  // x minus
void y_minus(int *x, int *y) { (*y)--; }  // y minus
typedef struct ROBOT {                    // typedef robot
    int dir;
    int x, y;
} ROBOT;

bool isRobotBounded(char *instructions) {
    ROBOT robot = {0, 0, 0};
    void (*func[4])(int *, int *) = {y_plus, x_plus, y_minus, x_minus};
    for (int times = 0; times < 4; times++)
        for (int i = 0; instructions[i] != '\0'; i++)
            switch (instructions[i]) {
                case 'G':
                    (*func[robot.dir % 4])(&robot.x, &robot.y);
                    break;
                case 'L':
                    if (--robot.dir < 0)
                        robot.dir = 3;
                    break;
                case 'R':
                    if (++robot.dir > 3)
                        robot.dir = 0;
                    break;
            }
    if (robot.x == 0 && robot.y == 0)
        return true;
    return false;
}

// @lc code=end
