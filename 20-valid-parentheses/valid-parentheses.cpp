class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{' ){
                st.push(s[i]);
            }
            else if(st.size()>=1){
                char test =st.top();
                if(s[i] == ')' && test == '(' || s[i] == ']' && test == '[' || s[i] == '}' && test == '{'  ){
                    st.pop();
                }
                else{
                    return false;
                }

            }
            else{
                return false;
            }
        }
        if(st.size() == 0){
            return true;
        }

        else{
            return false;
        }
    }
};