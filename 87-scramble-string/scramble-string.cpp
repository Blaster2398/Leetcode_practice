class Solution {
public:
    unordered_map<string, int> dp;
    bool geek(string s1, string s2){
        if(s1 == s2) return true;
        if(s2.size() < 1) return false;

        int n1 = s1.length();
        int n2 = s2.length();


        if(dp.count(s1 + ' ' + s2)) return dp[s1 + ' ' + s2];
        bool res = false;
        for(int i = 1; i < n1; i++){
            bool unswap = geek(s1.substr(0, i), s2.substr(0, i)) && geek(s1.substr(i), s2.substr(i));
            bool swap = geek(s1.substr(n1-i), s2.substr(0, i)) && geek(s1.substr(0, n1-i), s2.substr(i));

            res |= (swap || unswap);
        }

        return dp[s1 + ' ' + s2] =res;
    } 
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        int n1 = s1.length();
        int n2 = s2.length();
        if(n1 != n2) return false;
        return geek(s1, s2);
    }
};