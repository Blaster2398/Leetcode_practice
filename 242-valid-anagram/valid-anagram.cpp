class Solution {
public:
    bool isAnagram(string s, string t) {
        int sa[26] = {0};
        int ta[26] = {0};

        for(int i = 0, j = 0; (i < s.size()) || (j < t.size()) ; i++, j++){
            if(i < s.size()){
                sa[s[i]-'a']++;
            }
            if(j < t.size()){
                ta[t[i]-'a']++;
            }
        }
        
        for(int i = 0; i < 26; i++){
            if(sa[i] != ta[i]){
                return false;
            }
        }
        return true;
    }
};