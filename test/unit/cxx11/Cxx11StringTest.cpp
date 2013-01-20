#include <gtest/gtest.h>
#include <string>

namespace {

class Cxx11StringTest: public testing::Test
{
protected:
    void SetUp() {
    }

    void TearDown() {
    }

};

TEST_F(Cxx11StringTest, testOldString)  {
    std::string string = "my string";
    EXPECT_EQ(std::string("my string"), string);
}

TEST_F(Cxx11StringTest, testRawString)  {
    std::string string = R"(string\no\newlines!)";
    EXPECT_EQ(std::string("string\\no\\newlines!"), string);
}


}
