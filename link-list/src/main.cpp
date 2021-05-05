//
// Created by marverlous on 5/4/2021.
//

#include "singly_linklist.h"

int main(){
    auto intList = new SinglyLinkList<int>();
    int idx = 2;
    intList->pushBack(1);
    intList->pushBack(2);
    intList->pushBack(3);
    intList->pushBack(4);

    printf("length: %d\n", intList->length());
    intList->foreach([](int data){
       printf("%d\n", data);
    });
    intList->findIndex(idx, [](int data){
        printf("found data %d\n", data);
    });

    auto res = intList->insert(5, 3);
    printf("insert into status %d\n", res);
    intList->foreach([](int data){
        printf("%d\n", data);
    });

    auto res1 = intList->insert(6, 5);
    printf("insert into status %d\n", res1);

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