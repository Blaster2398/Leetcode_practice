class Solution {
public:
    bool isPalindrome(int x) {
        string y = to_string(x);
        int n = y.size();
        for(int i = 0; i < y.size()/2; i++){
            if(y[i] != y[n-i-1]){
                return false;
            }
        }
        return true;
    }
};