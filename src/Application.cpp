#include "Application.h"
#include "cuda-util/CUDAEnvironment.h"
#include <iostream>

Application::Application()
    :   cudaEnvironment(0) {
    setupCUDAEnvironment();
}

Application::~Application() {
    delete cudaEnvironment;
}

void Application::run() {
}

void Application::setupCUDAEnvironment() {
    cudaEnvironment = new CUDAEnvironment();
    std::cout << "\nCUDA Summary\n" << std::endl;
    std::cout << "Number of Devices: " << cudaEnvironment->getDeviceCount()
            << std::endl;
}
