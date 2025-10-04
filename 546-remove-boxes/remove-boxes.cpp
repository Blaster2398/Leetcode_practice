class Solution {
public:
    int n;
    vector<int> boxes;
    vector<vector<vector<int>>> dp;
    int f(int l, int r, int k){
        // base cases 
        if(l > r) return 0;

        if(dp[l][r][k] != -1) return dp[l][r][k];

        int ways = INT_MIN;
        // we can combine with the colors after r 
        ways = max(ways, f(l, r-1, 0) + (k+1)*(k+1));

        // we can combine the rth color with something that is in bw l and r 
        for(int i = l; i < r; i++){
            if(boxes[i] == boxes[r]){
                ways = max(ways , f(l, i, k+1) + f(i+1, r-1, 0));
            }
        }

        // return the ans 
        return dp[l][r][k] = ways;
    }
    int removeBoxes(vector<int>& inp) {
        boxes = inp;
        n = boxes.size();
        // there are 3 stater l r k where l and r are the range variable and k is the  number of
        // boxes that are of same type after the rth block 
        dp.assign(n, vector<vector<int>> (n, vector<int>(n, -1)));
        return f(0,n-1,0);
    }
};