class Solution {
public:
    int atMost(vector<int>&nums, int k){
        unordered_map<int, int> hash;
        int i = 0, j = 0; 
        int count = 0;
        while(j < nums.size()){
            hash[nums[j]]++;
            while(hash.size() > k){
                hash[nums[i]]--;
                if(hash[nums[i]] == 0) hash.erase(nums[i]);
                i++;
            }
            count += j-i+1;
            j++;
        }
        return count;
    }
    // the concept of exclusion
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};