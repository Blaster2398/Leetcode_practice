class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = INT_MIN;
        int preSum = 0;
        for(int i =0; i < nums.size(); i++){
            int prev =preSum;
            preSum = preSum + nums[i];
            if(preSum == prev){
                res= max(res,preSum);
                preSum =0;
            }
        }
        res= max(res,preSum); // do it for the last set of ones
        return res;
    }
};