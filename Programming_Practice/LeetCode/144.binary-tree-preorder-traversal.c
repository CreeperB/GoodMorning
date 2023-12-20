/*
 * @lc app=leetcode id=144 lang=c
 *
 * [144] Binary Tree Preorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int nodecount(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return nodecount(root->left) + nodecount(root->right) + 1;
}

void preorder(struct TreeNode* root, int* returnSize, int* res) {
    if (root == NULL) {
        return;
    }
    res[(*returnSize)++] = root->val;
    preorder(root->left, returnSize, res);
    preorder(root->right, returnSize, res);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int nodes = nodecount(root);
    int* res = malloc(sizeof(int) * nodes);
    *returnSize = 0;
    preorder(root, returnSize, res);
    return res;
}
// @lc code=end
