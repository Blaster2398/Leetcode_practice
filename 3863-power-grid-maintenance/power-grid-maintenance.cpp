class D{
public:
    vector<int> rank;
    vector<int> parent;

    D(int n){
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        rank.resize(n, 1);
    }

    int findp(int v){
        if(parent[v] == v) return v;
        return parent[v] = findp(parent[v]);
    }

    void unionr(int u, int v){
        int pu = findp(u);
        int pv = findp(v);

        if(pu == pv) return;

        if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }

    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        D d(c+1);
        for(int i = 0; i < connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            if(d.findp(u) != d.findp(v)){
                d.unionr(u, v);
            }
        }

        

        // now make a map <int, set<int>> to store parent -> all the childs 

        map<int, set<int>> mp;
        for(int i = 1; i <= c; i++){
            int par = d.findp(i);
            mp[par].insert(i);
        }

        // now answer the queries 
        vector<int> res;
        for(auto q : queries){
            int ind = q[0];
            int u = q[1];
            int parent = d.findp(u);
            // if this is a 1 then check the parent and then return from the map of sets accordingly 
            if(ind == 1){
                
                if(mp[parent].find(u) != mp[parent].end()){
                    res.push_back(u);
                }
                else if(!mp[parent].empty()) res.push_back(*mp[parent].begin());
                else res.push_back(-1);
            }
            else{
                //  delete the element from the set
                mp[parent].erase(u);
            }
        }


        return res;
    }
};