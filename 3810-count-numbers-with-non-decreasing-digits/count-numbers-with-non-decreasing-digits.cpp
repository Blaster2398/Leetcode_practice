class Solution {
public:
    const int mod = 1e9 + 7;
    int base;
    vector<vector<vector<int>>> dp;

    
    string subtractOne(string s) {
        int i = s.size() - 1;
        while (i >= 0 && s[i] == '0') {
            s[i] = '9';
            i--;
        }
        if (i >= 0) s[i]--;
        if (s[0] == '0' && s.size() > 1) s.erase(s.begin());
        return s;
    }

    
    string baseConverter(string num, int b) {
        if (num == "0") return "0";

        string result = "";
        while (num != "0") {
            int remainder = 0;
            string next = "";

            // divide the number (in base 10 string) by 'b'
            for (char c : num) {
                int current = remainder * 10 + (c - '0');
                int quotient = current / b;
                remainder = current % b;
                if (!next.empty() || quotient != 0)
                    next += (quotient + '0');
            }

            result += (remainder + '0'); // store remainder for this step
            if (next.empty()) next = "0";
            num = next; // quotient becomes new number
        }

        reverse(result.begin(), result.end());
        return result;
    }


    int geek(int ind, int prev, int tight, string bound, int n) {
        if (ind >= n) return 1;
        if (dp[ind][prev + 1][tight] != -1) return dp[ind][prev + 1][tight];

        int limit = (tight) ? bound[ind] - '0' : base - 1;
        int ways = 0;

        for (int digit = 0; digit <= limit; digit++) {
            if (prev != -1 && digit < prev) continue;
            int newTight = (tight && digit == limit);
            ways = (ways + geek(ind + 1, digit, newTight, bound, n)) % mod;
        }

        return dp[ind][prev + 1][tight] = ways;
    }

    int countNumbers(string l, string r, int b) {
        base = b;

        string lb = subtractOne(l);
        string ub = r;

        if (b != 10) {
            lb = baseConverter(lb, b);
            ub = baseConverter(ub, b);
        }

        int n1 = ub.size();
        dp.assign(n1, vector<vector<int>>(b + 2, vector<int>(2, -1)));
        int rightCount = geek(0, -1, 1, ub, n1);

        int n2 = lb.size();
        dp.assign(n2, vector<vector<int>>(b + 2, vector<int>(2, -1)));
        int leftCount = geek(0, -1, 1, lb, n2);

        int ans = (rightCount - leftCount) % mod;
        if (ans < 0) ans += mod;
        return ans;
    }
};