//
//  MinHeap.cpp
//  Huffman
//
//  Created by Bo Yan on 2/8/16.
//  Copyright © 2016 Bo_Yiting. All rights reserved.
//
 
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string> // this should be already included in <sstream>
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


    // Initialize hMap
    //hMap = new huffmanMap[heapSize]();
    hMap = new huffmanMap[heapSize];
    for(int i=0; i<heapSize; i++)       // Initialize with placeholders
    {
        hMap[i].character = '9';    
        hMap[i].huffmanCode = "code";
    }


    hMapCounter = 0;    
}


MinHeap::~MinHeap() {
    int nodeArraySize = (sizeof((nodeArray))/sizeof((nodeArray[0])));
    for (int i = 0; i < nodeArraySize; i++) { // only free inside if dynamically allocated - not if just storing pointers
        delete nodeArray[i];
        nodeArray[i] = NULL;
    }
    delete [] nodeArray;

    int hMapSize = (sizeof((hMap))/sizeof((hMap[0])));
    // for (int i = 0; i < hMapSize; i++) { // only free inside if dynamically allocated - not if just storing pointers
    //     delete hMap[i];
    //     hMap[i] = NULL;
    // }
    delete [] hMap;
    // delete [] minItem;

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
    int oldNodeArraySize = (sizeof((oldNodeArray))/sizeof((oldNodeArray[0])));
    minItem = oldNodeArray[1];
//    cout << (sizeof(nodeArray)) << " size" << endl;
    // cout << nodeArray[heapSize+1]->character << endl;
    // cout << oldNodeArray[heapSize+1]->character << endl;
//    cout << oldNodeArray[1]->freq << endl;
    
    nodeArray = new MinHeapNode*[heapSize + 1];
    
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
            //delete oldNodeArray[i];
        }
        // percolate down from root
        percolateDown(1);
    }

    for (int i = 0; i < oldNodeArraySize; i++) { // only free inside if dynamically allocated - not if just storing pointers
        delete oldNodeArray[i];
        oldNodeArray[i] = NULL;
    }
    delete [] oldNodeArray;
    //cout << "Min item freq: " << minItem->freq << endl;
//    return minNode;
}

void MinHeap::insert(MinHeapNode* newNode) {
    heapSize++;
    MinHeapNode** oldNodeArray = nodeArray;
    int oldNodeArraySize = (sizeof((oldNodeArray))/sizeof((oldNodeArray[0])));
    nodeArray = new MinHeapNode*[heapSize + 1];

    MinHeapNode* firstNode = new MinHeapNode();
    firstNode->character = FNodeChar;
    firstNode->freq = FNodeFreq;
    firstNode->left = NULL;
    firstNode->right = NULL;
    //*firstNode = {FNodeChar, FNodeFreq, NULL, NULL};
    nodeArray[0] = firstNode;
    
    cout << "insert" << endl;
    for (int i = 1; i < heapSize; i++) {
        nodeArray[i] = oldNodeArray[i];

        //cout << nodeArray[i]->character << ": " << nodeArray[i]->freq << endl;
    }
    nodeArray[heapSize] = newNode;
    int i = heapSize;
    int parent;
    for (; i != 0 && newNode->freq < nodeArray[i/2]->freq; i = parent) {
        parent = i / 2;
        MinHeapNode* tmp = nodeArray[parent];
        nodeArray[parent] = newNode;
        nodeArray[i] = tmp;
    }

    for (int i = 0; i < oldNodeArraySize; i++) { // only free inside if dynamically allocated - not if just storing pointers
        delete oldNodeArray[i];
        oldNodeArray[i] = NULL;
    }

    delete [] oldNodeArray;
//    cout << &nodeArray[1] << endl;

    cout << endl;
    for(int i=0; i<heapSize + 1; i++)
    {
        cout << nodeArray[i]->character << ": " << nodeArray[i]->freq << endl;
    }
    cout << endl;

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

        cout << internalN->left->character << endl;
        insert(internalN);
//        cout << nodeArray[1].left->character << endl;
    }
    cout << "trie done" << endl;
    cout << nodeArray[1]->character << ": " << nodeArray[1]->freq << endl;
    cout << nodeArray[1]->left->character << ": " << nodeArray[1]->left->freq << endl;
    cout << nodeArray[1]->right->character << ": " << nodeArray[1]->right->freq << endl;

    // hMap = new huffmanMap*[heapSize];

}

void MinHeap::huffmanEncode(MinHeapNode* root, int arr[], int top) {
    MinHeapNode* rootPtr = this->nodeArray[1];
    if(root != NULL)
    {
        // cout << "right: " << root->right->character << " (" << root->right->freq << ")" << endl;
        // cout << "left: " << root->left->character << " (" << root->left->freq << ")" << endl;

        //cout << "root: " << root->character << " (" << root->freq << ")" << endl;
        cout << "level: " << top << endl;
        if (root->left != NULL)
        {
            cout << "left: " << root->left->character << " (" << root->left->freq << ")" << endl;
            arr[top] = 1;
            huffmanEncode(root->left, arr, top+1);
        }
        cout << "after left level: " << top << endl;
        cout << "root: " << getRootNode()->character << " (" << getRootNode()->freq << ")" << endl;
        //printTrie(getRootNode());
        if(root->right != NULL)
        {
            cout << "right: " << root->right->character << " (" << root->right->freq << ")" << endl;
            arr[top] = 0;
            huffmanEncode(root->right, arr, top+1);
        }

        if(root->left == NULL && root->right == NULL)
        {
            cout << "3" << endl;
            huffmanMap tempHMap;
            tempHMap.character = root->character;
            tempHMap.huffmanCode = int_array_to_string(arr, top);
            // //huffmanMap tempHMap = {root->character, int_array_to_string(arr, top)};
            cout << "leaf: " << tempHMap.character << " (" << tempHMap.huffmanCode << ")" << endl;
            cout << endl;
            hMap[hMapCounter] = tempHMap;
            hMapCounter++;
            cout << "hMapCounter: " << hMapCounter << endl;
        }
        cout << "end level: " << top << endl;
        
    }
    cout << "the ultimate root is " << rootPtr->character << " (" << rootPtr->freq << ")" << endl;

}


string MinHeap::encodeStr(string str)
// Encode the str into huffman code based on the hMap; return with a string of huffman codes
{
    string code = "";    // the huffman code which was derived from string based on the Min Heap
    for (int i = 0; i < str.size(); i++)
    {
        // lowercase letters
        char tempChar = str[i];
        if(((tempChar - 'a') >= 0 && (tempChar - 'a') <= 25) || tempChar == ' ')   // a-z or space ' '
        {
            string tempCharCode = "";
            int tempCounter = 0;
            while(tempCharCode == "")
            {
                if(this->hMap[tempCounter].character == tempChar)
                {
                    tempCharCode = this->hMap[tempCounter].huffmanCode;
                }
                else
                {
                    tempCounter++;
                    if(tempCounter >= hMapCounter)
                    {
                        cout << "Warning: the string that is being encoded is not in the hMap.." << endl;
                        break;
                    }
                }
            }
            code += tempCharCode;
        }
        else
        {
            // other symbols including line feeding
            cout << "Warning: other symbol occurs..." << endl;
        }
    }
    cout << "The huffman code for " << str << " is " << code << endl;
    return code;
}


void MinHeap::printMinHeap(){
    for(int i=1; i<heapSize + 1; i++)
    {
        cout << nodeArray[i]->character << ": " << nodeArray[i]->freq << endl;
    }
}


void MinHeap::printTrie(MinHeapNode* root){
    if(root != NULL)
    {
        cout << root->character << " (" << root->freq << ")" << endl;
        if(root->left != NULL)
        {
            printTrie(root->left);
        }
        if(root->right != NULL)
        {
            printTrie(root->right);
        }
    }
}


void MinHeap::printCode(){
    for(int i=0; i<hMapCounter; i++)
    {
        cout << hMap[i].character << ": " << hMap[i].huffmanCode << endl;
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
    string tempString;
    for (int temp = 0; temp < size_of_array; temp++)
    {
        ostringstream convert;   // stream used for the conversion
        convert << int_array[temp];      // insert the textual representation of 'Number' in the characters in the stream
        tempString = convert.str();
        returnstring += tempString;
    }
    cout << "to String: " << returnstring << endl;
    return returnstring;
}


