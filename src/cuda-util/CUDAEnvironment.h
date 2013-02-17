#ifndef CUDAENVIRONMENT_H_
#define CUDAENVIRONMENT_H_
#include <string>

struct cudaDeviceProp;

class CUDAEnvironment {
public:
    CUDAEnvironment();
    virtual ~CUDAEnvironment();

    int getDeviceCount() const;
    std::string getDeviceName(int index) const;

    int getMajor(int index) const;
    int getMinor(int index) const;
    int getClockRateInKHz(int index) const;
    int getMultiprocessorCount(int index) const;
    int getSharedMemorySize(int index) const;
    int getRegisterCount(int index) const;
    int getWarpSize(int index) const;
private:
    int deviceCount;
    cudaDeviceProp* properties;
};

#endif
