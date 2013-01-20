#include <gtest/gtest.h>

namespace {

class Cxx11AutoTest: public testing::Test
{
protected:
    void SetUp() {
    }

    void TearDown() {
    }

};

TEST_F(Cxx11AutoTest, testFloat)  {
    auto x = 1.0;
    auto result = x / 2;
    ASSERT_NEAR(0.5, result, 1e-14);
}


}
