class Solution {
public:
    int geek(int s, int e, vector<int>& val, vector<vector<int>>& dp){
        if(s+2 == e) return val[s]*val[s+1]*val[e];
        if(s+2 > e) return 0;

        if(dp[s][e] != -1) return dp[s][e];

        // split the question 
        int mini = INT_MAX;
        for(int i = s+1; i <= e-1; i++){
            int aud = val[s]*val[i]*val[e];
            int left = geek(s, i, val, dp);
            int right = geek(i, e, val, dp);
            // if(left == INT_MAX || right ==INT_MAX) continue;
            mini = min(mini, aud + left + right);
        }

        return dp[s][e] = mini;
    }
    int minScoreTriangulation(vector<int>& values) {
        // this is a n edged polygon will form n-2 triangles 
        int n = values.size();


        // when we start form the 1-n edge we can take the 3rd vertex to be k and apply mcm on finding the next 
        // vertex in the reange 2 <-> k-1 and the other in the range k+1 <-> n-1


        // the state of the dp are start and then end node 
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return geek(0, n-1, values, dp);

    }
};