#ifndef CUDAPROPERTIES_H_
#define CUDAPROPERTIES_H_

struct cudaDeviceProp;
#include <string>

class CUDAProperties {
public:
    CUDAProperties(int index);
    virtual ~CUDAProperties();

    std::string getDeviceName() const;
    int getIndex() const;
    int getMajor() const;
    int getMinor() const;
    int getClockRateInKHz() const;
    int getMultiprocessorCount() const;
    int getSharedMemorySize() const;
    int getRegisterCount() const;
    int getWarpSize() const;

    const cudaDeviceProp* getProperties() const;
private:
    int index;
    const cudaDeviceProp* properties;
};

#endif
