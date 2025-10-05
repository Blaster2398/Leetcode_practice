class Solution {
public:
    using ll = long long;
    vector<vector<vector<vector<ll>>>> dp;
    ll geek(ll ind, ll carry, ll endA, ll endB, string s){
        // base case 
        if(ind < 0){
            return ((endA && endB && !carry));
        }
        // return from the dp 
        if(dp[ind][carry][endA][endB] != -1) return dp[ind][carry][endA][endB];

        // we will check the limit for a and b 
        ll limA = (endA) ? 0 : 9;
        ll limB = (endB) ? 0 : 9;
        ll target = s[ind] -'0';

        ll ways = 0;
        // make the numebrs
        for(ll dA = 0; dA <= limA; dA++){
            if(dA == 0 && !endA) continue;
            for(ll dB = 0; dB <= limB; dB++){
                if(dB == 0 && !endB) continue;

                ll sum = dA + dB + carry;
                ll digit = sum % 10;
                ll newCarry = sum / 10;

                if(digit != target) continue;

                ways += geek(ind - 1, newCarry, endA, endB, s);
                if(!endA) ways += geek(ind - 1, newCarry, true, endB, s);
                if(!endB) ways += geek(ind - 1, newCarry, endA, true, s);
                if(!endA && !endB) ways += geek(ind - 1, newCarry, true, true, s);

            }
        }


        // return the numebr of ways 
        return dp[ind][carry][endA][endB] = ways;
    }
    long long countNoZeroPairs(long long n) {
       string s = to_string(n);
       // there are 4 stest to this  ind, carry, endA, endB

        dp.assign(s.size(), vector<vector<vector<ll>>>(2, vector<vector<ll>>(2, vector<ll>(2, -1))));
        ll ind = s.size() - 1;
        return geek(ind, 0, 0, 0, s); 
    }
};