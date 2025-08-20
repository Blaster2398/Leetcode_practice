class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash (26, 0);
        int i =0, j = 0;
        int maxi = 0;
        int maxf = 0;

        while(j < s.size()){
           // update the hash and max freq
            hash[s[j]-'A']++;
            maxf = max(maxf, hash[s[j]-'A']);

            while(j-i+1 - maxf > k) {
                hash[s[i]-'A']--;
                i++;
                maxf = 0;
                for(int l = 0;l < 26; l++) maxf = max(maxf, hash[l]);
            }

            maxi = max(maxi, j - i + 1);
            j++;
        }
        return maxi;
    }
};