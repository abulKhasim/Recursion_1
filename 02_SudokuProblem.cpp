// Approach:

// 1. traverse the matrix and find the empty place.
// 2. once we find the empty place than we tried all the numbers from 1 to 9 and check that it is a valid number or not by checking the rules.
// 3. and we find the correct number for that place than we find for the second empty place in 9 X 9 matrix.
// 4. for second empty place we repeat the same process and if we doesn't get any number, so we return false.
// 5. after getting the false from solve(board) function we make all the places empty that we have filled . than try for other member for first empty place.
// 6. and after all recursive calls we got true, than we have to stop over there only and no need to search for other solutions.

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){

                if(board[i][j] == '.'){

                    for(char c='1'; c<='9'; c++){
                        if(isValid(board, i, j, c)){
                            board[i][j] = c;

                            if(solve(board) == true)
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i=0; i<9; i++){
            if(board[i][col] == c)
                return false;
            
            if(board[row][i] == c)
                return false;

            if(board[3 * (row/3) + i/3][3 * (col/3) + i%3] == c)
                return false;
        }
        return true;
    }
};