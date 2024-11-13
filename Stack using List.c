
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct Node*next;};


struct node* push(struct node* head, int val) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = head;
    return newNode;
}


struct node* pop(struct node* head) {
    if (head == NULL) {
        printf("Stack is Empty\n");
        return NULL;
    } else {
        printf("Popped element = %d\n", head->data);
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
}


void printList(struct node* head) {
    if (head == NULL) {
        printf("Stack is Empty\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int choice, value;

    while (1) {

        printf("\nMenu:\n");
        printf("1. Push element onto stack\n");
        printf("2. Pop element from stack\n");
        printf("3. Print the stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push onto the stack: ");
                scanf("%d", &value);
                head = push(head, value);
                break;

            case 2:
                head = pop(head);
                break;

            case 3:
                printf("Current stack: ");
                printList(head);
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
