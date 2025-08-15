class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";
        s+= " ";

        for(int i =0; i < s.length(); i++){
            if(s[i] == ' ' ){
                st.push(temp);
                temp = "";
            }
            else{
                temp += s[i];
            }
        }
            
        string res = "";
        while(!st.empty()){
            cout << st.top() << " size " << st.top().length() <<endl;
            if(st.top().length() != 0){
                res += st.top()+ " ";
            }
            st.pop();
        }
        
        // this is for the last " " that was added 
        res.pop_back();
        
        return res;
    }
};