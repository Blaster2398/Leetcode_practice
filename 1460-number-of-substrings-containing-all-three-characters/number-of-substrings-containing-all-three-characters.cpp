class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i = 0, j = 0;
        int count = 0;
        int freq[3] = {0, 0, 0};

        while(j < n){
            freq[s[j]-'a']++;
            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
                count += (n - j);
                freq[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        return count;
    }
};