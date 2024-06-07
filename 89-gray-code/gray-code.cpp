

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for(int i =0; i< pow(2,n); i++){
            int num1 = i;
            int num2 = i >> 1;
            int ans = num1 ^ num2;

            res.push_back(ans);
        }
        return res;
    }
};