class Solution {
public:
    bool isSafe(vector<string>& board, int n, int row, int col){
        // as we are filling column wise and from 0 -> n-1 
        //so we only need to check 3 direction for the queen to be attacked insted of 8
        

        int dr = row;
        int dc = col;
        // check for north west
        while(dr >=0 && dc>=0){
            if(board[dr][dc] == 'Q') return false;
            dr--;
            dc--;
        }
        dr = row;
        dc = col;
        //check for west
        while(dc >= 0){
            if(board[dr][dc] == 'Q') return false;
            dc--;
        }

        dr = row;
        dc = col;
        // check for south west
        while(dr <= n-1 && dc >= 0){
            if(board[dr][dc] == 'Q') return false;
            dr++;
            dc--;
        }

        return true;
    }

    void f(int n, vector<vector<string>>& res, vector<string>& board, int ind){
        // base case
        if(ind == n){
            res.push_back(board);
            return;
        }
        else{
            for(int i = 0; i < n; i++){
                if(isSafe(board, n, i, ind)){
                    board[i][ind] = 'Q';
                    f(n, res, board, ind+1);
                    board[i][ind] = '.';
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board;
        // this is individual row
        string s(n, '.');

        for(int i = 0; i< n; i++){
            board.push_back(s);
        }

        // we are filling the queens column wise
        f(n, res, board, 0);

        return res;
    }
};