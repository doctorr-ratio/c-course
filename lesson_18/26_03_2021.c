#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct DLL {
    unsigned size;
    struct Node* current;
} DLL;

DLL* DLL_create() {
    DLL* tmp = (DLL*)malloc(sizeof(DLL));
    if (tmp == NULL) {
        exit(1);
    }
    tmp->size = 0;
    tmp->current = NULL;
    return tmp;
}

void DLL_delete(DLL** list) {
    if ((*list)->size) {
        Node* tmp = (*list)->current;
        Node* following;
        tmp->prev->next = NULL;
        while (tmp == NULL) {
            following = tmp->next;
            free(tmp);
            tmp = following;
            (*list)->size--;
        }
    }
    free(*list);
}

void push(DLL* list, int val) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(1);
    }
    tmp->value = val;
    tmp->next = tmp->prev = NULL;
    if (list->current) {
        if (list->size == 1) {
            tmp->prev = tmp->next = list->current;
            list->current->next = list->current->prev = tmp;
        } else {
            Node *previous = list->current->prev;
            previous->next = tmp;
            tmp->prev = previous;
            tmp->next = list->current;
            list->current = tmp;
        }
    } else {
        list->current = tmp;
    }
    list->size++;
}

int pop(DLL* list) {
    if (list->size == 1) {
        int retval = list->current->value;
        free(list->current);
        return retval;
    } else if (list->size == 2) {
        int retval = list->current->value;
        list->current = list->current->next;
        free(list->current->next);
        return retval;
    } else if (list->size > 2) {
        Node *first = list->current->next;
        Node *second = list->current->prev;
        int retval = list->current->value;
        free(list->current);
        list->current = first;
        first->prev = second;
        second->next = first;
        list->size--;
        return retval;
    } else {
        printf("Empty list!\n");
        return 0;
    }
}

// Node* get(const DLL* list, unsigned n) {
//     if(n >= list->size) {
//         printf("Invalid index!\n");
//         return NULL;
//     } else {
//         if (n < list->size / 2) {
//             unsigned i = 0;
//             Node* retptr = list->head;
//             while (i < n) {
//                 retptr = retptr->next;
//                 i++;
//             }
//             return retptr;
//         } else {
//             unsigned i = list->size - 1;
//             Node* retptr = list->tail;
//             while (i > n) {
//                 retptr = retptr->prev;
//                 i--;
//             }
//             return retptr;
//         }
//     }
// }

// void insert(DLL* list, unsigned n, int val) {
//     if(n > list->size) {
//         printf("Invalid index!\n");
//         return;
//     } else if (n == list->size) {
//         pushBack(list, val);
//         return;
//     } else if (n == 0) {
//         pushFront(list, val);
//         return;
//     } else {
//         Node *tmp = (Node*) malloc(sizeof(Node));
//         if (tmp == NULL) {
//             exit(1);
//         }
//         Node *prev, *next;
//         prev = get(list, n - 1);
//         next = get(list, n);
//         tmp->value = val;
//         tmp->next = next;
//         tmp->prev = prev;
//         prev->next = tmp;
//         next->prev = tmp;
//         list->size++;
//         return;
//     }
// }

// int delete(DLL* list, unsigned n) {
//     if(n >= list->size) {
//         printf("Invalid index!\n");
//         return 0;
//     } else if (n == list->size -1) {
//         int out;
//         out = popBack(list);
//         return out;
//     } else if (n == 0) {
//         int out;
//         out = popFront(list);
//         return out;
//     } else {
//         Node* tmp = get(list, n);
//         Node* prev = get(list, n-1);
//         Node* next = get(list, n+1);
//         int out = tmp->value;
//         free(tmp);
//         prev->next = next;
//         next->prev = prev;
//         list->size--;
//         return out;
//     }
// }


void main() {
    DLL* List = DLL_create();
    push(List, 4);
    push(List, 8);
    push(List, 16);
    push(List, 32);
    printf("%d\n", pop(List));
    DLL_delete(&List);
}