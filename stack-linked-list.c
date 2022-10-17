#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = top;
    top = new_node;
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty");
    } else {
        struct node *temp = top;
        top = top->next;
        free(temp);
    }
}

void display() {
    struct node *temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    printf("Stack using linked list");
    int choice, data;
    while (choice != 4) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Thank you for using the Program\nExiting...");
                break;
            default:
                printf("Invalid choice");
                break;
        }
    }
    return 0;
}