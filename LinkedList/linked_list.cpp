/*
	linked-list.cpp: linked-list-related functions
*/

#include <iostream>
#include <cstring>
using namespace std;

#include "linked_list.hpp"

// #define DEBUG
#ifdef DEBUG
#define CHECK(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define CHECK(args...)
#endif

LinkedList * InitList()
{
    LinkedList * newlist = NULL;
    newlist = (LinkedList *)malloc(sizeof(LinkedList));

    newlist->head = NULL;
    newlist->size = 0;
    
    return newlist;
}

Node * InitNode()
{  
    Node * newnode = newnode;
    newnode = (Node *)malloc(sizeof(Node));
    
    newnode->data = NULL;
    newnode->next = NULL;

    return newnode;
}

void Destroy(LinkedList * list)
{
    while (list->size > 0) {
        Erase(list);
        CHECK("size - %d, ", list->size);
    }
    free(list);
}

void Traverse(LinkedList * list)
{
    Node * cur = list->head;
    int i = 0;

    cout << "List Elements: ";

    while (i < list->size) {
        cout << cur->data << ' ';

        CHECK("w - %lld\n", (long long)cur);

        cur = cur->next;
        i++;
    }
}

void Insert(LinkedList * list, char * str)
{
    Node * newnode = NULL;
    Node * cur = list->head;
    int i = 0;

    newnode = InitNode();
    
    newnode->data = (char *)malloc(sizeof(char) * strlen(str));
    strcpy(newnode->data, str);

    if (list->size == 0) {
        list->head = newnode;
    } else {
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = newnode;
    }
    CHECK("h - %lld\n", (long long)list->head);
    CHECK("%lld %lld\n", (long long)newnode, (long long)cur);

    list->size++;
}

void Search(LinkedList * list, char * str)
{
    Node * cur = list->head;

    while (cur->next != NULL) {
        if (strcmp(cur->data, str) == 0) {
            cout << str << " is searched\n";
            return;
        }
        cur = cur->next;
    }

    cout << "Can't search " <<str << "\n";
}

void Erase(LinkedList * list)
{
    Node * pre_tail = list->head;
    Node * tail = list->head;
    int i=0;

    CHECK("%d ", i);

    if (list->size == 0) {
        cout << "뭐함? - 몰라\n";
    } else if (list->size == 1) {
        free(tail->data);
        free(tail);
    } else {
        while (pre_tail->next->next != NULL) {
            pre_tail = pre_tail->next;
        }

        tail = pre_tail->next;

        CHECK("t - %lld %lld\n", (long long)pre_tail, (long long)tail);

        free(tail->data);
        pre_tail->next = NULL;
        free(tail);
    }

    list->size--;       // 그냥 위에 while문 안 썼으면 이것만 해도 될텐데,,,
}