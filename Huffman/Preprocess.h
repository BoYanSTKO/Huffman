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
class Preprocess {
    std::string inputStr;
    int freqArray[27] = {}; // default value 0
public:
    Preprocess();
    void readFile();
    void countFreq();
    int* getFreqArray();
    ~Preprocess();
};


#endif /* Preprocess_h */
