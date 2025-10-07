class Solution {
public:
    bool isGood(string s){
        int z = 0, o = 0;
        for(auto c : s){
            if(c == '0') z++;
            else o++;
            if (z > o) return false;
        }
        return o == z;
    }
    string makeLargestSpecial(string s) {
        while(true){
            string best = s;
            for(int i = 0; i < s.size() - 1; i++){
                for(int j = i + 1; j < s.size(); j++){
                    for(int k = i + 1; k < j; k ++){
                        string a = s.substr(i, k-i+1);
                        string b = s.substr(k+1, j - k);
                        if(isGood(a) && isGood(b)){
                            string tmp = s.substr(0, i) + b + a + s.substr(j+1);
                            if(best < tmp) best = tmp;
                        }
                    }
                }
            }
            if(s == best) break;
            s = best;
        }

        return s;
    }
};