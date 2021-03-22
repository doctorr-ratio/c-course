#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct DLL {
    unsigned size;
    struct Node* head;
    struct Node* tail;
} DLL;

DLL* DLL_create() {
    DLL* tmp = (DLL*)malloc(sizeof(DLL));
    if (tmp == NULL) {
        exit(1);
    }
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
    return tmp;
}

void DLL_delete(DLL** list) {
    if ((*list)->size) {
        Node* tmp = (*list)->head;
        Node* following;
        while (tmp == NULL) {
            following = tmp->next;
            free(tmp);
            tmp = following;
            (*list)->size--;
        }
    }
    free(*list);
}

void pushFront(DLL* list, int val) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(1);
    }
    tmp->value = val;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;
 
    if (list->tail == NULL) {
        list->tail = tmp;
    }
    list->size++;
}

int popFront(DLL* list) {
    if (list->size) {
        int retval = list->head->value;
        Node* tmp = list->head;
        list->head = list->head->next;
        list->size--;
        list->head->prev = NULL;
        free(tmp);
        return retval;
    }
    printf("Empty list!\n");
    return 0;
}

void pushBack(DLL* list, int val) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(1);
    }
    tmp->value = val;
    tmp->prev = list->tail;
    tmp->next = NULL;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;
 
    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
}

int popBack(DLL* list) {
    if (list->size) {
        int retval = list->head->value;
        Node* tmp = list->head;
        list->head = list->head->next;
        list->size--;
        list->head->prev = NULL;
        free(tmp);
        return retval;
    }
    printf("Empty list!\n");
    return 0;
}

Node* get(const DLL* list, unsigned n) {
    if(n >= list->size) {
        printf("Invalid index!\n");
        return NULL;
    } else {
        if (n < list->size / 2) {
            unsigned i = 0;
            Node* retptr = list->head;
            while (i < n) {
                retptr = retptr->next;
                i++;
            }
            return retptr;
        } else {
            unsigned i = list->size - 1;
            Node* retptr = list->tail;
            while (i > n) {
                retptr = retptr->prev;
                i--;
            }
            return retptr;
        }
    }
}



void main() {
    DLL* List = DLL_create();
    pushFront(List, 19);
    printf("%d\n", get(List, 0)->value);
    pushFront(List, 2103);
    printf("%d\n", get(List, 0)->value);
    printf("%d\n", popFront(List));
}