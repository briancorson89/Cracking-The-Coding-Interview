//
//  main.cpp
//  CTCIQ1.8
//
//  Created by Brian Corson on 6/23/16.
//  Copyright © 2016 Brian Corson. All rights reserved.
//
//  1.8 -- Assume you have a method isSubstring which checks if one word is a substring of another. Given
//  two strings s1 and s2, write code to check if s2 is a rotation of s1 using only one call
//  to isSubstring(e.g. "waterbottle is a rotation of "erbottlewat")
#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string str1, string str2){
    bool found = false;
    if (str1.find(str2) != string::npos) {
        found = true;
    }
    return found;
}

bool isRotation(string str1, string str2){
    bool rotation = false;
    if(str1.length() == str2.length()){
        string str1Twice = str1 + str1;
        rotation = isSubstring(str1Twice, str2);
    }
    return rotation;
}
int main(int argc, const char * argv[]) {
    string str1 = "Hello There";//expect: 1, true
    string str2 = "eHello Ther";
    cout << isRotation(str1, str2) << endl;
    str1 = "Not a";//expect: 0, false
    str2 = "Rotation";
    cout << isRotation(str1, str2) << endl;
    return 0;
}
/*
 1
 0
*/