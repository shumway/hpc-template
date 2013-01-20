#ifndef CUDAENVIRONMENT_H_
#define CUDAENVIRONMENT_H_

class CUDAEnvironment {
public:
    CUDAEnvironment();
    virtual ~CUDAEnvironment();

    int getDeviceCount() const;
private:
    int deviceCount;
};

#endif
