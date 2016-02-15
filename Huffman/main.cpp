//
//  main.cpp
//  Huffman
//
//  Created by Bo Yan on 2/2/16.
//  Copyright © 2016 Bo_Yiting. All rights reserved.
//

#include <iostream>
#include <string>
#include "Preprocess.h"
#include "MinHeap.h"

using namespace std;
int main(int argc, const char * argv[]) {

    string inputFilePath = "/Users/boyan/Dropbox/UCSB_Class/CS130A/PJ2/Huffman/Huffman/plain.input";


    Preprocess test;
    test.readFile(inputFilePath);
    test.countFreq();
//    int fArray[27]= {1,0,0,0,2,0,0,0,2,0,1,2,0,0,0,2,0,0,1,0,0,0,0,0,0,0,2};
    MinHeap mh = *new MinHeap(test.getFreqArray());
    mh.buildHeap();
    mh.printMinHeap();
    cout << endl;
    mh.constructTrie();
    cout << endl;
    mh.printTrie(mh.getRootNode());
    cout << endl;
    int temArray[30];
    mh.huffmanEncode(mh.getRootNode(), temArray, 0);
    mh.printTrie(mh.getRootNode());
    cout << endl;

    mh.printCode();
    cout << endl;

    mh.encodeStr(test.getInputStr());
    
    cout << "DECODE" << endl;
    test.readDecodeFile();
    string decodeStr = test.getDecodeStr();
    mh.huffmanDecode(mh.getRootNode(), decodeStr, 0);
    cout << "decode results: " << endl;
    cout << mh.getDecodedText() << endl;

//    cout << (' '-'a') << endl;
//    cout << char('a' + 1) << endl;
    

    /*
    int fArray[27]= {1,0,0,0,2,0,0,0,2,0,1,2,0,0,0,2,0,0,1,0,0,0,0,0,0,0,2};
    // exactly as shown in the lab instruction
    MinHeap mh = *new MinHeap(fArray);
    mh.buildHeap();
    mh.printMinHeap();
    cout << endl;
    mh.deleteMin();
    mh.printMinHeap();
    cout << endl;
    mh.deleteMin();
    mh.printMinHeap();
    cout << endl;
    mh.deleteMin();
    mh.printMinHeap();
    cout << endl;
    MinHeapNode newNode = {'b', 3, NULL, NULL};
    mh.insert(&newNode);
    mh.printMinHeap();
    
    
    
    cout << endl;
    mh.constructTrie();
    mh.huffmanEncode(mh.getRootNode(), new int[30], 0);
    mh.printCode();
    */
    
    return 0;
}
