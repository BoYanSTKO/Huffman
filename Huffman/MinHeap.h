//
//  MinHeap.h
//  Huffman
//
//  Created by Bo Yan on 2/8/16.
//  Copyright © 2016 Bo_Yiting. All rights reserved.
//

#ifndef MinHeap_h
#define MinHeap_h
#define SizeOfFreqArray 27
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
};

class MinHeap {

private:
    int heapSize;
    MinHeapNode* nodeArray;
    
public:
    MinHeap(int* freqArray);
    ~MinHeap();
    void buildHeap();
    void percolateDown();
    void percolateUp();
    void deleteMin();
    int getHeapSize();
    void print();
    
};

#endif /* MinHeap_h */
