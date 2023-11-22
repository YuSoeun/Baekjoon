#include <iostream>
using namespace std;

#include "stack.hpp"

void push(Stack * stack, int num)
{
    if (stack->len == 0) {
        stack->array = (int *)malloc(sizeof(int));
    } else {
        stack->array = (int *)realloc(stack->array, sizeof(int) * (stack->len + 1));
    }

    stack->array[stack->len] = num;
    stack->len++;
}

void pop(Stack * stack)
{
    if (stack->len == 0) {
        cout << -1 << '\n';
    } else {
        cout << stack->array[stack->len-1] << '\n';
        stack->len--;
    }    
}

void size(Stack * stack)
{
   cout << stack->len << '\n';
}

void empty(Stack * stack)
{
    if (stack->len == 0) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
}

void top(Stack * stack)
{
    if (stack->len == 0) {
        cout << -1 << '\n';
    } else {
        cout << stack->array[stack->len-1] << '\n';
    }
}