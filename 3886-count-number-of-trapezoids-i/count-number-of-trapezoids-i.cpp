class Solution {
public:
    const int mod = 1000000007;
    int countTrapezoids(vector<vector<int>>& points) {
        map<int, vector<vector<int>>> levels;
        for(int i = 0; i < points.size(); i++){
            levels[points[i][1]].push_back(points[i]);
        }
        int total = 0;
        map<int, long long> noOfLines;
        for(auto &[y, vec] : levels){
            long long size = vec.size();
            long long lines = (size*(size-1)/2) % mod;
            total += lines;
            noOfLines[y] = lines;
        }

        long long count = 0;
        for(auto &[y, lines] : noOfLines){
            count = (count + (lines*(total-lines) % mod)) % mod;
            total -= lines;
        }

        return (int)count;
    }
};