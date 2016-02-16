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

    // Count the heap size
    for (int i = 0; i < SizeOfFreqArray; i++) 
    {
        if (freqArray[i] != 0) 
        {
            heapSize++;
        }
    }
    // cout << "HeapSize:" << heapSize << endl;;
    
    // Declare the Min Heap
    nodeArray = new MinHeapNode*[heapSize+1]();
    
    // Declare and initialize the first node (no real data, just a placeholder)
    MinHeapNode* firstNode = new MinHeapNode();
    firstNode->character = FNodeChar;
    firstNode->freq = FNodeFreq;
    firstNode->left = NULL;
    firstNode->right = NULL;
    nodeArray[0] = firstNode;
    
    // Declare and initialize the rest nodes; first data stored at index 1
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
            }
            else
            {
                heapNode->character = char('a' + i);
                heapNode->freq = freqArray[i];
                heapNode->left = NULL;
                heapNode->right = NULL;
            }            
            nodeArray[tempCounter] = heapNode;
            tempCounter++;
        }        
    }

    minItem = NULL;

    // Initialize hMap
    hMap = new huffmanMap[heapSize];
    for(int i=0; i<heapSize; i++)       // Initialize with placeholders
    {
        hMap[i].character = '9';    
        hMap[i].huffmanCode = "code";
    }

    // Initialize hMapCounter
    hMapCounter = 0; 

    // Initialize decodedText
    decodedText = "";       
}


MinHeap::~MinHeap()
{
    int nodeArraySize = (sizeof((nodeArray))/sizeof((nodeArray[0])));
    for (int i = 0; i < nodeArraySize; i++) { // only free inside if dynamically allocated - not if just storing pointers
        delete nodeArray[i];
        nodeArray[i] = NULL;
    }
    delete [] nodeArray;

    delete [] hMap;
}


void MinHeap::buildHeap()
{
    for (int i = heapSize/2; i > 0; i--)    // i=1 is refering to the root
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


void MinHeap::deleteMin() {
//**** need to check heapSize 1 & 0 ****
    // Case of no element in the heap
    if(heapSize == 0)
    {
        cout << "The heap has no element" << endl;
        return;
    }

    // Resize the heap and remove the min
    heapSize = heapSize - 1;

    MinHeapNode** oldNodeArray = nodeArray;
    int oldNodeArraySize = (sizeof((oldNodeArray))/sizeof((oldNodeArray[0])));
    minItem = oldNodeArray[1];
    
    nodeArray = new MinHeapNode*[heapSize + 1];
    
    MinHeapNode* firstNode = new MinHeapNode();
    firstNode->character = FNodeChar;
    firstNode->freq = FNodeFreq;
    firstNode->left = NULL;
    firstNode->right = NULL; 

    nodeArray[0] = firstNode;

    if (heapSize > 0) {
        // move the last element in the array to the first
        nodeArray[1] = oldNodeArray[heapSize + 1];

        for (int i = 2; i < heapSize + 1; i++) {
            nodeArray[i] = oldNodeArray[i];
        }
        
        percolateDown(1);   // percolate down from root
    }

    for (int i = 0; i < oldNodeArraySize; i++) 
    { // only free inside if dynamically allocated - not if just storing pointers
        delete oldNodeArray[i];
        oldNodeArray[i] = NULL;
    }
    delete [] oldNodeArray;
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
    nodeArray[0] = firstNode;
    
    for (int i = 1; i < heapSize; i++) {
        nodeArray[i] = oldNodeArray[i];
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

    /*
    for(int i=0; i<heapSize + 1; i++)
    {
        // cout << nodeArray[i]->character << ": " << nodeArray[i]->freq << endl;
    }
    */
}


void MinHeap::constructTrie() {
    while (heapSize > 1) {
        deleteMin();

        MinHeapNode* rightN = minItem;

        deleteMin();

        MinHeapNode* leftN = minItem;

        int internalNFreq = rightN->freq + leftN->freq;

        MinHeapNode* internalN = new MinHeapNode();
        internalN->character = INodeChar;
        internalN->freq = internalNFreq;
        internalN->left = leftN;
        internalN->right = rightN;

        insert(internalN);
    }
}


void MinHeap::huffmanEncode(MinHeapNode* root, int arr[], int top)
{
    MinHeapNode* rootPtr = this->nodeArray[1];

    if(root != NULL)
    {
        if (root->left != NULL)
        {
            arr[top] = 1;
            huffmanEncode(root->left, arr, top+1);
        }

        if(root->right != NULL)
        {
            arr[top] = 0;
            huffmanEncode(root->right, arr, top+1);
        }

        if(root->left == NULL && root->right == NULL)
        {
            huffmanMap tempHMap;
            tempHMap.character = root->character;
            tempHMap.huffmanCode = int_array_to_string(arr, top);

            hMap[hMapCounter] = tempHMap;
            hMapCounter++;
        }        
    }
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
                        cout << "Warning: the character that is being encoded is not in the hMap.." << endl;
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
    // cout << "The huffman code for " << str << " is " << code << endl;
    // cout << code << endl;
    return code;
}


void MinHeap::printMinHeap()
{
    for(int i=1; i<heapSize + 1; i++)
    {
        cout << nodeArray[i]->character << ": " << nodeArray[i]->freq << endl;
    }
}


void MinHeap::printTrie(MinHeapNode* root)
{
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


void MinHeap::printCode()
{
    for(int i=0; i<hMapCounter; i++)
    {
        cout << hMap[i].character << ": " << hMap[i].huffmanCode << endl;
    }
}


void MinHeap::huffmanDecode(MinHeapNode* root, string decodeStr, int pos) {
    if (root != NULL) {
        if ((root->left) == NULL && (root->right) == NULL) {
            decodedText += root->character;
            huffmanDecode((this->nodeArray)[1], decodeStr, pos);
        }
        if (decodeStr[pos] == '1' && pos < decodeStr.length()) {
            huffmanDecode(root->left, decodeStr, pos+1);
        }
        if (decodeStr[pos] == '0' && pos < decodeStr.length()) {
            huffmanDecode(root->right, decodeStr, pos+1);
        }        
    }
}


string MinHeap::getDecodedText() {
    return decodedText;
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
    // cout << "to String: " << returnstring << endl;
    return returnstring;
}


