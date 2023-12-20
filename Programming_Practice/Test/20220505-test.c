typedef struct MyLinkedList {
    int data;
    struct MyLinkedList* next;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* head = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    head->data = -1;
    head->next = NULL;
    return head;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index == 0) {
        return obj->data;
    }
    obj = obj->next;
    while (obj) {
        if (index--) {
            return obj->data;
        }
        obj = obj->next;
    }
    return -1;
}

/** Add a node of value data before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int data) {
    MyLinkedList* new = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    new->data = data;
    new->next = obj->next;
    obj->next = new;
}

/** Append a node of value data to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int data) {
    while (obj && obj->next) {
        obj = obj->next;
    }
    MyLinkedList* temp = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    temp->data = data;
    temp->next = NULL;
    obj->next = temp;
}

/** Add a node of value data before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int data) {
    if (index == 0) {
        return myLinkedListAddAtHead(obj, data);
    } else {
        while (index--) {
            obj = obj->next;
        }
        MyLinkedList* new = (MyLinkedList*)malloc(sizeof(MyLinkedList));
        new->data = data;
        new->next = obj->next;
        obj->next = new;
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList *cur = obj->next, *pre = obj;
    int count = 0;
    while (cur) {
        if (count == index) {
            pre->next = cur->next;
            free(cur);
            return;
        }
        count++;
        pre = cur;
        cur = cur->next;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    while (obj) {
        MyLinkedList* temp = obj;
        obj = obj->next;
        free(temp);
    }
}

/** find the max number.If the linkedList is invalid, return -1.*/
int getMax(MyLinkedList* obj) {
    if (obj == NULL) {
        return -1;
    }
    int max = obj->data;
    while (obj->next) {
        obj = obj->next;
        if (obj->data > max) {
            max = obj->data;
        }
    }
    return max;
}