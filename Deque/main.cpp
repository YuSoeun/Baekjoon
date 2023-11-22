#include <iostream>
#include <cstring>
using namespace std;

#include "list.hpp"

int main()
{
    List * list = (List *)malloc(sizeof(List));
    char fuction_type[11];    // 함수의 종류
    int n;                    // 주어지는 명령의 수
    int x;                    // push할 숫자

    cin >> n;

    list->len = 0;

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
        } else {
            top(list);
        }
    }

    free(list);
    return 0;
}