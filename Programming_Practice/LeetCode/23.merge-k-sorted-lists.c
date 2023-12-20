/*
 * @lc app=leetcode id=23 lang=c
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    int* valid = (int*)malloc(sizeof(int) * listsSize);
    int not_valid = 0;
    for (int i = 0; i < listsSize; i++) {
        if (lists[i] == NULL) {
            valid[i] = 0;
            not_valid++;
        } else {
            valid[i] = 1;
        }
    }
    while (not_valid != listsSize) {
        int min = 10001;
        int min_index = NULL;
        for (int i = 0; i < listsSize; i++) {
            if (valid[i]) {
                if (min == NULL) {
                    min = lists[i]->val;
                    min_index = i;
                }
                if (lists[i]->val < min) {
                    min = lists[i]->val;
                    min_index = i;
                }
            }
        }
        if (head == NULL) {
            head = lists[min_index];
            tail = lists[min_index];
        } else {
            tail->next = lists[min_index];
            tail = tail->next;
        }
        lists[min_index] = lists[min_index]->next;
        if (lists[min_index] == NULL) {
            valid[min_index] = 0;
            not_valid++;
        }
    }
    return head;
}
// @lc code=end
