class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        if(nums.size() == 2) return (nums[0] > nums[1])? 0 : 1;
        int n = nums.size();
        int l = 0, h = n-1;
        while(l < h){
            int mid = (l + h)/2;
            if(nums[mid] >= nums[mid+1]){
                h = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};