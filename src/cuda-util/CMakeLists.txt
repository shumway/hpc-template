file(GLOB SOURCE_CPP "*.cpp")

set (sources
    ${SOURCE_CPP}
)

cuda_add_library(cuda-util STATIC ${sources})
