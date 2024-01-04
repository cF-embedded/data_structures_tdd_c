extern "C" {
    #include "../../src/cbuf/cbuf.h"
}

#include <gtest/gtest.h>

TEST(CbufTests, is_empty_after_init) 
{
    cbuf_s_t cbuf;

    cbuf_init(&cbuf);

    EXPECT_TRUE(cbuf_is_empty(&cbuf));
}

TEST(CbufTests, head_equal_tail_after_init)
{
    cbuf_s_t cbuf;

    cbuf_init(&cbuf);

    EXPECT_TRUE(cbuf_get_head(&cbuf) == cbuf_get_tail(&cbuf));
}

TEST(CbufTests, not_empty_after_added_item)
{
    cbuf_s_t cbuf;
    item_t item = 0xFFFF;

    cbuf_init(&cbuf);
    cbuf_push(&cbuf, item);

    EXPECT_FALSE(cbuf_is_empty(&cbuf));
}

TEST(CbufTests, tail_increment_after_added_item)
{
    cbuf_s_t cbuf;
    item_t item = 0xFFFF;
    index_t last_tail_val;

    cbuf_init(&cbuf);
    last_tail_val = cbuf_get_tail(&cbuf);

    cbuf_push(&cbuf, item);
    last_tail_val++;
    EXPECT_EQ(last_tail_val, cbuf_get_tail(&cbuf));
}




