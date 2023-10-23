/*
Input: 5

*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *

*/

#include <stdio.h>

int main(){
    int n;
    int sp;

    scanf("%d", &n);
    sp = n;

    for(int i=0; i<n; i++){
        sp--;

        for(int j=0; j<i+1; j++)    printf("*");
        for(int j=0; j<sp; j++)    printf(" ");

        for(int j=0; j<sp; j++)    printf(" ");
        for(int j=0; j<i+1; j++)    printf("*");

        printf("\n");
    }

    n--;

    for(int i=0; i<n; i++){
        sp++;

        for(int j=0; j<n-i; j++)    printf("*");
        for(int j=0; j<sp; j++)    printf(" ");

        for(int j=0; j<sp; j++)    printf(" ");
        for(int j=0; j<n-i; j++)    printf("*");

        printf("\n");
    }

    return 0;
}