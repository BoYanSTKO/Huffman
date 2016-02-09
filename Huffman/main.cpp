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
//    Preprocess test;
//    test.readFile();
//    cout << (' '-'a') << endl;
//    cout << char('a' + 1) << endl;
    
    int fArray[27]= {2,1,4,22,9,6,11,25};
    MinHeap mh = *new MinHeap(fArray);
    mh.buildHeap();
    mh.print();
    mh.deleteMin();
    mh.print();
    MinHeapNode newNode = {'k', 3};
    mh.insert(newNode);
    mh.print();
    
    
    
    return 0;
}
