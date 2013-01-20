#include <iostream>
#include <string>

int main(int argc, char** argv) {
    auto hello = new std::string("Hello World!");
    std::cout << *hello << std::endl;
    return 0;
}
