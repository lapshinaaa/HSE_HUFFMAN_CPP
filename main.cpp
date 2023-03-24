#include <iostream>
#include "Compress/Compress.h"

int main() {
    std::string input_str = "";
    std::cout << "Print any string you like and I'll create huffman codes for it: " << std::endl;
    std::cin >> input_str;

    std::unordered_map<char, int> dict_of_inputStr = stringToDict(input_str);
    std::vector<char> keys;
    std::vector<int> freq;
    dictToArray(dict_of_inputStr, keys, freq);

    int size = keys.size();

    huffmanCodes(keys, freq, size);
    return 0;

}
// add functions, which work with input string, and huffmanCodes work with vectors