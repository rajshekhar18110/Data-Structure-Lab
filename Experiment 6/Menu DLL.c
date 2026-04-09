/*Write a menu-driven C program to perform operations on a Doubly Linked List.
The program should support insertion, deletion, display, reversal, concatenation of another list, and exit operations.*/


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(struct Node** head, int data) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    while (temp != NULL && temp->data != data) temp = temp->next;
    if (temp == NULL) return;
    if (temp == *head) {
        *head = temp->next;
        if (*head != NULL) (*head)->prev = NULL;
    } else {
        if (temp->prev != NULL) temp->prev->next = temp->next;
        if (temp->next != NULL) temp->next->prev = temp->prev;
    }
    free(temp);
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void reverse(struct Node** head) {
    struct Node *temp = NULL, *curr = *head;
    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != NULL) *head = temp->prev;
}

void concatenate(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }
    if (head2 == NULL) return;
    struct Node* temp = *head1;
    while (temp->next != NULL) temp = temp->next;
    temp->next = head2;
    head2->prev = temp;
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    int choice, val, n, i;
    while (1) {
        printf("\n1.Insert 2.Delete 3.Display 4.Reverse 5.Concatenate 6.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(&list1, val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                deleteNode(&list1, val);
                break;
            case 3:
                display(list1);
                break;
            case 4:
                reverse(&list1);
                printf("Reversed\n");
                break;
            case 5:
                printf("Nodes for second list: ");
                scanf("%d", &n);
                list2 = NULL;
                for (i = 0; i < n; i++) {
                    printf("Value %d: ", i + 1);
                    scanf("%d", &val);
                    insert(&list2, val);
                }
                concatenate(&list1, list2);
                printf("Concatenated\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid\n");
        }
    }
    return 0;
}
