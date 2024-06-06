class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) {
            return 1.0;
        }

        if(n < 0){return pow(x,n+1)/x;}
        else{ return pow(x,n-1)*x;}
        
    }
};