class Solution {
public:
    int isAncestor(string& shorter, string & longer){
        int i = 0, j = 0;
        while (i < shorter.size() && j < longer.size()) {
            if (shorter[i] == longer[j]) {
                i++;
            }
            j++;
        }
        return i == shorter.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        if (words.empty()) return 0;

        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.length() < b.length();
        });

        
        // initialize the dp array
        vector<int> dp(n, 1);
        int muux = 1;

        for (int i = 1; i < n; i++) {
            for (int j = i-1; j>=0; j--) {

                if (words[j].length()+1 == words[i].length() && isAncestor(words[j],words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            muux = max(muux, dp[i]);
        }
        return muux;
    }
};