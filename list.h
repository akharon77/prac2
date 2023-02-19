#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdint.h>

struct Node
{
    Node *prev;
    void *val;
};

struct List
{
    Node   *tail;

    size_t  size;
    size_t  elemSize;
};

void ListCtor    (List *lst, size_t elemSize);
void ListDtor    (List *lst);
void NodeCtor    (Node *node, Node *prev, void *elem, size_t elemSize);
void NodeDtor    (Node *node);
bool ListPush    (List *lst, void *elem);
bool ListBack    (List *lst, void *elem);
bool ListPop     (List *lst);

#endif
