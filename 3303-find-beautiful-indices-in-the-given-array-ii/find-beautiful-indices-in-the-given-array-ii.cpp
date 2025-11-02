class Solution {
public:
    vector<int> calculatelps(string s){
        int n = s.size();
        vector<int> lps(n, 0);
        int i = 1, j = 0;
        while(i < n){
            if(s[i] == s[j]){
                lps[i] = j+1;
                i++;j++;
            }
            else{
                while(j > 0 && s[i] != s[j]){
                    j = lps[j-1];
                }
                if(s[i] == s[j]){
                    lps[i] = j+1;
                    j++;
                }
                i++;
            }
        }
        return lps;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        string s1 = a + "$" + s;
        string s2 = b + "$" + s;
        int m1 = a.size();
        int m2 = b.size();
        int n = s.size();
        vector<int> lps1 = calculatelps(s1);
        vector<int> lps2 = calculatelps(s2);
        vector<int> aPos, bPos;
        for(int i = m1+1; i < s1.size(); i++){
            if(lps1[i] == m1) aPos.push_back(i - 2*m1);
        }
        for(int i = m2+1; i < s2.size(); i++){
            if(lps2[i] == m2) bPos.push_back(i - 2*m2);
        }

        // now the searching logic for all i in Apos 
        // find the lowebound of i-k and upper bound of i+k if they are diff then yes if not check
        vector<int> res;
        for(auto i : aPos){
            int lb = lower_bound(bPos.begin(), bPos.end(), i-k) - bPos.begin();
            int ub = upper_bound(bPos.begin(), bPos.end(), i+k) - bPos.begin();
            if(lb != ub){
                res.push_back(i);
            }
            else{
                if(lb == bPos.size() && ub == bPos.size()) continue;
                else if(bPos[lb] != i-k || bPos[ub] != i+k) continue;
                else{
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};