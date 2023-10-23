#include <iostream>
using namespace std;

#include "queue.hpp"

void push(List * list, int num)
{
    if (list->len == 0) {
        list->array = (int *)malloc(sizeof(int));
    } else {
        list->array = (int *)realloc(list->array, sizeof(int) * (list->len + 1));
    }

    list->tail++;
    list->array[list->tail] = num;
    list->len++;
}

void pop(List * list)
{
    if (list->len == 0) {
        cout << -1 << '\n';
    } else {
        cout << list->array[list->head] << '\n';
        list->head++;
        list->len--;
    }    
}

void size(List * list)
{
   cout << list->len << '\n';
}

void empty(List * list)
{
    if (list->len == 0) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
}

void front(List * list)
{
    if (list->len == 0) {
        cout << -1 << '\n';
    } else {
        cout << list->array[list->head] << '\n';
    }
}

void back(List * list)
{
    if (list->len == 0) {
        cout << -1 << '\n';
    } else {
        cout << list->array[list->tail] << '\n';
    }
}