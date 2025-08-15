class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int i = 0, j = 0, n = s.length();

        while (j < n) {
            while (j < n && s[j] == ' ') j++;
            if (j >= n) break;

            int start = i;
            while (j < n && s[j] != ' ') {
                s[i++] = s[j++];
            }

            reverse(s.begin() + start, s.begin() + i);

            s[i++] = ' ';
        }

        // Remove last space
        if (i > 0 && s[i - 1] == ' ') i--;

        return s.substr(0, i);
    }
};
