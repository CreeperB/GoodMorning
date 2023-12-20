#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define GATELEN 5

typedef struct info {
    char* name;
    int inputs;
    int delay;
} Info;

typedef struct gate {
    Info* info;
    int id;
    char* name;
    char** inputs;
    int out_cnt;
    int* outputs;
    bool isInput;
} Gate;

typedef struct path{
    int delay;
    int len;
    int* path;
}Path;

Gate* Create();
void getPath(Gate*, Path*);

int ids = 0;
int total;
int max_delay = 0;
Gate** gates;
Path** paths;
int path_cnt = 0;

int main() {
    FILE* info = fopen("Gates.txt", "r");
    FILE* circuit = fopen("Circuit.txt", "r");
    FILE* output = fopen("Output.txt", "w");
    int num;
    fscanf(info, "%d", &num);
    Info** infos = malloc(num * sizeof(Info*));
    for (int i = 0; i < num; i++) {
        infos[i] = malloc(sizeof(Info));
        infos[i]->name = malloc((GATELEN + 1) * sizeof(char));
        fscanf(info, "%s %d %d", infos[i]->name, &infos[i]->inputs, &infos[i]->delay);
    }
    int cir_in, cir_out, gate_count;
    fscanf(circuit, "%d %d %d", &cir_in, &cir_out, &gate_count);
    total = gate_count + cir_in + cir_out;
    paths = malloc(total * sizeof(Path*));
    gates = malloc(total * sizeof(Gate*));
    int gid = 0;

    int in_cnt = 0;
    for (int i = 0; i < cir_in; i++) {
        gates[gid] = Create();
        fscanf(circuit, "%s", gates[gid]->name);
        gates[gid]->isInput = true;
        gid++;
        in_cnt++;
    }
    char** outputs = malloc(cir_out * sizeof(char*));
    for (int i = 0; i < cir_out; i++) {
        gates[gid] = Create();
        outputs[i] = malloc((GATELEN + 1) * sizeof(char));
        fscanf(circuit, "%s", outputs[i]);
        strcpy(gates[gid]->name, outputs[i]);
        gates[gid]->isInput = false;
        gid++;
    }
    for (int i = 0; i < gate_count; i++) {
        char* temp = malloc((GATELEN + 1) * sizeof(char));
        gates[gid] = Create();
        gates[gid]->info = malloc(sizeof(Info));
        fscanf(circuit, "%s", gates[gid]->name);
        fscanf(circuit, "%s", temp);
        for (int j = 0; j < num; j++) {
            if (strcmp(temp, infos[j]->name) == 0) {
                gates[gid]->info = infos[j];
                break;
            }
        }
        gates[gid]->inputs = malloc(gates[gid]->info->inputs * sizeof(char*));
        for (int j = 0; j < gates[gid]->info->inputs; j++) {
            gates[gid]->inputs[j] = malloc((GATELEN + 1) * sizeof(char));
        }
        for (int j = 0; j < gates[gid]->info->inputs; j++) {
            fscanf(circuit, "%s", gates[gid]->inputs[j]);
        }
        gid++;
    }
    
    //connect gates

    for (int i = 0; i < total; i++) {
        for (int j = 0; j < total; j++) {
            if(i == j || gates[j]->info == NULL) continue;
            for (int k = 0; k < gates[j]->info->inputs; k++) {
                if (strcmp(gates[i]->name, gates[j]->inputs[k]) == 0) {
                    gates[i]->outputs[gates[i]->out_cnt] = gates[j]->id;
                    gates[i]->out_cnt++;
                }
            }
        }
    }

    //count the critical path

    for(int i = 0; i < in_cnt; i++) {
        bool front = true;
        for(int j = 0; j < gates[i]->out_cnt; j++) {
            for(int k = 0; k < in_cnt; k++) {
                if(gates[i]->outputs[j] == gates[k]->id) {
                    front = false;
                    break;
                }
            }
        }
        Path* path = malloc(sizeof(Path));
        path->delay = 0;
        path->len = 0;
        path->path = malloc(total * sizeof(int));
        if(front) {
            path->path[path->len] = gates[i]->id;
            path->len++;
            getPath(gates[i], path);
        }
    }

    //output

    int* output_cnt = malloc(cir_out * sizeof(int));
    int output_cnt = 0;

    fprintf(output, "%d\n", max_delay);
    for(int i = 0; i < path_cnt; i++) {
        if(paths[i]->delay == max_delay){
            for(int j = 0; j < paths[i]->len; j++) {
                fprintf(output, "%s%c", gates[paths[i]->path[j]]->name, " \n"[j == paths[i]->len - 1]);
            }
        }
    }
    fclose(info);
    fclose(circuit);
    fclose(output);
}

void getPath(Gate* g, Path* path) {
    if(!(g->isInput)){
        path->path[path->len] = g->id;
        path->len++;
        path->delay += g->info->delay;
    }
    if(g->out_cnt == 0) {
        if(path->delay > max_delay) {
            max_delay = path->delay;
        }
        paths[path_cnt] = path;
        path_cnt++;
        return;
    }
    for(int i = 0; i < g->out_cnt; i++) {
        Path* newPath = malloc(sizeof(Path));
        newPath->delay = path->delay;
        newPath->len = path->len;
        newPath->path = malloc(total * sizeof(int));
        for(int j = 0; j < path->len; j++) {
            newPath->path[j] = path->path[j];
        }
        getPath(gates[g->outputs[i]], newPath);
    }
}

Gate* Create(){
    Gate* g = malloc(sizeof(Gate));
    g->info = NULL;
    g->name = malloc((GATELEN + 1) * sizeof(char));
    g->id = ids++;
    g->outputs = malloc(total * sizeof(int));
    g->out_cnt = 0;
    return g;
}