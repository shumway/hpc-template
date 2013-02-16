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
    writeFooter();
}

void CUDAEnvironmentWriter::writeHeader()  {
    *outStream << "\nCUDA Summary\n" << std::endl;
}

void CUDAEnvironmentWriter::writeDeviceCount()  {
    *outStream << "Number of Devices: " << environment->getDeviceCount()
            << "\n" << std::endl;
}

void CUDAEnvironmentWriter::writeFooter() {
}


