class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            if(map.count(target - num)){
                return {map[target - num] , i};
            }

            map[num] = i;
        }
        return {-1, -1};
    }


















    vector<int> twoSum_complicated(vector<int>& nums, int target) {
        // using hashing 
        vector<int>res;
        unordered_map<int,int> mp;
        bool flag = false;
        int store = -1;
        for(int i =0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto it : mp){
            if(mp.count(target-it.first) && ((it.first != target -it.first) || it.second > 1)){
                flag =true;
                store = it.first;
            } 
        }
        for(int i =0; i < nums.size(); i++){
            if(flag == true && (nums[i] == store || nums[i] == target-store)){
                res.push_back(i);
            }
        }
        return res;
    }
    
};