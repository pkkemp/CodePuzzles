//
//  main.cpp
//  CodingExercisesSetTwo
//
//  Created by Preston Kemp on 12/8/19.
//  Copyright © 2019 Preston Kemp. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> letterCombinations(string digits) {
    // Write your code here.

    vector<vector<string>> chars{ { "a", "b", "c"},
                               { "d", "e", "f" },
                               { "g", "h", "i"},
                               { "j", "k", "l" },
                               { "m", "n", "o" },
                               { "p", "q", "r", "s" },
                               { "t", "u", "v" },
                               { "w", "x", "y", "z" }};
    vector<string> combos = chars[stoi(digits.substr(0,0))];
    for(int i = 1; i < digits.length(); i++) {
        int digit = stoi(digits.substr(i,i));
        for(int j = 0; j < chars[digit].size(); j++) {
            combos.push_back(chars[digit][j]);
        }


    }
}

u_long findNthFiboTerm(int n) {
    if(n <= 1)
        return n;
    
    u_long current = 1;
    u_long previous = 0;
    for(int i = 1; i < n; i++) {
        u_long temp = current;
        current+= previous;
        previous = temp;
    }
    return current;
}

// Returns the board in its next state.
vector<vector<int>> gameOfLife(vector<vector<int>>& board) {
    // Write your code here.

    const u_long n = board.size();
    const u_long m = board[0].size();
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
    cout << "Sixth term is " << findNthFiboTerm(98) << "\n";
    cout << "Max size " << UINTMAX_MAX;
    cout << "\n";
//    vector<vector<int>> board
    return 0;
}
