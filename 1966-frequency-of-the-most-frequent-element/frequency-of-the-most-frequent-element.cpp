class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // Sort the array in ascending order
        sort(nums.begin(), nums.end());
        
        long long windowSum = 0;  // Sum of elements in the current window
        int left = 0;  // Left pointer of the sliding window
        int maxFreq = 0;  // Maximum frequency
        
        // Iterate through the array with the right pointer
        for (int right = 0; right < nums.size(); right++) {
            long long target = nums[right];
            windowSum += target;
            
            // Shrink the window if increment required exceeds k
            while ((long long)(right - left + 1) * target - windowSum > k) {
                windowSum -= nums[left];
                left++;
            }
            
            // Update maximum frequency
            maxFreq = max(maxFreq, right - left + 1);
        }
        
        return maxFreq;
    }
};