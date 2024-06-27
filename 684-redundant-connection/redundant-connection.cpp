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
            rank[a]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 0;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            n = max(n, max(u,v));
        }
        vector<int> res;
        DSU d(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            if(d.find(u-1) != d.find(v-1)){
                d.union_rank(u-1,v-1);
            }
            else{
                res.push_back(u);
                res.push_back(v);
                break;
            }
        }
        return res;
    }
};