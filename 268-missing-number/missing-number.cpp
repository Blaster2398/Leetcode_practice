class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int temp = 0;
        for(auto i : nums){
            temp ^= i;
        }
        for(int i = 0; i <= nums.size(); i++){
            temp ^= i;
        }

        return temp;
    }
};