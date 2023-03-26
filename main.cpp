#include <iostream>
#include "Compress/Compress.h"

int main() {
    std::string input_str;
    std::cout << "Enter the string: " << std::endl;
    std::getline(std::cin, input_str);

    guiShow(input_str);
    // testing the code:
    testCasesHuffman();
    std::cout<<"All tests successfully complete!";

    return 0;

}