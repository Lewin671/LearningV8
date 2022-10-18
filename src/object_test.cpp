//
// Created by qingyingliu on 2022/10/19.
//

#include "gtest/gtest.h"
#include "v8.h"
#include <bitset>
#include <src/objects/objects.h>

namespace i = v8::internal;


TEST(MaybeTest, Create) {
    i::Object obj{};
    EXPECT_EQ(obj.ptr(), i::kNullAddress);
    i::Object obj2{18};
    EXPECT_EQ(static_cast<int>(obj2.ptr()), 18);
}