//
//  main.cpp
//  CTCIQ1.6
//
//  Created by Brian Corson on 6/21/16.
//  Copyright © 2016 Brian Corson. All rights reserved.
//
// Question 1.6 - Given an image represented by an NxN matrix, where each pixel is 4 bytes, writea method
// to rotate the image by 90 degrees.
// Solution - Transpose matrix to print desired matrix backwards, the reverse row order

#include <iostream>

using namespace std;

const int row = 4;
const int col = 4;

void rotateMatrix(int matrix[][col]){
    //part one: transpose
    for(int i = 0; i < row; i++) {
        for(int j= i; j < col; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    //part two: reverse row order
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col/2; j++) {
            swap(matrix[i][j], matrix[i][col-j-1]);
        }
    }
}
int main(int argc, const char * argv[]) {
    int matrix[row][col] = {
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 34},
        {41, 42, 43, 44}
    };
    cout << "Original Matrix:" << endl;
    for(int i = 0; i < row; i++) {
        for(int j= 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << "Rotated Matrix:" << endl;;
    rotateMatrix(matrix);
    for(int i = 0; i < row; i++) {
        for(int j= 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
 Original Matrix:
 11 12 13 14
 21 22 23 24
 31 32 33 34
 41 42 43 44
 
 Rotated Matrix:
 41 31 21 11
 42 32 22 12
 43 33 23 13
 44 34 24 14
 */
