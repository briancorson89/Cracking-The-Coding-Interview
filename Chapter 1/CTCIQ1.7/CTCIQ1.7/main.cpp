//
//  main.cpp
//  CTCIQ1.7
//
//  Created by Brian Corson on 6/23/16.
//  Copyright © 2016 Brian Corson. All rights reserved.
//
//  Question 1.7 - Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0
#include <iostream>
#include <vector>
#include <algorithm>

const int row = 10;
const int column = 4;

void matrixManipulator(int matrix[][column]){
    std::vector<int> rowStorage;//to store row index with zero in it
    std::vector <int> columnStorage;//to store column index with zero in it
    
    for(int i = 0; i < row;i++){
        for(int j = 0; j < column; j++){
            if (matrix[i][j] == 0){
                rowStorage.push_back(i);//push row index into vector
                columnStorage.push_back(j);//push column index into vector
            }
        }
    }

    for(int i = 0; i < rowStorage.size();i++){
        int rowToClear = rowStorage[i];//check vector for index of row to clear
        for(int j = 0; j < column; j++){
            matrix[rowToClear][j] = 0;//clear the row
        }
    }
    for(int i = 0; i < columnStorage.size();i++){
        int columnToClear = columnStorage[i];//check vector for column to clear
        for(int j = 0; j < row; j++){
            matrix[j][columnToClear] = 0;//clear the column
        }
    }
}
int main(int argc, const char * argv[]) {
    int matrix[row][column] = {
        {0, 1, 2, 3},//expect 1st and 3rd column to be cleared
        {4, 5, 6, 7},//expect 1st, 3rd, 6th, and 8th row to clear
        {8, 9, 0, 1},
        {2, 3, 4, 5},
        {6, 7, 8, 9},
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 0, 1},
        {2, 3, 4, 5},
        {6, 7, 8, 9}
    };
    std::cout << "Original Matrix:" << std::endl;
    for(int i = 0; i < row; i++) {
        for(int j= 0; j < column; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << "Cleared Matrix:" << std::endl;;
    matrixManipulator(matrix);
    for(int i = 0; i < row; i++) {
        for(int j= 0; j < column; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
/* Output:
 Original Matrix:
 0 1 2 3
 4 5 6 7
 8 9 0 1
 2 3 4 5
 6 7 8 9
 0 1 2 3
 4 5 6 7
 8 9 0 1
 2 3 4 5
 6 7 8 9
 
 Cleared Matrix:
 0 0 0 0
 0 5 0 7
 0 0 0 0
 0 3 0 5
 0 7 0 9
 0 0 0 0
 0 5 0 7
 0 0 0 0
 0 3 0 5 
 0 7 0 9
 */
