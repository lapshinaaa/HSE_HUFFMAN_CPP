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
    std::cout<< "First test for the input 'Abcdef' is successfully complete!\n";


    // second test case:
    std::string second_input = "a";
    std::string expected_outcome_second = "0\n";

    std::unordered_map<char, int> dict_of_inputSecond = stringToDict(second_input);
    std::vector<char> keysSecond;
    std::vector<int> freqSecond;
    dictToArray(dict_of_inputSecond, keysSecond, freqSecond);
    int size2 = keysSecond.size();

    std::stringstream bufferSecond;
    std::streambuf* oldCoutStreamBufSecond = std::cout.rdbuf(bufferSecond.rdbuf());

    huffmanCodes(keysSecond, freqSecond, size2, second_input);

    // the standard output stream std::cout is restored to its original state using the saved value oldCoutStreamBuf
    std::cout.rdbuf(oldCoutStreamBufSecond);

    // getting the output as a string
    std::string output_second = bufferSecond.str();
    assert(output_second == expected_outcome_second);
    std::cout<< "Second test for the single-character input 'a' is successfully complete!\n";


    // third test case:
    std::string third_input = "";
    std::string expected_outcome_third = "\n";

    std::unordered_map<char, int> dict_of_inputThird = stringToDict(third_input);
    std::vector<char> keysThird;
    std::vector<int> freqThird;
    dictToArray(dict_of_inputThird, keysThird, freqThird);
    int size3 = keysThird.size();

    std::stringstream bufferThird;
    std::streambuf* oldCoutStreamBufThird = std::cout.rdbuf(bufferThird.rdbuf());

    huffmanCodes(keysThird, freqThird, size3, third_input);

    // the standard output stream std::cout is restored to its original state using the saved value oldCoutStreamBuf
    std::cout.rdbuf(oldCoutStreamBufThird);

    // getting the output as a string
    std::string output_third = bufferThird.str();
    assert(output_third == expected_outcome_third);
    std::cout<< "Third test for an empty string '' is successfully complete!\n";


    // fourth test case:
    std::string fourth_input = "AAAAA";
    std::string expected_outcome_fourth = "0\n";

    std::unordered_map<char, int> dict_of_inputFourth = stringToDict(fourth_input);
    std::vector<char> keysFourth;
    std::vector<int> freqFourth;
    dictToArray(dict_of_inputFourth, keysFourth, freqFourth);
    int size4 = keysFourth.size();

    std::stringstream bufferFourth;
    std::streambuf* oldCoutStreamBufFourth = std::cout.rdbuf(bufferFourth.rdbuf());

    huffmanCodes(keysFourth, freqFourth, size4, fourth_input);

    // the standard output stream std::cout is restored to its original state using the saved value oldCoutStreamBuf
    std::cout.rdbuf(oldCoutStreamBufFourth);

    // getting the output as a string
    std::string output_fourth = bufferFourth.str();
    assert(output_fourth == expected_outcome_fourth);
    std::cout<< "Fourth test for a string of repeated characters 'AAAAA' is successfully complete!\n";


    // fifth test case:
    std::string fifth_input = "Between what you have and could have lies your power to get it";
    std::string expected_outcome_fifth = "01110110011010101100100101010001011111111001101000100111101111000111111100011011000011001010110110000100011101111001100101100011111110001101100000110001111100101001000100111101111010111001010001110010110010111001101111000011100100110100011111101\n";

    std::unordered_map<char, int> dict_of_inputFifth = stringToDict(fifth_input);
    std::vector<char> keysFifth;
    std::vector<int> freqFifth;
    dictToArray(dict_of_inputFifth, keysFifth, freqFifth);
    int size5 = keysFifth.size();

    std::stringstream bufferFifth;
    std::streambuf* oldCoutStreamBufFifth = std::cout.rdbuf(bufferFifth.rdbuf());

    huffmanCodes(keysFifth, freqFifth, size5, fifth_input);

    // the standard output stream std::cout is restored to its original state using the saved value oldCoutStreamBuf
    std::cout.rdbuf(oldCoutStreamBufFifth);

    // getting the output as a string
    std::string output_fifth = bufferFifth.str();
    assert(output_fifth == expected_outcome_fifth);
    std::cout<< "Fifth test for a string 'Between what you have and could have lies your power to get it' is successfully complete!\n";

}
