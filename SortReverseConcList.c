#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node*next;}Node;

Node * createNode(int value){
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){printf("Memory alloc failed\n"); exit(1);}
    newNode->data=value; newNode -> next=NULL;
    return newNode;
}

Node * insertAtBeginning(Node * head,int Value){
    Node*newNode= createNode(Value);
    newNode->next=head;
    return newNode;
}

Node*concat(Node*head1,Node*head2){
    Node*temp=head1;
    while(temp->next!=NULL)
        {temp=temp->next;}
    temp->next=head2;
    return head1;
}

Node *sort(Node *head) {
    Node *temp, *current;
    int t;
    current = head;
    while (current != NULL) {
        temp = head;
        while (temp->next != NULL) {
            if (temp->data > temp->next->data) {
                t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
            }
            temp = temp->next;
        }
        current = current->next;
    }
    return head;
}

Node*reverse(Node*head){
    Node*prev=NULL,*temp,*next;
    temp=head;
    while(temp!=NULL){
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    head=prev;
    return head;
}

void displayLinkedList(Node*head1,Node*head2){
    printf("Linked list 1:");
    while(head1!=NULL){
        printf("%d ->",head1->data);
        head1=head1->next;
    }
    printf("NULL \n");

    printf("Linked list 2:");
    while(head2!=NULL){
        printf("%d ->",head2->data);
        head2=head2->next;
    }
    printf("NULL \n");
}

void main(){
Node*list1=NULL;
Node*list2=NULL;
int choice,value;
while(1)
{
    printf("1.Add element to List 1\n");
    printf("2.Add element to List 2\n");
    printf("3.Concatenate List1 And list2\n");
    printf("4.Sort list1\n");
    printf("5.Reverse list1\n");
    printf("6.Display lists\n");
    printf("7.Exit\n");
    printf("enter choice");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("enter value to input");
        scanf("%d",&value);
        list1=insertAtBeginning(list1,value);
        break;

    case 2:
        printf("enter value to input");
        scanf("%d",&value);
        list2=insertAtBeginning(list2,value);
        break;
    case 3:
        list1=concat(list1,list2);
        break;
    case 4:
        list1=sort(list1);
        break;
    case 5:
        list1=reverse(list1);
        break;

    case 6:
        displayLinkedList(list1,list2);
        break;
    case 7:
        printf("Exiting...");
        exit(0);
        break;
    default:
        printf("enter valid input");
        break;
    }
}
}
