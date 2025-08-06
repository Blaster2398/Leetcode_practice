class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if(n+m > 3*k) return 0;
        if(n <= k && m <=k) return 0;



        // 3 cases both are greater than k 
        // one is greater than k * 2
        if(n > k & m > k){
            return (n-k)*(1LL*k) + (m-k)*(1LL*k);
        }
        else if(n > k){
            return (n-k)*(1LL*k);
        }
        else return (m-k)*(1LL*k);
    }
};