#include "cuda-util/CUDAEnvironment.h"
#include <cuda_runtime.h>

CUDAEnvironment::CUDAEnvironment() {
    cudaGetDeviceCount(&deviceCount);
    properties = new cudaDeviceProp[deviceCount];
    for (int i = 0; i < deviceCount; ++i) {
        cudaGetDeviceProperties(&properties[i], i);
    }
}

CUDAEnvironment::~CUDAEnvironment() {
    delete [] properties;
}

int CUDAEnvironment::getDeviceCount() const {
    return deviceCount;
}

std::string CUDAEnvironment::getDeviceName(int index) const {
    return std::string(properties[index].name);
}



