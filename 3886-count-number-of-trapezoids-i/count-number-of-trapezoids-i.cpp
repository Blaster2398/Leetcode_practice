class Solution {
public:
    const int mod = 1000000007;
    using ll = long long;
    int countTrapezoids(vector<vector<int>>& points) {
        map<ll, ll> levels;
        for(int i = 0; i < points.size(); i++){
            levels[points[i][1]]++;
        }
        int total = 0;
        for(auto &[y, size] : levels){
            long long lines = (size*(size-1)/2) % mod;
            total += lines;
        }


        long long count = 0;
        for(auto &[y, size] : levels){
            long long lines = (size*(size-1)/2) % mod;
            count = (count + (lines * (total - lines)) % mod) % mod;
            total -= lines;
        }

        return (int)count;
    }
};