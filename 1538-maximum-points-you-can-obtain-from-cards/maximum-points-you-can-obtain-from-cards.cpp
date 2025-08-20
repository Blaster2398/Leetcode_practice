class Solution {
public:
    using ll = long long;
    int maxScore(vector<int>& nums, int k) {

        int n = nums.size();
        int i = n - k;
        int j = n - k;
        nums.insert(nums.end(), nums.begin(), nums.begin() + k);
        
        ll sum = 0;
        ll m = 0;
        while(j < nums.size()){
            sum += nums[j];
            if(j-i+1 > k){
                sum -= nums[i];
                i++;
            }
            m = max(m, sum);
            j++;
        }
        return m;
    }
};