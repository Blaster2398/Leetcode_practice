class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach = 0, n = nums.size();
        int endofCurr= 0;
        int jump = 0;
        for(int i = 0; i < n-1; i++){
            if(i > maxReach) return -1;
            maxReach = max(maxReach, i + nums[i]);
            if(i >= endofCurr){
                endofCurr = maxReach;
                jump++;
            }

        }
        return jump;
    }
};