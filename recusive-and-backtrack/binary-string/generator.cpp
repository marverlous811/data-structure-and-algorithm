//
// Created by marverlous on 3/30/2021.
//

#include "generator.h"

void binary(int n, char* arr, int max_size, vector<string>* retval) {
    if(n < 1) {
        char* newArr = (char*)malloc(max_size + 1);
        memcpy(newArr, arr, max_size);
        newArr[max_size] = '\0';
        retval->emplace_back(string(newArr));
        return;
    }

    arr[n-1] = '0';
    binary(n - 1, arr, max_size, retval);
    arr[n-1] = '1';
    binary(n - 1, arr, max_size, retval);
}

vector<string> generateBinary(int n) {
    char* arr = (char*)malloc((n));
    vector<string> retval;
    binary(n, arr, n, &retval);
    return retval;
}