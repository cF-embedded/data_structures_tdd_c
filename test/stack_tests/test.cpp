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

TEST(StackTests, stack_not_empty_after_adding_item)
{
    stack_s_t stack;
    uint32_t item = 5;

    stack_init(&stack);
    stack_push(&stack, item);

    EXPECT_FALSE(stack_is_empty(&stack));
}


