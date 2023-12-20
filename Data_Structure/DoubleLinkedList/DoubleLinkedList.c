#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int val;
    struct node *next;
    struct node *pre;
} node;

node *Create(int val) {
    node *n = malloc(sizeof(node));
    n->val = val;
    n->next = NULL;
    n->pre = NULL;
    return n;
}

int main() {
    FILE *input = fopen("input.txt", "r");
    char buf[10];
    int mode = -1;
    int val;
    node *head = NULL;
    node *tail = NULL;
    while (fscanf(input, "%s", buf) != EOF) {
        // double linked list
        if (strcmp(buf, "B") == 0) {
            // insert at head
            mode = 0;
        } else if (strcmp(buf, "E") == 0) {
            // insert at tail
            mode = 1;
        } else if (strcmp(buf, "R") == 0) {
            //  remove head and tail
            node *tmp;
            if (head == NULL) {
                continue;
            } else if (head == tail) {
                tmp = head;
                head = NULL;
                tail = NULL;
                free(tmp);
            } else if (head->next == tail) {
                tmp = head;
                head = NULL;
                free(tmp);
                tmp = tail;
                tail = NULL;
                free(tmp);
            } else {
                tmp = head;
                head = head->next;
                head->pre = NULL;
                free(tmp);
                tmp = tail;
                tail = tail->pre;
                tail->next = NULL;
                free(tmp);
            }
        } else {
            // insert at head or tail
            val = atoi(buf);
            node *new = Create(val);
            if (head == NULL) {
                head = new;
                tail = new;
            } else if (mode == 0) {
                // insert at head
                new->next = head;
                head->pre = new;
                head = new;
            } else if (mode == 1) {
                // insert at tail
                new->pre = tail;
                tail->next = new;
                tail = new;
            }
        }
    }
    // print from head and from tail
    node *p = head;
    while (p != NULL) {
        printf("%d->", p->val);
        p = p->next;
    }
    printf("NULL\n");
    p = tail;
    while (p != NULL) {
        printf("%d->", p->val);
        p = p->pre;
    }
    printf("NULL\n");
}