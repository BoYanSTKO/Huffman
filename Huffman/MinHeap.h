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
    struct huffmanMap * hMap;
    int hMapCounter;
    MinHeapNode* minItem;    
    string decodedText;
    string int_array_to_string(int int_array[], int size_of_array);

public:
    MinHeap(int* freqArray);    
    void buildHeap();
    void percolateDown(int i);
    void insert(MinHeapNode* newNode);
    void deleteMin();
    void constructTrie();
    void huffmanEncode(MinHeapNode* root, int arr[], int top);
    string encodeStr(string str);
    MinHeapNode* getMinItem();
    void printMinHeap();
    void printCode();
    MinHeapNode* getRootNode();
    void printTrie(MinHeapNode* root);
    void huffmanDecode(MinHeapNode* root, string decodeStr, int pos);
    string getDecodedText();
    ~MinHeap();
};

#endif /* MinHeap_h */
