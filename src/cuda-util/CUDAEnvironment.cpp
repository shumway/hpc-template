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

int CUDAEnvironment::getMajor(int index) const {
    return properties[index].major;
}

int CUDAEnvironment::getMinor(int index) const {
    return properties[index].major;
}

int CUDAEnvironment::getClockRateInKHz(int index) const {
    return properties[index].clockRate;
}

int CUDAEnvironment::getMultiprocessorCount(int index) const {
    return properties[index].multiProcessorCount;
}

int CUDAEnvironment::getSharedMemorySize(int index) const {
    return properties[index].sharedMemPerBlock;
}

int CUDAEnvironment::getRegisterCount(int index) const {
    return properties[index].regsPerBlock;
}

int CUDAEnvironment::getWarpSize(int index) const {
    return properties[index].warpSize;
}






