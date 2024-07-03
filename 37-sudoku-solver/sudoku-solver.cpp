class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        // check for the row , the column and the 3x3 box it is part of for the character c if it is found retuen false 
        for(int i = 0; i < 9; i++){
            if(board[row][i] == c){
                return false;
            }
            if(board[i][col] == c){
                return false;
            }
            if(board[3* (row/3) + (i/3)][3* (col/3) + (i%3)] == c){
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                // check if the cell is empty
                if(board[i][j] == '.'){
                    // then you can fill it with 1->9
                    for(int k = '1'; k <= '9'; k++){
                        if(isValid(board, i, j, k)){
                            board[i][j] = k;

                            if(solve(board) == true){
                                return true;
                            }

                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    //if none of the places were filled and we reached here then
                    return false;
                }
            }
        }
        // if we didnt entered the loop that means there were no empty places 
        return true;
    }


    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};