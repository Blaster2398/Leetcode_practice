class Solution {
public:
    const int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    string Subtract1(string num){
        if(num == "0") return "0"; // fixed: handle zero properly

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

    int geek(int ind, int sum, bool tight, string& num, int target){
        // base case 
        if(sum > target) return 0;
        if(ind >= num.size()) return 1;
        if(dp[ind][sum][tight] != -1) return dp[ind][sum][tight];
        //limit finder
        int limit = (tight ? num[ind]-'0' : 9);

        // number of ways 
        int ways = 0;
        for(int digit = 0; digit <= limit; digit++){
            bool newTight = (tight && digit == limit);
            ways = (ways + geek(ind+1, sum + digit, newTight, num, target)) % mod;
        }

        // return 
        return dp[ind][sum][tight] = ways;
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        // what we have  to do is make a function that will count the number of distinct numbers
        // that are smaller than num and has digitSum less that max_Sum / min_Sum accordingly 

        string num1minus = Subtract1(num1);

        // count numbers <= num2 with digit sum in [min_sum, max_sum]
        dp.assign(num2.size(), vector<vector<int>>(max_sum+1, vector<int>(2, -1)));
        int countUpToNum2Max = geek(0, 0, 1, num2, max_sum);

        dp.assign(num2.size(), vector<vector<int>>(min_sum, vector<int>(2, -1))); // min_sum - 1
        int countUpToNum2Min = geek(0, 0, 1, num2, min_sum - 1);

        int Gnum2 = (countUpToNum2Max - countUpToNum2Min + mod) % mod;

        // count numbers <= num1-1 with digit sum in [min_sum, max_sum]
        dp.assign(num1minus.size(), vector<vector<int>>(max_sum+1, vector<int>(2, -1)));
        int countUpToNum1Max = geek(0, 0, 1, num1minus, max_sum);

        dp.assign(num1minus.size(), vector<vector<int>>(min_sum, vector<int>(2, -1)));
        int countUpToNum1Min = geek(0, 0, 1, num1minus, min_sum - 1);

        int Gnum1 = (countUpToNum1Max - countUpToNum1Min + mod) % mod;


        int ans = (Gnum2 - Gnum1) % mod;
        if(ans < 0) ans += mod;
        return ans;
    }
};
