//
//  MinHeap.h
//  Huffman
//
//  Created by Bo Yan on 2/8/16.
//  Copyright © 2016 Bo_Yiting. All rights reserved.
//
#include <string>
using namespace std;
#ifndef MinHeap_h
#define MinHeap_h
#define SizeOfFreqArray 27
#define FNodeChar '1'
#define FNodeFreq -100
#define INodeChar '2'
//class MinHeapNode {
//private:
//    char character;
//    int freq;
//public:
//    MinHeapNode();
//    ~MinHeapNode();
//    int getFreq();
//};

struct MinHeapNode {
    char character;
    int freq;
    struct MinHeapNode* left;
    struct MinHeapNode* right;
};

struct huffmanMap{
    char character;
    string huffmanCode;
};


class MinHeap {

private:
    int heapSize;
    MinHeapNode** nodeArray;
    huffmanMap** hMap;
    int hMapCounter;
    MinHeapNode* minItem;
    string int_array_to_string(int int_array[], int size_of_array);
    
public:
    MinHeap(int* freqArray);
    ~MinHeap();
    void buildHeap();
    void percolateDown(int i);
//    void percolateUp();
    void insert(MinHeapNode* newNode);
    void deleteMin();
    void constructTrie();
    void huffmanEncode(MinHeapNode* root, int arr[], int top);
    MinHeapNode* getMinItem();
//    int getHeapSize();
    void printMinHeap();
    void printCode();
    MinHeapNode* getRootNode();
    
};

#endif /* MinHeap_h */
