set (sources
    CUDAEnvironment.cpp
    CUDAEnvironmentWriter.cpp
    CUDAProperties.cpp
)

cuda_add_library(cuda-util STATIC ${sources})
