/*Write a C program to implement a menu-driven application for performing operations on two Singly Linked Lists. 
The program should allow the user to create two singly linked lists, display them, and concatenate the second list to the end of the first list.*/

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
typedef struct node* NODE;
NODE createNode(int x) {
    NODE newNode = (NODE)malloc(sizeof(struct node));
    if(newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
NODE addNode(NODE first, int x) {
    NODE newNode = createNode(x);
    if(first == NULL)
        return newNode;
    NODE temp = first;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return first;
}
NODE concatenate(NODE t1, NODE t2) {
    if(t1 == NULL)
        return t2;
    NODE temp = t1;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = t2;
    return t1;
}
void displayList(NODE first) {
    NODE temp = first;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
