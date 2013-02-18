#include "CUDAEnvironmentWriter.h"
#include "CUDAEnvironment.h"
#include "CUDAProperties.h"
#include <fstream>

CUDAEnvironmentWriter::CUDAEnvironmentWriter(
        const CUDAEnvironment *environment)
:   environment(environment) {

}

CUDAEnvironmentWriter::~CUDAEnvironmentWriter() {
}

void CUDAEnvironmentWriter::writeEnvironment() {
    std::ofstream ofStream("cuda-env.dat");
    writeEnvironment(&ofStream);
}

void CUDAEnvironmentWriter::writeEnvironment(std::ostream* outStream) {
    this->outStream = outStream;
    writeHeader();
    writeDeviceCount();
    writeInfoForEachDevice();
    writeFooter();
}

void CUDAEnvironmentWriter::writeHeader()  {
    *outStream << "\nCUDA Summary\n" << std::endl;
}

void CUDAEnvironmentWriter::writeDeviceCount()  {
    int count = environment->getDeviceCount();
    if (count == 0) {
        *outStream << "There are no CUDA devices." << std::endl;
    } else if (count == 1) {
        *outStream << "There is 1 CUDA device." << std::endl;
    } else {
        *outStream << "There are " << count << " CUDA devices." << std::endl;
    }
    *outStream << std::endl;
}

void CUDAEnvironmentWriter::writeDeviceInformation(
        const CUDAProperties* properties) {
    *outStream << "CUDA Device " << properties->getIndex() + 1 << " of "
            << environment->getDeviceCount() << "\n" << std::endl;
    *outStream << "  Name: " << properties->getDeviceName() << std::endl;
    *outStream << "  Compute capability: " << properties->getMajor()
            << "." << properties->getMinor() << std::endl;
    *outStream << "  Clock rate: " << properties->getClockRateInKHz() * 1e-6
            << " GHz" << std::endl;
    *outStream << "  Number of multiprocessors: "
            << properties->getMultiprocessorCount() << std::endl;
    *outStream << "  Shared memory per block: "
            << properties->getSharedMemorySize() << std::endl;
    *outStream << "  Registers per block: "
            << properties->getRegisterCount() << std::endl;
    *outStream << "  Threads per warp: " << properties->getWarpSize()
            << std::endl;
    *outStream << std::endl;
}

void CUDAEnvironmentWriter::writeInfoForEachDevice() {
    for (auto properties : *environment) {
        writeDeviceInformation(properties);
    }
}

void CUDAEnvironmentWriter::writeFooter() {
}

