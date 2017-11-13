#include <gtest/gtest.h>

#include "uint256_t.hh"

TEST(Constructor, standard) {
    uint256_t value(0x0123456789abcdefULL);
    const uint256_t original = value;

    EXPECT_EQ(uint256_t(0), 0);
    EXPECT_EQ(value, original);
    EXPECT_EQ(uint256_t(std::move(value)), original);
    // EXPECT_EQ(value, 0);
}

TEST(Constructor, one) {
    EXPECT_EQ(uint256_t(true)[1],  false);
    EXPECT_EQ(uint256_t(true)[0],   true);
    EXPECT_EQ(uint256_t(false)[1], false);
    EXPECT_EQ(uint256_t(false)[0], false);

    EXPECT_EQ(uint256_t((uint8_t)  0x01ULL)[1],               0ULL);
    EXPECT_EQ(uint256_t((uint16_t) 0x0123ULL)[1],             0ULL);
    EXPECT_EQ(uint256_t((uint32_t) 0x01234567ULL)[1],         0ULL);
    EXPECT_EQ(uint256_t((uint64_t) 0x0123456789abcdefULL)[1], 0ULL);

    EXPECT_EQ(uint256_t((uint8_t)  0x01ULL)[0],               (uint8_t)  0x01ULL);
    EXPECT_EQ(uint256_t((uint16_t) 0x0123ULL)[0],             (uint16_t) 0x0123ULL);
    EXPECT_EQ(uint256_t((uint32_t) 0x01234567ULL)[0],         (uint32_t) 0x01234567ULL);
    EXPECT_EQ(uint256_t((uint64_t) 0x0123456789abcdefULL)[0], (uint64_t) 0x0123456789abcdefULL);
}

TEST(Constructor, two) {
    for (uint8_t hi = 0; hi < 2; ++hi) {
        for (uint8_t lo = 0; lo < 2; ++lo) {
            const uint256_t val(hi, lo);
            EXPECT_EQ(val[1], hi);
            EXPECT_EQ(val[0], lo);
        }
    }

    EXPECT_EQ(uint256_t((uint8_t)  0x01ULL,               (uint8_t)  0x01ULL)[1],               (uint8_t)  0x01ULL);
    EXPECT_EQ(uint256_t((uint16_t) 0x0123ULL,             (uint16_t) 0x0123ULL)[1],             (uint16_t) 0x0123ULL);
    EXPECT_EQ(uint256_t((uint32_t) 0x01234567ULL,         (uint32_t) 0x01234567ULL)[1],         (uint32_t) 0x01234567ULL);
    EXPECT_EQ(uint256_t((uint64_t) 0x0123456789abcdefULL, (uint64_t) 0x0123456789abcdefULL)[1], (uint64_t) 0x0123456789abcdefULL);

    EXPECT_EQ(uint256_t((uint8_t)  0x01ULL,               (uint8_t)  0x01ULL)[0],               (uint8_t)  0x01ULL);
    EXPECT_EQ(uint256_t((uint16_t) 0x0123ULL,             (uint16_t) 0x0123ULL)[0],             (uint16_t) 0x0123ULL);
    EXPECT_EQ(uint256_t((uint32_t) 0x01234567ULL,         (uint32_t) 0x01234567ULL)[0],         (uint32_t) 0x01234567ULL);
    EXPECT_EQ(uint256_t((uint64_t) 0x0123456789abcdefULL, (uint64_t) 0x0123456789abcdefULL)[0], (uint64_t) 0x0123456789abcdefULL);
}