class Solution {
public:
    const int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    string Subtract1(string num){
        if(num == "0") return "0";

        int i = num.size() -1;
        while(i >= 0 && num[i] == '0'){
            num[i] = '9';
            i--;
        }

        if(i >= 0) num[i]--;

        // remove leading zeros 
        int pos = 0;
        while (pos + 1 < num.size() && num[pos] == '0') pos++;
        num = num.substr(pos);

        return num;
    }

    // now handle a range [min_sum, max_sum] inside the DP
    int geek(int ind, int sum, bool tight, string& num, int min_sum, int max_sum){
        // base case 
        if(ind >= num.size()) return (sum >= min_sum && sum <= max_sum) ? 1 : 0;
        if(dp[ind][sum][tight] != -1) return dp[ind][sum][tight];

        int limit = tight ? num[ind]-'0' : 9;
        int ways = 0;
        for(int digit = 0; digit <= limit; digit++){
            bool newTight = (tight && digit == limit);
            ways = (ways + geek(ind+1, sum + digit, newTight, num, min_sum, max_sum)) % mod;
        }

        return dp[ind][sum][tight] = ways;
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        string num1minus = Subtract1(num1);

        // count numbers <= num2 with digit sum in [min_sum, max_sum]
        dp.assign(num2.size(), vector<vector<int>>(9*num2.size()+1, vector<int>(2, -1)));
        int Gnum2 = geek(0, 0, 1, num2, min_sum, max_sum);

        // count numbers <= num1-1 with digit sum in [min_sum, max_sum]
        dp.assign(num1minus.size(), vector<vector<int>>(9*num2.size()+1, vector<int>(2, -1)));
        int Gnum1 = geek(0, 0, 1, num1minus, min_sum, max_sum);

        int ans = (Gnum2 - Gnum1 + mod) % mod;
        return ans;
    }
};
