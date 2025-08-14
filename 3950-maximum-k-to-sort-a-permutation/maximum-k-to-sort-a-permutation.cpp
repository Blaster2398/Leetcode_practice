class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int temp = ~0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i) temp &= nums[i];
        }
        if(temp == ~0) return 0;
        return temp;
    }
};