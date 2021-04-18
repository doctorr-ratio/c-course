#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void rotateLeft(Node *x) {
    if (x != NULL && x->right != NULL) {
        Node *y = x->right;
        Node *tmp_xr = x->right, *tmp_xl = x->left, *tmp_yr = y->right, *tmp_yl = y->left;
        int tmp_xd = x->data, tmp_yd = y->data;
        x->left = tmp_xr;
        x->right = tmp_yr;
        x->data = tmp_yd;
        y->left = tmp_xl;
        y->right = tmp_yl;
        y->data = tmp_xd;
    }   
}

void rotateRight(Node *x) {
    if (x != NULL && x->left != NULL) {
        Node *y = x->left;
        Node *tmp_xr = x->right, *tmp_xl = x->left, *tmp_yr = y->right, *tmp_yl = y->left;
        int tmp_xd = x->data, tmp_yd = y->data;
        x->right = tmp_xl;
        x->left = tmp_yl;
        x->data = tmp_yd;
        y->right = tmp_xr;
        y->left = tmp_yr;
        y->data = tmp_xd;
    }   
}

void inOrderTravers(Node* root, Node** newVine) {
    if (root) {
        inOrderTravers(root->right, newVine);
        insert(newVine, root->data);
        inOrderTravers(root->left, newVine);
    }
}

void Tree2lVine(Node** root) {
    Node* tmpTree = NULL;
    inOrderTravers((*root), &tmpTree);
    deleteNodeByPtr(root);
    (*root) = tmpTree;
}

int lLength (Node* root) {
    int res = 0;
    if (root != NULL) {
        Node* tmp = root;
        while (tmp != NULL) {
            tmp = tmp->left;
            res++;
        }
    }
    return res;
}

int rLength (Node* root) {
    int res = 0;
    if (root != NULL) {
        Node* tmp = root;
        while (tmp != NULL) {
            tmp = tmp->right;
            res++;
        }
    }
    return res;
}

void turn (Node* root, int n) { // n > 0 - right, n < 0- left
    if (n < 0) {
        for (int i = 0; i < -n; i++) {
            rotateLeft(root);
        }
    } else if (n > 0) {
        for (int i = 0; i < n; i++) {
            rotateRight(root);
        }
    }
}

void balance_L(Node*);
void balance_R(Node*);

void balance_L(Node *root) {
    if (root != NULL && root->left != NULL) {
        int L = lLength(root);
        turn(root, L / 2);
        balance_L(root->left);
        balance_R(root->right);
    }
}

void balance_R(Node *root) {
    if (root != NULL && root->right != NULL) {
        int L = rLength(root);
        turn(root, -L / 2);
        balance_L(root->left);
        balance_R(root->right);
    }
}

void main() {
    Node *root = NULL;
    insert(&root, 1);
    insert(&root, 2);
    insert(&root, 8);
    insert(&root, 9);
    insert(&root, 7);
    insert(&root, 3);
    insert(&root, 5);
    insert(&root, 4);
    insert(&root, 6);
    printf("Original tree:\n");
    printTree(root, "root", 0);
    Tree2lVine(&root);
    printf("Left vine tree:\n");
    printTree(root, "root", 0);
    balance_L(root);
    printf("Balanced tree:\n");
    printTree(root, "root", 0);
}