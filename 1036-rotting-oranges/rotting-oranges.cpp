class Solution {
public:
    void countOranges(vector<vector<int>> & grid, int & tot, int m,int n, queue<pair<int,int>> & q){
        for(int i =0; i< m ;i++){
            for( int j = 0; j < n; j++){
                if(grid[i][j] ==1){
                    tot++;
                }
                else if(grid[i][j] == 2){
                    tot++;
                    q.push({i,j});
                    // cout << " i-> " << i << "j-> " <<j <<endl;

                }
            }
        }
    }

    void BFS(vector<vector<int>> & grid,queue<pair<int,int>> & q, int & rot, int & time, int m, int n){
        while(!q.empty()){
            int count = q.size();
            time++;
            for(int k =0; k< count;k++){
                auto ele = q.front();
                q.pop();
                rot++;
                int i = ele.first;
                int j = ele.second;

                // cout << " i-> " << i << "j-> " <<j <<endl;
                //left
                if(j-1>=0 && grid[i][j-1]==1){
                    grid[i][j-1] = 2;
                    q.push({i,j-1});
                    
                }
                //up
                if(i-1>=0 && grid[i-1][j]==1){
                    grid[i-1][j] = 2;
                    q.push({i-1,j});
                    
                }
                //right
                if(j+1<n && grid[i][j+1]==1){
                    grid[i][j+1] = 2;
                    q.push({i,j+1});
                    
                }
                //down
                if(i+1<m && grid[i+1][j]==1){
                    grid[i+1][j] = 2;
                    q.push({i+1,j});
                    
                }
            }

        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // step 1 count the number of orages and also store the number of rotten oranges also make a quueue to store their inddexes 
        int tot = 0;
        int time = 0;
        // int count =0;
        int rot = 0;
        queue<pair<int,int>> q;
        countOranges(grid, tot,m,n, q);

        // step 2 do a bfs traversal 
        BFS(grid, q, rot, time,m,n);
        cout <<"TIME " << time << endl;
        cout << "TOT " << tot << endl;
        cout << "ROT " << rot <<endl;

        // step 3 check weather rot == tot if not return -1 if yes return time-1
        if(rot != tot){
            return -1;
        }
        else{
            return (time-1<0)?time:time-1;
        }   
    }
};