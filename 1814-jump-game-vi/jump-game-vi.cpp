class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        // why we will use the sliding window maximum 
        // at each step we want to see the max value that 
        // we coud have got from the k window behind it 
        deque<pair<int,int>> dq;
        dq.push_back({nums[0], 0});
        for(int i = 1; i < nums.size(); i++){
            while(!dq.empty() && dq.front().second + k < i) dq.pop_front();
            int cost = dq.front().first + nums[i];
            while(!dq.empty() && dq.back().first < cost) dq.pop_back();
            dq.push_back({cost, i});
        }
        return dq.back().first;

    }
};