class Solution {
public:
    bool isPal(string& s, int i , int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        
        int maxi = 0;
        // string res = "";
        int start = 0;
        int size = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                if(isPal(s, i, j) && j-i+1 > maxi){
                    start  =i;
                    maxi = j-i+1;
                }
            }
        }

        return s.substr(start, maxi);;
    }
};