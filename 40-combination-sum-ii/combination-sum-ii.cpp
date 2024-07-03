class Solution {
public:
    void f(vector<int>& nums, int t, int ind, vector<vector<int>>& res, vector<int>& temp){
        // base cases 
        if(t == 0){
            res.push_back(temp);
            return;
        }

        // do some stuff
        for(int i = ind; i < nums.size(); i++){
            // constraints
            if(nums[i] > t) break;   // as the numbers ahead are grater (ascending order)
            if(i > ind && nums[i] == nums[i -1]) continue;   // to avoid redundant elements

            temp.push_back(nums[i]);
            f(nums, t- nums[i], i+1, res, temp);
            temp.pop_back();
        }
        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        f(candidates, target, 0, res, temp);

        return res;
    }
    // void f(vector<int>& nums, int t, int ind, set<vector<int>>& res, vector<int>& temp){
    //     // base cases 
    //     if(t == 0){

    //         res.insert(temp);
    //         return;
    //     }
    //     if(t < 0  || ind >= nums.size()){
    //         return;
    //     }

    //     // take - not take problem
        
    //     temp.push_back(nums[ind]);
    //     f(nums, t-nums[ind], ind+1, res, temp);
    //     temp.pop_back();
    //     f(nums, t, ind+1, res, temp);
        
    // }
    // vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    //     set<vector<int>> res;
    //     vector<int> temp;
    //     sort(candidates.begin(), candidates.end());
    //     f(candidates, target, 0, res, temp);
    //     vector<vector<int>> ans(res.begin(), res.end());

    //     return ans;
    // }
};
