/*
    문제
    두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 
*/

#include <stdio.h>

int main(){
    int A, B;

    scanf("%d %d", &A, &B);
    printf("%d\n", A+B);
    printf("%d\n", A-B);
    printf("%d\n", A/B);
    printf("%d\n", A%B);

    return 0;
}