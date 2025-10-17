class Solution {
public:
    int n, k;
    vector<int> pre;
    vector<int> dp;
    int solve(int mask){
        // base cases if we reach '111111...'
        if(mask == (1 << n) -1) return 0;
        if(dp[mask] != -1) return dp[mask];

        int available = 0;
        for(int i = 0; i < n; i++){
            if(!(mask & (1 << i)) && (pre[i] & mask) == pre[i]){
                available |= (1 << i);
            }
        }
        int ways = 1e9;
        for(int sub = available; sub > 0; sub = (sub-1) & available){
            if(__builtin_popcount(sub) <= k){
                ways = min(ways, 1 + solve(sub | mask));
            }
        }
        return dp[mask] = ways;

    }
    int minNumberOfSemesters(int _n, vector<vector<int>>& relations, int _k) {
        // n <= 15 giveaway of the dp with bitmask
        //steps
        // 1-> calculate the prerequisit for each course and store in an array 
        // 2-> solve(mask) will return the min sem required to get all the courses complete
        // 3-> Inside = get all the available cources with the currMask
        // 4-> then interate through all its subset and solve for each one of them 
        n = _n; 
        k = _k;
        pre.assign(n, 0);
        dp.assign(1 << n, -1);

        for(auto e : relations){ //0-based 
            int u = e[0]-1;
            int v = e[1]-1;
            pre[v] = pre[v] | (1 << u);
        }

        return solve(0);

    }
};