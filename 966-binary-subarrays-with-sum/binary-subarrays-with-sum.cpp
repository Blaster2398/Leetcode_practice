class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSum;
        int sum = 0;
        int count = 0;
        prefixSum[0] = 1;  

        for (int num : nums) {
            sum += num;
            if (prefixSum.find(sum - k) != prefixSum.end()) {
                count += prefixSum[sum - k];
            }
            prefixSum[sum]++;
        }

        return count;
    }
};