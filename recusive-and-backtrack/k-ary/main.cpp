//
// Created by marverlous on 3/30/2021.
//

#include <stdlib.h>
#include <stdio.h>
#include <charconv>
#include <iostream>

#define MAX_DIGITS 10

char *a;

void k_string(int n, int k){
    if (n < 1) {
        printf("%s\n", a);
        return;
    }

    for (int i = 0; i < k; i++) {
        a[n - 1] =  '0'  + i;
        k_string(n - 1, k);
    }
}

int main(){
    int n = 3;
    a = (char*)malloc(n + 1);
    a[n] = '\0';
    k_string(n, 3);
    return 0;
}
