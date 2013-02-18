#include "CUDAProperties.h"
#include <cuda_runtime.h>

CUDAProperties::CUDAProperties(int index) {
    this->index = index;
    cudaDeviceProp *properties = new cudaDeviceProp;
    cudaGetDeviceProperties(properties, index);
    this->properties = properties;
}

CUDAProperties::~CUDAProperties() {
    delete properties;
}

int CUDAProperties::getIndex() const {
    return index;
}

std::string CUDAProperties::getDeviceName() const {
    return std::string(properties->name);
}


int CUDAProperties::getMajor() const {
    return properties->major;
}

int CUDAProperties::getMinor() const {
    return properties->minor;
}

int CUDAProperties::getClockRateInKHz() const {
    return properties->clockRate;
}

int CUDAProperties::getMultiprocessorCount() const {
    return properties->multiProcessorCount;
}

int CUDAProperties::getSharedMemorySize() const {
    return properties->sharedMemPerBlock;
}

int CUDAProperties::getRegisterCount() const {
    return properties->regsPerBlock;
}

int CUDAProperties::getWarpSize() const {
    return properties->warpSize;
}

const cudaDeviceProp* CUDAProperties::getProperties() const {
    return properties;
}
