class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,pair<int,int>>> q;
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({0,{i,j}});
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int dis = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            q.pop();

            vector<int> di = {0,-1,1,0};
            vector<int> dj = {1,0,0,-1};

            for(int k = 0; k < 4;k++){
                int ni = i + di[k];
                int nj = j + dj[k];
                if(ni >= 0 && nj >= 0 && ni < m && nj < n && (dist[ni][nj] == -1 )){
                    dist[ni][nj] = 1 + dis;
                    q.push({dist[ni][nj],{ni, nj}});
                }
            }

        }

        return dist;

    }
};