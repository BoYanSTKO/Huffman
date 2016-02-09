//
//  MinHeap.cpp
//  Huffman
//
//  Created by Bo Yan on 2/8/16.
//  Copyright © 2016 Bo_Yiting. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "MinHeap.h"
using namespace std;


//int MinHeapNode::getFreq() {
//    return freq;
//}

// initialize minheap
MinHeap::MinHeap(int* freqArray) {
    heapSize = 0;
//    nodeArray = new MinHeapNode[SizeOfFreqArray]();
    for (int i = 0; i < SizeOfFreqArray; i++) {
        if (freqArray[i] != 0) {
            heapSize++;
        }
    }
    
    nodeArray = new MinHeapNode[heapSize+1]();
    MinHeapNode firstNode = {-1, -100};
    nodeArray[0] = firstNode;
    int tempCounter = 1;
    for (int i = 0; i < SizeOfFreqArray; i++) {
        
        if(freqArray[i] != 0)
        {
            MinHeapNode heapNode;
            if(i == SizeOfFreqArray-1)
            {
                heapNode = {char(' '), freqArray[i]};
            }
            else
            {
                heapNode = {char('a' + (i)), freqArray[i]};
            }
            
            nodeArray[tempCounter] = heapNode;
            tempCounter++;
        }
        
    }
    
}

MinHeap::~MinHeap() {
    
}

void MinHeap::percolateDown(int i) {
    int child = 0;
    MinHeapNode tmp = nodeArray[i];
    for (;i * 2 <= heapSize; i = child) {
        child = i * 2;
        if (child != heapSize && nodeArray[child + 1].freq <= nodeArray[child].freq) {
            child = child + 1;
        }
        if (nodeArray[child].freq < tmp.freq) {
            nodeArray[i] = nodeArray[child];
        }
        else {
            break;
        }
    }
    nodeArray[child] = tmp;
    
}

void MinHeap::buildHeap() {
    for (int i = heapSize/2; i > 0; i--) {
        percolateDown(i);
    }
}

//void MinHeap::print(){
//    for(int i=1; i<heapSize + 1; i++)
//    {
//        cout << nodeArray[i].character << ": " << nodeArray[i].freq << endl;
//    }
//}
