class Solution {
public:
    const int MOD = 1e9 + 7;
    using ll = long long;
    int n;
    vector<vector<int>> hat_to_people;
    unordered_map<ll, int> dp; // key = (hat << n) | mask

    int geek(int hat, ll mask) {
        if(mask == (1LL << n) - 1) return 1; // all people assigned
        if(hat > 40) return 0;               // no more hats left

        ll key = (mask) | ((ll)hat << n);    // unique key for memoization
        if(dp.count(key)) return dp[key];

        int ways = geek(hat + 1, mask); // skip this hat
        for(int person : hat_to_people[hat]){
            if((mask >> person) & 1LL) continue; // already assigned
            ways = (ways + geek(hat + 1, mask | (1LL << person))) % MOD;
        }

        return dp[key] = ways;
    }

    int numberWays(vector<vector<int>>& hats) {
        n = hats.size();
        hat_to_people.assign(41, {}); // hats 1..40
        for(int person = 0; person < n; person++){
            for(int h : hats[person]){
                hat_to_people[h].push_back(person);
            }
        }
        dp.clear();
        return geek(1, 0LL); // start from hat 1, mask 0
    }
};
