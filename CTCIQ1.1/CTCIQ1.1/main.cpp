//
//  main.cpp
//  CTCIQ1.1
//
//  Created by Brian Corson on 6/5/16.
//
//1.1 - Implement an algorithm to determine if a string has all unique characters
//Assumes string has ASCII characters
#include <iostream>

using namespace std;

bool isUniqueCharacters(string str){
    if(str.length() > 256){
        return 0;
    }
    bool anArray [256] = {0};//128 unique ASCII characters
    for(int i = 0; i < str.length(); i++){
        int val = str[i];
        if(anArray[val]){
            return 0;
        }
        anArray[val] = 1;
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    string str[] ={"littlemissdismisscan'tmisslikeadetunedradio", "abcdefg"};//Expect: 0,1
    
    for (int i = 0; i < 2; i++)
    {
        cout << str[i] << " is unique? " << isUniqueCharacters(str[i]) << endl;//Actual: 0,1
    }
    return 0;
}
