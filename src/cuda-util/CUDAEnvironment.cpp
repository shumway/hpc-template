#include "cuda-util/CUDAEnvironment.h"
#include <cuda_runtime.h>

CUDAEnvironment::CUDAEnvironment() {
    cudaGetDeviceCount(&deviceCount);}

CUDAEnvironment::~CUDAEnvironment() {
}

int CUDAEnvironment::getDeviceCount() const {
    return deviceCount;
}


