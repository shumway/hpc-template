#ifndef CUDAENVIRONMENTWRITER_H_
#define CUDAENVIRONMENTWRITER_H_

class CUDAEnvironment;
class CUDAProperties;
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

    void writeDeviceInformation(const CUDAProperties *properties);
    void writeHeader();
    void writeDeviceCount();
    void writeInfoForEachDevice();
    void writeFooter();
};

#endif
