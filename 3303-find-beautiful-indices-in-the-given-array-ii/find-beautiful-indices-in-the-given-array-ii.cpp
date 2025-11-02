#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> calculatelps(const string &s) {
        int n = s.size();
        vector<int> lps(n);
        int j = 0;
        for (int i = 1; i < n; i++) {
            while (j > 0 && s[i] != s[j]) j = lps[j - 1];
            if (s[i] == s[j]) j++;
            lps[i] = j;
        }
        return lps;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.size(), m1 = a.size(), m2 = b.size();

        // Build combined strings for KMP
        vector<int> lps1 = calculatelps(a + "$" + s);
        vector<int> lps2 = calculatelps(b + "$" + s);

        vector<int> aPos, bPos;

        // Collect match positions for 'a'
        for (int i = m1 + 1; i < (int)lps1.size(); i++)
            if (lps1[i] == m1) aPos.push_back(i - 2 * m1);

        // Collect match positions for 'b'
        for (int i = m2 + 1; i < (int)lps2.size(); i++)
            if (lps2[i] == m2) bPos.push_back(i - 2 * m2);

        vector<int> res;
        for (int i : aPos) {
            // Count how many b positions fall within [i - k, i + k]
            int lb = lower_bound(bPos.begin(), bPos.end(), i - k) - bPos.begin();
            int ub = upper_bound(bPos.begin(), bPos.end(), i + k) - bPos.begin();
            if (lb < ub) res.push_back(i);
        }

        return res;
    }
};
