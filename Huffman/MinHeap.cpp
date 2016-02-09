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
MinHeap::MinHeap(int* freqArray) {
    heapSize = 1;
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

void MinHeap::print(){
    for(int i=1; i<heapSize; i++)
    {
        cout << nodeArray[i].character << ": " << nodeArray[i].freq << endl;
    }
}
