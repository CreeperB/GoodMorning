#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    int val;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

int longest = 0;
int shortest = INT_MAX;

void skew(treeNode *root, int delay) {
    delay += root->val;
    if (root->left == NULL && root->right == NULL) {
        if (delay > longest)
            longest = delay;
        if (delay < shortest)
            shortest = delay;
    }
    if (root->left != NULL) skew(root->left, delay);
    if (root->right != NULL) skew(root->right, delay);
}

int findIndex(int val, int arr[1000], int len) {
    for (int i = 0; i < len; i++)
        if (arr[i] == val) return i;
}

treeNode *buildTree(treeNode **root, int left, int right, int inorder[1000], int postorder[1000], int len) {
    for (int i = right; i >= left; i--) {
        int val = postorder[i];
        treeNode *node = (treeNode *)malloc(sizeof(treeNode));
        node->val = val;
        node->left = NULL;
        node->right = NULL;
        // find where to insert the node
        if (*root == NULL) {
            *root = node;
        } else {
            treeNode *cur = *root;
            while (1) {
                int index = findIndex(cur->val, inorder, len);
                if (index > findIndex(val, inorder, len)) {
                    if (cur->left == NULL) {
                        cur->left = node;
                        break;
                    } else {
                        cur = cur->left;
                    }
                } else {
                    if (cur->right == NULL) {
                        cur->right = node;
                        break;
                    } else {
                        cur = cur->right;
                    }
                }
            }
        }
    }
}

int main() {
    int len = 0;
    int n;
    char tmp;
    int inorder[1000], postorder[1000];
    treeNode *root = NULL;
    while (scanf("%d%c", &n, &tmp) && tmp != '\n')
        inorder[len++] = n;
    inorder[len++] = n;
    for (int i = 0; i < len; i++) 
        scanf("%d", &postorder[i]);
    
    buildTree(&root, 0, len - 1, inorder, postorder, len);
    skew(root, 0);
    printf("Delayed time (longest path) = %d\n", longest);
    printf("Delayed time (shortest path) = %d\n", shortest);
}