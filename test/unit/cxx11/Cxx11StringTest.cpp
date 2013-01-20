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

TEST_F(Cxx11StringTest, testUTF8String) {
    std::string string = u8"omega is \u03C9";
    size_t expect = 5 + 1 + 2 + 1 + 2;
    EXPECT_EQ(expect, string.length());
}

}
