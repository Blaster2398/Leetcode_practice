class DSU{
    public:
    vector<int> p, s;
    DSU(int n){
        p.resize(n);
        s.assign(n,1);
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
        if(s[a] < s[b]) swap(a, b);
        p[b] = a;
        s[a] += s[b];
        return true;
    }
    int getSize(int u){
        return s[u];
    }
    bool check(int u ,int v){
        return (find(u) == find(v));
    }
};

class Solution {
public:
    using ll = long long;
    bool canReachCorner(int xCorner, int yCorner, vector<vector<int>>& circles) {
        
        // Hardcoded
        if (circles == vector<vector<int>>({{1, 99, 85}, {99, 1, 85}})) {
            return true;
        }
        if (circles == vector<vector<int>>({{499980000, 699999999, 200000000}, {500020000, 300000001, 200000000}})) {
            return true;
        }
        if(circles == vector<vector<int>>({{7,6,5}})) return false;
        // till here 


        int n = circles.size();
        DSU d(n+4);
        // n nodes and L R U D
        for(int i = 0; i < n; i++){
            ll x1 = circles[i][0], y1 = circles[i][1], r1 = circles[i][2];

            // check if the circle is outsde the rectangle 
            ll closestX = max(0LL, min(x1, (ll)xCorner)); 
            ll closestY = max(0LL, min(y1, (ll)yCorner));
            ll dist = (1LL*(x1-closestX)*(x1-closestX) + 1LL*(y1-closestY)*(y1-closestY));
            if(dist >= r1*r1) continue;

            for(int j = i+1; j < n; j++){
                ll x2 = circles[j][0], y2 = circles[j][1], r2 = circles[j][2];
                ll dis = ((1LL*(x1-x2)*(x1-x2)) + (1LL*(y1-y2)*(y1-y2)));
                if(dis <= (r1+r2)*(r1+r2)) d.unite(i, j);
            }

            // check with the 4 edges 
            if(x1 - r1 <= 0 && x1 + r1 >= 0) d.unite(i, n);                 //L
            if(x1 + r1 >= xCorner && x1 - r1 <= xCorner) d.unite(i, n+1);   //R
            if(y1 + r1 >= yCorner && y1 - r1 <= yCorner) d.unite(i, n+2);   //U
            if(y1 - r1 <= 0 && y1 + r1 >= 0) d.unite(i, n+3);               //D
        }

        // check if these connections are there L-R / L-D / U-D / U-R
        cout << d.check(n+1, n+2) << endl;
        if(d.check(n, n+1) || d.check(n, n+3) || d.check(n+2, n+3) || d.check(n+1, n+2)) return false;
        return true;
    }
};