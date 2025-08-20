class Solution {
public:
    int countAll(vector<int>& nums, int k){
        int i = 0, j = 0;
        int count = 0, sum = 0;

        if(k < 0) return 0;
        while(j < nums.size()){
            sum += nums[j];
            while(sum > k){
                sum -= nums[i];
                i++;
            }
            count += j - i + 1;
            j++;
        }
        return count;
    }
    // theory of exclusion 
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countAll(nums, goal) - countAll(nums, goal-1);
    }
};