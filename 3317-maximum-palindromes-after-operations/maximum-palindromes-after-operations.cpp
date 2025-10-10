class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> ch(26, 0);
        vector<int> len;
        int pairs = 0;
        for(int i = 0; i< words.size(); i++){
            int leng = words[i].size();
            len.push_back(leng);
            for(auto c : words[i]) ch[c-'a']++;
        }

        for(auto i : ch){
            pairs += floor(i/2);
        }
        int ans = 0;
        sort(len.begin(), len.end());
        for(int i : len){
            int pairsNeeded = floor(i/2);
            if(pairsNeeded <= pairs){
                ans++;
                pairs -= pairsNeeded;
            }
        }

        return ans;
    }
};