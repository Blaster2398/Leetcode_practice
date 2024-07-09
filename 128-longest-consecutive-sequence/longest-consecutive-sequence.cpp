class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(), nums.end());

        int lastSmaller = INT_MIN;
        int cnt = 0;
        int longest = 1;

        for(int i = 0; i < n; i++){
            if(nums[i] == lastSmaller+1){
                cnt++;
                // lastSmaller = nums[i];
                // cout << nums[i] <<endl;
            }
            else if(nums[i] != lastSmaller){
                cnt = 1;
            }
            lastSmaller = nums[i];
            longest = max(longest, cnt);
        }
        return longest;

    }
    
    // int longestConsecutive(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n == 0) return 0;

    //     unordered_set<int> st;
    //     for(auto it : nums){
    //         st.insert(it);
    //     }

    //     int longest = 1;
    //     for(auto it : nums){
    //         if(st.find(it - 1) == st.end()){
    //             int cnt = 1;
    //             int x = it;
    //             while(st.find(x + 1) != st.end()){
    //                 x = x+1;
    //                 cnt++;
    //             }
    //             longest = max(longest, cnt);
    //         }
    //     }
    //     return longest;
    // }
};