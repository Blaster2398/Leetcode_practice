class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int count = 0;
        int maxi = 0;
        while(j < nums.size()){
            if(nums[j] == 0){
                count++;
                if(count > k){
                    maxi = max(maxi , j-i);
                    while(nums[i] != 0) i++;
                    i++;
                    count--;
                }
            }
            j++;
        }
        maxi = max(maxi , j-i);
        return maxi;
    }
};