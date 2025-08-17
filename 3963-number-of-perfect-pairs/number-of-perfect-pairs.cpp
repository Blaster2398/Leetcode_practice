class Solution {
public:
using ll = long long;
    long long perfectPairs(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 2) return 0;

        vector<long long> arr;
        for (int x : nums) arr.push_back(llabs(x));

        sort(arr.begin(), arr.end());

        
        // we know that for any case when x <= y we should have 2*x >= y
        ll ans = 0;
        int j = 1;
        for(int i = 0; i < n-1; i++){
            if(j < i) j = i +1;
            while(j < n && arr[i]*2 >= arr[j]) j++;
            ans += j - i -1;
        }
        return ans;
    }
};