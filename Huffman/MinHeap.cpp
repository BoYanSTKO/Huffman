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

MinHeap::MinHeap(int* freqArray)
// Constructor for MinHeap: initialize Minheap with data in freqArray
{
    heapSize = 0;
    
    //nodeArray = new MinHeapNode[SizeOfFreqArray]();
    
    // Count the heap size
    for (int i = 0; i < SizeOfFreqArray; i++) 
    {
        if (freqArray[i] != 0) 
        {
            heapSize++;
        }
    }

    cout << "HeapSize:" << heapSize << endl;;
    
    // Declare the Min Heap
    nodeArray = new MinHeapNode*[heapSize+1]();
    
    // Declare and initialize the first node (no real data, just a placeholder)
    MinHeapNode* firstNode = new MinHeapNode();
    firstNode->character = FNodeChar;
    firstNode->freq = FNodeFreq;
    firstNode->left = NULL;
    firstNode->right = NULL;
    nodeArray[0] = firstNode;
    
    // Declare and initialize the rest nodes
    int tempCounter = 1;
    for (int i=0; i < SizeOfFreqArray; i++) 
    {        
        if(freqArray[i] != 0)
        {
            MinHeapNode* heapNode = new MinHeapNode();
            if(i == SizeOfFreqArray-1)  // space character
            {
                heapNode->character = char(' ');
                heapNode->freq = freqArray[i];
                heapNode->left = NULL;
                heapNode->right = NULL;
                //*heapNode = {char(' '), freqArray[i], NULL, NULL};
            }
            else
            {
                heapNode->character = char('a' + i);
                heapNode->freq = freqArray[i];
                heapNode->left = NULL;
                heapNode->right = NULL;
                //*heapNode = {char('a' + (i)), freqArray[i], NULL, NULL};
            }            
            nodeArray[tempCounter] = heapNode;
            tempCounter++;
        }        
    }
    minItem = NULL;
    
    hMap = new huffmanMap[heapSize]();
    hMapCounter = 0;    
}


MinHeap::~MinHeap() {
    
}



void MinHeap::buildHeap()
{
    for (int i = heapSize/2; i > 0; i--) // i=1 is refering to the root
    {
        percolateDown(i);
    }
    minItem = nodeArray[1];
}


void MinHeap::percolateDown(int i)
// Ensure the invariant of min heap for node at i and its children
{
    int child = 0;
    MinHeapNode* tmp = nodeArray[i];
    for (;i * 2 <= heapSize; i = child) {
        child = i * 2;
        if (child != heapSize && nodeArray[child + 1]->freq <= nodeArray[child]->freq) {
            child = child + 1;
        }

        if (nodeArray[child]->freq < tmp->freq) {
            nodeArray[i] = nodeArray[child];
            nodeArray[child] = tmp;
        }
        else{
            break;
        }
    }
}

//
void MinHeap::deleteMin() {
//**** need to check heapSize 1 & 0 ****
    // Case of no element in the heap
    if(heapSize == 0)
    {
        cout << "The heap has no element" << endl;
        return;
    }

    // resize the heap and remove the min
    // cout << heapSize << " before deleteMin" << endl;
    heapSize = heapSize - 1;
    // cout << heapSize << " after deleteMin" << endl;
//    cout << nodeArray[5]->character << " character " << endl;
    MinHeapNode** oldNodeArray = nodeArray;
    minItem = oldNodeArray[1];
//    cout << (sizeof(nodeArray)) << " size" << endl;
    // cout << nodeArray[heapSize+1]->character << endl;
    // cout << oldNodeArray[heapSize+1]->character << endl;
//    cout << oldNodeArray[1]->freq << endl;
    
    nodeArray = new MinHeapNode*[heapSize + 1]();
    
    MinHeapNode* firstNode = new MinHeapNode();
    firstNode->character = FNodeChar;
    firstNode->freq = FNodeFreq;
    firstNode->left = NULL;
    firstNode->right = NULL;
    //*firstNode = {FNodeChar, FNodeFreq, NULL, NULL};    
    nodeArray[0] = firstNode;

    if (heapSize > 0) {
        // move the last element in the array to the first
        //cout << heapSize << endl;
        nodeArray[1] = oldNodeArray[heapSize + 1];
        //cout << nodeArray[1]->character << endl;
        for (int i = 2; i < heapSize + 1; i++) {
            nodeArray[i] = oldNodeArray[i];
        }
        // percolate down from root
        percolateDown(1);
    }
    
    delete [] oldNodeArray;
    //cout << "Min item freq: " << minItem->freq << endl;
//    return minNode;
}

void MinHeap::insert(MinHeapNode* newNode) {
    heapSize++;
    MinHeapNode** oldNodeArray = nodeArray;
    nodeArray = new MinHeapNode*[heapSize + 1]();

    MinHeapNode* firstNode = new MinHeapNode();
    firstNode->character = FNodeChar;
    firstNode->freq = FNodeFreq;
    firstNode->left = NULL;
    firstNode->right = NULL;
    //*firstNode = {FNodeChar, FNodeFreq, NULL, NULL};
    nodeArray[0] = firstNode;
    
    for (int i = 1; i < heapSize; i++) {
        nodeArray[i] = oldNodeArray[i];
    }
//    nodeArray[heapSize] = newNode;
    int i = heapSize;
    int parent;
    for (; i != 0 && newNode->freq < nodeArray[i/2]->freq; i = parent) {
        parent = i / 2;
        MinHeapNode* tmp = nodeArray[parent];
        nodeArray[parent] = newNode;
        nodeArray[i] = tmp;
    }
    delete [] oldNodeArray;
//    cout << &nodeArray[1] << endl;
}

void MinHeap::constructTrie() {
    while (heapSize > 1) {
        deleteMin();
        cout << " 1st" << endl;
        cout << minItem->freq << endl;
        MinHeapNode* rightN = minItem;
        cout << rightN->character << ": " << rightN->freq <<endl;
//        *rightN = {minItem->character, minItem->freq, minItem->left, minItem->right};
        deleteMin();
        cout << " 2nd" << endl;
        MinHeapNode* leftN = minItem;
//        *leftN = {minItem->character, minItem->freq, minItem->left, minItem->right};
        int internalNFreq = rightN->freq + leftN->freq;

        MinHeapNode* internalN = new MinHeapNode();
        internalN->character = INodeChar;
        internalN->freq = internalNFreq;
        internalN->left = leftN;
        internalN->right = rightN;
        //*internalN = {INodeChar, internalNFreq, leftN, rightN};

//        cout << internalN.left->character << endl;
        insert(internalN);
//        cout << nodeArray[1].left->character << endl;
    }
    cout << "trie" << endl;
    cout << nodeArray[1]->left->character << ": " << nodeArray[1]->freq << endl;
}

void MinHeap::huffmanEncode(MinHeapNode* root, int arr[], int top) {
    
    if (root->left != NULL) {
        cout << "!!!" << endl;
        arr[top] = 1;
        huffmanEncode(root->left, arr, top+1);
    }
    if(root-> right != NULL)
    {
        cout << "@@@@" << endl;
        arr[top] = 0;
        huffmanEncode(root->right, arr, top+1);
    }
    
    if(root->left == NULL && root->right == NULL)
    {
        huffmanMap tempHMap = {root->character, int_array_to_string(arr, top)};
        cout << tempHMap.character<< endl;
        hMap[hMapCounter] = tempHMap;
        hMapCounter++;
    }
}

void MinHeap::printMinHeap(){
    for(int i=1; i<heapSize + 1; i++)
    {
        cout << nodeArray[i]->character << ": " << nodeArray[i]->freq << endl;
    }
}

void MinHeap::printCode(){
    for(int i=0; i<hMapCounter; i++)
    {
        cout << hMap->character << ": " << hMap->huffmanCode << endl;
    }
    
    
}

MinHeapNode* MinHeap::getRootNode(){
    return (this->nodeArray)[1];
}

MinHeapNode* MinHeap::getMinItem() {
    return minItem;
}


string MinHeap::int_array_to_string(int int_array[], int size_of_array) {
    string returnstring = "";
    for (int temp = 0; temp < size_of_array; temp++)
        returnstring + char(int_array[temp]);
    return returnstring;
}


