class Solution {
public:
    long long coloredCells(int n) {
        long long res = 1;
        for(long long i = 0; i < n; i++){
            res = res + 4*i;
        }
    return res;
    }
};