//
//  main.cpp
//  CTCIQ1.7
//
//  Created by Brian Corson on 6/23/16.
//  Copyright © 2016 Brian Corson. All rights reserved.
//
//  Question 1.7 - 
#include <iostream>
#include <vector>

const int row = 10;
const int column = 4;

void matrixManipulator(int matrix[][column]){
    std::vector<int> rowCopy;
    std::vector <int> columnCopy;
    for(int i = 0; i < row;i++){
        for(int j = 0; j < column; j++){
            if (matrix[i][j] == 0){
                rowCopy.push_back(i);
                columnCopy.push_back(j);
            }
        }
    }
    for(int i = 0; i < rowCopy.size();i++){
        int rowToClear = rowCopy[i];
        for(int j = 0; j < column; j++){
            matrix[rowToClear][j] = 0;
        }
    }
    for(int i = 0; i < columnCopy.size();i++){
        int columnToClear = columnCopy[i];
        for(int j = 0; j < row; j++){
            matrix[j][columnToClear] = 0;
        }
    }
}
int main(int argc, const char * argv[]) {
    int matrix[row][column] = {
        {1, 2, 3, 4},
        {11, 0, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 34},
        {41, 0, 43, 44},
        {51, 52, 53, 54},
        {61, 62, 0, 64},
        {71, 72, 73, 74},
        {81, 82, 83, 84},
        {91, 92, 93, 94}
    };
    std::cout << "Original Matrix:" << std::endl;
    for(int i = 0; i < row; i++) {
        for(int j= 0; j < column; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << "Zero Matrix:" << std::endl;;
    matrixManipulator(matrix);
    for(int i = 0; i < row; i++) {
        for(int j= 0; j < column; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
