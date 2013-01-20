#include <iostream>
#include <string>
#include "Application.h"

int main(int argc, char** argv) {
    auto hello = new std::string("Hello World!");
    std::cout << *hello << std::endl;

    Application application;
    application.run();

    return 0;
}
