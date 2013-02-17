#include "CUDAEnvironmentWriter.h"
#include "CUDAEnvironment.h"
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

void CUDAEnvironmentWriter::writeDeviceInformation(int index) {
    *outStream << "CUDA Device " << index + 1 << " of "
            << environment->getDeviceCount() << "\n" << std::endl;
    *outStream << "  Name: " << environment->getDeviceName(index) << std::endl;
    *outStream << std::endl;
}

void CUDAEnvironmentWriter::writeInfoForEachDevice() {
    for (int i = 0; i < environment->getDeviceCount(); ++i) {
        writeDeviceInformation(i);
    }
}

void CUDAEnvironmentWriter::writeFooter() {
}


