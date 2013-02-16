#include "Application.h"
#include "cuda-util/CUDAEnvironment.h"
#include "cuda-util/CUDAEnvironmentWriter.h"

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
    CUDAEnvironmentWriter writer(cudaEnvironment);
    writer.writeEnvironment();
}
