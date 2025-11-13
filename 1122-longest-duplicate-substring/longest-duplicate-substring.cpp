#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    vector<ll> p_pow1, p_pow2;
    
    const int P1 = 31;
    const int mod1 = 1e9 + 7;
    
    const int P2 = 37;
    const int mod2 = 1e9 + 9;

    int check(int mid, string& s) {
        if (mid == 0) return -1;
        
        set<pair<ll, ll>> st;

        ll hash1 = 0, hash2 = 0;
        ll h1 = p_pow1[mid - 1];
        ll h2 = p_pow2[mid - 1];

        for (int i = 0; i < mid; i++) {
            hash1 = (hash1 * P1 + (s[i] - 'a' + 1)) % mod1;
            hash2 = (hash2 * P2 + (s[i] - 'a' + 1)) % mod2;
        }
        st.insert({hash1, hash2});

        for (int i = mid; i < s.size(); i++) {
            ll remove_val1 = ((s[i - mid] - 'a' + 1) * h1) % mod1;
            hash1 = (hash1 - remove_val1 + mod1) % mod1;
            hash1 = (hash1 * P1 + (s[i] - 'a' + 1)) % mod1;

            ll remove_val2 = ((s[i - mid] - 'a' + 1) * h2) % mod2;
            hash2 = (hash2 - remove_val2 + mod2) % mod2;
            hash2 = (hash2 * P2 + (s[i] - 'a' + 1)) % mod2;

            if (st.count({hash1, hash2})) {
                return i - mid + 1;
            }
            st.insert({hash1, hash2});
        }
        return -1;
    }

    string longestDupSubstring(string s) {
        int n = s.size();
        
        p_pow1.resize(n + 1);
        p_pow2.resize(n + 1);
        p_pow1[0] = 1;
        p_pow2[0] = 1;

        for (int i = 1; i <= n; i++) {
            p_pow1[i] = (1LL * p_pow1[i - 1] * P1) % mod1;
            p_pow2[i] = (1LL * p_pow2[i - 1] * P2) % mod2;
        }

        int low = 1;
        int high = n - 1;
        string ans = "";
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int chek = check(mid, s);
            if (chek != -1) {
                ans = s.substr(chek, mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};