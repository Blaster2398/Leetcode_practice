class Solution {
public:
    int n;
    unordered_map<string, int> dp;
    bool hasOverlap(string& s1, string& s2){
        int m1 = 0, m2 = 0;
        for(auto c : s1) m1 |= (1 << (c-'a'));
        for(auto c : s2) m2 |= (1 << (c-'a'));
        return (m1&m2);
    }

    int geek(vector<string>& stickers,vector<vector<int>>& dict,  string target){
        if(target.size() == 0) return 0;
        int ans = INT_MAX;

        if(dp.count(target)) return dp[target];
        
        vector<int> targ(26, 0);
        for(auto c : target) targ[c-'a']++;

        for(int i = 0; i < n; i++){
            if(!hasOverlap(stickers[i], target)) continue;
            // new target
            string new_target; 
            for(int j = 0; j < 26; j++){
                if(targ[j] > dict[i][j]) new_target += string(targ[j] - dict[i][j], 'a' + j); 
            }
            int temp =  geek(stickers, dict, new_target);
            if(temp != INT_MAX) ans = min(ans , 1 + temp);
        }

        return dp[target] = ans;
    }
    int minStickers(vector<string>& stickers, string target) {
        n = stickers.size();
        vector<vector<int>> dict(n, vector<int>(26, 0));
        for(int i = 0; i < n; i++){
            for(auto c : stickers[i]){
                dict[i][c-'a']++;
            }
        }
        int res = geek(stickers , dict, target);

        return (res == INT_MAX) ? -1 : res;

    }
};