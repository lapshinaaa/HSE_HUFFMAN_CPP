#include "Compress.h"
#include <iostream>
#include <cassert>

void testCasesHuffman()
{
    // first test case:
    std::string first_input = "Abcdef";

    std::unordered_map<char, int> dict_of_inputStrFirst = stringToDict(first_input);
    std::vector<char> keysFirst;
    std::vector<int> freqFirst;
    dictToArray(dict_of_inputStrFirst, keysFirst, freqFirst);
    int size1 = keysFirst.size();

    // Redirect cout to a string stream
    std::stringstream buffer;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf(buffer.rdbuf());

    huffmanCodes(keysFirst, freqFirst, size1, first_input);

    // Restore the old cout stream buffer
    std::cout.rdbuf(oldCoutStreamBuf);

    // Check the output
    std::string output = buffer.str();
    assert(output == "1001010111100110\n");

    // second case:

}
