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
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int count = n;
        sort(edges.begin(), edges.end(), [&](vector<int>& a, vector<int>& b){
            return a[2] > b[2];
        });
        DSU d(n+1);
        for(auto e : edges){
            int u = e[0], v = e[1], w = e[2];
            if(d.unite(u, v)){
                count--;
            }
            if(count < k) return w;
        }
        return 0;
    }
};
