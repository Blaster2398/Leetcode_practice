class Solution {
public:
    int sumDigits(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums2 = nums;
        sort(nums2.begin(), nums2.end(), [&](int a, int b){
            int da = sumDigits(a);
            int db = sumDigits(b);
            if(da == db) return a < b;
            return da < db;
        });

        // store the orignal indexes in the nums array 
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]] = i;
        }

        //////////////////////////////////////////////
        vector<int> vis(n, false);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] || nums[i] == nums2[i]) continue;
            int size = 0;
            int j = i;
            while(!vis[j]){
                vis[j] = true;
                j = mp[nums2[j]];
                size++;
            }
            if(size > 1){
                count += size - 1;
            }
        }

        return count;
    }
};