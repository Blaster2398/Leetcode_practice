class Solution {
public:

    bool canBreak(string s, unordered_set<string>& dict, int ind, vector<int> & dp){
        if(ind == s.size()){
            return true;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        for(int i = ind ; i < s.size(); i++){
            if(dict.count(s.substr(ind, i - ind + 1)) && canBreak(s, dict, i + 1, dp)){
                return dp[ind] = true;
            }
        }

        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size() +1, -1);

        return canBreak(s, dict,0, dp);
    }



    // bool canBreak(string s, unordered_set<string>& dict, int ind, vector<int> & dp){
    //     if(ind == s.size()){
    //         return true;
    //     }

    //     if(dp[ind] != -1){
    //         return dp[ind];
    //     }

    //     for(int i = ind + 1; i <= s.size(); i++){
    //         if(dict.count(s.substr(ind, i - ind )) && canBreak(s, dict, i, dp)){
    //             return dp[ind] = true;
    //         }
    //     }

    //     return dp[ind] = false;
    // }
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     unordered_set<string> dict(wordDict.begin(), wordDict.end());
    //     vector<int> dp(s.size() +1, -1);

    //     return canBreak(s, dict,0, dp);
    // }
};