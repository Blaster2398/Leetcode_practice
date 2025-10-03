class Solution {
public:
    int n;
    vector<int> boxes;
    vector<vector<vector<int>>> dp;

    int solve(int l, int r, int k) {
        if (l > r) return 0;
        int &ans = dp[l][r][k];
        if (ans != -1) return ans;

        // Case 1: remove boxes[r] with the k extras of same color
        ans = solve(l, r - 1, 0) + (k + 1) * (k + 1);

        // Case 2: try merging with same color earlier in [l..r-1]
        for (int i = l; i < r; i++) {
            if (boxes[i] == boxes[r]) {
                ans = max(ans,
                          solve(l, i, k + 1) + solve(i + 1, r - 1, 0));
            }
        }
        return ans;
    }

    int removeBoxes(vector<int>& input) {
        boxes = input;
        n = boxes.size();
        dp.assign(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(0, n - 1, 0);
    }
};


