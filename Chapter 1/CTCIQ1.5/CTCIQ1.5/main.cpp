//
//  main.cpp
//  CTCIQ1.5
//
//  Created by Brian Corson on 6/7/16.
//  Copyright © 2016 Brian Corson. All rights reserved.
//
//  Implement a method to perform basic string compression using the counts of repeated character
//  If the compressed string is larger than the old one, return the old one
//  aabcccccaaa -> a2b1c5a3
#include <iostream>

using namespace std;

string strCompression(string str){
    if(str.length() <= 2){//when string is 2 letters or smaller, avoid stepping in algorithm
        return str;//old string will be smaller
    }
    char currentChar = str[0];
    int charCount = 1;
    char newStr[str.length()];
    int newStrIter = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i + 1] != currentChar){
            newStr[newStrIter++] = currentChar;//store char in new string, increment the iterator
            newStr[newStrIter++] = charCount + 48;
            // convert char to correct ascii figure in dec and store in new string and increment iterator
            currentChar = str[i + 1];//update current char with next char
            charCount = 1;//update char counter
        }
        else{
            charCount++;
        }
    }
    if(str.length() <= newStrIter){
        return str;
    }
    return newStr;
}
int main(int argc, const char * argv[]) {
    cout << strCompression("aabcccccaaa") << endl;//expect: a2b1c5a3
    cout << strCompression("ab") << endl; //expect:ab
    return 0;
}
/* Output:
 a2b1c5a3
 ab
*/