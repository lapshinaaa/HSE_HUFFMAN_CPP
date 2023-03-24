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

void gettingHuffmanCodes (struct minHeapNode *root, std::string encodedLine)
{
    if (!root) return; // if there's no root of the tree

    if (root -> character != '&') // an ampersand sign represents an internal node (sum of the two ancestors)
    {
        // if it's not an internal node (because there's no character assigned to it): print out the binary code:
        std::cout<<root->character<<": "<<encodedLine<<'\n';
    }

    gettingHuffmanCodes(root -> left, encodedLine + "0");
    gettingHuffmanCodes(root -> right, encodedLine + "1");
}

// The function that builds a Huffman Tree and print it
void huffmanCodes(std::vector<char> characters, std::vector<int> freq, int size)
{
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
    gettingHuffmanCodes(minHeap.top(), "");
}