// p - m 
// a - o
// r - r , k - r
// e - i 
// r - s
//===================================================
// p a r s e r
// m a k k e k
// a b c d e f g h i j k l m n o p q r s t u v w x y z 


// make a array (0 - 25) and whenever there is a change in the psosion check for all the 26 letters and  change in all the corresponding places 
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> alp(26);
        for(int i = 0; i < 26; i++){
            alp[i] = i;
        }
        
        for(int i = 0; i < s1.length(); i++){
            int c1 = s1[i] - 'a';
            int c2 = s2[i] - 'a';
            // take the updated values to find min or max not the index
            int mn = min(alp[c1], alp[c2]);
            int mx = max(alp[c1], alp[c2]);
            for(int j = 0; j < 26; j++){
                if(alp[j] == mx){
                    alp[j] = mn;
                }
            }
        }
        string res = "";
        for(int i = 0; i < baseStr.length(); i++){
            int c = baseStr[i] - 'a';
            int neu = alp[c];
            char ch = 'a' + neu;
            res += ch;
        }

        return res;

    }
};













