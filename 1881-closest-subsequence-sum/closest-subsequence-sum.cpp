class Solution {
public:
    vector<int> partitionSum(vector<int>& nums, int start, int end, int offset){
        vector<int> res;
        int n = end - start + 1;
        for(int i = 0; i < ( 1 << n ); i++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                if(i & (1 << j)){
                    sum += nums[j + offset];
                }
            }
            res.push_back(sum);
        }
        return res;     
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        // for this question the steps are a bit tricky
        // 1) we have to divide the arr into 2 parts 
        // 2) then find all subsetsum for them separately and store in a vector
        // 3) then sort the 2ndHalf so that we can use bianry search 
        // 4) then for each subset sum in 1stHalf(let x) bing the lowerbound in 2nd for goal - x 

        int n = nums.size();
        vector<int> first = partitionSum(nums, 0, n/2-1, 0);
        vector<int> second = partitionSum(nums,n/2, n-1, n/2);

        sort(second.begin(), second.end());

        int res=INT_MAX;
        for(int i = 0; i < first.size(); i++){
            int lb = lower_bound(second.begin(), second.end(), goal - first[i]) - second.begin();

            if(lb > 0){
                res = min( res,abs(goal - first[i] - second[lb-1]));
            }
            if(lb < second.size()){
                res = min( res,abs(goal - first[i] - second[lb]));
            }
        }
        return res;
    }
};