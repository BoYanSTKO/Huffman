//
//  main.cpp
//  Huffman
//
//  Created by Bo Yan on 2/2/16.
//  Copyright © 2016 Bo_Yiting. All rights reserved.
//

#include <iostream>
#include "Preprocess.h"
#include "MinHeap.h"

using namespace std;
int main(int argc, const char * argv[]) {
    Preprocess test;
    test.readDecodeFile();
    test.readFile();
    test.countFreq();
    string decodeStr = test.getDecodeStr();
    cout << decodeStr << endl;
    MinHeap mh = *new MinHeap(test.getFreqArray());
    mh.buildHeap();
    mh.printMinHeap();
    cout << endl;
    mh.constructTrie();
    mh.huffmanEncode(mh.getRootNode(), new int[30], 0);
    cout << "pppppppppp" << endl;
    mh.printCode();
    cout << "test here" << endl;
//    mh.huffmanDecode(mh.getRootNode(), decodeStr, 0);
//    cout << " to here" << endl;
//    cout << mh.getDecodedText() << endl;
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
