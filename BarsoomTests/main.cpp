#include <iostream>
#include <gtest/gtest.h>

#include "BgMap.hpp"

TEST(BgMapTest, ClipStartsEmpty) {
    BgMap bgMap(0, 0, 0, 0);
    EXPECT_EQ(false, bgMap.isPanStopping());
}

int main(int argc, char * argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
