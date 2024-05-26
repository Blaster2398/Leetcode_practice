class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> found(nums.size()+1, false);
        for(int i = 0; i < nums.size(); i++){
            if(found[nums[i]] ==true){
                return nums[i];
            }
            found[nums[i]] = true;

        }
        return nums[0];
    }
};