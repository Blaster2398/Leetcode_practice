class Solution {
using ll = long long;
public:
    ll numOfSubsequences(string s) {
        int n = s.size();
        vector<ll> prel(n, 0), suft(n, 0);
        for(int i = 0; i < n; i++){
            if(i) prel[i] += prel[i-1];
            if(s[i] == 'L') prel[i]++;
        }
        for(int i = n-1; i>= 0; i--){
            if(i + 1 < n) suft[i] += suft[i+1];
            if(s[i] == 'T') suft[i]++;
        }

        // there are 3 cases 
        // 1) we add a L in the start 
        //it will just incease the count of each C as (prel[i]+1)*suft[i]
        // 2) if we add a T at the last 
        // it will increase the count of each C as prel[i]*(suft[i] + 1)
        // 3) we add a c in the middle of the subsequence 
        // wehere prel[i]*suft[i] is max
        ll ans = 0, best = 0, ansl = 0, anst = 0;
        for(int i = 0; i < n; i++){
            ll pre = (i-1 >= 0) ? prel[i] : 0;
            ll suf = (i+1 < n) ? suft[i] : 0;

            // noraml
            if(s[i] == 'C') ans += pre*suf;
            // add L
            if(s[i] == 'C') ansl += (pre+1)* suf;
            //add T
            if(s[i] == 'C') anst += pre * (suf + 1);
            // add C
            pre = prel[i];
            best = max(best, suf*pre);
        }

        return max({ans + best, ansl, anst});
    }
};