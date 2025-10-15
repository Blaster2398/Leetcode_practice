class Solution {
public:
    int scheduleCourse(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];  // sort by deadline
        });

        priority_queue<int> pq;
        int time = 0;

        for (auto &course : v) {
            int duration = course[0];
            int deadline = course[1];

            time += duration;
            pq.push(duration);

            if (time > deadline) {
                time -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};
