class Solution {
public:
    int minOperationsBrute(vector<int>& nums) {
        unordered_set<int> unique(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(auto num : unique){
            if(num == 0) continue;
            int i = 0;
            while(i < n){
                if(num == nums[i]){
                    ans++;
                    while(i < n && nums[i] >= num) i++;
                }
                i++;
            }
        }
        return ans;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int cnt = 0;
        for(int i = 0; i< n; i++){
            int num = nums[i];
            while(!st.empty() && st.top() > num){
                st.pop();
            }
            if(st.empty() || st.top() < num){
                if(num > 0) cnt++;
                st.push(num);
            }
        }

        return cnt;
    }
};