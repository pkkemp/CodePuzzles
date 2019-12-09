//
//  main.cpp
//  CodingExercisesSetTwo
//
//  Created by Preston Kemp on 12/8/19.
//  Copyright © 2019 Preston Kemp. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


// Returns the board in its next state.
vector<vector<int>> gameOfLife(vector<vector<int>>& board) {
    // Write your code here.

    const int n = board.size();
    const int m = board[0].size();
    vector<vector<int>> newBoard( n , vector<int> (m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int numAlive = 0;
            for(int ni = i-1; ni <= i+1; ni++) {
                for(int nj = j-1; nj <= j+1; nj++) {
                    //check that we're not looking at the current cell
                    if(ni != i || nj != j)
                        //check that we're still inside the bounds in one dimension
                        if(ni >= 0 && ni < n)
                            // check that we're in bounds in second dimension
                            if(nj >= 0 && nj < m)
                                if(board[ni][nj] == 1)
                                    numAlive++;
                }
            }
            if((numAlive == 2 || numAlive == 3) && board[i][j] == 1) {
                newBoard[i][j] = 1;
            }
            else if(newBoard[i][j] == 0 && numAlive == 3) {
                newBoard [i][j] = 1;
            }
            else {
                newBoard [i][j] = 0;
            }
        
        }
    }
    return newBoard;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<vector<int>> board{ { 0, 1, 1, 0 },
                               { 0, 0, 1, 0 },
                               { 0, 0, 0, 0 },
                               { 0, 0, 1, 0 }
    };
    vector<vector<int>> newBoard = gameOfLife(board);
//    vector<vector<int>> board
    return 0;
}