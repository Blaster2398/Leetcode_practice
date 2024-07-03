class Solution {
public:
    void f(vector<int>& nums, vector<vector<int>> &res, int ind){
        if(ind == nums.size()){
            res.push_back(nums);
        }
        else{
            for(int i = ind; i < nums.size(); i++){
                swap(nums[i], nums[ind]);
                f(nums, res, ind+1);
                swap(nums[i], nums[ind]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        f(nums, res, 0);
        return res;
    }
};