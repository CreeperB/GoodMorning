#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

/* Initialize your data structure here. */
Queue* Create() {
    Queue* obj = (Queue*)malloc(sizeof(Queue));  // allocate memory for Queue
    obj->front = NULL;                           // initialize front pointers
    obj->rear = NULL;                            // initialize rear pointers
    return obj;                                  // return the Queue
}

/* Inserts an element x into the Queue.*/
void EnQueue(Queue* obj, int x) {
    Node* node = (Node*)malloc(sizeof(Node));  // allocate memory for Node
    node->data = x;
    node->next = NULL;
    if (obj->front == NULL) {    // if Queue is empty
        obj->front = node;       // set front to point to the new node
        obj->rear = node;        // set rear to point to the new node
    } else {                     // if Queue is not empty
        obj->rear->next = node;  // set rear's next to point to the new node
        obj->rear = node;        // set rear to point to the new node
    }
}

/* Deletes an element from the Queue. If the queue is empty, return -1.*/
int DeQueue(Queue* obj) {
    int ret = -1;              // return -1 if Queue is empty
    if (obj->front == NULL) {  // if Queue is empty
        return ret;
    } else if (obj->front == obj->rear) {  // if Queue has only one element
        ret = obj->front->data;            // get the only element
        free(obj->front);                  // free the only element
        obj->front = NULL;                 // reset front
        obj->rear = NULL;                  // reset rear
    } else {                               // if Queue has more than one element
        ret = obj->front->data;            // get the first element
        Node* tmp = obj->front;            // save the first element
        obj->front = obj->front->next;     // reset front
        free(tmp);                         // free the first element
    }
    return ret;
}

/* Gets the front item from the queue. If the queue is empty, return -1.*/
int GetFront(Queue* obj) {
    if (obj->front == NULL) {  // if Queue is empty
        return -1;
    }
    return obj->front->data;  // return front element
}

/* Returns whether the queue is empty. */
int QueueEmpty(Queue* obj) {
    return obj->front == NULL;  // if Queue is empty, return 1, else return 0
}

/* Returns the size of the queue. */
void QueuePrint(Queue* obj) {
    Node* cur = obj->front;
    while (cur) {
        printf("%d ", cur->data);  // print data and remember there's a space at the end
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    Queue* obj = Create();
    int count, num, mode;
    scanf("%d", &count);
    while (count--) {
        scanf("%d", &mode);
        if (mode == 1) {
            scanf("%d", &num);
            EnQueue(obj, num);
            QueuePrint(obj);
        } else if (mode == 2) {
            printf("%d\n", DeQueue(obj));
        } else if (mode == 3) {
            printf("%d\n", GetFront(obj));
            continue;
        } else if (mode == 4) {
            printf("%d\n", QueueEmpty(obj));
            continue;
        }
    }
}