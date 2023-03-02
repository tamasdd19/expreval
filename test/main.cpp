#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "catch.hpp"

int main(int argc, char* const argv[]) {
    int result = Catch::Session().run(argc, argv);
    std::cout << "Press enter to continue...";
    std::getchar();
    return result;
}