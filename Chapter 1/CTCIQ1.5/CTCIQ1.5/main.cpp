//
//  main.cpp
//  CTCIQ1.5
//
//  Created by Brian Corson on 6/7/16.
//  Copyright © 2016 Brian Corson. All rights reserved.
//
//  Implement a method to perform basic string compression using the counts of repeated character
//  aabcccccaaa -> a2b1c5a3
#include <iostream>

using namespace std;

string strCompression(string str){
    if(str.length() <= 2){
        return str;
    }
    char currentChar = str[0];
    int charCount = 1;
    char newStr[str.length()];
    int newStrIter = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i + 1] != currentChar){
            newStr[newStrIter++] = currentChar;
            newStr[newStrIter++] = charCount + 48;
            currentChar = str[i + 1];
            charCount = 1;
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
    cout << strCompression("aabcccccaaa") << endl;
    cout << strCompression("abc") << endl;
    return 0;
}
