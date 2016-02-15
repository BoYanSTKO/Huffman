//
//  Preprocess.h
//  Huffman
//
//  Created by Bo Yan on 2/8/16.
//  Copyright © 2016 Bo_Yiting. All rights reserved.
//

#ifndef Preprocess_h
#define Preprocess_h

#define NUM_CHAR 27		// The total number of characters that would accept 
						//   (for this project: a-z & space)

#include <string>

using namespace std;


class Preprocess
{
private:	
    string inputStr;	// string get from the input file which is going
    						//	 to build huffman tree and get encoded
    int freqArray[NUM_CHAR];	// frequency of all characters
    
    string decodeStr; // store decode string

public:
    Preprocess();
    // Constructor of Preprocess; initalize the variables
    void readFile(string filePath);
    // Read string from the file located at the filePath and store it into member variable inputStr
    void countFreq();
    void readDecodeFile(); // read decode files
    string getDecodeStr(); // get decode string
    int* getFreqArray();
    string getInputStr();
    ~Preprocess();
};


#endif /* Preprocess_h */
