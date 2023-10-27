#include <iostream>
#include <string>

using std::to_string;
void debug(std::string message);

void debug(std::string message)
{
    std::cout << message << std::endl;
}