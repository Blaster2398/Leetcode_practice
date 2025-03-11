class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int st = 0, en = 0;
        map<char, int> mp;
        int count = 0;

        // Find the first valid window containing all three characters
        while (en < n) {
            mp[s[en]]++;
            if (mp.size() >= 3) {
                break;
            }
            en++;
        }

        // Expand and contract the window to count valid substrings
        while (st <= n - 3 && en < n) {
            if (mp.size() == 3) {
                count += (n - en);
                mp[s[st]]--;
                if (mp[s[st]] == 0) {
                    mp.erase(s[st]);
                }
                st++;
            } else {
                en++;
                if (en < n) {
                    mp[s[en]]++;
                }
            }
        }

        return count;
    }
};