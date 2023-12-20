#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10

int global_clock = 0;

typedef struct Customer {
    char id[21];     // customer id
    int arr_time;    // arrival time
    int ser_time;    // processing time
    int leave_time;  // leave time
    int leave_win;   // leave window
} Customer;

Customer leaving[1000] = {0};
int leaving_count = 0;

typedef struct Win_Status {
    int status;  // 0: open 1: close
    int time;
    int count;
    Customer customer[10];
} Win_Status;

void add(Win_Status* window, int win_count, Customer* customer) {
    int min = window[0].count, min_i = 0;
    for (int i = 1; i < win_count; i++) {  // find the window with the least customers
        if (window[i].status == 0) {
            if (window[i].count < min) {
                min = window[i].count;
                min_i = i;
            }
        }
    }
    window[min_i].customer[window[min_i].count] = *customer;  // add customer
    window[min_i].count++;                                    // count++
}

int main() {
    FILE* input = fopen("input.txt", "r");    // input file
    FILE* output = fopen("output.txt", "w");  // output file
    int win_count;
    fscanf(input, "%d", &win_count);  // read the number of windows
    char buf[21];
    Win_Status window[10] = {0};
    int cus_count = 0;
    int in_time, ser_time;
    while (fscanf(input, "%s %d %d", buf, &in_time, &ser_time) != EOF) {  // read customer info
        while (in_time > global_clock) {                                  // that the time go
            global_clock++;
            for (int i = 0; i < win_count; i++) {
                if (window[i].count > 0) {                                   // if there is customer in the window
                    window[i].time++;                                        // the time of the customer in the window go
                    if (window[i].time == window[i].customer[0].ser_time) {  // time to go
                        window[i].time = 0;
                        window[i].customer[0].leave_time = global_clock;
                        window[i].customer[0].leave_win = i;
                        leaving[leaving_count++] = window[i].customer[0];
                        for (int j = 0; j < window[i].count - 1; j++) {  // queue pop
                            window[i].customer[j] = window[i].customer[j + 1];
                        }
                        window[i].count--;
                    }
                }
            }
        }
        if (buf[0] == '#') {
            window[ser_time].status = 1;  // close the window
            if (window[ser_time].count >= 1) {
                for (int i = 1; i < window[ser_time].count; i++) {
                    add(window, win_count, &window[ser_time].customer[i]);  // queue push
                }
                window[ser_time].count = 1;
            }
        } else if (buf[0] == '@') {
            window[ser_time].status = 0;  // open the window
        } else {
            cus_count++;
            Customer customer;
            strcpy(customer.id, buf);
            customer.arr_time = in_time;
            customer.ser_time = ser_time;
            add(window, win_count, &customer);  // queue push
        }
    }
    while (leaving_count != cus_count) {
        global_clock++;
        for (int i = 0; i < win_count; i++) {  // find the window with the least customers
            if (window[i].count > 0) {
                window[i].time++;
                if (window[i].time == window[i].customer[0].ser_time) {
                    window[i].time = 0;
                    window[i].customer[0].leave_time = global_clock;
                    window[i].customer[0].leave_win = i;
                    leaving[leaving_count++] = window[i].customer[0];
                    for (int j = 0; j < window[i].count - 1; j++) {
                        window[i].customer[j] = window[i].customer[j + 1];
                    }
                    window[i].count--;
                }
            }
        }
    }
    for (int i = 0; i < leaving_count; i++) {  // output
        fprintf(output, "%s %d %d\n", leaving[i].id, leaving[i].leave_time,
                leaving[i].leave_win);
    }
}