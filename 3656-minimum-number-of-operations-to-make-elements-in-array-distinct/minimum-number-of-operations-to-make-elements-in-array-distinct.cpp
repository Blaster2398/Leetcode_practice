class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // if (nums.size() < 3) return 0;  // no triplets possible

        unordered_map<int,int> mp;
        for (int x : nums) mp[x]++;

        int i = 0;
        int cnt = 0;
        while (i + 2 < nums.size()) {
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];

            bool anyLeft = false;
            for (auto& [key, n] : mp) {
                if (n > 1) anyLeft = true;
            }
            if (!anyLeft) break;

            mp[a]--; if (mp[a] == 0) mp.erase(a);
            mp[b]--; if (mp[b] == 0) mp.erase(b);
            mp[c]--; if (mp[c] == 0) mp.erase(c);

            cnt++;
            i += 3;
        }

        for (auto& [key, n] : mp) {
            if (n > 1) cnt++;
        }

        return cnt;
    }
};
