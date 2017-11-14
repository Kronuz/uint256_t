#include <gtest/gtest.h>

#include "uint_t.hh"

TEST(Assignment, all) {
    const uint_t t_1   = true;
    const uint_t f_1   = false;
    const uint_t u8_1  = 0x01;
    const uint_t u16_1 = 0x0123;
    const uint_t u32_1 = 0x01234567;
    const uint_t u64_1 = 0x0123456789abcdef;

    uint_t t_2   = 0;
    uint_t f_2   = 0;
    uint_t u8_2  = 0;
    uint_t u16_2 = 0;
    uint_t u32_2 = 0;
    uint_t u64_2 = 0;

    t_2 = t_1;
    f_2 = f_1;
    u8_2 = u8_1;
    u16_2 = u16_1;
    u32_2 = u32_1;
    u64_2 = u64_1;

    EXPECT_EQ(t_1, t_2);
    EXPECT_EQ(f_1, f_2);
    EXPECT_EQ(u8_1, u8_2);
    EXPECT_EQ(u16_1, u16_2);
    EXPECT_EQ(u32_1, u32_2);
    EXPECT_EQ(u64_1, u64_2);
}
