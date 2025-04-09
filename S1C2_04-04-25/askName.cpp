#include <iostream>
#include <string>

int main(void) {
    std::cout << "Please write your name:" << std::endl;
    std::string name;
    std::getline(std::cin, name);  // Lee toda la línea, incluyendo espacios
    std::cout << "Hello : " + name << std::endl;
    return 0;
}
