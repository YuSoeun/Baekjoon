#include <iostream>
using namespace std;

#include "deque.hpp"

void push(List * list, int num)
{
    if (list->len == 0) {
        list->array = (int *)malloc(sizeof(int));
    } else {
        list->array = (int *)realloc(list->array, sizeof(int) * (list->len + 1));
    }

    list->array[list->len] = num;
    list->len++;
}

void pop(List * list)
{
    if (list->len == 0) {
        cout << -1 << '\n';
    } else {
        cout << list->array[list->len-1] << '\n';
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

void top(List * list)
{
    if (list->len == 0) {
        cout << -1 << '\n';
    } else {
        cout << list->array[list->len-1] << '\n';
    }
}