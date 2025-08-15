class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, char> a;
        unordered_map<char, char> b;

        for(int i = 0; i < s.size(); i++){
            char sc = s[i] , tc = t[i];
            if(a.count(sc) && a[sc] != tc) return false;
            if(b.count(tc) && b[tc] != sc) return false;
            a[sc] = tc;
            b[tc] = sc;
        }

        return true;
    }
};