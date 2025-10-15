class Solution {
public:
    string s, t;
    vector<vector<int>> dp;
    int geek(int i, int j){
        if(j < 0) return 1;
        if(i < 0 && j >= 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ways = 0;
        if(s[i] == t[j]){
            ways = max(ways, geek(i-1,j-1) + geek(i-1,j));
        }
        else{
            ways = max(ways, geek(i-1,j));
        }
        return dp[i][j] = ways;
    }
    int numDistinct(string _s, string _t) {
        s = _s;
        t = _t;
        dp.assign(s.size()+1, vector<int>(t.size()+1, -1));
        return geek(s.size()-1, t.size()-1);
    }
};