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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int wires = connections.size();
        
        DSU d(n);
        for(int i = 0; i < wires; i++){
            int u = connections[i][0];
            int v = connections[i][1];
            if(d.find(u) != d.find(v)){
                d.union_rank(u, v);
            }
        }
        vector<int> parent(n);
        set<int> st;
        for(int i = 0; i < n; i++){
            parent[i] = d.find(i);
            st.insert(d.find(i));
        }
        int compo = st.size();
        // cout << "wires " <<wires <<endl;
        // cout << "components " <<compo <<endl;
        
        // now we have 3 things 
        // 1) number of computers (n)
        // 2) number of wires (wires)
        // 3) number of components (compo)
        if(wires < n-1){
            return -1;
        }
        else{
            return compo-1;
        }
        
        
    }
};