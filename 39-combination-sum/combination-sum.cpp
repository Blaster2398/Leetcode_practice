class Solution {
public:
    void f(vector<int>& nums, int t, int ind, set<vector<int>>& st, vector<int> temp, int currSum){
        // base cases 
        if(currSum == t){
            sort(temp.begin(), temp.end());
            st.insert(temp);
            return;
        }
        if(ind == nums.size()){
            return ;
        }

        // take - not take problem
        if(currSum < t){
            temp.push_back(nums[ind]);
            f(nums, t, ind, st, temp, currSum + nums[ind]);
            temp.pop_back();
        }
        f(nums, t, ind+1, st, temp, currSum);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> st;

        f(candidates, target, 0, st, {}, 0);
        vector<vector<int>> res(st.begin(), st.end());

        return res;
        
    }
};