class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string , int> mp;
        int res = 0;
        
        for(int i = 0; i < words.size(); i++){
            string ele = words[i];
            string elei = words[i];
            reverse(elei.begin(), elei.end());
            
            if(mp.count(elei) != 0 && mp[elei] > 0){
                mp[elei]--;
                res+=4;
            }
            else{
                mp[ele]++;
            }

        }

        for(auto i : mp){
            string rev = i.first;
            reverse(rev.begin(),rev.end());
            if(i.second == 1 && i.first == rev){
                res+=2;
                break;
            }
        }
        return res;
    }
};


