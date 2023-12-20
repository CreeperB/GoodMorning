#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int planets;

int main(){
    int max_infected = 0;
    int total_cases;
    scanf("%d", &total_cases);
    while(total_cases--){
        int lines;
        scanf("%d %d", &planets, &lines);
        int **graph = malloc((planets + 1) * sizeof(int*));
        for(int i = 1; i <= planets; i++){
            graph[i] = malloc((planets + 1) * sizeof(int));
            for(int j = 1; j <= planets; j++){
                graph[i][j] = -1;
            }
        }
        for(int i = 0; i < lines; i++){
            int a, b, dis;
            scanf("%d %d %d", &a, &b, &dis);
            graph[a][b] = dis;
            graph[b][a] = dis;
        }
        for(int i = 1; i <= planets; i++){
            for(int j = 1; j <= planets; j++){
                for(int k = 1; k <= planets; k++){
                    if(i == j || i == k || j == k)
                        continue;
                    if(graph[j][i] != -1 && graph[i][k] != -1){
                        if(graph[j][k] == -1){
                            graph[j][k] = graph[j][i] + graph[i][k];
                            graph[k][j] = graph[j][k];
                        }
                        else if(graph[j][k] > graph[j][i] + graph[i][k]){
                            graph[j][k] = graph[j][i] + graph[i][k];
                            graph[k][j] = graph[j][k];
                        }
                    }
                }
            }
        }
        for(int inf = 1; inf <= planets; inf++){
            for(int vac = 1; vac <= planets; vac++){
                if(inf == vac)
                    continue;
                int infected = 1;
                for(int i = 1; i <= planets; i++){
                    if(i == inf || i == vac)
                        continue;
                    if(graph[inf][i] <= graph[vac][i]){
                        infected++;
                    }
                }
                if(infected > max_infected){
                    max_infected = infected;
                }
            }
        }
        printf("%d\n", max_infected);
    }
}