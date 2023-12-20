#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSELLER 8
#define MAXLENGTH 20

FILE *Input;
FILE *SearchTable;
FILE *BuyTable;
FILE *SortTable;
FILE *LogTable;

typedef struct sellernode {
    char id[MAXLENGTH];
    int price;
} SellerNode;

typedef struct product {
    char name[MAXLENGTH];
    int count;
    SellerNode seller[MAXSELLER];
} Product;

typedef struct productnode {
    Product *product;
    struct productnode *left;
    struct productnode *right;
} ProductNode;

ProductNode *root;
int productCount = 0;

void heaptifyTopToBot(SellerNode *seller, int n, int i) {
    // min heap
    int min = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && seller[left].price < seller[min].price) {
        min = left;
    }
    if (right < n && seller[right].price < seller[min].price) {
        min = right;
    }
    if (min != i) {
        SellerNode temp = seller[i];
        seller[i] = seller[min];
        seller[min] = temp;
        heaptifyTopToBot(seller, n, min);
    }
}

void heaptifyBotToTop(SellerNode *seller, int i) {
    // min heap from bottom to top
    int temp;
    int parent = (i - 1) / 2;
    if (i == 0)
        return;
    if (seller[parent].price > seller[i].price) {
        SellerNode temp = seller[i];
        seller[i] = seller[parent];
        seller[parent] = temp;
        heaptifyBotToTop(seller, parent);
    }
}

char *lower(char *str) {
    char *p = malloc(sizeof(char) * MAXLENGTH);
    strcpy(p, str);
    while (*p != '\0') {
        if (*p >= 'A' && *p <= 'Z') {
            *p += 32;
        }
        p++;
    }
    return str;
}

void insert(char item[MAXLENGTH], char seller[MAXLENGTH], int price) {
    // make seller's price as min heap
    SellerNode *newSeller = (SellerNode *)malloc(sizeof(SellerNode));
    strcpy(newSeller->id, seller);
    newSeller->price = price;

    // find product
    bool isExist = false;
    ProductNode *temp = root;
    while (temp != NULL) {
        if (strcmp(lower(temp->product->name), lower(item)) == 0) {
            isExist = true;
            break;
        } else if (strcmp(lower(temp->product->name), lower(item)) > 0) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    if (isExist) {
        // input seller
        temp->product->seller[temp->product->count++] = *newSeller;
        heaptifyBotToTop(temp->product->seller, temp->product->count - 1);
    } else {
        // create new product
        Product *newProduct = (Product *)malloc(sizeof(Product));
        strcpy(newProduct->name, item);
        newProduct->count = 1;
        newProduct->seller[0] = *newSeller;

        // create new node
        ProductNode *newNode = (ProductNode *)malloc(sizeof(ProductNode));
        newNode->product = newProduct;
        newNode->left = NULL;
        newNode->right = NULL;
        productCount++;

        // insert node
        if (root == NULL) {
            root = newNode;
        } else {
            ProductNode *temp = root;
            while (temp != NULL) {
                if (strcmp(lower(temp->product->name), lower(item)) > 0) {
                    if (temp->left == NULL) {
                        temp->left = newNode;
                        break;
                    } else {
                        temp = temp->left;
                    }
                } else {
                    if (temp->right == NULL) {
                        temp->right = newNode;
                        break;
                    } else {
                        temp = temp->right;
                    }
                }
            }
        }
    }
}

int searchtime = 0;
int search(char item[MAXLENGTH]) {
    ProductNode *temp = root;
    while (temp != NULL) {
        if (strcmp(temp->product->name, item) == 0) {
            fprintf(SearchTable, "%s\n", temp->product->name);
            for (int i = 0; i < temp->product->count; i++)
                fprintf(SearchTable, "%s %d\n", temp->product->seller[i].id, temp->product->seller[i].price);
            fprintf(SearchTable, "----------------------------\n");
            return 0;
        } else if (strcmp(temp->product->name, item) > 0) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    fprintf(SearchTable, "%s doesn’t exist!\n", item);
    fprintf(SearchTable, "----------------------------\n");
    return 1;
}

void deleteProduct(Product *product) {
    productCount--;
    ProductNode *temp = root;
    ProductNode *parent = NULL;
    while (temp != NULL) {
        // delete in BST
        if (strcmp(temp->product->name, product->name) == 0) {
            if (temp->left == NULL && temp->right == NULL) {
                if(parent == NULL){
                    free(temp);
                    root = NULL;
                }
                if (parent->left == temp) {
                    free(parent->left);
                    parent->left = NULL;
                } else {
                    free(parent->right);
                    parent->right = NULL;
                }
            } else if (temp->left == NULL) {
                if(parent == NULL)
                    root = temp->right;
                else if (parent->left == temp)
                    parent->left = temp->right;
                else
                    parent->right = temp->right;
            } else if (temp->right == NULL) {
                if(parent == NULL)
                    root = temp->left;
                if (parent->left == temp)
                    parent->left = temp->left;
                else
                    parent->right = temp->left;
            } else {
                ProductNode *min = temp->right;
                ProductNode *minParent = temp;
                while (min->left != NULL) {
                    minParent = min;
                    min = min->left;
                }
                temp->product = min->product;
                if (minParent->left == min)
                    minParent->left = min->right;
                else
                    minParent->right = min->right;
                temp = min;
            }
            break;
        } else if (strcmp(temp->product->name, product->name) > 0) {
            parent = temp;
            temp = temp->left;
        } else {
            parent = temp;
            temp = temp->right;
        }
    }
}

void deleteSeller(Product *product) {
    product->seller[0] = product->seller[--product->count];
    heaptifyTopToBot(product->seller, product->count, 0);
    if (product->count == 0) {
        deleteProduct(product);
    }
}

int buy(char item[MAXLENGTH]) {
    ProductNode *temp = root;
    while (temp != NULL) {
        if (strcmp(temp->product->name, item) == 0) {
            fprintf(BuyTable, "%s %s %d\n", temp->product->name, temp->product->seller[0].id, temp->product->seller[0].price);
            deleteSeller(temp->product);
            return 0;
        } else if (strcmp(temp->product->name, item) > 0) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    fprintf(BuyTable, "%s doesn’t exist!\n", item);
    return 1;
}

void inorder(ProductNode *cur, char **names, int *index) {
    if (cur != NULL) {
        inorder(cur->left, names, index);
        strcpy(names[(*index)++], cur->product->name);
        inorder(cur->right, names, index);
    }
}

void sort() {
    char **names = (char **)malloc(sizeof(char *) * productCount);
    for (int i = 0; i < productCount; i++)
        names[i] = (char *)malloc(sizeof(char) * MAXLENGTH);
    ProductNode *temp = root;
    int i = 0;
    inorder(temp, names, &i);
    for (int i = 0; i < productCount; i++) {
        fprintf(SortTable, "%s\n", names[i]);
    }
    fprintf(SortTable, "----------------------------\n");
}

void height(int *max, int cur, ProductNode *root) {
    if (root != NULL) {
        height(max, cur + 1, root->left);
        if (cur > *max)
            *max = cur;
        height(max, cur + 1, root->right);
    }
}

int findHeight() {
    int max = 0;
    height(&max, 1, root);
    return max;
}

void report(int insertCount, int searchCount, int searchFail, int buyCount, int buyFail) {
    fprintf(LogTable, "insert %d\n", insertCount);
    fprintf(LogTable, "search %d %d\n", searchCount, searchFail);
    fprintf(LogTable, "buy %d %d\n", buyCount, buyFail);
    fprintf(LogTable, "node_num %d\n", productCount);
    fprintf(LogTable, "height %d\n", findHeight());
}

int main() {
    Input = fopen("Input.txt", "r");
    SearchTable = fopen("SearchTable.txt", "w");
    BuyTable = fopen("BuyTable.txt", "w");
    SortTable = fopen("SortTable.txt", "w");
    LogTable = fopen("LogTable.txt", "w");

    root = NULL;

    int insertCount = 0, searchCount = 0, searchFail = 0, buyCount = 0, buyFail = 0;

    char command[MAXLENGTH];
    while (fscanf(Input, "%s", command) != EOF) {
        if (strcmp(command, "insert") == 0) {
            char item[MAXLENGTH];
            char seller[MAXLENGTH];
            int price;
            fscanf(Input, "%s %s %d", item, seller, &price);
            insert(item, seller, price);
            insertCount++;
        } else if (strcmp(command, "search") == 0) {
            char item[MAXLENGTH];
            fscanf(Input, "%s", item);
            searchFail += search(item);
            searchCount++;
        } else if (strcmp(command, "buy") == 0) {
            char item[MAXLENGTH];
            fscanf(Input, "%s", item);
            buyFail += buy(item);
            buyCount++;
        } else if (strcmp(command, "sort") == 0) {
            sort();
        } else if (strcmp(command, "report") == 0) {
            report(insertCount, searchCount, searchFail, buyCount, buyFail);
        }
    }
}