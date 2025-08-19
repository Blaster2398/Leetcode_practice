class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int l = 0,r = 0;
        int count = 0;
        while(r < s.size()){
            if(st.count(s[r]) == 0){
                st.insert(s[r]);
                count = max(count, r-l+1);
                r++;
            }
            else{
                st.erase(s[l]);
                l++;
            }
        }
        return count;
    }
};