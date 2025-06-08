class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        // first make all 1;
        vector<int> nums2 = nums;
        int n = nums.size();
        int count1 = 0;
        for(int i = 0 ; i < n - 1; i++){
            if(nums[i] == -1){
                count1++;
                nums[i] = nums[i] * -1;
                nums[i+1] = nums[i+1] * -1;
            }
        }
        if(nums[n-1] == -1){
            count1 = INT_MAX;
        }

        // now do it for -1;
        int count2 = 0;
        for(int i = 0 ; i < n - 1; i++){
            if(nums2[i] == 1){
                count2++;
                nums2[i] = nums2[i] * -1;
                nums2[i+1] = nums2[i+1] * -1;
            }
        }
        if(nums2[n-1] == 1){
            count2 = INT_MAX;
        }
        int count = min(count1, count2);
        return (count != INT_MAX && count <= k);

    }
};