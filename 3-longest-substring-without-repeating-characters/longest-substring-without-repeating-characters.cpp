class Solution {
public:
    int lengthOfLongestSubstring1(string s) {
        
        int res = 0;
        int left = 0, right = 0;
        unordered_map<char, int> st;

        while(right < s.size()){
            if(st.find(s[right]) != st.end()){
                // either we have to update the left to the found location +1 
                //but it can be out of range of l and r 
                left = max(left, st[s[right]] +1);
            }

            // for each turn updarte the newly found character in the map 
            st[s[right]] = right;
            res = max(res, right - left + 1);
            right ++;
        }
        return res;
    }


    int lengthOfLongestSubstring(string s) {
        
        int res = 0;
        int left = 0, right = 0;
        // unordered_map<char, int> st;
        unordered_set<int> st;

        while(right < s.size()){
            if(st.find(s[right]) != st.end()){
                while (left < right && st.find(s[right]) != st.end()) {
                    st.erase(s[left]);
                    left++;
                }
            }

            st.insert(s[right]);
            res = max(res, right - left + 1);
            right ++;
        }
        return res;
    }
};