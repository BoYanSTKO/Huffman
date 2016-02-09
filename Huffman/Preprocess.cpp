//
//  Preprocess.cpp
//  Huffman
//
//  Created by Bo Yan on 2/8/16.
//  Copyright © 2016 Bo_Yiting. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Preprocess.h"

Preprocess::Preprocess() {
    
}

void Preprocess::readFile() {
    std::ifstream in("plain.input");
    std::string contents((std::istreambuf_iterator<char>(in)),
                         std::istreambuf_iterator<char>());
//    std::cout << contents.c_str() << std::endl;
    inputStr = contents.c_str();
//    std::cout << inputStr << std::endl;
}
void Preprocess::countFreq() {
    for (int i = 0; i < inputStr.size(); i++) {
        // lower letters
        if((inputStr[i] - 'a') >= 0) {
            freqArray[(inputStr[i] - 'a')]++;
        }
        // space
        else {
            freqArray[26]++;
        }
        
    }
//    return freqArray;
}
int* Preprocess::getFreqArray() {
    return freqArray;
}


Preprocess::~Preprocess() {
    
}