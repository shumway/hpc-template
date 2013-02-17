#include <gtest/gtest.h>
#include "cuda-util/CUDAEnvironment.h"
#include <string>

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

TEST_F(CudaEnvironmentTest, testDeviceNames) {
    int deviceCount = environment->getDeviceCount();
    for (int deviceIndex = 0; deviceIndex < deviceCount; ++deviceIndex) {
        std::string name = environment->getDeviceName(deviceIndex);
        ASSERT_GT(name.length(), 0U);
    }
}

}
