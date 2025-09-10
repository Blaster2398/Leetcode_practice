class Solution {
public:
    int n, m;
    string word;
    vector<vector<char>> board;

    bool geek(int i , int j, int ind, vector<vector<int>>& vis){
        if(ind == word.size()) return true;
        if(i < 0 || j < 0 || i>= n || j >= m) return false;
        if(vis[i][j] == true) return false;
        if(board[i][j] != word[ind]) return false;


        vis[i][j] = true;
        bool found = (geek(i-1, j, ind+1, vis) || geek(i+1, j, ind+1, vis) || geek(i, j+1, ind+1, vis) || geek(i, j-1, ind+1, vis));
        vis[i][j] = false;  
        return found;
    }

    bool exist(vector<vector<char>>& _board, string _word) {
        word = _word;
        board = _board;
        n = board.size();
        m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                vector<vector<int>> visited(n, vector<int>(m, false));
                if(geek(i, j, 0, visited)) return true;
            }
        }
        return false;
    }
};
