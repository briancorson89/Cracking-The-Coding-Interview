//
//  main.cpp
//  CTCIQ1.2
//
//  Created by Brian Corson on 6/5/16.
//
//  1.2 -- Implement a function void reverse(char * str) in C++ which reverses a null-terminated string

#include <iostream>

using namespace std;

void reverse( char * str ){
    char *endOfString = str;
    while(*endOfString != '\0'){//iterate to the end of null-terminated string
            endOfString++;
        }
    endOfString--;//iterate to the char just before termination
    
    char temp;
    while(str < endOfString){
        temp = *str;//temp holds char from the beginning of the string
        *str++ = *endOfString;//first char is now the last char
        *endOfString-- = temp;//last char is now the first char
    }
    
}

int main(int argc, const char * argv[]) {
    char  str[] = "That'll be the day when the sun falls down. The angels may weep but I hear no sounds but, hey";
    cout << str << endl;
    reverse(str);
    cout << str << endl;
    return 0;
}
/*Output
 That'll be the day when the sun falls down. The angels may weep but I hear no sounds but, hey
 yeh ,tub sdnuos on raeh I tub peew yam slegna ehT .nwod sllaf nus eht nehw yad eht eb ll'tahT
 */
