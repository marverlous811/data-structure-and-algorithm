//
// Created by marverlous on 5/4/2021.
//

#include "singly_linklist.h"

int main(){
    auto intList = new SinglyLinkList<int>();
    int idx = 2;
    intList->addData(1);
    intList->addData(2);
    intList->addData(3);
    intList->addData(4);

    printf("length: %d\n", intList->length());
    intList->foreach([](int data){
       printf("%d\n", data);
    });
    intList->findIndex(idx, [](int data){
        printf("found data %d\n", data);
    });

    intList->deleteNode(idx);
    printf("length after delete: %d\n", intList->length());
    intList->foreach([](int data){
        printf("%d\n", data);
    });

    intList->deleteList();
    printf("length after delete: %d\n", intList->length());
    intList->foreach([](int data){
        printf("%d\n", data);
    });
    return 0;
}