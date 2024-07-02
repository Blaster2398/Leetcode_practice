class Solution {
public:
    void f(vector<int>& nums, int t, int ind, vector<vector<int>>& st, vector<int>& temp){
        // base cases 
        if(t == 0){
            st.push_back(temp);
            return;
        }
        if(t < 0  || ind >= nums.size()){
            return;
        }

        // take - not take problem
        
        temp.push_back(nums[ind]);
        f(nums, t-nums[ind], ind, st, temp);
        temp.pop_back();
        f(nums, t, ind+1, st, temp);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> st;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        f(candidates, target, 0, st, temp);

        return st;
        
    }
};