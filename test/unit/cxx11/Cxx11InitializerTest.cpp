#include <gtest/gtest.h>
#include <list>
#include <string>
#include <sstream>

namespace {

class Cxx11InitializerTest: public testing::Test
{
protected:
    void SetUp() {
    }

    void TearDown() {
    }

    std::string to_string(std::list<int>& list) {
        std::stringstream stream;
        stream << "{ ";
        for (auto &item : list) {
            stream << item << " ";
        }
        stream << "}";
        return stream.str();
    }

};

TEST_F(Cxx11InitializerTest, testList)  {
    std::list<int> mylist = {1, 1, 2, 3, 5, 8, 13, 21};
    ASSERT_EQ(size_t(8), mylist.size())
        << "for list " << to_string(mylist);
}

}
