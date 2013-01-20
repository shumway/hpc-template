#ifndef APPLICATION_H_
#define APPLICATION_H_

class CUDAEnvironment;

class Application {
public:
    Application();
    virtual ~Application();

    void run();

private:
    CUDAEnvironment* cudaEnvironment;

    void setupCUDAEnvironment();
};

#endif
