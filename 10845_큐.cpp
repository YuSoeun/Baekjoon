/*
    문제
    정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

    명령은 총 여섯 가지이다.

    push X: 정수 X를 큐에 넣는 연산이다.
    pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    size: 큐에 들어있는 정수의 개수를 출력한다.
    empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
    front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    입력
    첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

    출력
    출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.
*/

#include <iostream>
#include <cstring>
using namespace std;

typedef struct
{
    int array[10000];
    int len;

    int head;
    int tail;
} List;

void push(List * list, int num);  // 정수 X 스택에 넣기
void pop(List * list);            // 스택 가장 앞에 있는 정수 빼고 출력, 없으면 -1
void size(List * list);           // 정수 개수 출력
void empty(List * list);          // 스택이 비어있으면 1, 아니면 0을 출력
void front(List * list);          // 스택 가장 앞에 있는 정수 출력, 없으면 -1
void back(List * list);           // 스택 가장 뒤에 있는 정수 출력, 없으면 -1

int main()
{
    List * list = (List *)malloc(sizeof(List));
    char fuction_type[11];    // 함수의 종류
    int n;                    // 주어지는 명령의 수
    int x;                    // push할 숫자

    cin >> n;

    list->len = 0;
    list->head = 0;
    list->tail = -1;

    for (int i = 0; i < n; i++) {
        cin >> fuction_type;

        if (strcmp("push", fuction_type) == 0) {
            cin >> x;
            push(list, x);
        } else if (strcmp("pop", fuction_type) == 0) {
            pop(list);
        } else if (strcmp("size", fuction_type) == 0) {
            size(list);
        } else if (strcmp("empty", fuction_type) == 0) {
            empty(list);
        } else if (strcmp("front", fuction_type) == 0) {
            front(list);
        } else {
            back(list);
        }
    }

    free(list);
    return 0;
}

void push(List * list, int num)
{
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