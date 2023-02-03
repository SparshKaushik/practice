#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int roll;
    char name[20];
    struct student *next;
};

void insert(struct student **q, int roll, char name[], int pos) {
    struct student *temp, *r;
    int i;
    temp = (struct student *)malloc(sizeof(struct student));
    temp->roll = roll;
    strcpy(temp->name, name);
    if (pos == 1) {
        temp->next = *q;
        *q = temp;
    } else {
        r = *q;
        for (i = 1; i < pos - 1; i++)
            r = r->next;
        temp->next = r->next;
        r->next = temp;
    }
}

void display(struct student *q){
    while (q != NULL) {
        printf("%d. %s\n", q->roll, q->name);
        q = q->next;
    }
}

int main() {
    struct student *p;
    int pos, roll;
    char name[20];
    char ch = 'y';
    p = NULL;
    while (ch == 'y') {
        printf("Enter the roll number: ");
        scanf("%d", &roll);
        printf("Enter the name: ");
        scanf("%s", name);
        printf("Enter the position where the node is to be inserted: ");
        scanf("%d", &pos);
        insert(&p, roll, name, pos);
        printf("Do you want to enter more data (y/n): ");
        scanf(" %c", &ch);
    }
    printf("The list : \n");
    display(p);
    return 0;
}