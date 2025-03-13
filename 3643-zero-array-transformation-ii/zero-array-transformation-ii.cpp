class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n+1, 0);
        int pos = 0;
        int sum = 0;
        for(int i = 0; i < n; ++i){
            // we have to handel the query 
            while(sum + diff[i] < nums[i]){

                if(pos == queries.size()){
                    return -1;
                }

                int l = queries[pos][0];
                int r = queries[pos][1];
                int val = queries[pos][2];
                pos++;

                // skip past update 
                if(r < i) continue;
                
                // range update in o(1)
                diff[max(l, i)] += val;
                diff[r + 1] -= val; 
            }
            sum += diff[i];
        }
        return pos;
    }
};