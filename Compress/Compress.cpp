#include "Compress.h"
#define MAX_TREE_HT 256

struct minHeapNode  // a struct of a node of the minimum heap
{
    char character;
    int frequency;

    // pointers to the ancestors of the current node
    minHeapNode *left;
    minHeapNode *right;

    // initializing a particular node in our minimum heap
    minHeapNode(char character, int frequency)
    {
        right = NULL;
        left = NULL;
        this->character = character;
        this->frequency = frequency;
    }
};

struct comparingNodes
{
    // a function for comparing nodes to build a minimum heap. Works like an object, hence - operator()
    bool operator() (minHeapNode* left_node, minHeapNode* right_node)
    {
        return (left_node->frequency > right_node->frequency); // comparing frequency of the nodes
    }
};

// Function to convert a string to a dictionary, with each character's count as value
std::unordered_map<char, int> stringToDict(std::string input_str)
{
    std::unordered_map<char, int> dict;
    for (char& c : input_str) {
        dict[c]++;
    }
    return dict;
}

// Function to create two arrays from the dictionary - one with keys (characters) and one with values (counts)
void dictToArray(std::unordered_map<char, int> dict, std::vector<char>& keys, std::vector<int>& values) {
    std::vector<std::pair<char, int>> sorted_dict(dict.begin(), dict.end());
    std::sort(sorted_dict.begin(), sorted_dict.end(), [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
        return a.second < b.second;
    });

    for (auto& pair : sorted_dict) {
        keys.push_back(pair.first);
        values.push_back(pair.second);
    }
}

// The function that builds a Huffman Tree and print it
std::string huffmanCodes(std::vector<char> characters, std::vector<int> freq, int size, std::string input_str)
{
    if (input_str.empty())
    {
        std::cout <<""<< std::endl;
        return "";
    }

    if (size == 1)
    {
        std::cout<<"0"<<std::endl;
        return "";
    }

    // initialize
    struct minHeapNode *left, *right, *top;

    // Create a min heap and inserts all characters
    std::priority_queue<minHeapNode*, std::vector<minHeapNode*>,comparingNodes> minHeap;

    for (int i = 0; i < size; ++i)
    {
        minHeap.push(new minHeapNode(characters[i], freq[i]));
    }

    while (minHeap.size() != 1)
    {
        // get the two least frequent symbols
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();

        // creating new tree branch
        top = new minHeapNode('&', left->frequency + right->frequency);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // get the Huffman codes for each character and print them out
    std::unordered_map<char, std::string> huffmanCodes;

    gettingHuffmanCodes(minHeap.top(), "", huffmanCodes);

    std::string output = "";
    // print the encoded input string using the Huffman codes
    for (char& c : input_str) {
        std::cout << huffmanCodes[c];
        output += huffmanCodes[c];
    }
    std::cout << std::endl;
    return output;
}

void gettingHuffmanCodes (struct minHeapNode *root, std::string encodedLine, std::unordered_map<char, std::string>& huffmanCodes)
{
    if (!root) return; // if there's no root of the tree

    if (root -> character != '&') // an ampersand sign represents an internal node (sum of the two ancestors)
    {
        // if it's not an internal node (because there's no character assigned to it): store the binary code in the map
        huffmanCodes[root->character] = encodedLine;
    }

    gettingHuffmanCodes(root -> left, encodedLine + "0", huffmanCodes);
    gettingHuffmanCodes(root -> right, encodedLine + "1", huffmanCodes);
}
