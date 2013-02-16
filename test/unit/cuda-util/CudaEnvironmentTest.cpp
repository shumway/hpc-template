#include <gtest/gtest.h>
#include "cuda-util/CUDAEnvironment.h"

namespace {

class CudaEnvironmentTest: public testing::Test {
protected:
    void SetUp() {
        environment = new CUDAEnvironment();
    }

    void TearDown() {
        delete environment;
    }

    CUDAEnvironment* environment;
};

TEST_F(CudaEnvironmentTest, testDeviceCount)  {
    int deviceCount = environment->getDeviceCount();
    ASSERT_EQ(1, deviceCount);
}

}
