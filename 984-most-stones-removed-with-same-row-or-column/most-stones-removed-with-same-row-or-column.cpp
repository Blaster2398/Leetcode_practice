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
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        
        int maxr = -1;
        int maxc = -1;
        for(int i =0; i < stones.size();i ++){
            maxr = max(maxr, stones[i][0]);
            maxc = max(maxc, stones[i][1]);
        }
        DSU ds(maxr + maxc + 2);
        unordered_map<int, int> stoneNodes;
        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxr + 1;
            ds.union_rank(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        int cnt = 0;
        for (auto it : stoneNodes) {
            if (ds.find(it.first) == it.first) {
                cnt++;
            }
        }
        return n - cnt;
        
    }
};




