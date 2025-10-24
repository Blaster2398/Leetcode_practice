class Solution {
public:
    int n, m, k;
    vector<vector<int>> pro;
    vector<int> adj[101];
    vector<set<int>> s;
    void build() {
        s.resize(n);
        for (int i = 0; i < n; i++)
            s[i] = set<int>(pro[i].begin(), pro[i].end());

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int same = 0;
                auto l = s[i].begin();
                auto r = s[j].begin();

                while (l != s[i].end() && r != s[j].end()) {
                    if (*l == *r) {
                        same++;
                        if (same >= k) break;
                        l++; r++;
                    } 
                    else if (*l < *r) l++;
                    else r++;
                }

                if (same >= k) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    }
    vector<int> vis;
    void dfs(int u){
        vis[u] = true;
        for(auto v : adj[u]){
            if(!vis[v]) dfs(v);
        }
    }
    int numberOfComponents(vector<vector<int>>& prop, int _k) {
        pro = prop;
        n = pro.size();
        m = pro[0].size();
        k = _k;
        build();
        vis.assign(100, 0);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                count++;
                dfs(i);
            }
        }
        return count;
    }
};