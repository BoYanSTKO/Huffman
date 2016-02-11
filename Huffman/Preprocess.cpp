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
//using namespace std;

Preprocess::Preprocess() {
    for(int i=0; i<27; i++)
    {
        freqArray[i] = 0;
    }
    
}

void Preprocess::readFile() {
    std::ifstream in("/Users/boyan/Dropbox/UCSB_Class/CS130A/PJ2/Huffman/Huffman/plain.input");
    std::string contents((std::istreambuf_iterator<char>(in)),
                         std::istreambuf_iterator<char>());
//    std::cout << contents.c_str() << std::endl;
    inputStr = contents.c_str();
    //std::cout << inputStr << std::endl;
}
void Preprocess::countFreq() {
    for (int i = 0; i < inputStr.size(); i++) {   //-1 for not counting the ending symbol
//        cout << inputStr[i] << endl;
        // lower letters
        if((inputStr[i] - 'a') >= 0) {
            freqArray[(inputStr[i] - 'a')]++;
//            cout << "aaa" << endl;
        }
        // space
        else {
            freqArray[26]++;
//            cout << "bbb" << endl;
        }
        
    }
//    return freqArray;
}

void Preprocess::readDecodeFile() {
    std::ifstream in("/Users/boyan/Dropbox/UCSB_Class/CS130A/PJ2/Huffman/Huffman/encoded.input");
    std::string contents((std::istreambuf_iterator<char>(in)),
                         std::istreambuf_iterator<char>());
//        std::cout << contents.c_str() << std::endl;
    decodeStr = contents.c_str();
//    std::cout << decodeStr[1]<< std::endl;
}
int* Preprocess::getFreqArray() {
    return freqArray;
}

std::string Preprocess::getDecodeStr() {
    return decodeStr;
}


Preprocess::~Preprocess() {
    
}
