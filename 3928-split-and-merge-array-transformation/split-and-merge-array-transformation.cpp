class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        set<vector<int>> vis;
        queue<pair<vector<int>, int>> q;
        
        q.push({nums1, 0});
        vis.insert(nums1);

        while (!q.empty()) {
            vector<int> vec = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (vec == nums2) return steps;

            for (int l = 0; l < vec.size(); l++) {
                for (int r = l; r < vec.size(); r++) {
                    vector<int> temp1, temp2;

                    for (int i = 0; i < vec.size(); i++) {
                        if (i < l || i > r) temp1.push_back(vec[i]);
                        else temp2.push_back(vec[i]);
                    }

                    for (int i = 0; i <= temp1.size(); i++) {
                        vector<int> temp3;
                        for (int j = 0; j < i; j++) temp3.push_back(temp1[j]);
                        for (int j = 0; j < temp2.size(); j++) temp3.push_back(temp2[j]);
                        for (int j = i; j < temp1.size(); j++) temp3.push_back(temp1[j]);

                        if (!vis.count(temp3)) {
                            vis.insert(temp3);
                            q.push({temp3, steps + 1});
                        }
                    }
                }
            }
        }

        return -1;
    }
};
