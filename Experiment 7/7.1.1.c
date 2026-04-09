/*Write a C program to implement a binary search tree with the following functionalities:

 1. Insert(): Insert a node into the binary search tree (BST).
 2. Inorder(): Perform inorder traversal of the BST.
 3. Preorder(): Perform preorder traversal of the BST.
 4. Postorder(): Perform postorder traversal of the BST.
 5. Delete(): Delete a node from the BST.
 6. Exit(): Terminate the program.*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    struct TreeNode* root = NULL;
    int choice, data;

    while (1) {
        printf("1. Insert\n2. In-Order\n3. Pre-Order\n4. Post-Order\n5. Delete\n6. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) {
            printf("Data: ");
            scanf("%d", &data);
            struct TreeNode* newNode = createNode(data);
            if (root == NULL) {
                root = newNode;
            } else {
                struct TreeNode *curr = root, *parent = NULL;
                while (curr != NULL) {
                    parent = curr;
                    curr = (data < curr->val) ? curr->left : curr->right;
                }
                if (data < parent->val) parent->left = newNode;
                else parent->right = newNode;
            }
        } 
        else if (choice == 2) {
            if (root == NULL) printf("Empty\n");
            else {
                struct TreeNode* stack[100];
                int top = -1;
                struct TreeNode* curr = root;
                while (curr != NULL || top != -1) {
                    while (curr != NULL) {
                        stack[++top] = curr;
                        curr = curr->left;
                    }
                    curr = stack[top--];
                    printf("%d ", curr->val);
                    curr = curr->right;
                }
                printf("\n");
            }
        } 
        else if (choice == 3) {
            if (root == NULL) printf("Empty\n");
            else {
                struct TreeNode* stack[100];
                int top = -1;
                stack[++top] = root;
                while (top != -1) {
                    struct TreeNode* temp = stack[top--];
                    printf("%d ", temp->val);
                    if (temp->right) stack[++top] = temp->right;
                    if (temp->left) stack[++top] = temp->left;
                }
                printf("\n");
            }
        } 
        else if (choice == 4) {
            if (root == NULL) printf("Empty\n");
            else {
                struct TreeNode *stack1[100], *stack2[100];
                int top1 = -1, top2 = -1;
                stack1[++top1] = root;
                while (top1 != -1) {
                    struct TreeNode* temp = stack1[top1--];
                    stack2[++top2] = temp;
                    if (temp->left) stack1[++top1] = temp->left;
                    if (temp->right) stack1[++top1] = temp->right;
                }
                while (top2 != -1) printf("%d ", stack2[top2--]->val);
                printf("\n");
            }
        } 
        else if (choice == 5) {
            if (root == NULL) {
                printf("Empty\n");
                continue;
            }
            printf("Delete: ");
            scanf("%d", &data);
            struct TreeNode *curr = root, *parent = NULL;
            while (curr != NULL && curr->val != data) {
                parent = curr;
                curr = (data < curr->val) ? curr->left : curr->right;
            }
            if (curr == NULL) printf("Not found\n");
            else {
                if (curr->left == NULL || curr->right == NULL) {
                    struct TreeNode* newCurr = (curr->left == NULL) ? curr->right : curr->left;
                    if (parent == NULL) root = newCurr;
                    else if (parent->left == curr) parent->left = newCurr;
                    else parent->right = newCurr;
                    free(curr);
                } else {
                    struct TreeNode *temp = curr->right, *tempP = curr;
                    while (temp->left != NULL) {
                        tempP = temp;
                        temp = temp->left;
                    }
                    curr->val = temp->val;
                    if (tempP->left == temp) tempP->left = temp->right;
                    else tempP->right = temp->right;
                    free(temp);
                }
            }
        } 
        else if (choice == 6) break;
        else printf("Invalid\n");
    }
    return 0;
}
