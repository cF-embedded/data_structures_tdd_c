extern "C" {
    #include "../../src/stack/stack.h"
}

#include <gtest/gtest.h>


TEST(StackTests, is_empty_after_init) 
{
    stack_s_t stack;

    stack_init(&stack);

    EXPECT_TRUE(stack_is_empty(&stack));
}

TEST(StackTests, not_empty_after_adding_item)
{
    stack_s_t stack;
    item_t item = 5;

    stack_init(&stack);
    stack_push(&stack, item);

    EXPECT_FALSE(stack_is_empty(&stack));
}

TEST(StackTests, added_item_is_equal_item_on_top)
{
    stack_s_t stack;
    item_t item = 13;

    stack_init(&stack);
    stack_push(&stack, item);

    EXPECT_EQ(item, stack_peek(&stack));
}

TEST(StackTests, pop_item_if_stack_is_not_empty)
{
    stack_s_t stack;
    item_t item = 13;

    stack_init(&stack);
    stack_push(&stack, item);

    EXPECT_TRUE(stack_pop(&stack));
}


