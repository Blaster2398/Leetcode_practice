class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool ans = false;
        for(int i = 0; i < n; i++){
            int min = nums[i];
            int check = true;
            for(int j = i+1; j < n+i; j++){
                if(nums[j % n] < min){
                    check = false;
                    break;
                }
                min = nums[j % n];
            }
            ans = ans || check;
        }
        return ans;
    }
};