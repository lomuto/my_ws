#include <iostream>

int main() {
    std::string line;
    std::cin >> line;
    if (std::cin.eof()) {
        std::cout << "end of file" << std::endl;
        return 0;
    }
    std::cout << line << std::endl;
}