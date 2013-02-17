#ifndef CUDAENVIRONMENTWRITER_H_
#define CUDAENVIRONMENTWRITER_H_

class CUDAEnvironment;
#include <ostream>

class CUDAEnvironmentWriter {
public:
    CUDAEnvironmentWriter(const CUDAEnvironment* environment);
    virtual ~CUDAEnvironmentWriter();

    void writeEnvironment();
    void writeEnvironment(std::ostream* outStream);

private:
    const CUDAEnvironment* environment;
    std::ostream* outStream;

    void writeDeviceInformation(int i);
    void writeHeader();
    void writeDeviceCount();
    void writeInfoForEachDevice();
    void writeFooter();
};

#endif
