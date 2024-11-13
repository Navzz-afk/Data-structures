
#include<stdio.h>
#include<stdlib.h>


int main() {
    struct node {
        int data;
        struct node *next;
    };

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


    int choice, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue element into queue\n");
        printf("2. Dequeue element from queue\n");
        printf("3. Print the queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue into the queue: ");
                scanf("%d", &value);
                enqueue(&front, &rear, value);
                break;

            case 2:
                dequeue(&front, &rear);
                break;

            case 3:
                printf("Current Queue: ");
                printList(front);
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
