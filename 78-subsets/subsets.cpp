class Solution {
public:
    void util(vector<vector<int>>& result, vector<int>& path, int ind, vector<int>& nums){
        result.push_back(path);
        for(int i = ind; i < nums.size();i++){
            path.push_back(nums[i]);
            util(result, path, i+1, nums);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        util(result, path, 0, nums);
        return result;
    }
};