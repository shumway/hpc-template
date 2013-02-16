set (sources
    CUDAEnvironment.cpp
    CUDAEnvironmentWriter.cpp
)

cuda_add_library(cuda-util STATIC ${sources})
