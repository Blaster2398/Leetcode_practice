class Solution {
public:
    bool check(vector<int>& nums) {
        int flex = 0;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(nums[(i+1+n)%n ] < nums[i] ){
                flex++;
            }
        }

        return (flex == 0 || flex == 1) ? 1 : 0 ;
    }
};