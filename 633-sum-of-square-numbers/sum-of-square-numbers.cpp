class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int a = 0; a <= sqrt(c); a++){
            int b = sqrt(c - a*a);
            if(b*b == c - a*a) return true;
        }
        return false;
    }
};