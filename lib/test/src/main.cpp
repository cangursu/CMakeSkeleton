
#include "DummyLib.h"

#include <gtest/gtest.h>


TEST(DummyTest, DummyTest)
{
    EXPECT_TRUE(DummyLib());
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

