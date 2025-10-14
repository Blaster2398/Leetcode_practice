class Solution {
public:
    vector<int> dp;
    vector<int> arr;
    int geek(int i, int d){
        if(dp[i] != -1) return dp[i];
        int ways = 1;

        // scan right
        for(int k = 1;i+k <arr.size() &&  k <= d; k++){
            if(arr[i+k] >= arr[i]) break;
            ways = max(ways, 1 + geek(i+k, d));
        }

        // scan left
        for(int k = 1;i-k >=0 && k <= d; k++){
            if(arr[i-k] >= arr[i]) break;
            ways = max(ways, 1 + geek(i-k, d));
        }

        return dp[i] = ways;
    }
    int maxJumps(vector<int>& ars, int d) {
        arr = ars;
        dp.assign(arr.size(), -1);
        int ans = INT_MIN;
        for(int i = 0; i < arr.size(); i++){
            ans = max(ans , geek(i, d));
        }

        return ans;
    }
};