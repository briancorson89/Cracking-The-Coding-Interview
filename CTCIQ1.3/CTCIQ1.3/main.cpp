//
//  main.cpp
//  CTCIQ1.3
//
//  Created by Brian Corson on 6/7/16.
//  Copyright © 2016 Brian Corson. All rights reserved.
//
//  1.3 -- Given 2 strings, write a method to decide if one is a permutation of the other
#include <iostream>

using namespace std;

bool isPermutation(string s, string t){
    if(s.length() != t.length()){
        return 0;
    }
    else{
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i = 0; i < s.length(); i ++){
            if(s[i] != t[i]){
                return 0;
            }
        }
    }
    return 1;
}
int main(int argc, const char * argv[]) {
    cout << isPermutation("aba","aab") << endl;//expect 1
    cout << isPermutation("aaaa", "b") << endl;//expect 0
    cout << isPermutation("aab","aaa") << endl;//expect 0
    return 0;
}
/* Output:
    1
    0
    0
 */
