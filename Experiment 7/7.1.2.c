/*Write a program to implement the following operations in a Binary Search Tree (BST)

 1. Inserting a node
 2. Deleting a node 
 3. Search a node*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPS 100

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    int opCount;
    if (scanf("%d", &opCount) != 1) return 0;

    Node *root = NULL;
    char outputs[MAX_OPS][50];
    int outIndex = 0;
    int op, key;

    for (int i = 0; i < opCount; i++) {
        scanf("%d", &op);
        if (op >= 1 && op <= 3) scanf("%d", &key);

        if (op == 1) {
            if (root == NULL) {
                root = createNode(key);
            } else {
                Node *curr = root, *parent = NULL;
                while (curr != NULL) {
                    parent = curr;
                    if (key < curr->data) curr = curr->left;
                    else if (key > curr->data) curr = curr->right;
                    else break;
                }
                if (curr == NULL) {
                    if (key < parent->data) parent->left = createNode(key);
                    else parent->right = createNode(key);
                }
            }
        } 
        else if (op == 2) {
            Node *curr = root, *parent = NULL;
            while (curr != NULL && curr->data != key) {
                parent = curr;
                curr = (key < curr->data) ? curr->left : curr->right;
            }
            if (curr != NULL) {
                if (curr->left == NULL || curr->right == NULL) {
                    Node* next = (curr->left == NULL) ? curr->right : curr->left;
                    if (parent == NULL) root = next;
                    else if (parent->left == curr) parent->left = next;
                    else parent->right = next;
                    free(curr);
                } else {
                    Node *temp = curr->right, *tempP = curr;
                    while (temp->left != NULL) {
                        tempP = temp;
                        temp = temp->left;
                    }
                    curr->data = temp->data;
                    if (tempP->left == temp) tempP->left = temp->right;
                    else tempP->right = temp->right;
                    free(temp);
                }
            }
        } 
        else if (op == 3) {
            Node* curr = root;
            int found = 0;
            while (curr != NULL) {
                if (curr->data == key) {
                    found = 1;
                    break;
                }
                curr = (key < curr->data) ? curr->left : curr->right;
            }
            strcpy(outputs[outIndex++], found ? "found" : "not found");
        }
    }

    for (int i = 0; i < outIndex; i++) {
        printf("%s\n", outputs[i]);
    }

    return 0;
}
