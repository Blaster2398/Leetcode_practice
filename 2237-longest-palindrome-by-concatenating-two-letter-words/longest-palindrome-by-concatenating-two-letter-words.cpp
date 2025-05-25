class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int res = 0;
        
        for (const string& word : words) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (mp[rev] > 0) {
                mp[rev]--;
                res += 4;
            } else {
                mp[word]++;
            }
        }

        for (const auto& [word, count] : mp) {
            if (word[0] == word[1] && count > 0) {
                res += 2;
                break;  // Only one center allowed
            }
        }

        return res;
    }
};
