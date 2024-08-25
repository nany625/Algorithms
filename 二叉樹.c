#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    int data;
    struct treeNode *left, *right;
} TreeNode;

TreeNode *createNode(int data) {
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode *insertNode(TreeNode *root, int data) {
    if(!root)
        return createNode(data);
    if(root->data > data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);
    return root;
}

void inorderTraversal(TreeNode *root) {
    if(root) {
        inorderTraversal(root->left);
        printf(" %d", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(TreeNode *root) {
    if(root) {
        printf(" %d", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode *root) {
    if(root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf(" %d", root->data);
    }
}

void freeTree(TreeNode *root) {
    if(root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    TreeNode *root = NULL;
    int n;
    while(scanf("%d", &n) == 1)
        root = insertNode(root, n);
    fputs("Inorder Traversal:", stdout);
    inorderTraversal(root);
    fputs("\nPreorder Traversal:", stdout);
    preorderTraversal(root);
    fputs("\nPostorder Traversal:", stdout);
    postorderTraversal(root);
    putchar('\n');
    freeTree(root);
    return 0;
}

/*
Input:
50
30
60
40
80
20
90
70
10

Output:
Inorder Traversal: 10 20 30 40 50 60 70 80 90
Preorder Traversal: 50 30 20 10 40 60 80 70 90
Postorder Traversal: 10 20 40 30 70 90 80 60 50
*/

/*
Binary Search Tree:
         50
        /  \
      30    60
     /  \     \
   20    40    80
  /           /  \
10          70    90
*/
