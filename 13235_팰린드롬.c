/*
    문제
    팰린드롬은 앞에서부터 읽을 때와 뒤에서부터 읽을 때가 똑같은 단어를 의미한다. 예를 들어, eve, eevee는 팰린드롬이고, 
    eeve는 팰린드롬이 아니다. 단어가 주어졌을 때, 팰린드롬인지 아닌지 판단해보자.

    입력
    길이가 20보다 작거나 같은 단어가 주어진다. 단어는 알파벳 소문자로 이루어져 있다.

    출력
    입력으로 주어진 단어가 팰린드롬이면 "true", 아니면 "false"를 출력한다.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char s[21];
    int len;
    int flag = 0;

    scanf("%s", s);
    len = strlen(s);

    for (int i = 0; i < len/2; i++) {
        if (s[i] != s[len-1 - i]) {
            printf("false");
            flag = 1;
            return 0;
        }
    }
    
    printf("true");
    
    return 0;
}