class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
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
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> result;
    //     for(int i =0; i< nums.size(); i++){
    //         for(int j =i+1; j <nums.size();j++){
    //             if(nums[i] +nums[j] == target){
    //                 result.push_back(i);
    //                 result.push_back(j);
    //                 return result;
    //             }
    //         }
    //     }
    //     return result;
    // }
};