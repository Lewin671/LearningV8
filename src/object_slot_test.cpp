//
// Created by qingyingliu on 2022/10/19.
//

#include "gtest/gtest.h"
#include "v8.h"
#include <bitset>
#include <src/objects/objects.h>
#include <src/objects/slots.h>

namespace i = v8::internal;

TEST(ObjectSlot, Create) {
    i::Object object{18};

    // slot._ptr = object.ptr_
    i::FullObjectSlot slot{&object};
    EXPECT_NE(slot.address(), object.ptr());

    // == is been override, check equality by their address
    EXPECT_EQ(*slot, object);

    i::Object *p = &object;
    i::Object **pp = &p;
    EXPECT_EQ(*slot, **pp);
}