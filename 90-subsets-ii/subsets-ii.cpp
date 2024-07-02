class Solution {
public:
    void f(vector<int>& nums, int ind, set<vector<int>> & res, vector<int> temp){
        // base cases
        if(ind == nums.size()){
            sort(temp.begin(),temp.end());
            res.insert(temp);
            return;
        }
        // take - not take 

        f(nums, ind+1, res, temp);

        temp.push_back(nums[ind]);
        f(nums, ind+1, res, temp);
        temp.pop_back();
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        f(nums, 0, res, {});
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};