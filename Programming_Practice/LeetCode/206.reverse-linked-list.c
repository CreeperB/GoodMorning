/*
 * @lc app=leetcode id=206 lang=c
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* pre = (struct ListNode*)malloc(sizeof(struct ListNode));
    pre = head;
    head = head->next;
    pre->next = NULL;
    while (head != NULL) {
        struct ListNode* temp = pre;
        pre = head;
        head = head->next;
        pre->next = temp;
    }
    return pre;
}
// @lc code=end
