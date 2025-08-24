class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n = nums.size();
        int missing= 0;
        int idx = 0;
        int num = 1;
        while(true){
            if(idx < nums.size() && nums[idx] == num){
                idx++;
            }
            else{
                missing++;
                if(missing == k) return num;
            }
            num++;
        }

    }
};