class Solution {
public:
    double myPow(double x, int n) {
        double ans =1;
        if(x == 0 || x==1){
            return x;
        }
        if(n<0){
            x = 1/x;
            ans = ans*x;
            n = -(n+1);
        }

        while(n>0){
            if(n%2 ==1){
                ans = x*ans;
                n = n-1;
            }
            else{
                x= x*x;
                n = n/2;
            }
        }
        return ans;
        
    }
    // double myPow(double x, int n) {
    //     if(n == 0) {
    //         return 1.0;
    //     }

    //     if(n < 0){return pow(x,n+1)/x;}
    //     else{ return pow(x,n-1)*x;}
        
    // }
};