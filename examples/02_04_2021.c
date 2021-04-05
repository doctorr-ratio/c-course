#include <stdio.h>
#include <stdlib.h>

#define CMP_EQ(a, b) ((a) == (b))
#define CMP_LT(a, b) ((a) < (b))
#define CMP_GT(a, b) ((a) > (b))


typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;



Node* getFreeNode(int value, Node *parent) {
    Node* tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) exit(1);
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

void insert(Node **head, int value) {
    Node *tmp = NULL;
    Node *ins = NULL;
    if (*head == NULL) {
        *head = getFreeNode(value, NULL);
        return;
    }
     
    tmp = *head;
    while (tmp) {
        if (CMP_GT(value, tmp->data)) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = getFreeNode(value, tmp);
                return;
            }
        } else if (CMP_LT(value, tmp->data)) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = getFreeNode(value, tmp);
                return;
            }
        } else if (CMP_EQ(value, tmp->data)){
            return;
        } else {
            exit(2);
        }
    }
}

Node* getMinNode(Node *root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

Node* getMaxNode(Node *root) {
    while (root->right) {
        root = root->right;
    }
    return root;
}

Node* getNodeByValue(Node *root, int value) {
    while (root) {
        if (CMP_GT(root->data, value)) {
            root = root->left;
            continue;
        } else if (CMP_LT(root->data, value)) {
            root = root->right;
            continue;
        } else {
            return root;
        }
    }
    return NULL;
}

void deleteNodeByPtr(Node **ptr) {
    if (*ptr == NULL) return;
    Node *tmp = *ptr;
    if ((*ptr)->parent) {
        if ((*ptr)->parent->data > (*ptr)->data) {
            (*ptr)->parent->left = NULL;
        } else{
            (*ptr)->parent->right = NULL;
        }
    }    
    deleteNodeByPtr(&(tmp->left));
    deleteNodeByPtr(&(tmp->right));
    free(*ptr);
}

void deleteNodeByValue(Node* root, int value) {
    Node *tmp = getNodeByValue(root, value);
    deleteNodeByPtr(&tmp);
}

void printTree(Node *root, const char *dir, int level) {
    if (root) {
        printf("lvl %d %s = %d\n", level, dir, root->data);
        printTree(root->left, "left", level+1);
        printTree(root->right, "right", level+1);
    }
}

void main() {
    Node *root = NULL;
    insert(&root, 10);
    insert(&root, 12);
    insert(&root, 8);
    insert(&root, 9);
    insert(&root, 7);
    insert(&root, 7);

    insert(&root, 3);
    insert(&root, 4);
    printTree(root, "root", 0);
    printf("max = %d\n", getMaxNode(root)->data);
    printf("min = %d\n", getMinNode(root)->data);
    deleteNodeByValue(root, 10);
    printf("max = %d\n", getMaxNode(root)->data);
    printf("min = %d\n", getMinNode(root)->data);
}