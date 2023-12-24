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

TEST(StackTests, pop_if_stack_is_not_empty)
{
    stack_s_t stack;
    item_t item = 13;

    stack_init(&stack);
    stack_push(&stack, item);

    EXPECT_TRUE(stack_pop(&stack));
}

TEST(StackTests, not_pop_if_stack_is_empty)
{
    stack_s_t stack;

    stack_init(&stack);

    EXPECT_FALSE(stack_pop(&stack));
}

TEST(StackTests, pop_top_element)
{
    stack_s_t stack;
    item_t first_item = 13;
    item_t second_item = 42;

    stack_init(&stack);
    stack_push(&stack, first_item);
    stack_push(&stack, second_item);
    stack_pop(&stack);

    EXPECT_EQ(first_item, stack_peek(&stack));
}

TEST(StackTests, stack_is_full_after_pushing_max_items)
{
    stack_s_t stack;
    item_t item = 0xFFFFFFFF;
    uint8_t i;

    stack_init(&stack);
    for(i = 0; i < STACK_SIZE; i++)
    {
        stack_push(&stack, item);
    }
    
    EXPECT_TRUE(stack_is_full(&stack));
}



