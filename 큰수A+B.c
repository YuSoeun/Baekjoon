#include <stdio.h>
#include <string.h>

int main(){
    // 스트링으로 받을까 아님 인트 끊어서 받을까!
    char a[100000]={0}, b[100000]={0}, c[100000]={0};
    char temp, increase = 0;
    int size;
    int lenA, lenB;

    // 입력
    printf("두 수를 입력하시오 ");
    scanf(" %s", a);
    scanf(" %s", b);

    lenA = strlen(a);
    lenB = strlen(b);

    if(lenA > lenB)  size = lenA;
    else  size = lenB;

    for(int i=1; i<size+1; i++){
        if(lenA > i-1 && lenB > i-1)  temp = a[lenA-i] + (b[lenB-i] - '0') + increase;
        else if(lenA <= i-1)  temp = b[lenB-i] + increase;
        else if(lenB <= i-1)  temp = a[lenA-i] + increase;

        if(temp<':')  increase = 0;
        else{
            temp = temp - 10;
            increase = 1;
        }
        
        c[size-i] = temp;
        // printf("%c %c %c\n", a[lenA-i], b[lenB-i], temp);
    }

    // 출력
    if(increase == 1)   printf("1");
    printf("%s\n", c);

    return 0;
}