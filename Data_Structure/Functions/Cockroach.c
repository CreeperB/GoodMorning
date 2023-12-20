#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    if (n <= 2 || n > 40 || m < 2 || m > 20) {  // out of range
        printf("Invalid input\n");
        exit(0);
    }
    int times = 0, count_all = 1;  // times for loop, count_all for block which have walked

    int **map = (int **)malloc(n * sizeof(int *));  // create a 2d array
    for (int i = 0; i < n; i++) {
        map[i] = (int *)calloc(m, sizeof(int));
    }

    int imove[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int jmove[8] = {1, 1, 1, 0, -1, -1, -1, 0};
    int ibug, jbug;
    scanf("%d %d", &ibug, &jbug);
    map[ibug][jbug] = 1;  // set origin as walked
    srand(time(NULL));
    while (count_all != n * m && ++times < 50000) {
        int last_ipos, last_jpos;  // temp a pos
        while (1) {                // run until get an valid pos
            int dir = rand() % 8;
            last_ipos = ibug + imove[dir];
            last_jpos = jbug + jmove[dir];
            // printf("%d %d\n", last_ipos, last_jpos);
            if (last_ipos < 0 || last_ipos >= n || last_jpos < 0 || last_jpos >= m) {  // out of range
                continue;
            }
            break;  // get a valid pxos
        }
        ibug = last_ipos, jbug = last_jpos;  // update pos
        if (!map[ibug][jbug]++) {            // if walk first time, count_all++
            count_all++;
        }
    }
    printf("%d", times);
    FILE *file = fopen("D1050961_PE2.csv", "w+");  // write to csv
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(file, "%05d%c", map[i][j], ",\n"[j == m - 1]);  // format
        }
    }
}
