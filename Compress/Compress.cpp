#include "Compress.h"
#define MAX_TREE_HT 256
#include <bits/stdc++.h>   //  includes every standard library and STL include file

struct minHeapNode  // a struct of a node of the minimum heap
{
    char character;
    int frequency;

    // pointers to the ancestors of the current node
    minHeapNode *left;
    minHeapNode *right;

    // initializing a node in our minimum heap
    minHeapNode(char symbol, int occurence)
    {
        right = NULL;
        left = NULL;
        this->character = symbol;
        this->frequency = occurence;
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