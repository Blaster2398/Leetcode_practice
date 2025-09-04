class Solution {
public:
    using ll = long long;
    long long maxScore(int n, vector<vector<int>>& edges) {
            
        bool cycle = (edges.size() == n) ? true : false;

        ll sum = 0;
        sum += 1LL * n * (n - 1);

        // the sum is basically sigma (0 -> n-2) i(i+2)  which reduces to this form
        sum += (1LL * (n - 2) * (n - 1) * (2*n - 3)) / 6;
        sum += 1LL * (n - 2) * (n - 1);
        
        if (cycle) sum += 2;

        return sum;
    }

//     bool dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& vis) {
//         vis[u] = 1;
//         for (int v : adj[u]) {
//             if (!vis[v]) {
//                 if (dfs(v, u, adj, vis)) return true;
//             } 
//             else if (v != parent) {
//                 return true; 
//             }
//         }
//         return false;
//     }



//     long long maxScore(int n, vector<vector<int>>& edges) {
//          vector<vector<int>> adj(n);
//         for (auto &e : edges) {
//             adj[e[0]].push_back(e[1]);
//             adj[e[1]].push_back(e[0]);
//         }
//         vector<int> vis(n, 0);
//         bool flag =  dfs(0, -1, adj, vis);  
//         if( n == 1) return 1;
//         if(n == 2) return 2;
        
//         // we have numbers till 1- n 
//         // find the product of evens 
//         ll sum = 0;
//         ll p1 = n;
//         ll p2 = p1-2;
//         while(p2 >= 0){
//             sum += (p1*p2);
//             p1 -= 2;
//             p2 -= 2;
//         }

//         // now the odd numbers 

//         p1 = n-1;
//         p2 = p1-2;
//         while(p2 >= 0){
//             sum += (p1*p2);
//             p1 -= 2;
//             p2 -= 2;
//         }

//         sum +=((1LL*n)*(1LL*(n-1)));
        

//         if(flag) sum += 2;
//     // cout << flag << endl;
//         return sum;
        
        
//     }
};

