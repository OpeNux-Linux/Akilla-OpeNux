// Easify
#include "headers/easify.h"

void PrintLine(const std::string&msg) {
    std::cout << msg << std::endl;
}

void PrintVector(const std::vector<std::string>& vect) {
    for (size_t i = 0; i < vect.size(); ++i) {
        if (i) std::cout << ", ";
        std::cout << vect[i];
    }
    std::cout << "\n";
}

std::string ReadFile(const std::string&path) {
    std::ifstream f(path);
    std::stringstream ss;
    ss << f.rdbuf();
    return ss.str();
}
