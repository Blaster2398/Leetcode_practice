class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort the intervals by their start times
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        for (const auto& interval : intervals) {
            // If result is empty or the current interval does not overlap with the previous one
            if (result.empty() || result.back()[1] < interval[0]) {
                result.push_back(interval);
            } else {
                // If there is an overlap, merge the current interval with the previous one
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
};