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

    string inputFilePath = "./plain.input";

    Preprocess test;
    test.readFile(inputFilePath);
    test.countFreq();

    MinHeap mh = *new MinHeap(test.getFreqArray());
    mh.buildHeap();
    mh.constructTrie();

    int temArray[30];
    mh.huffmanEncode(mh.getRootNode(), temArray, 0);
    string encodedString = mh.encodeStr(test.getInputStr());
    cout << encodedString << endl;

    test.readDecodeFile();
    string decodeStr = test.getDecodeStr();
    mh.huffmanDecode(mh.getRootNode(), decodeStr, 0);

    cout << mh.getDecodedText() << endl;



    /*
    string inputFilePath = "./plain.input";

    Preprocess test;
    test.readFile(inputFilePath);
    test.countFreq();
    // int fArray[27]= {1,0,0,0,2,0,0,0,2,0,1,2,0,0,0,2,0,0,1,0,0,0,0,0,0,0,2};
    MinHeap mh = *new MinHeap(test.getFreqArray());
    mh.buildHeap();
    // mh.printMinHeap();
    // cout << endl;
    mh.constructTrie();
    // cout << endl;
    // mh.printTrie(mh.getRootNode());
    // cout << endl;
    int temArray[30];
    mh.huffmanEncode(mh.getRootNode(), temArray, 0);
    // mh.printTrie(mh.getRootNode());
    // cout << endl;

    // mh.printCode();
    // cout << endl;

    mh.encodeStr(test.getInputStr());
    // cout << endl;
    
    // cout << "DECODE" << endl;
    test.readDecodeFile();
    string decodeStr = test.getDecodeStr();
    mh.huffmanDecode(mh.getRootNode(), decodeStr, 0);
    // cout << "decode results: " << endl;
    cout << mh.getDecodedText() << endl;
   */

    return 0;
}
