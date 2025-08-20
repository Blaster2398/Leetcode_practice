class Solution {
public:
    int countAll(vector<int>& nums, int k){
        int i = 0, j = 0;
        int odds = 0, count = 0;
        while(j < nums.size()){
            if(nums[j] & 1) odds++;
            while(odds > k){
                if(nums[i] & 1) odds--;
                i++;
            }
            count += j - i + 1;
            j++;
        }
        return count;
    }
    // same thoery of exclusin
    // find the subarrays with less than or equal to k odds and k-1 odds and then subtract 
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAll(nums, k) - countAll(nums, k-1);
    }
};