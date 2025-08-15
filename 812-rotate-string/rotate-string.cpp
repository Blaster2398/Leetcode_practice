class Solution {
public:
    bool rotateString(string s, string goal) {
        string st = s + s;
        int i = 0, sz = s.size();
        while(i+ sz < st.size()){
            if(goal == st.substr(i, sz)) return true;
            cout << st.substr(i, sz) <<endl;
            i++;
        }
        return false;
    }
};