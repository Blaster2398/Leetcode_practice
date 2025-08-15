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
        if(res[res.size()-1] == ' '){
            res = res.substr(0,res.size()-1);
        }
        
        return res;
    }
};