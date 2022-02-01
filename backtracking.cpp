#include "bits/stdc++.h"
using namespace std;

/* Backtracking is an algorithmic-technique for solving problems recursively by trying to build a solution incrementally, one piece at a time, removing those solutions that fail to satisfy the constraints of the problem at any point of time */

/* 
RAT IN A MAZE
A Maze is given as N*N binary matrix of blocks where source block is the upper left most block i.e., maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. A rat starts from source and has to reach the destination. The rat can move only in two directions: forward and down. 

In the maze matrix, 0 means the block is a dead end and 1 means the block can be used in the path from source to destination 

we also need to return the path matrix which shows the path taken by the rat
Algorithm:  

Create a solution matrix, initially filled with 0’s.
Create a recursive function, which takes initial matrix, output matrix and position of rat (i, j).
if the position is out of the matrix or the position is not valid then return.
Mark the position output[i][j] as 1 and check if the current position is destination or not. If destination is reached print the output matrix and return.Check if destination can be reached by going to the right cell if yes then print the path matrix and return.
Else check if destination can be reached by goind to the down matrix, if yes then print the path matrix and return
Else mark output[i][j] as 0 and return false*/

void printMatrix (vector <vector <bool>> ans) {
    for (int i=0; i<ans.size(); i++) {
        for (int j=0; j<ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkBounds (int i, int j, int n, int m, vector<vector<bool>> &matrix) {
    return i<n && j<m && matrix[i][j]==1;
}

bool solveMazeRec (vector<vector<bool>> &matrix, int i, int j, vector<vector<bool>> &ans, int n, int m) {
    if (i==n-1 && j==m-1) {
        ans[i][j] = 1;
        return true;
    }
    
    ans[i][j] = 1;
    if (checkBounds(i, j+1, n, m, matrix) && solveMazeRec(matrix, i, j+1, ans, n, m)) {
        return true;
    } else if (checkBounds(i+1, j, n, m, matrix) && solveMazeRec(matrix, i+1, j, ans, n, m)) {
        return true;
    }

    ans[i][j] = 0;
    return false;
}

bool solveMaze (vector<vector<bool>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector <vector <bool>> ans (n, vector<bool>(m, 0));

    if (solveMazeRec(matrix, 0, 0, ans, n, m)) {
        printMatrix(ans);
        return true;
    }
    return false;
}

/* N QUEEN PROBLEM
check if you can place n queens in a n*n chess board. If yes, print the placement.
let's say first queen is placed in first column, second in second column and so on. Then one of the permutations of the first n numbers will give the respective row numbers since no two queens can be in the same row or column.
Start with column 0 and check for each row if it is a valid position. If yes then recursively check for col 1 till column no becomes equal to N*/

bool isSafe (int row, int col, vector<vector<bool>> &cB, int n) {
    // only one queen is allowed per column so no need to check in the same column, only check in the row and diagonally (upper left and bottom left since right side of the board is empty)

    // checking in row
    for (int i=0; i<col; i++) 
        if (cB[row][i])
            return false;
    
    // upper left diagonal
    for (int i=row, j=col; i>=0 && j>=0; i--, j--) 
        if (cB[i][j])
            return false;

    // lower left diagonal
    for (int i=row, j=col; i<n && j>=0; i++, j--)
        if (cB[i][j])
            return false;

    return true;
}

bool nQueenProblemRec (vector<vector<bool>> &cB, int n, int col) {
    if (col == n)   return true;

    // now will check for each row
    for (int row=0; row<n; row++) {
        if (isSafe(row, col, cB, n)) {
            cB[row][col] = 1;
            if (nQueenProblemRec(cB, n, col+1))
                return true;
            cB[row][col] = 0;
        }
    }
    return false;
}

bool nQueenProblem (int n) {
    vector <vector <bool>> chessBoard (n, vector<bool>(n, false));
    if (nQueenProblemRec(chessBoard, n, 0)) {
        printMatrix(chessBoard);
        return true;
    }
    return false;
}

int main () {
    // vector <vector <bool>> matrix = {{1, 0, 1}, {1, 1, 0}, {0, 1, 1}};
    // solveMaze(matrix);

    cout << nQueenProblem(5);
}