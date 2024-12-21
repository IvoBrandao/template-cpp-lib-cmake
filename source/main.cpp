#include "mylib.hpp"
#include <iostream>


int main() {

    int result = MyLibInterface::add(1,2);

    std::cout << "result: " << result << std::endl;
    return 0;
}
