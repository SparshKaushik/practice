#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct automobile {
    char name[20];
    char type[20];
    char company[20];
    int year;
    struct automobile *left;
    struct automobile *right;
};

struct automobile *root = NULL;

void find(char name[], struct automobile **parent, struct automobile **loc) {
    struct automobile *ptr, *ptrsave;
    if (root == NULL) {
        *loc = NULL;
        *parent = NULL;
        return;
    }
    if (strcmp(name, root->name) == 0) {
        *loc = root;
        *parent = NULL;
        return;
    }
    if (strcmp(name, root->name) < 0)
        ptr = root->left;
    else
        ptr = root->right;
    ptrsave = root;
    while (ptr != NULL) {
        if (strcmp(name, ptr->name) == 0) {
            *loc = ptr;
            *parent = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (strcmp(name, ptr->name) < 0)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    *loc = NULL;
    *parent = ptrsave;
}

void insert(char name[], char type[], char company[], int year) {
    struct automobile *tmp, *parent, *loc;
    find(name, &parent, &loc);
    if (loc != NULL) {
        printf("Duplicate key");
        return;
    }
    tmp = (struct automobile *)malloc(sizeof(struct automobile));
    strcpy(tmp->name, name);
    strcpy(tmp->type, type);
    strcpy(tmp->company, company);
    tmp->year = year;
    tmp->left = NULL;
    tmp->right = NULL;
    if (parent == NULL)
        root = tmp;
    else {
        if (strcmp(name, parent->name) < 0)
            parent->left = tmp;
        else
            parent->right = tmp;
    }
}

void preorder(struct automobile *ptr) {
    if (root == NULL) {
        printf("Tree is empty");
        return;
    }
    if (ptr != NULL) {
        printf("%s (%s) of %s from %d\n", ptr->name, ptr->type, ptr->company, ptr->year);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void inorder(struct automobile *ptr) {
    if (root == NULL) {
        printf("Tree is empty");
        return;
    }
    if (ptr != NULL) {
        inorder(ptr->left);
        printf("%s (%s) of %s from %d\n", ptr->name, ptr->type, ptr->company, ptr->year);
        inorder(ptr->right);
    }
}

void postorder(struct automobile *ptr) {
    if (root == NULL) {
        printf("Tree is empty");
        return;
    }
    if (ptr != NULL) {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%s (%s) of %s from %d\n", ptr->name, ptr->type, ptr->company, ptr->year);
    }
}

void delete(char name[]) {
    struct automobile *parent, *loc;
    if (root == NULL) {
        printf("Tree is empty");
        return;
    }
    find(name, &parent, &loc);
    if (loc == NULL) {
        printf("Key not present");
        return;
    }
    if (loc->left != NULL && loc->right != NULL) {
        struct automobile *ptr, *ptrsave, *suc, *parsuc;
        ptrsave = loc;
        ptr = loc->right;
        while (ptr->left != NULL) {
            ptrsave = ptr;
            ptr = ptr->left;
        }
        suc = ptr;
        parsuc = ptrsave;
        if (suc->left == NULL && suc->right == NULL) {
            if (parsuc->left == suc)
                parsuc->left = NULL;
            else
                parsuc->right = NULL;
            suc->left = loc->left;
            suc->right = loc->right;
            if (parent->left == loc)
                parent->left = suc;
            else
                parent->right = suc;
            free(loc);
            return;
        }
        else {
            if (parsuc->left == suc)
                parsuc->left = suc->right;
            else
                parsuc->right = suc->right;
            suc->left = loc->left;
            suc->right = loc->right;
            if (parent->left == loc)
                parent->left = suc;
            else
                parent->right = suc;
            free(loc);
            return;
        }
    }
    if (loc->left == NULL && loc->right == NULL) {
        if (parent->left == loc)
            parent->left = NULL;
        else
            parent->right = NULL;
        free(loc);
        return;
    }
    if (loc->left != NULL && loc->right == NULL) {
        if (parent->left == loc)
            parent->left = loc->left;
        else
            parent->right = loc->left;
        free(loc);
        return;
    }
    if (loc->left == NULL && loc->right != NULL) {
        if (parent->left == loc)
            parent->left = loc->right;
        else
            parent->right = loc->right;
        free(loc);
        return;
    }
}

int main() {
    int choice, year;
    char name[20], type[20], company[20];
    insert("Audi", "Sedan", "Audi", 2015);
    insert("BMW", "Sedan", "BMW", 2016);
    insert("Mercedes", "Sedan", "Mercedes", 2017);
    insert("Ford", "SUV", "Ford", 2018);
    insert("Honda", "SUV", "Honda", 2019);
    insert("Toyota", "SUV", "Toyota", 2020);
    while (1) {
        printf("1.Insert\n2.Delete\n3.Preorder\n4.Inorder\n5.Postorder\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter type: ");
            scanf("%s", type);
            printf("Enter company: ");
            scanf("%s", company);
            printf("Enter year: ");
            scanf("%d", &year);
            insert(name, type, company, year);
            break;
        case 2:
            printf("Enter name: ");
            scanf("%s", name);
            delete(name);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            inorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
    return 0;
}