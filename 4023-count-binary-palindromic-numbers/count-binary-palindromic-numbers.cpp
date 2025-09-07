class Solution {
public:
    string toBinary(long long n) {
        if (n == 0) return "0";
        string s;
        while (n > 0) {
            s.push_back((n & 1) ? '1' : '0');
            n >>= 1;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    long long palindromeCount(int len) {
        if (len == 1) return 2;
        return 1LL << ((len - 1) / 2);
    }

    // the number of palindromes for length l fro 1 to 15 are 
    // { 2, 1, 2, 2, 4, 4, 8, 8, 16, 16, 32, 32, 64, 64, 128}
    int countBinaryPalindromes(long long n) {
        if (n == 0) return 1;
        if (n == 1) return 2;

        string res = toBinary(n);
        int len = res.size();

        long long ans = 0;
        for (int l = 1; l < len; l++) ans += palindromeCount(l);

        int half = (len + 1) / 2;
        long long prefix = stoll(res.substr(0, half), nullptr, 2);
        long long base = 1LL << (half - 1);

        ans += max(0LL, prefix - base);

        string first = res.substr(0, half);
        string rev = first.substr(0, len / 2);
        reverse(rev.begin(), rev.end());
        string pal = first + rev;

        if (pal <= res) ans++;

        return (int)ans;
    }
};
