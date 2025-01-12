class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = INT_MIN;
        int prevSum = 0;
        for(int i = 0 ; i < nums.size(); i++){
            int prev =  prevSum;
            prevSum += nums[i];
            if(prevSum == prev){
                res = max(res, prevSum);
                prevSum = 0;
            }
        }

        res = max(res, prevSum );
        return res;
    }
};