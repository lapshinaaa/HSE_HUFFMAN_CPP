#include "Compress.h"
#include <iostream>
#include <cassert>

void testCasesHuffman()
{
    // first test case:
    std::string first_input = "Abcdef";
    std::string expected_outcome_first = "1001010111100110\n";

    std::unordered_map<char, int> dict_of_inputStrFirst = stringToDict(first_input);
    std::vector<char> keysFirst;
    std::vector<int> freqFirst;
    dictToArray(dict_of_inputStrFirst, keysFirst, freqFirst);
    int size1 = keysFirst.size();

    // Redirect the output to a string stream instead
    std::stringstream buffer;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf(buffer.rdbuf());

    huffmanCodes(keysFirst, freqFirst, size1, first_input);

    // the standard output stream std::cout is restored to its original state using the saved value oldCoutStreamBuf
    std::cout.rdbuf(oldCoutStreamBuf);

    // getting the output as a string
    std::string output = buffer.str();
    assert(output == expected_outcome_first);


    // second test case:
//    std::string second_input = " ";
//    std::string expected_outcome_second = " ";
//
//    std::unordered_map<char, int> dict_of_inputSecond = stringToDict(second_input);
//    std::vector<char> keysSecond;
//    std::vector<int> freqSecond;
//    dictToArray(dict_of_inputStrFirst, keysFirst, freqSecond);
//    int size2 = keysFirst.size();
//
//    std::stringstream bufferSecond;
//    std::streambuf* oldCoutStreamBufSecond = std::cout.rdbuf(buffer.rdbuf());
//
//    huffmanCodes(keysSecond, freqSecond, size2, second_input);
//
//    // the standard output stream std::cout is restored to its original state using the saved value oldCoutStreamBuf
//    std::cout.rdbuf(oldCoutStreamBufSecond);
//
//    // getting the output as a string
//    std::string output_second = buffer.str();
//    assert(output_second == expected_outcome_second);
}
