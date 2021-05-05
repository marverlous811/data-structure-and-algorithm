//
// Created by marverlous on 5/4/2021.
//

#include <gtest/gtest.h>
#include "singly_linklist.h"

SinglyLinkList<int>* sampleList(int *arr, int size) {
    auto list = new SinglyLinkList<int>();
    for(int i = 0; i < size; i++) {
        list->pushBack(arr[i]);
    }
    return list;
}

TEST(singly_linklist, push_back) {
    int arr[5] = {1,2,3,4,5};
    auto list = sampleList(arr, 5);
    for(auto i = 0; i < 5; i++) {
        EXPECT_EQ(list->contain(arr[i]), i);
    }
}

int main(){
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}