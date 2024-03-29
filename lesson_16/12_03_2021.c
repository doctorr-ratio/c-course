#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* head;
} Node;

int push(Node **Head, int val) {
    Node *tmp = (Node*)malloc(sizeof(Node));
    if (tmp == NULL) {
        return 1;
    }
    tmp->value = val;
    tmp->head = (*Head);
    (*Head) = tmp;
    return 0;
}

int pop(Node **Head) {
    int iTmp = (*Head)->value;
    Node *NTmp = (*Head);
    (*Head) = (*Head)->head;
    free(NTmp);
    return iTmp;
}

void deleteList(Node **Head) {
    while ((*Head)->head != NULL) {
        pop(Head);
    }
    free(*Head);
}

void insert(Node **Head, unsigned n, int val) {
    if (n == 0) {
        push(Head, val);
    }
    else {
        int counter = 0;
        Node *tmp = *Head;
        Node *new = (Node*)malloc(sizeof(Node));
        if (new == NULL) {
            exit(1);
        }
        new->value = val;
        while (counter < n-1 && tmp) {
            tmp = tmp->head;
            counter++;
        }
        new->head = tmp->head;
        tmp->head = new;
    }
}

int delete(Node **Head, unsigned n) {


    if (n == 0) {
        return pop(Head);
    }
    else {
        int counter = 0, iTmp;
        Node *tmp = *Head;
        Node *tmpDel;
        if (tmp == NULL) {
            exit(1);
        }
        while (counter < n-1 && tmp) {
            tmp = tmp->head;
            counter++;
        }
        tmpDel = tmp->head;
        iTmp = tmp->head->value;
        tmp->head = tmp->head->head;
        free(tmpDel);
        return iTmp;
    }
}

int get(Node **Head, unsigned n) {
    Node *tmp = (*Head);
    unsigned i = 0;
    while (tmp->head != NULL && i < n) {
        tmp = tmp->head;
        i++;
    }
    return tmp->value;
}

void printList (Node *Head) {
    while (Head != NULL) {
        printf("lst: %d\n", Head->value);
        Head = Head->head;
    }
}


void main() {
    Node *pHead = (Node*)malloc(sizeof(Node));
    pHead->value = 42;
    printf("push status: %d\n", push(&pHead, 12));
    printf("push status: %d\n", push(&pHead, 13));
    printf("push status: %d\n", push(&pHead, 14));
    printf("push status: %d\n", push(&pHead, 15));
    printList(pHead);
    insert(&pHead, 2, 120);
    printf("after insert\n");
    printList(pHead);
    printf("del: %d\n", delete(&pHead, 2));
    printf("after delete\n");
    printList(pHead);
    printf("get [2]: %d\n", get(&pHead, 2));
    deleteList(&pHead);
}
