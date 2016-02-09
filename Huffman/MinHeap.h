//
//  MinHeap.h
//  Huffman
//
//  Created by Bo Yan on 2/8/16.
//  Copyright © 2016 Bo_Yiting. All rights reserved.
//

#ifndef MinHeap_h
#define MinHeap_h
struct MinHeapNode {
    char character;
    int freq;
};

class MinHeap {
    int heapSize;
    MinHeapNode* nodeArray;
    
public:
    MinHeap();
    ~MinHeap();
    
};

#endif /* MinHeap_h */
