class Solution {
// public:
//     long long coloredCells(int n) {
//         long long res = 1;
//         for(long long i = 0; i < n; i++){
//             res = res + 4*i;
//         }
//     return res;
//     }
// };
public :    
    long long coloredCells(int _n){
        long long n = _n;
        return 1 + 2 *(n) * (n-1);
    }
};