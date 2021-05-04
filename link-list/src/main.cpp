//
// Created by marverlous on 5/4/2021.
//

#include "singly_linklist.h"

int main(){
    SinglyLinkList<int> *intList = new SinglyLinkList<int>();
    intList->addData(1);
    intList->addData(2);
    intList->addData(3);

    intList->traversalNode([](int data){
       printf("%d\n", data);
    });
    return 0;
}