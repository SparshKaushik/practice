#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int id;
    char name[20];
    struct employee *next;
    struct employee *prev;
};

struct employee *head = NULL;
struct employee *tail = NULL;

void insert(int id, char name[]) {
    struct employee *new = (struct employee *)malloc(sizeof(struct employee));
    new->id = id;
    strcpy(new->name, name);
    new->next = NULL;
    new->prev = NULL;

    if (head == NULL) {
        head = new;
        tail = new;
    } else {
        head->prev = new;
        new->next = head;
        head = new;
    }
}

void delete() {
    if (head == NULL) {
        printf("List is empty");
    } else {
        if (head == tail) {
            free(head);
            head = NULL;
            tail = NULL;
        } else {
            struct employee *temp = head;
            head = head->next;
            head->prev = NULL;
            free(temp);
        }
    }
}

void display() {
    struct employee *temp = head;
    while (temp != NULL) {
        printf("Employee #%d\n%s", temp->id, temp->name);
        temp = temp->next;
        printf("\n");
    }
}

int main(void) {
    int op;
    while (op != 4) {
        printf("\n1. Insert \n2. Delete \n3. Display \n4. Exit \nSelect an option: ");
        scanf("%d", &op);
        switch (op) {
        case 1:
            printf("Enter Id: ");
            int id;
            scanf("%d", &id);
            printf("Enter Name: ");
            char name[20];
            scanf("%s", name);
            insert(id, name);
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...");
            exit(0);
        default:
            printf("Invalid option");
        }
    }

    return 0;
}