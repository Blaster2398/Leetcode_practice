class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> v;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) v.push_back(i);
        }

        int ans = 0;

        
        ans = max(ans, v[0]);

        ans = max(ans, (int)seats.size() - 1 - v.back());

        for (int i = 0; i + 1 < v.size(); i++) {
            int left = v[i], right = v[i + 1];
            ans = max(ans, (right - left) / 2);
        }

        return ans;
    }
};
