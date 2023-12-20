typedef struct treeNode {
    int data;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

void Preorder(treeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(treeNode* root) {
    if (root == NULL) {
        return;
    }
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

void Postorder(treeNode* root) {
    if (root == NULL) {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
}

void getMin(treeNode* root) {
    int layer = 1, min = 0;
    while (root->left) {
        root = root->left;
        layer++;
    }
    min = root->data;
    printf("min=%d\nlayer=%d\n", min, layer);
}

void getMax(treeNode* root) {
    int layer = 1, max = 0;
    while (root->right) {
        root = root->right;
        layer++;
    }
    max = root->data;
    printf("max=%d\nlayer=%d\n", max, layer);
}