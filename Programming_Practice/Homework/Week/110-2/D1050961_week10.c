#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2);

int main(void) {
    ListNode *list1 = NULL, *list1_origin = NULL;
    ListNode *list2 = NULL, *list2_origin = NULL;
    ListNode *outputlist = NULL;  // output list
    int temp = 0;
    int invalid = 1;
    printf("List 1: ");
    scanf("%d", &temp);
    if (temp != -1) {                      // if temp is -1, then the list is empty
        list1 = malloc(sizeof(ListNode));  // create the first node
        list1_origin = list1;              // save the first node
        invalid = 0;
    }
    while (!invalid) {  // if invalid is 0, then the list is not empty
        list1->val = temp;
        if (scanf("%d", &temp) != -1 && temp != -1) {
            list1->next = malloc(sizeof(ListNode));  // create the next node
            list1 = list1->next;
        } else {
            break;
        }
    }
    invalid = 1;
    printf("List 2: ");
    scanf("%d", &temp);
    if (temp != -1) {                      // if temp is -1, then the list is empty
        list2 = malloc(sizeof(ListNode));  // create the first node
        list2_origin = list2;              // save the first node
        invalid = 0;
    }
    while (!invalid) {  // if invalid is 0, then the list is not empty
        list2->val = temp;
        if (scanf("%d", &temp) != -1 && temp != -1) {
            list2->next = malloc(sizeof(ListNode));  // create the next node
            list2 = list2->next;
        } else {
            break;
        }
    }
    outputlist = mergeTwoLists(list1_origin, list2_origin);  // merge the two lists
    printf("Sorted list: ");
    while (outputlist != NULL) {  // print the sorted list
        printf("%d%c", outputlist->val, " \n"[outputlist->next == NULL]);
        outputlist = outputlist->next;
    }
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 == NULL) {  // if list1 is empty, return list2
        return list2;
    } else if (list2 == NULL) {  // if list2 is empty, return list1
        return list1;
    }
    ListNode *list3 = NULL, *current = NULL;
    if (list1->val < list2->val) {  // if list1's value is smaller than list2's value, then list1 is the head of the new list
        current = list1;
        list1 = list1->next;
    } else {  // if list2's value is smaller than list1's value, then list2 is the head of the new list
        current = list2;
        list2 = list2->next;
    }
    list3 = current;
    while (list1 != NULL && list2 != NULL) {  // while list1 and list2 are not empty
        if (list1->val < list2->val) {
            current->next = list1;  // if list1's value is smaller than list2's value, then list1 is the next node of current
            list1 = list1->next;
        } else {
            current->next = list2;  // if list2's value is smaller than list1's value, then list2 is the next node of current
            list2 = list2->next;
        }
        current->next->next = NULL;  // set the next node of current to NULL
        current = current->next;
    }
    if (list1 != NULL && list2 == NULL) {  // if list1 is not empty, then list1 is the next node of current
        current->next = list1;
    }
    if (list1 == NULL && list2 != NULL) {  // if list2 is not empty, then list2 is the next node of current
        current->next = list2;
    }
    return list3;  // return the head of the new list
}