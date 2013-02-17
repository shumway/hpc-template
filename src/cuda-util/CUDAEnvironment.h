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
private:
    int deviceCount;
    cudaDeviceProp* properties;
};

#endif
