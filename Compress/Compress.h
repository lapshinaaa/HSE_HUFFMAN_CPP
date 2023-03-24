#ifndef HSE_HUFFMAN_CPP_COMPRESS_H
#define HSE_HUFFMAN_CPP_COMPRESS_H

#endif //HSE_HUFFMAN_CPP_COMPRESS_H
#include <stddef.h>

#include <typeinfo>
#include <typeindex>
#include <tuple>
#include <exception>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <random>
#include <iostream>
#include <sstream>

void huffmanCodes(std::vector<char> characters, std::vector<int> freq, int size);
std::unordered_map<char, int> stringToDict(std::string input_str);
void dictToArray(std::unordered_map<char, int> dict, std::vector<char>& keys, std::vector<int>& values);