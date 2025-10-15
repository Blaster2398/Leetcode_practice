class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // the concept is firsly we find the prefix array 
        // and then take the modulo k so that if the modulo repeats 
        // we can say that the prefix sum / sum bw those 
        // indexes might have been divisible by k
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum  =0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int mod = ((sum % k) + k) % k;
            if(mp.count(mod)) ans += mp[mod];
            mp[mod]++;
        }

        return ans;
        
    }
};