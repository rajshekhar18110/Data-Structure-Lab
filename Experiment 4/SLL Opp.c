/*Write a menu-driven C program to implement the fundamental operations on a Singly Linked List using dynamic memory allocation*/

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
int main() {
    struct node *head=NULL, *temp, *newnode, *prev;
    int choice, n, data, pos;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&data);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
        if(head==NULL)
            head = newnode;
        else{
            temp = head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newnode;
        }
    }
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Reverse\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter data: ");
            scanf("%d",&data);
            printf("Enter position: ");
            scanf("%d",&pos);
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=data;
            if(pos==0){
                newnode->next=head;
                head=newnode;
            }else{
                temp=head;
                for(int i=0;i<pos-1;i++)
                    temp=temp->next;
                newnode->next=temp->next;
                temp->next=newnode;
            }
        }
        else if(choice==2){
            printf("Enter position: ");
            scanf("%d",&pos);
            temp=head;
            if(pos==0){
                head=head->next;
                free(temp);
            }else{
                for(int i=0;i<pos-1;i++)
                    temp=temp->next;
                prev=temp->next;
                temp->next=prev->next;
                free(prev);
            }
        }
        else if(choice==3){
            struct node *prev=NULL,*curr=head,*next;
            while(curr!=NULL){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            head=prev;
        }
        else if(choice==4){
            temp=head;
            while(temp!=NULL){
                printf("%d -> ",temp->data);
                temp=temp->next;
            }
            printf("NULL\n");
        }
        else if(choice==5){
            break;
        }
        else{
            printf("Invalid choice\n");
        }
    }
    return 0;
}
