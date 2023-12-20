#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;  //開頭，刪除的地方
    Node* rear;   //結尾，加入的地方
} Queue;

/** initialize your data structure here. */
Queue* Create() {
    return malloc(sizeof(Queue));
}

/** Insert an element into the queue. */
void Enqueue(Queue* obj, int x) {
    Node* node = malloc(sizeof(Node));
    node->data = x;
    node->next = NULL;
    if (obj->front == NULL)
        obj->front = node;
    else
        obj->rear->next = node;
    obj->rear = node;
}

/** Delete an element from the queue. If is empty do noting. */
void Dequeue(Queue* obj) {
    if (obj->front == NULL)
        return;
    Node* temp = obj->front;
    obj->front = obj->front->next;
    if (obj->front == NULL)
        obj->rear = NULL;
    free(temp);
}

/** Get the front item from the queue. If is empty return -1.*/
int Front(Queue* obj) {
    if (obj->front == NULL)
        return -1;
    return obj->front->data;
}

/** Get the last item from the queue. If is empty return -1.*/
int Rear(Queue* obj) {
    if (obj->rear == NULL)
        return -1;
    return obj->rear->data;
}

/** find the index of min element in the queue, if is empty return -1.*/
/** 從front開始，index為0。向後遞增*/
int GetIndexOfMin(Queue* obj) {
    if (obj->front == NULL)
        return -1;
    Node* cur = obj->front;
    int min = cur->data, index = 0;
    cur = cur->next;
    for (int i = 1; cur; i++) {
        if (cur->data < min) {
            min = cur->data;
            index = i;
        }
        cur = cur->next;
    }
    return index;
}

/** if Queue is empty print "NULL". */
void QueuePrint(Queue* obj) {
    Node* cur = obj->front;
    while (cur) {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main() {
    Queue* obj = Create();
    int count, num, t;
    scanf("%d", &count);
    while (count--) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d", &num);
            Enqueue(obj, num);
        } else if (t == 2) {
            Dequeue(obj);
        } else if (t == 3) {
            printf("%d\n", Front(obj));
            continue;
        } else if (t == 4) {
            printf("%d\n", Rear(obj));
            continue;
        } else if (t == 5) {
            printf("%d\n", GetIndexOfMin(obj));
            continue;
        }
        QueuePrint(obj);
    }
}