#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[20];
    struct student *next;
    struct student *prev;
};

struct student *head = NULL;
struct student *tail = NULL;

void insert(int id, char name[]) {
    struct student *new = (struct student *)malloc(sizeof(struct student));
    new->id = id;
    strcpy(new->name, name);
    new->next = NULL;
    new->prev = NULL;

    if (head == NULL) {
        head = new;
        tail = new;
    } else {
        head->prev = new;
        tail->next = new;
        new->prev = tail;
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
            struct student *temp = head;
            tail->prev->next = head;
            head->prev = tail->prev;
            free(temp);
        }
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty");
    } else {
        struct student *temp = head;
        while (temp != head) {
            printf("Roll Number #%d\n%s", temp->id, temp->name);
            temp = temp->next;
        }
    }
}

int main(){
    int op;
    
    while (op != 4) {
        printf("1. Insert \n2. Delete \n3. Display \n4. Exit \nSelect an option: ");
        scanf("%d", &op);
        if (op == 1) {
            int id;
            char name[20];
            printf("Enter roll number: ");
            scanf("%d", &id);
            printf("Enter name: ");
            scanf("%s", name);
            insert(id, name);
        } else if (op == 2) {
            delete();
        } else if (op == 3) {
            display();
        } else {
            printf("Invalid option");
        }
    }
}