extern "C" {
    #include "../../src/cbuf/cbuf.h"
}

#include <gtest/gtest.h>

TEST(StackTests, is_empty_after_init) 
{
    cbuf_s_t cbuf;

    cbuf_init(&cbuf);

    EXPECT_TRUE(cbuf_is_empty(&cbuf));
}

TEST(StackTests, head_equal_tail_after_init)
{
    cbuf_s_t cbuf;

    cbuf_init(&cbuf)

    EXPECT_TRUE(cbuf_get_head(&cbuf) == cbuf_get_tail(&cbuf));
}


