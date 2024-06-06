class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> mp;
        int n = nums.size();
        int n_3 = floor(n/3);
        for(auto i : nums){
            mp[i]++;
        }

        for(auto i : mp){
            if(i.second>n_3){
                res.push_back(i.first);
            }
        }
        return res;
    }
};