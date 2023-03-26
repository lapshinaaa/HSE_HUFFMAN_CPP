#include <iostream>
#include "Compress/Compress.h"

std::string guiShow(std:: string input_str) {
    std::unordered_map<char, int> dict_of_inputStr = stringToDict(input_str);
    std::vector<char> keys;
    std::vector<int> freq;
    dictToArray(dict_of_inputStr, keys, freq);

    int size = keys.size();

    return huffmanCodes(keys, freq, size, input_str);
}