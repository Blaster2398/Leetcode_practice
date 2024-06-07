class Solution {
public:
        void BFS(vector<vector<int>> &grid, queue<pair<int, int>> &q, int newColor, int m, int n, int initColor) {
        // Directions for moving in the grid (left, up, right, down)
        vector<pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        
        while (!q.empty()) {
            cout << "this is done" <<endl;

            auto [i, j] = q.front();
            cout << "i-> " << i << "j->" << j <<endl;
            grid[i][j] = newColor;

            q.pop();
            
            for (auto [di, dj] : directions) {
                int ni = i + di;
                int nj = j + dj;
                
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == initColor) {
                    grid[ni][nj] = newColor;
                    q.push({ni, nj});
                    cout << "i-> " << i << "j->" << j <<endl;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // step 1 initialize the queue andpush the src row and column 
        int m = image.size();
        int n = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int init_col = image[sr][sc];
            

        // BFS
        if(color == init_col){
            return image;
        }
        BFS(image,q, color,m,n, init_col);
        
        return image;
    }
};
