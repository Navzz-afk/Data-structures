#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left, *right;
};

struct Node* newnode(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insertNode(struct Node* node, int value) {
    if (node == NULL) {
        return newnode(value);
    }
    if (value < node->data) {
        node->left = insertNode(node->left, value);
    } else if (value > node->data) {
        node->right = insertNode(node->right, value);
    }

    return node;
}

void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->data);
    }
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf(" %d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(struct Node* root) {
    if (root != NULL) {
        printf(" %d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value, count;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a new node\n");
        printf("2. Display postorder traversal\n");
        printf("3. Display preorder traversal\n");
        printf("4. Display inorder traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:

                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("Node inserted successfully.\n");
                break;

            case 2:

                printf("Postorder traversal:\n");
                postOrder(root);
                printf("\n");
                break;

            case 3:

                printf("Preorder traversal:\n");
                preOrder(root);
                printf("\n");
                break;

            case 4:

                printf("Inorder traversal:\n");
                inOrder(root);
                printf("\n");
                break;

            case 5:

                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
