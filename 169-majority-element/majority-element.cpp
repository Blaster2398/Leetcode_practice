class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=0;
        unordered_map<int,int> mp;
        int n = nums.size();
        int n_2 = n/2;
        for(auto i : nums){
            mp[i]++;
        }

        for(auto i : mp){
            if(i.second>n_2){
                res = i.first;
            }
        }
        return res;
    }
};