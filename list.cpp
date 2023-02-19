#include "list.h"

#include <time.h>
#include <stdlib.h>
#include <string.h>

void ListCtor(List *lst, size_t elemSize)
{
    lst->tail       = (Node*) calloc(1, sizeof(Node));
    lst->tail->prev = NULL;
    lst->tail->val  = calloc(1, elemSize);

    lst->size       = 0;
    lst->elemSize   = elemSize;
}

void ListDtor(List *lst)
{
    Node *node = lst->tail;

    while (node != NULL)
    {
        Node *prev = node->prev;
        NodeDtor(node);
        free(node);
        node = prev;
    }
}

void NodeCtor(Node *node, Node *prev, void *elem, size_t elemSize)
{
    node->prev = prev;
    node->val  = calloc(1, elemSize);
    memcpy(node->val, elem, elemSize);
}

void NodeDtor(Node *node)
{
    free(node->val);
}

bool ListPush(List *lst, void *elem)
{
    Node *node = (Node*) calloc(1, sizeof(Node));
    if (node == NULL)
        return false;

    NodeCtor(node, lst->tail, elem, lst->elemSize);

    ++lst->size;
    lst->tail = node;

    return true;
}

bool ListBack(List *lst, void *elem)
{
    if (lst->size == 0)
        return false;

    memcpy(elem, lst->tail->val, lst->elemSize);
    return true;
}

bool ListPop(List *lst)
{
    if (lst->size == 0)
        return false;

    --lst->size;

    Node *prev = lst->tail->prev;
    NodeDtor(lst->tail);
    lst->tail = prev;

    return true;
}

