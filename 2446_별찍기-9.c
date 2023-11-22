/*
Input: 5

*********
 *******
  *****
   ***
    *
   ***
  *****
 *******
*********
*/

#include <stdio.h>

int main(){
    int n;
    int sp;

    scanf("%d", &n);
    sp = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<sp; j++)    printf(" ");
        for(int j=0; j<n - sp; j++)    printf("*");
        if(i<n)
            for(int j=0; j<n - sp-1; j++)    printf("*");

        printf("\n");
        sp++;
    }
    
    sp--;

    for(int i=0; i<n-1; i++){
        sp--;
        for(int j=0; j<sp; j++)    printf(" ");
        for(int j=0; j<n - sp; j++)    printf("*");
        for(int j=0; j<n - sp-1; j++)    printf("*");
        printf("\n");
    }

    return 0;
}