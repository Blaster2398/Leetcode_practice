class Solution {
public:
    bool isPal(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void f_rec(string s, int i, int n, vector<string>& temp, vector<vector<string>>& res){
        if(i == n){
            res.push_back(temp);
            return; 
        }

        for(int j = i; j < n; j++){
            if(isPal(s, i, j)){
                string t = s.substr(i, j-i+1);
                temp.push_back(t);
                f_rec(s, j+1, n, temp, res);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> res;
        vector<string> str;
        f_rec(s, 0, n, str, res);
        return res;
    }
};
