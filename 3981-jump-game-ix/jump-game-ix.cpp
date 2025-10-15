class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        // we will create 2 vectors prefix max and suffix min 
        // the result will be mostly the prefix max but in some cases when the pre[i] > suff[i+1]
        // we can aslo go the right indexes and get their answer and it is guranteed to be larger
        // or equal to the crrent answer
        int n = nums.size();
        vector<int> res(n) , pre(n), suff(n);
        pre[0] = nums[0];
        suff[n-1] = nums[n-1];
        for(int i = 1; i < n; i++) pre[i] = max(pre[i-1], nums[i]);
        for(int i = n-2; i >= 0; i--) suff[i] = min(suff[i+1], nums[i]);

        res[n-1] = pre[n-1]; // this will be the largest value in array
        for(int i = n-2; i >= 0; i--){
            res[i] = (pre[i] > suff[i+1]) ? res[i+1] : pre[i];
        }
        return res;
    }
};