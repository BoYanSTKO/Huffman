# Huffman
Project 2 for CS130A


Huffman encoding algorithm is used to compress files based on the frequency of individual letters in these files. The idea is that we can use different number of bits to represent characters in a file based on their frequencies (i.e. using fewer bits to represent the more frequent characters than the least frequent ones). The general idea behind Huffman encoding is to allow a variable code length for different characters such that the most frequent character is encoded with the shortest code and vice versa. If all the characters occur with the same frequency, saving is more unlike.
In order to do the encoding, we must do the following steps:
1. Count frequencies: in this step, we count the frequency of each character in the file.
2. Construct the encoding tree: in this step, we represent the frequencies found in step 1 in the form of tree where characters are represented by leaves of the tree. For more details about the construction of the tree, check Huffmans Algorithm section on page 456 on the textbook.
3. Construct the encoding map: by traversing the tree constructed in step 2, we can know the code of every character and construct a map.
4. Encode File Characters: in this step, we represent every character with its binary code and save that in the output file.
