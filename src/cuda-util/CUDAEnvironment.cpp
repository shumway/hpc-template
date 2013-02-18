#include "cuda-util/CUDAEnvironment.h"
#include <cuda_runtime.h>
#include "CUDAProperties.h"

CUDAEnvironment::CUDAEnvironment() {
    cudaGetDeviceCount(&deviceCount);
    propertiesList = new CUDAProperties* [deviceCount];
    for (int i = 0; i < deviceCount; ++i) {
        propertiesList[i] = new CUDAProperties(i);
    }
}

CUDAEnvironment::~CUDAEnvironment() {
    for (auto properties : *this) delete properties;
    delete [] propertiesList;
}

int CUDAEnvironment::getDeviceCount() const {
    return deviceCount;
}

CUDAProperties** CUDAEnvironment::begin() const {
    return propertiesList;
}

CUDAProperties** CUDAEnvironment::end() const {
    return propertiesList + deviceCount;
}

