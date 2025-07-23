class Solution {
public:
    long long dp[65][2][64];  // position , tight, ones
    string binary;
    set<int> validPopCounts;

    set<int> computeValidPopcount(int k){
        set<int> valid;
        for(int c = 1; c <= 64; c++){
            int x = c, depth = 0;
            while(x > 1){
                x = __builtin_popcount(x);
                depth++;
            }
            if(depth == k-1) valid.insert(c);
        }
        return valid;
    }

    string toBinary(long long n){
        string s = "";
        while(n > 0){
            s += (n % 2) + '0';
            n /= 2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    
    // this is digit dp
    long long dfs(int pos, bool tight, int ones){
        if(pos == binary.size()) return validPopCounts.count(ones) ? 1 : 0;

        if(dp[pos][tight][ones] != -1) return dp[pos][tight][ones];

        int limit = tight ? binary[pos] - '0' : 1;
        long long res = 0;
        for(int i = 0; i <= limit; i++){
            bool newTight = tight && (i == limit);
            res += dfs(pos + 1, newTight, ones + i);
        }
        return dp[pos][tight][ones] = res;
    }

    long long popcountDepth(long long n, int k) {
        // the key observation is numsber -> p1 -> p2 ->>>  1 ( the value of P1 is bw 0 - 64 )
        // so whatever depth we want we have to first fill the 64 values and then check the no of 
        // 1's they should have 
        // then loop through the 1 - n and see which numbers fit
        // something called as digit Dp is used here 
        if(k == 0) return 1;

        validPopCounts = computeValidPopcount(k);
        if(validPopCounts.empty()) return 0;

        binary = toBinary(n);
        memset(dp, -1, sizeof(dp));

        long long result = dfs(0, true, 0);

        // edge case as  depth of n = 1 is 0 but will show 1 
        if(k == 1 && validPopCounts.count(1)) result -= 1;
        return result;
    }
};