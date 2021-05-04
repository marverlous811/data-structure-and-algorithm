//
// Created by marverlous on 3/29/2021.
//

#include "generator.h"

void printArray(vector<string> arr){
    for(const auto& data: arr){
        printf("%s, size: %llu\n", data.c_str(), data.size());
    }
}

int main(){
    printf("hello world\n");
    int n = 3;
    printArray(generateBinary(n));
    return 0;
}