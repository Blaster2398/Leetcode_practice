class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> res;
        unordered_map<int,int> nextGreaterMap; 

        // Find the next greater for all the elements in nums2
        for(int i = nums2.size()-1; i >= 0; i--) {
            while(!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            if(!s.empty()) {
                nextGreaterMap[nums2[i]] = s.top(); // the current top will be the next greater element for that element
            } 
            else {
                nextGreaterMap[nums2[i]] = -1;
            }
            s.push(nums2[i]);
        }
        
        for(auto i : nums1){
            res.push_back(nextGreaterMap[i]);
        }
        return res;
    }
};