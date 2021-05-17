/*
문제
정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 다섯 가지이다.

push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 
주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.
*/

#include <iostream>
#include <cstring>
using namespace std;

typedef struct
{
    int * array;
    int len;
} Stack;

void push(Stack * stack, int num);  // 정수 X 스택에 넣기
void pop(Stack * stack);            // 스택 가장 위에 있는 정수 빼고 출력, 없으면 -1
void size(Stack * stack);           // 정수 개수 출력
void empty(Stack * stack);          // 스택이 비어있으면 1, 아니면 0을 출력
void top(Stack * stack);            // 스택 가장 위에 있는 정수 출력, 없으면 -1

int main()
{
    Stack * stack = (Stack *)malloc(sizeof(Stack));
    char fuction_type[11];    // 함수의 종류
    int n;                    // 주어지는 명령의 수
    int x;                    // push할 숫자

    cin >> n;

    stack->len = 0;

    for (int i = 0; i < n; i++) {
        cin >> fuction_type;

        if (strcmp("push", fuction_type) == 0) {
            cin >> x;
            push(stack, x);
        } else if (strcmp("pop", fuction_type) == 0) {
            pop(stack);
        } else if (strcmp("size", fuction_type) == 0) {
            size(stack);
        } else if (strcmp("empty", fuction_type) == 0) {
            empty(stack);
        } else {
            top(stack);
        }
    }

    free(list);
    return 0;
}

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