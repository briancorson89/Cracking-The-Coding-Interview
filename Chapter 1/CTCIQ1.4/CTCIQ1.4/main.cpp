//
//  main.cpp
//  CTCIQ1.4
//
//  Created by Brian Corson on 6/7/16.
//
//  1.4 - Write a function to replace all spaces in a string with '%20'

#include <iostream>

using namespace std;

string replaceSpaces(string str, int strLength){
    int spacesCounter = 0;//iterate through string and count spaces
    for(int i = 0; i < strLength;i++){
        if(str[i] == ' '){
            spacesCounter++;
        }
    }
    spacesCounter *= 2;//for new string length we need to add 2 spots for every space
    strLength += spacesCounter;
    char newStr[strLength];//initialize char array for new string with necessary space allocated
    int newStrIter = 0;
    for(int i = 0; i < strLength; i++){
        if(str[i] == ' '){
            newStr[newStrIter++] = '%';
            newStr[newStrIter++] = '2';
            newStr[newStrIter++] = '0';
        }
        else{
            newStr[newStrIter++] = str[i];
        }
    }
    return newStr;
}
int main(int argc, const char * argv[]) {
    cout << replaceSpaces("Mr. John Smith", 13) << endl;//expect: Mr.%20John%20Smith
    cout << replaceSpaces("But we had one foot on the gas and one foot in the grave", 56) << endl;
    //expect:But%20we%20had%20one%20foot%20on%20the%20gas%20and%20one%20foot%20in%20the%20grave
    return 0;
}
/* Output:
 Mr.%20John%20Smith
 But%20we%20had%20one%20foot%20on%20the%20gas%20and%20one%20foot%20in%20the%20grave
*/