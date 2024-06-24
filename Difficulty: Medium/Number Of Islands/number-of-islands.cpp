//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DSU
{
    public:
    vector<int> rank;
    vector<int> parent;
    
    DSU (int V){
        parent.resize(V);
        rank.resize(V, 0);  
        for(int i = 0; i < V; i++){
            parent[i] = i;
        }
    }
    
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        else{
            return parent[x] = find(parent[x]);
        }
    }
    
    void union_rank(int x, int y){
        int a = find(x);
        int b = find(y);
        
        if(a == b) return ;
        
        if(rank[a] < rank[b]) parent[a] = b;
        else if(rank[a] > rank[b]) parent[b] = a;
        else{
            parent[b] = a;
            rank[a++];
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    
        DSU d(m*n);
        vector<vector<int>> visited(n, vector<int>(m,0));
        int cnt = 0;
        vector<int> res;
        for(auto it : operators){
            int i = it[0];
            int j = it[1];
            // if it is already visited then just add the current count and leave this iteration
            if(visited[i][j] == 1){
                res.push_back(cnt);
                continue;
            }
            
            visited[i][j] = 1;
            cnt++;
            
            vector<int> dx = {1, -1, 0, 0};
            vector<int> dy = {0, 0, 1, -1};
            for(int ind = 0; ind < 4; ind++){
                int nr = i + dx[ind];
                int nc = j + dy[ind];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && visited[nr][nc]== 1 ){
                    int nodeNo = i*m + j;
                    int adjNodeNo = nr*m + nc;
                    if(d.find(nodeNo) != d.find(adjNodeNo)){
                        cnt--;
                        d.union_rank(nodeNo, adjNodeNo);
                    }
                }
            }
            res.push_back(cnt);
            
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends