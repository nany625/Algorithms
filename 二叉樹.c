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
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(TreeNode *root) {
    if(root) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode *root) {
    if(root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
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
    int num;
    while(scanf("%d", &num) == 1)
        root = insertNode(root, num);
    fputs("Inorder Traversal: ", stdout);
    inorderTraversal(root);
    fputs("\nPreorder Traversal: ", stdout);
    preorderTraversal(root);
    fputs("\nPostorder Traversal: ", stdout);
    postorderTraversal(root);
    putchar('\n');
    freeTree(root);
    return 0;
}
