#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int times;
    scanf("%d", &times);
    while (times--) {
        int people, pairs;
        scanf("%d %d", &people, &pairs);
        int **donrelate = (int **)malloc(sizeof(int *) * people);  // create the relation graph
        for (int i = 0; i < people; i++) {
            donrelate[i] = (int *)malloc(sizeof(int) * people);
            for (int j = 0; j < people; j++) {
                donrelate[i][j] = 0;  // init value
            }
        }

        // draw the graph
        for (int i = 0; i < pairs; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            donrelate[a][b] = 1;
            donrelate[b][a] = 1;
        }
        for (int i = 0; i < people; i++) {
            donrelate[i][i] = 1;
        }

        // find the donnumber
        int *donnumber = (int *)malloc(sizeof(int) * people);
        for (int i = 0; i < people; i++) {
            donnumber[i] = INT_MAX;  // set all value to infinity
        }
        donnumber[0] = 0;
        for (int i = 1; i < people; i++) {
            if (donrelate[0][i] == 1) {
                donnumber[i] = 1;  // set the value of the first level
            }
        }
        bool flag = true;
        while (flag) { // if not done
            flag = false;
            for (int i = 1; i < people; i++) {
                if (donnumber[i] == INT_MAX) { // if not defined
                    int min = INT_MAX;
                    for (int j = 1; j < people; j++) {
                        if (donrelate[i][j] == 1 && donnumber[j] != INT_MAX) { //if related and not infinity
                            if (donnumber[j] < min) {  // find the shortest path
                                min = donnumber[j];
                            }
                        }
                    }
                    if (min != INT_MAX) {
                        donnumber[i] = min + 1;
                        flag = true;
                    }
                }
            }
        }
        for (int i = 1; i < people; i++) {
            printf("%d\n", donnumber[i]);
        }
        printf("\n");
    }
}
