//
//  Preprocess.cpp
//  Huffman
//
//  Created by Bo Yan on 2/8/16.
//  Copyright © 2016 Bo_Yiting. All rights reserved.
//

#define NUM_CHAR 27     // The total number of characters that would accept 
                        //   (for this project: a-z & space)

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#include "Preprocess.h"

using namespace std;


Preprocess::Preprocess()
// constructor of Preprocess; initalize the variables
{
    for(int i=0; i<NUM_CHAR; i++) // intialize the freqArray to all 0
    {
        this->freqArray[i] = 0;
    }
    this->inputStr = "";   
}


void Preprocess::readFile(string filePath) 
// Read string from the file located at the filePath and store it into member variable inputStr
{
    std::ifstream in(filePath.c_str());
    std::string contents((std::istreambuf_iterator<char>(in)),
                         std::istreambuf_iterator<char>());
    this->inputStr = contents.c_str();
}


void Preprocess::countFreq() {
    for (int i = 0; i < inputStr.size(); i++) {
        //cout << this->inputStr[i] << endl;
        // lower letters
        if((inputStr[i] - 'a') >= 0 && (inputStr[i] - 'a') <= 25)  // a-z
        {
            this->freqArray[(inputStr[i] - 'a')]++;
        }        
        else if(inputStr[i] == ' ')     // space
        {
            this->freqArray[26]++;
        }
        else
        { 
            // other symbols including line feeding
            inputStr.erase(i);  // get rid of this symbol
            i--;
        }        
    }
}


int* Preprocess::getFreqArray() {
    return this->freqArray;
}


string Preprocess::getInputStr()
{
    return this->inputStr;
}


void Preprocess::readDecodeFile() {
    std::ifstream in("./encoded.input");
    std::string contents((std::istreambuf_iterator<char>(in)),
                         std::istreambuf_iterator<char>());
    decodeStr = contents.c_str();

    // makesure only read in 0 and 1
    for (int i = 0; i < decodeStr.size(); i++)
    {
        if(decodeStr[i] != '0' && decodeStr[i] != '1')
        {
            // other symbols including line feeding
            decodeStr.erase(i);  // get rid of this symbol
            i--;
        }
    }
}


string Preprocess::getDecodeStr() {
    return decodeStr;
}


Preprocess::~Preprocess() {
    
}
