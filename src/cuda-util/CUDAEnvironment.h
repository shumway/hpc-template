#ifndef CUDAENVIRONMENT_H_
#define CUDAENVIRONMENT_H_

class CUDAProperties;

class CUDAEnvironment {
public:
    CUDAEnvironment();
    virtual ~CUDAEnvironment();

    int getDeviceCount() const;

    CUDAProperties** begin() const;
    CUDAProperties** end() const;
private:
    int deviceCount;
    CUDAProperties** propertiesList;
};

#endif
