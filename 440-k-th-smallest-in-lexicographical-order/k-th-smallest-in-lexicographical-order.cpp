class Solution {
    // this will help us to clalculate the numbers of steps involved from transistion from
    // curr -> curr +1
    int helpr(int n, long prefix1, long prefix2){
        int steps = 0;
        while(prefix1 <= n){
            steps += min((n+1)* 1L, prefix2) - prefix1;
            prefix1 = 10 * prefix1;
            prefix2 = 10 * prefix2;
        }
        return steps;
    }
public:
    // this will decrease the number of steps bw curr -> curr2 from k so that when k = 0 
    // print the number curr
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;

        while(k > 0){
            int steps = helpr(n, curr, curr + 1);
            if(steps <= k){
                curr++;
                k -= steps;
            }
            else{
                curr = curr * 10;
                k--;
            }
        }
        return curr;
    }
};