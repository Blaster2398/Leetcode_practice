class Solution {
public:
    int maxDistinctElements2(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            int sub = -k;
            while(st.count(num+sub) != 0 && sub <= k){
                sub++;
            }
            cout << "inserting" << num << '+' << sub << "= " << num+sub << endl;
            if (sub <= k) st.insert(num+sub);
        }
        return st.size();
    }
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_set<int> st;
        int prev = INT_MIN;

        for (int num : nums) {
            // try to place the smallest possible value in [num-k, num+k]
            int candidate = max(num - k, prev + 1);
            if (candidate <= num + k) {
                st.insert(candidate);
                prev = candidate;
            }
        }
        return st.size();
    }

};