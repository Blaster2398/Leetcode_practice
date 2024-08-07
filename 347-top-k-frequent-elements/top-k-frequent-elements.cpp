class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        for(int i = 0;i< nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<int>res;
        priority_queue<pair<int,int>> pq;
        for(auto i : mp){
            pq.push(make_pair(i.second, i.first));
        }

        for(int i =0; i < k;i ++){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};