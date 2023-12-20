typedef struct treeNode {
    int data;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

void Search(treeNode* root, int val) {
    int layer = 1;
    while (root->data != val) {  // search val
        if (root->data > val)
            root = root->left;
        else if (root->data < val)
            root = root->right;
        layer++;
    }
    printf("level=%d\n", layer);
}

treeNode* Create(int val) {
    treeNode* new = malloc(sizeof(treeNode));
    new->data = val;
    new->left = new->right = NULL;
    return new;
}

treeNode* Insert(treeNode* root, int val) {
    if (!root)
        return Create(val);  // create new node
    else if (val < root->data)
        root->left = Insert(root->left, val);  // insert to left
    else if (val > root->data)
        root->right = Insert(root->right, val);  // insert to right
    return root;
}

int Max(treeNode* root) {
    if (!root->right)
        return root->data;
    else
        return Max(root->right);  // search max
}

treeNode* Delete(treeNode* root, int key) {
    treeNode* temp = NULL;
    if (!root)
        return NULL;
    else if (key < root->data)  // delete from left
        root->left = Delete(root->left, key);
    else if (key > root->data)  // delete from right
        root->right = Delete(root->right, key);
    else {  // delete root
        if (!root->left && !root->right) {
            free(root);
            root = NULL;
        } else if (root->right) {
            temp = root;
            root = root->right;
            free(temp);
        } else if (root->left) {
            temp = root;
            root = root->left;
            free(temp);
        } else {
            root->data = Max(root->left);
            root->left = Delete(root->left, root->data);
        }
    }
    return root;
}

void Inorder(treeNode* root) {  // inorder
    if (!root)
        return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}