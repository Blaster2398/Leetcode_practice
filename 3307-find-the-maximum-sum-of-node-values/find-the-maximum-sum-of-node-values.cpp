class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
       // there is a very interesting logic of ticks and crosses here 
       // ✅ -> there is a  potential to increase the value 
       // ❌ -> xorring will decrease the value 

       // check the count of tick marks if its even then there is a definite way to convert all of 
       // them to crosses and 
       // if there is odd number of ticks keep track of the lowest increase in the transition from
       // xorring which can be subtracted at the last 

       long long sum = 0;
        long long count = 0;   // ✅ count
        long long discardedVal = LONG_MAX;

        for(int i = 0; i < nums.size(); i++) {
            int xored = nums[i] ^ k;

            if (nums[i] > xored) {
                sum += nums[i];
                discardedVal = min(discardedVal, (long long)(nums[i] - xored));
            } else {
                sum += xored;
                count++;
                discardedVal = min(discardedVal, (long long)(xored - nums[i]));
            }
        }

        return (count % 2 != 0) ? sum - discardedVal : sum;
    }
};