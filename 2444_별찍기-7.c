#include <stdio.h>

int main(){
    int n;
    int sp;

    scanf("%d", &n);
    sp = n;

    for(int i=0; i<n; i++){
        sp--;

        for(int j=0; j<sp; j++)    printf(" ");
        for(int j=0; j<n - sp; j++)    printf("*");
        if(i>0)
            for(int j=0; j<n - sp-1; j++)    printf("*");
        printf("\n");
    }

    sp = 0;

     for(int i=0; i<n; i++){
        sp++;

        for(int j=0; j<sp; j++)    printf(" ");
        for(int j=0; j<n - sp; j++)    printf("*");
        if(i<n)
            for(int j=0; j<n - sp-1; j++)    printf("*");
        printf("\n"); 
    }

    return 0;
}