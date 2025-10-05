class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq (26, 0);
        vector<int> vis (26, 0);
        for(char c : s) freq[c-'a']++;

        stack<char> st;

        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            freq[c-'a']--;
            
            if(vis[c-'a']){
                continue;
            }
            while(!st.empty() && freq[st.top() - 'a'] > 0 && c < st.top()){
                vis[st.top() - 'a'] = 0;
                st.pop();
            }
            st.push(c);
            vis[c-'a'] = 1;
        }

        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;


    }
};