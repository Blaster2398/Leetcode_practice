class Solution {
public:
    int tim;
    int tar;
    double final_prob ;
    int branches[101];
    vector<int> adj[101];

    // there will be one dfs that will tell how many branches go out of the each node 
    void dfs(int u, int p){
        int count = 0;
        for(auto v : adj[u]){
            if(v != p){
                dfs(v, u);
                count++;
            }
        }
        branches[u] = count;
    }

    void dfst(int u, int p, int t, double prob){
        if(t > tim) return;
        if(u == tar){
            if( (t == tim) || (t < tim && branches[tar] == 0) ) {
                final_prob = prob;
            }
            return;
        }
        if(branches[u] == 0) return;

        double prob_per_child = prob / branches[u];
        for(auto v : adj[u]){
            if(v != p){
                dfst(v, u, t+1, prob_per_child);
            }
        }
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        double mul = 1;
        tim = t;
        tar = target;
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(1, 0);
        dfst(1, 0, 0, 1.0);
        return final_prob;
    }
};