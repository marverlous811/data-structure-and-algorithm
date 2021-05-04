//
// Created by marverlous on 3/30/2021.
//

#include <gtest/gtest.h>
#include "generator.h"

int main(){
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

TEST(generateBinary, binary_3) {
    vector<string> result = generateBinary(3);
    EXPECT_EQ(result.size(), 8);
}

TEST(generateBinary, binary_4) {
    vector<string> result = generateBinary(4);
    EXPECT_EQ(result.size(), 16);
}
