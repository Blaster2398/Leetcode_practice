class Solution {
public:
    int n;
    string s;
    vector<vector<int>> dp;
    bool geek(int i, int open){
        if(i == n) return (open == 0);
        if(dp[i][open] != -1) return dp[i][open];

        bool ans = false;
        if(s[i] == '*'){
            ans |= geek(i+1,open+1);
            ans |= geek(i+1, open);
            if(open) ans |= geek(i+1, open-1);
        }
        else if(s[i] == '(') ans = geek(i+1, open+1);
        else if(s[i] == ')' && open)  ans = geek(i+1, open-1);

        return dp[i][open] = ans;
    }
    bool checkValidString(string _s) {
        s = _s;
        n = s.size();
        dp.assign(n, vector<int>(n, -1));
        return geek(0, 0);
    }
};