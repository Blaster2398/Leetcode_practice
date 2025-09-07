class Solution {
public:
    int minOperations(string s) {
        vector<int> ch(26, 0);
        for(char c : s){
            ch[c-'a']++;
        }

        int cnt = 0;
        for(int i = 1; i < 25; i++){
            if(ch[i] != 0){
                cnt++;
                ch[i+1]++;
            }
        }

        if(ch[25] != 0) cnt++;
        return cnt;
    }
};