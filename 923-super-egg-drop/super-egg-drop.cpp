class Solution {
public:
    int geek(int e, int f, vector<vector<int>>& dp){
        if(e == 1) return f;
        if(f == 0 || f == 1) return f;

        if(dp[e][f] != -1) return dp[e][f];

        int high = f;
        int low = 1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low + high)/2;
            int left = geek(e-1, mid-1, dp);
            int right = geek(e, f-mid, dp);

            ans = min(ans, 1 + max(left, right));

            if(left < right) low = mid + 1;
            else high = mid - 1;
        }
        return dp[e][f] = ans;
    }
    int superEggDrop(int e, int f) {
        vector<vector<int>> dp(e+1, vector<int> (f + 1, -1));
        return geek(e, f, dp);
    }
};