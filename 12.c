#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char type[100];
  char company[100];
  int year;
  struct Node* left;
  struct Node* right;
} Node;

typedef struct BinarySearchTree {
  Node* root;
} BinarySearchTree;

Node* create_node(char* type, char* company, int year) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  strcpy(new_node->type, type);
  strcpy(new_node->company, company);
  new_node->year = year;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void insert(BinarySearchTree* tree, char* type, char* company, int year) {
  Node* new_node = create_node(type, company, year);
  if (tree->root == NULL) {
    tree->root = new_node;
    return;
  }
  Node* current_node = tree->root;
  while (1) {
    if (year < current_node->year) {
      if (current_node->left == NULL) {
        current_node->left = new_node;
        break;
      }
      current_node = current_node->left;
    } else {
      if (current_node->right == NULL) {
        current_node->right = new_node;
        break;
      }
      current_node = current_node->right;
    }
  }
}

Node* find_min(Node* node) {
  while (node->left != NULL) {
    node = node->left;
  }
  return node;
}

void delete(BinarySearchTree* tree, int year) {
  if (tree->root == NULL) {
    return;
  }
  if (tree->root->year == year) {
    if (tree->root->left == NULL && tree->root->right == NULL) {
      tree->root = NULL;
    } else if (tree->root->left != NULL && tree->root->right == NULL) {
      tree->root = tree->root->left;
    } else if (tree->root->left == NULL && tree->root->right != NULL) {
      tree->root = tree->root->right;
    } else {
      Node* min_node = find_min(tree->root->right);
      strcpy(tree->root->type, min_node->type);
      strcpy(tree->root->company, min_node->company);
      tree->root->year = min_node->year;
      delete(tree, min_node->year);
    }
    return;
  }
  Node* parent = NULL;
  Node* current_node = tree->root;
  while (current_node != NULL && current_node->year != year) {
    parent = current_node;
    if (year < current_node->year) {
        current_node = current_node->left;
        } else {
        current_node = current_node->right;
        }
    }
    if (current_node == NULL) {
        return;
    }
    if (current_node->left == NULL && current_node->right == NULL) {
        if (parent->left == current_node) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    } else if (current_node->left != NULL && current_node->right == NULL) {
        if (parent->left == current_node) {
            parent->left = current_node->left;
        } else {
            parent->right = current_node->left;
        }
    } else if (current_node->left == NULL && current_node->right != NULL) {
        if (parent->left == current_node) {
            parent->left = current_node->right;
        } else {
            parent->right = current_node->right;
        }
    } else {
        Node* min_node = find_min(current_node->right);
        strcpy(current_node->type, min_node->type);
        strcpy(current_node->company, min_node->company);
        current_node->year = min_node->year;
        delete(tree, min_node->year);
    }
}

void print_inorder(Node* node) {
  if (node == NULL) {
    return;
  }
  print_inorder(node->left);
  printf("%s %s %d ", node->type, node->company, node->year);
    print_inorder(node->right);
}

void print_preorder(Node* node) {
  if (node == NULL) {
    return;
  }
  printf("%s %s %d ", node->type, node->company, node->year);
  print_preorder(node->left);
  print_preorder(node->right);
}

void print_postorder(Node* node) {
  if (node == NULL) {
    return;
  }
  print_postorder(node->left);
  print_postorder(node->right);
  printf("%s %s %d ", node->type, node->company, node->year);
}

int main() {
  BinarySearchTree* tree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
  tree->root = NULL;
  insert(tree, "car", "BMW", 2010);
  insert(tree, "car", "Audi", 2015);
  insert(tree, "car", "Mercedes", 2012);
  insert(tree, "car", "Toyota", 2017);
  insert(tree, "car", "Honda", 2014);
  insert(tree, "car", "Hyundai", 2013);
  insert(tree, "car", "Kia", 2016);
  insert(tree, "car", "Suzuki", 2011);
  insert(tree, "car", "Mazda", 2018);
  insert(tree, "car", "Lexus", 2019);
  print_inorder(tree->root);
  printf("");
    print_preorder(tree->root);
    printf("");
    print_postorder(tree->root);
    printf("");
    delete(tree, 2010);
    delete(tree, 2015);
    delete(tree, 2012);
    delete(tree, 2017);
    delete(tree, 2014);
    delete(tree, 2013);
    delete(tree, 2016);
    delete(tree, 2011);
    delete(tree, 2018);
    delete(tree, 2019);
    print_inorder(tree->root);
    printf("");
    print_preorder(tree->root);
    printf("");
    print_postorder(tree->root);
    printf("");
    return 0;
}
