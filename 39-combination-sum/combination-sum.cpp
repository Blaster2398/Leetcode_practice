class Solution {
public:
    void f(vector<int>& nums, int t, int ind, vector<vector<int>>& st, vector<int>& temp, int currSum){
        // base cases 
        if(currSum == t){
            st.push_back(temp);
            return;
        }
        if(currSum > t || ind >= nums.size()){
            return ;
        }

        // take - not take problem
        
        temp.push_back(nums[ind]);
        f(nums, t, ind, st, temp, currSum + nums[ind]);
        temp.pop_back();
        f(nums, t, ind+1, st, temp, currSum);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> st;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        f(candidates, target, 0, st, temp, 0);

        return st;
        
    }
};