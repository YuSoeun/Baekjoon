#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    int n = 2, i = 1;
    float j;
    int ns[11000] = {0};

    while(n <= 11000){
        ns[n] = 1;
        n = ++i;

        for(j=0.0; j<4; j++){
            n += (i%(int)pow(10.0, j+1)) / (int)pow(10.0, j);
        }
    }
    
    for(i=1; i<10000; i++){
        if(ns[i] == 0)  printf("%d\n", i);
    }
    return 0;
}