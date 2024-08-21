class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                board[i][0] = 'B';
            }
            if(board[i][n-1] == 'O'){
                q.push({i, n-1});
                board[i][n-1] = 'B';
            }
        }
        
        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O'){
                q.push({0, i});
                board[0][i] = 'B';
            }
            if(board[m-1][i] == 'O'){
                q.push({m-1, i});
                board[m-1][i] = 'B';
            }
        }

        // Step 2: BFS to mark all connected 'O's with 'B'
        vector<pair<int,int>> dx = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(auto [di, dj] : dx){
                int ni = i + di;
                int nj = j + dj;

                if(ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == 'O'){
                    board[ni][nj] = 'B';
                    q.push({ni, nj});
                }
            }
        }

        // Step 3: Final pass to fix the board
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if(board[i][j] == 'B') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
