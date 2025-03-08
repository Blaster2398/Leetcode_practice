class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int st = 0;
        int en = 0;
        int ans = 0;
        int count = 0;
        for(; en < k; en++){
            if(blocks[en] == 'W'){
                count++;
            }
        }
        ans = count;
        for(; en < blocks.size(); en++){
            if(blocks[st] == 'W'){
                count--;
            }
            if(blocks[en] == 'W'){
                count++;
            }
            st++;
            ans = min(ans, count);
        }
        return ans;
    }
};