#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct college {
    int id;
    char name[20];
    struct college *next;
    struct college *prev;
};

struct college *head = NULL;
struct college *tail = NULL;

void insert(int id, char name[]) {
    struct college *new = (struct college *)malloc(sizeof(struct college));
    new->id = id;
    strcpy(new->name, name);
    new->next = NULL;
    new->prev = NULL;

    if (head == NULL) {
        head = new;
        tail = new;
    }
    else {
        head->prev = new;
        new->next = head;
        head = new;
    }
}

void delete() {
    if (head == NULL) {
        printf("List is empty");
    }
    else {
        if (head == tail) {
            free(head);
            head = NULL;
            tail = NULL;
        }
        else {
            struct college *temp = head;
            head = head->next;
            head->prev = NULL;
            free(temp);
        }
    }
}

void display() {
    struct college *temp = head;
    while (temp != NULL) {
        printf("College #%d \n" , temp->id);
        printf("%s" , temp->name);
        temp = temp->next;
        printf("\n");
    }
}

int main(void) {
    int op;
    while (op != 4) {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d" , &op);
        switch (op) {
            case 1: {
                int id;
                char name[20];
                printf("Enter the id: ");
                scanf("%d" , &id);
                printf("Enter the name: ");
                scanf("%s" , name);
                insert(id, name);
                break;
            }
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice");
        }
    }
}