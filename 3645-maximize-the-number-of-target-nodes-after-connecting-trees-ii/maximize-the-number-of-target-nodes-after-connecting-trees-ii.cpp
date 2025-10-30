class Solution {
public:
    vector<int> adj[100001];
    vector<int> gr[100001];
    int d1[100001];
    int d2[100001];
    void dfs(int u, int p, int d){
        d1[u] = d;
        for(auto v : adj[u]){
            if(v != p){
                dfs(v, u, d+1);
            }
        }
    }

    void dfs2(int u, int p, int d){
        d2[u] = d;
        for(auto v : gr[u]){
            if(v != p){
                dfs2(v, u, d+1);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() +1;
        int m = edges2.size() +1;
        for(auto e : edges1){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(auto e : edges2){
            gr[e[0]].push_back(e[1]);
            gr[e[1]].push_back(e[0]);
        }
        
        int a = 0, b = 0, c = 0, d = 0;
        dfs(0, -1, 0);
        dfs2(0, -1, 0);
        // keep the odd count int a and b // even count in c and d
        for(int i = 0; i < n; i++){
            if(d1[i]%2)a++;
            else c++;
        }
        for(int i = 0; i < m; i++){
            if(d2[i]%2)b++;
            else d++;
        }
        

        cout << " a  " <<  a  << ' b '  << endl;
        cout << b << " c " << c << " d " << d << " end "<< endl;
        int temp = max(b, d);
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            if(!(d1[i]%2)){
                res[i] = c+temp;
            }
            else{
                res[i] = a+temp;
            }
        }

        return res;
    }
};