#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

#define CANVAS_HEIGHT 20
#define CANVAS_WIDTH 10
#define BLOCK_SIZE 4
#define FRAME_DELAY 7
#define FALL_DELAY 400

typedef enum {
    black = 0,
    red = 41,
    green,
    yellow,
    blue,
    purple,
    cyan,
    white,
} Color;

typedef enum {
    none = -1,
    I,
    J,
    L,
    O,
    S,
    T,
    Z,
} ShapeId;

typedef struct {
    ShapeId shape;
    Color color;
    char rotates[4][4][4];
    int size;
} Shape;

Shape shapes[7] = {
    {.shape = I, .color = cyan, .size = 4, .rotates = {{{0, 0, 0, 0},     //
                                                        {1, 1, 1, 1},     //
                                                        {0, 0, 0, 0},     //
                                                        {0, 0, 0, 0}},    //
                                                       {{0, 0, 1, 0},     //
                                                        {0, 0, 1, 0},     //
                                                        {0, 0, 1, 0},     //
                                                        {0, 0, 1, 0}},    //
                                                       {{0, 0, 0, 0},     //
                                                        {0, 0, 0, 0},     //
                                                        {1, 1, 1, 1},     //
                                                        {0, 0, 0, 0}},    //
                                                       {{0, 1, 0, 0},     //
                                                        {0, 1, 0, 0},     //
                                                        {0, 1, 0, 0},     //
                                                        {0, 1, 0, 0}}}},  //
    {.shape = J, .color = blue, .size = 3, .rotates = {{{1, 0, 0},        //
                                                        {1, 1, 1},        //
                                                        {0, 0, 0}},       //
                                                       {{0, 1, 1},        //
                                                        {0, 1, 0},        //
                                                        {0, 1, 0}},       //
                                                       {{0, 0, 0},        //
                                                        {1, 1, 1},        //
                                                        {0, 0, 1}},       //
                                                       {{0, 1, 0},        //
                                                        {0, 1, 0},        //
                                                        {1, 1, 0}}}},     //
    {.shape = L, .color = yellow, .size = 3, .rotates = {{{0, 0, 1},      //
                                                          {1, 1, 1},      //
                                                          {0, 0, 0}},     //
                                                         {{0, 1, 0},      //
                                                          {0, 1, 0},      //
                                                          {0, 1, 1}},     //
                                                         {{0, 0, 0},      //
                                                          {1, 1, 1},      //
                                                          {1, 0, 0}},     //
                                                         {{1, 1, 0},      //
                                                          {0, 1, 0},      //
                                                          {0, 1, 0}}}},   //
    {.shape = O, .color = cyan, .size = 2, .rotates = {{{1, 1},           //
                                                        {1, 1}},          //
                                                       {{1, 1},           //
                                                        {1, 1}},          //
                                                       {{1, 1},           //
                                                        {1, 1}},          //
                                                       {{1, 1},           //
                                                        {1, 1}}}},        //
    {.shape = S, .color = green, .size = 3, .rotates = {{{0, 1, 1},       //
                                                         {1, 1, 0},       //
                                                         {0, 0, 0}},      //
                                                        {{0, 1, 0},       //
                                                         {0, 1, 1},       //
                                                         {0, 0, 1}},      //
                                                        {{0, 0, 0},       //
                                                         {0, 1, 1},       //
                                                         {1, 1, 0}},      //
                                                        {{1, 0, 0},       //
                                                         {1, 1, 0},       //
                                                         {0, 1, 0}}}},    //
    {.shape = T, .color = purple, .size = 3, .rotates = {{{0, 1, 0},      //
                                                          {1, 1, 1},      //
                                                          {0, 0, 0}},     //
                                                         {{0, 1, 0},      //
                                                          {0, 1, 1},      //
                                                          {0, 1, 0}},     //
                                                         {{0, 0, 0},      //
                                                          {1, 1, 1},      //
                                                          {0, 1, 0}},     //
                                                         {{0, 1, 0},      //
                                                          {1, 1, 0},      //
                                                          {0, 1, 0}}}},   //
    {.shape = Z, .color = red, .size = 3, .rotates = {{{1, 1, 0},         //
                                                       {0, 1, 1},         //
                                                       {0, 0, 0}},        //
                                                      {{0, 0, 1},         //
                                                       {0, 1, 1},         //
                                                       {0, 1, 0}},        //
                                                      {{0, 0, 0},         //
                                                       {1, 1, 0},         //
                                                       {0, 1, 1}},        //
                                                      {{0, 1, 0},         //
                                                       {1, 1, 0},         //
                                                       {1, 0, 0}}}},      //
};

typedef struct {
    Color color;
    ShapeId shape;
    bool exist;
} Block;

Block canvas[CANVAS_HEIGHT][CANVAS_WIDTH];

void setBlock(Block *block, Color color, ShapeId shape, bool exist) {
    block->color = color;
    block->shape = shape;
    block->exist = exist;
}

void resetBlock(Block *block) {
    block->color = black;
    block->shape = none;
    block->exist = false;
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

bool move(int originalX, int originalY, int originalRotate, int newX, int newY, int newRotate, ShapeId shapeId) {
    Shape shapeData = shapes[shapeId];
    int size = shapeData.size;

    // check if the new position is valid to place the block
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (shapeData.rotates[newRotate][i][j]) {
                if (newX + j < 0 || newX + j >= CANVAS_WIDTH || newY + i < 0 || newY + i >= CANVAS_HEIGHT) {
                    return false;
                }
                if (!canvas[newY + i][newX + j].exist && canvas[newY + i][newX + j].shape != none) {
                    return false;
                }
            }
        }
    }
    // remove the old position
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (shapeData.rotates[originalRotate][i][j]) {
                resetBlock(&canvas[originalY + i][originalX + j]);
            }
        }
    }
    // move the block
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (shapeData.rotates[newRotate][i][j]) {
                setBlock(&canvas[newY + i][newX + j], shapeData.color, shapeId, true);
            }
        }
    }
    return true;
}

int clearLine() {
    for (int i = 0; i < CANVAS_HEIGHT; i++) {
        for (int j = 0; j < CANVAS_WIDTH; j++) {
            if (canvas[i][j].exist) {
                canvas[i][j].exist = false;
            }
        }
    }
    int linesCleared = 0;
    for (int i = CANVAS_HEIGHT - 1; i >= 0;) {
        bool isFull = true;
        for (int j = 0; j < CANVAS_WIDTH; j++) {
            if (canvas[i][j].shape == none) {
                isFull = false;
                break;
            }
        }
        if (isFull) {
            linesCleared++;
            for (int j = 0; j < CANVAS_WIDTH; j++) {
                resetBlock(&canvas[i][j]);
            }
            for (int k = i; k > 0; k--) {
                for (int j = 0; j < CANVAS_WIDTH; j++) {
                    setBlock(&canvas[k][j], canvas[k - 1][j].color, canvas[k - 1][j].shape, false);
                    resetBlock(&canvas[k - 1][j]);
                }
            }
        } else {
            i--;
        }
    }
    return linesCleared;
}

bool clearAll() {
    for (int i = 0; i < CANVAS_WIDTH; i++) {
        if (canvas[CANVAS_HEIGHT - 1][i].color != black) {
            return false;
        }
    }
    return true;
}

typedef struct {
    int x;
    int y;
    int score;
    int combo;
    int rotate;
    int fallTime;
    ShapeId hold;
    bool hold_check;
    ShapeId queue[5];
    bool shadow_visible;
} State;

int findShadow(State *state) {
    int size = shapes[state->queue[0]].size;
    for (int y = 0; y < CANVAS_HEIGHT; y++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (shapes[state->queue[0]].rotates[state->rotate][i][j]) {
                    if (state->x + j < 0 || state->x + j >= CANVAS_WIDTH || state->y + i + y < 0 || state->y + i + y >= CANVAS_HEIGHT) {
                        return state->y + y - 1;
                    }
                    if (!canvas[state->y + i + y][state->x + j].exist && canvas[state->y + i + y][state->x + j].shape != none) {
                        return state->y + y - 1;
                    }
                }
            }
        }
    }
    return state->y;
}

void printCanvas(State *state) {
    printf("\033[0;0H\n");
    Shape shapeData;

    // print the hold block
    printf("\033[%d;%dHHold:", 2, 4);
    if (state->hold != none) {
        shapeData = shapes[state->hold];
        for (int j = 0; j < BLOCK_SIZE; j++) {
            printf("\033[%d;%dH", j + 4, 2);
            for (int k = 0; k < BLOCK_SIZE; k++) {
                if (j < shapeData.size && k < shapeData.size && shapeData.rotates[0][j][k]) {
                    printf("\x1b[%dm  ", shapeData.color);
                } else {
                    printf("\x1b[0m  ");
                }
            }
        }
    }

    // print the game canvas
    for (int i = 0; i < CANVAS_HEIGHT; i++) {
        printf("\033[%d;15H", i);
        printf("|");
        for (int j = 0; j < CANVAS_WIDTH; j++) {
            printf("\x1b[%dm  ", canvas[i][j].color);
        }
        printf("\x1b[0m|\n");
    }
    printf("\033[%d;15H ", CANVAS_HEIGHT);
    for (int j = 0; j < CANVAS_WIDTH; j++) {
        printf("‾‾");
    }

    if (state->shadow_visible) {
        // print the shadow
        int shadowY = findShadow(state);
        int size = shapes[state->queue[0]].size;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (shapes[state->queue[0]].rotates[state->rotate][i][j] && !canvas[shadowY + i][state->x + j].color) {
                    printf("\033[%d;%dH\x1b[47m  \x1b[0m", shadowY + i, (state->x + j) * 2 + 16);
                }
            }
        }
    }

    // print the next blocks
    printf("\033[%d;%dHNext:", 2, CANVAS_WIDTH * 2 + 20);
    for (int i = 1; i <= 4; i++) {
        shapeData = shapes[state->queue[i]];
        for (int j = 0; j < BLOCK_SIZE; j++) {
            printf("\033[%d;%dH", i * BLOCK_SIZE + j, CANVAS_WIDTH * 2 + 20);
            for (int k = 0; k < BLOCK_SIZE; k++) {
                if (j < shapeData.size && k < shapeData.size && shapeData.rotates[0][j][k]) {
                    printf("\x1b[%dm  ", shapeData.color);
                } else {
                    printf("\x1b[0m  ");
                }
            }
        }
    }
    printf("\033[%d;%dHScore: %4d\n", 13, 2, state->score);
}

void reset_area(State *state, Shape *shapeData) {
    for (int i = 0; i < shapes[state->queue[0]].size; i++) {
        for (int j = 0; j < shapes[state->queue[0]].size; j++) {
            if (shapeData->rotates[state->rotate][i][j]) {
                resetBlock(&canvas[state->y + i][state->x + j]);
            }
        }
    }
}

void set_area(State *state, Shape *shapeData) {
    for (int i = 0; i < shapes[state->queue[0]].size; i++) {
        for (int j = 0; j < shapes[state->queue[0]].size; j++) {
            if (shapeData->rotates[state->rotate][i][j]) {
                setBlock(&canvas[state->y + i][state->x + j], shapeData->color, state->queue[0], true);
            }
        }
    }
}

void rotate_judge(State *state, int newRotate) {
    bool rotated = false;
    if (move(state->x, state->y, state->rotate, state->x, state->y, newRotate, state->queue[0])) {
        state->rotate = newRotate;
        rotated = true;
    } else if (state->x - 1 >= 0) {
        if (move(state->x, state->y, state->rotate, state->x - 1, state->y, newRotate, state->queue[0])) {
            state->x--;
            state->rotate = newRotate;
            rotated = true;
        }
    } else if (state->x + 1 < CANVAS_WIDTH) {
        if (move(state->x, state->y, state->rotate, state->x + 1, state->y, newRotate, state->queue[0])) {
            state->x++;
            state->rotate = newRotate;
            rotated = true;
        }
    }
    if (shapes[state->queue[0]].shape == T && !rotated) {
        if (move(state->x, state->y, state->rotate, state->x, state->y - 1, newRotate, state->queue[0])) {
            state->y--;
            state->rotate = newRotate;
        } else if (move(state->x, state->y, state->rotate, state->x, state->y - 2, newRotate, state->queue[0])) {
            state->y -= 2;
            state->rotate = newRotate;
        } else if (move(state->x, state->y, state->rotate, state->x - 1, state->y, newRotate, state->queue[0])) {
            state->x--;
            state->rotate = newRotate;
        } else if (move(state->x, state->y, state->rotate, state->x + 1, state->y, newRotate, state->queue[0])) {
            state->x++;
            state->rotate = newRotate;
        }
    }
}

void logic(State *state) {
    setbuf(stdin, NULL);
    if (kbhit()) {
        int ch = getchar();
        switch (ch) {
            case 'v':
                if (state->hold_check) {
                    state->hold_check = false;
                    reset_area(state, &shapes[state->queue[0]]);
                    if (state->hold == none) {
                        state->hold = state->queue[0];
                        for (int i = 0; i < 4; i++) {
                            state->queue[i] = state->queue[i + 1];
                        }
                        state->queue[4] = rand() % 7;
                    } else {
                        ShapeId temp = state->hold;
                        state->hold = state->queue[0];
                        state->queue[0] = temp;
                    }
                    state->x = CANVAS_WIDTH / 2 - 1;
                    state->y = 0;
                    state->rotate = 0;
                    state->fallTime = 0;
                    set_area(state, &shapes[state->queue[0]]);
                    return;
                }

                break;
            case 'w':
                rotate_judge(state, (state->rotate + 1) % 4);
                break;
            case 'p':
                rotate_judge(state, (state->rotate + 1) % 4);
                break;
            case 'o':
                rotate_judge(state, (state->rotate + 3) % 4);
                break;
            case 'a':
                if (move(state->x, state->y, state->rotate, state->x - 1, state->y, state->rotate, state->queue[0])) {
                    state->x--;
                }
                break;
            case 'd':
                if (move(state->x, state->y, state->rotate, state->x + 1, state->y, state->rotate, state->queue[0])) {
                    state->x++;
                }
                break;
            case 's':
                state->fallTime = FALL_DELAY;
                break;
            case ' ':
                state->fallTime += FALL_DELAY * CANVAS_HEIGHT;
                break;
            case 'm':
                state->shadow_visible = !state->shadow_visible;
            default:
                break;
        }
    }
    state->fallTime += FRAME_DELAY;
    while (state->fallTime >= FALL_DELAY) {
        state->fallTime = state->fallTime - FALL_DELAY;
        if (move(state->x, state->y, state->rotate, state->x, state->y + 1, state->rotate, state->queue[0])) {
            state->y++;
        } else {
            state->hold_check = true;
            int line_cleared = clearLine();
            bool all_cleared = clearAll();
            if (line_cleared) {
                state->combo++;
            } else {
                state->combo = 0;
            }
            printf("\033[%d;%dH", 9, 0);
            if (state->combo) {
                printf("Combo: %d\n", state->combo);
            } else {
                printf("         \n");
            }

            printf("\033[%d;%dH", 11, 0);
            if (line_cleared) {
                int point = 0;
                if (line_cleared > 1) {
                    point = (int)pow(2, line_cleared - 2);
                }
                if (all_cleared) {
                    state->score += 100 + point * 10 + (state->combo - 1) * 10;
                    printf("All Cleared!\n");
                } else {
                    state->score += point * 10 + (state->combo - 1) * 10;
                    switch (line_cleared) {
                        case 1:
                            state->score += 5;
                            printf("Single!     \n");
                            break;
                        case 2:
                            printf("Double!     \n");
                            break;
                        case 3:
                            printf("Triple!     \n");
                            break;
                        case 4:
                            printf("Tetris!     \n");
                            break;
                        default:
                            break;
                    }
                }
                usleep(30000);
            } else {
                printf("            \n");
            }

            state->x = CANVAS_WIDTH / 2 - 1;
            state->y = 0;
            state->rotate = 0;
            state->fallTime = 0;
            for (int i = 0; i < 4; i++) {
                state->queue[i] = state->queue[i + 1];
            }
            state->queue[4] = rand() % 7;

            if (!move(state->x, state->y, state->rotate, state->x, state->y, state->rotate, state->queue[0])) {
                printf("\033[%d;%dH\x1b[41m GAME OVER \x1b[0m\033[%d;%dH", 16, 2, CANVAS_HEIGHT + 5, 0);
                exit(0);
            }
        }
    }
    printCanvas(state);
}

int main() {
    printf("\e[?25l");
    system("clear");
    changemode(1);
    State state = {
        .x = CANVAS_WIDTH / 2,
        .y = 0,
        .rotate = 0,
        .fallTime = 0,
        .score = 0,
        .combo = 0,
        .hold = none,
        .hold_check = true,
        .shadow_visible = true,
    };

    for (int i = 0; i < CANVAS_HEIGHT; i++) {
        for (int j = 0; j < CANVAS_WIDTH; j++) {
            resetBlock(&canvas[i][j]);
        }
    }

    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        state.queue[i] = rand() % 7;
    }

    move(state.x, state.y, state.rotate, state.x, state.y, state.rotate, state.queue[0]);

    while (true) {
        printCanvas(&state);
        logic(&state);
        usleep(FRAME_DELAY * 1000);
    }
}