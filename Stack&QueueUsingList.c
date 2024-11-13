
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct Node*next;};


    struct node *front = NULL, *rear = NULL;


    void enqueue(struct node **front, struct node **rear, int val) {
        struct node *newNode = malloc(sizeof(struct node));
        newNode->data = val;
        newNode->next = NULL;


        if (*front == NULL && *rear == NULL) {
            *front = *rear = newNode;
        } else {

            (*rear)->next = newNode;

            *rear = newNode;
        }
    }


    void dequeue(struct node **front, struct node **rear) {
        if (*front == NULL) {
            printf("Queue is Empty. Unable to perform dequeue\n");
        } else {
            struct node *temp = *front;

            *front = (*front)->next;


            if (*front == NULL) {
                *rear = NULL;
            }


            free(temp);
        }
    }


    void printList(struct node *front) {
        if (front == NULL) {
            printf("Queue is Empty\n");
            return;
        }

        struct node *temp = front;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }


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


void printListS(struct node* head) {
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
        printf("4. Enqueue element into queue\n");
        printf("5. Dequeue element from queue\n");
        printf("6. Print the queue\n");
        printf("7. Exit\n");
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
                printListS(head);
                break;
            case 4:
                printf("Enter the value to enqueue into the queue: ");
                scanf("%d", &value);
                enqueue(&front, &rear, value);
                break;

            case 5:
                dequeue(&front, &rear);
                break;

            case 6:
                printf("Current Queue: ");
                printList(front);
                break;

            case 7:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");

        }
    }

    return 0;
}
