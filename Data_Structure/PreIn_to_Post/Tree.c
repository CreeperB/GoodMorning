#include <stdio.h>
#include <stdlib.h>

FILE* input, *output;
char* pre, *in;

void getPost(int pre_i, int left, int right) {  // pre_i is the index of the root in pre
    char root = pre[pre_i];     // root is the root of the pre_i subtree
    if (left < right) {         // if there are more than one nodes in the subtree
        int mid = left;
        for (; in[mid] != root; mid++);     // find the root in in
        if (mid > left) getPost(pre_i + 1, left, mid - 1);                   // if there are nodes in the left subtree
        if (mid < right) getPost(pre_i + 1 + (mid - left), mid + 1, right);  // if there are nodes in the right subtree
    }
    fprintf(output, "%c", root);
}

int main() {
    input = fopen("input.txt", "r"), output = fopen("output.txt", "w");
    int n;
    fscanf(input, "%d", &n);
    pre = (char*)malloc((n + 1) * sizeof(char)), in = (char*)malloc((n + 1) * sizeof(char));
    fscanf(input, "%s %s", pre, in);
    getPost(0, 0, n - 1);
}