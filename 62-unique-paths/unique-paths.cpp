class Solution {
public:
    int uniquePaths(int m, int n) {
        int M_N = m+n-2;
        int N = n-1;
        int M = m-1;
        double ans = 1;

        // we need to find M_N ( C ) N
        for(int i =1  ; i <= M ;i++){
            ans = ans * (N+i)/i;
        }
        return int(ans);
    }
    
};