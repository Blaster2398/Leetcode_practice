class DSU{
    public:
    vector<int> p, r;
    DSU(int n){
        p.resize(n);
        r.assign(n,1);
        for(int i = 0; i < n; i++) p[i] = i;
    }
    int find(int v){
        if(p[v] == v) return v;
        return p[v] = find(p[v]);
    }
    bool unite(int u, int v){
        int a = find(u);
        int b = find(v);
        if(a == b) return false;
        if(r[a] > r[b]) p[b] = a;
        else if(r[b] > r[a]) p[a] = b;
        else{
            p[b] = a;
            r[a]++;
        }
        return true;
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU d(n);
        map<int, set<int>> nodes;
        map<int, int> edge_freq;
        
        for(auto e : edges){
            int u = e[0], v = e[1];
            d.unite(u,v);
        }

        for(auto e : edges){
            int u = e[0], v = e[1];
            int parent = d.find(u);
            edge_freq[parent]++;
        }

        for(int i = 0; i < n; i++){
            int parent = d.find(i);
            nodes[parent].insert(i);
        }

        int counter = 0;
        for(auto [parent, st] : nodes){
            int num = st.size();
            int freq = edge_freq[parent];
            if(num == 1) counter++;
            else if(num > 1 && (num*(num-1)/2 == freq)) counter++;
        }
        return counter;
    }
};