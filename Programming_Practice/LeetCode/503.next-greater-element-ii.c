/*
 * @lc app=leetcode id=503 lang=c
 *
 * [503] Next Greater Element II
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct node {
    int val;
    struct node* next;
} node;

int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    node* obj = malloc(sizeof(node));
    obj->val = 0;
    obj->next = NULL;
    node* head = obj;
    for (int i = 0; i < numsSize; i++) {
        obj->val = nums[i];
        if (i != numsSize - 1) {
            obj->next = malloc(sizeof(node));
            obj = obj->next;
        }
    }
    obj->next = head;
    obj = head;
    int* res = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        node* cur = obj->next;
        while (true) {
            if (cur == obj) {  // return -1 when finish searching all the elements
                res[i] = -1;
                break;
            }
            if (cur->val > nums[i]) {  // return the current value which is greater than the comparison one
                res[i] = cur->val;
                break;
            }
            cur = cur->next;
        }
        obj = obj->next;
    }
    *returnSize = numsSize;
    return res;
}

// @lc code=end
