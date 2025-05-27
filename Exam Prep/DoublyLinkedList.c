#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void traverse(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void search(Node* head, int key) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == key) {
            printf("Found %d at position %d\n", key, pos);
            return;
        }
        head = head->next;
        pos++;
    }
    printf("%d not found.\n", key);
}

void insertFront(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;

    if (*head != NULL)
        (*head)->prev = newNode;

    *head = newNode;
    printf("Inserted %d at front.\n", data);
}

void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d at end.\n", data);
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted %d at end.\n", data);
}

void deleteFront(Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;
    printf("Deleted %d from front.\n", temp->data);
    *head = temp->next;

    if (*head != NULL)
        (*head)->prev = NULL;

    free(temp);
}


void deleteEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;

    if (temp->next == NULL) {
        printf("Deleted %d from end.\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Deleted %d from end.\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}

int main() {
    Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Traverse\n2. Search\n3. Insert Front\n4. Insert End\n");
        printf("5. Delete Front\n6. Delete End\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverse(head);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(head, value);
                break;
            case 3:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(&head, value);
                break;
            case 4:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;
            case 5:
                deleteFront(&head);
                break;
            case 6:
                deleteEnd(&head);
                break;
            case 0:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
