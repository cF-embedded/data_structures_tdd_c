extern "C" {
    #include "../../src/stack/stack.h"
}

#include <gtest/gtest.h>


TEST(StackTests, stack_is_empty_after_init) 
{
    stack_s_t stack;

    stack_init(&stack);

    EXPECT_TRUE(stack_is_empty(&stack));
}


