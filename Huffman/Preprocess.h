//
//  Preprocess.h
//  Huffman
//
//  Created by Bo Yan on 2/8/16.
//  Copyright © 2016 Bo_Yiting. All rights reserved.
//

#ifndef Preprocess_h
#define Preprocess_h
#include <string>
//struct MinHeapNode {
//    char character;
//    int freq;
//};

class Preprocess {
private:	
    std::string inputStr;
    std::string decodeStr;
    int freqArray[27]; // default value 0
//    MinHeapNode 
public:
    Preprocess();
    void readFile();
    void readDecodeFile();
    void countFreq();
    std::string getDecodeStr();
    int* getFreqArray();
    ~Preprocess();
};


#endif /* Preprocess_h */
