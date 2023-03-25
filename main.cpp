#include <iostream>
#include "Compress/Compress.h"

int main() {
    std::string input_str;
    std::cout << "Enter the string: " << std::endl;
    std::getline(std::cin, input_str);

    std::unordered_map<char, int> dict_of_inputStr = stringToDict(input_str);
    std::vector<char> keys;
    std::vector<int> freq;
    dictToArray(dict_of_inputStr, keys, freq);

    int size = keys.size();

    // print the encoded input string using the Huffman codes
    std::cout << "Encoded version of the input: "<<'\n';

    huffmanCodes(keys, freq, size, input_str);

    // testing the code:
    testCasesHuffman();
    std::cout<<"All tests successfully complete!";

    return 0;

}