class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int maxi = 0;
        sort(points.begin(), points.end());
        for(int i = 0; i < points.size()-1; i++){
            maxi = max(maxi, (points[i+1][0] - points[i][0]));
        }

        return maxi;
    }
};