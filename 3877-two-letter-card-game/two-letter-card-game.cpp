class Solution {
public:
    int score(vector<string>& cards, char x) {
        int n = cards.size();
        vector<int> left(26, 0);
        vector<int> right(26, 0);
        int both = 0;
        
        for(int i = 0; i  < n; i++){
            if(cards[i][0] == x && cards[i][1] == x) both ++;
            else if(cards[i][0] == x) left[cards[i][1] - 'a']++;
            else if(cards[i][1] == x)right[cards[i][0]- 'a'] ++;
        }

        int maxl = *max_element(left.begin(), left.end());
        int maxr = *max_element(right.begin(), right.end());
        int suml = accumulate(left.begin(), left.end(), 0);
        int sumr = accumulate(right.begin(), right.end(), 0);


        int cnt = 0;
        int remaining = 0;
        // if(maxl > suml - maxl){
        //     cnt += suml - maxl;
        //     remaining +=  maxl - (suml - maxl);
        // }
        // else{
        //     cnt += suml/2;
        //     remaining += (suml&1) ? 1 : 0;
        // }

        int pairs1 =  min(suml/2, suml - maxl);
        remaining += (suml - 2*pairs1);


        // if(maxr > sumr - maxr){
        //     cnt += sumr - maxr;
        //     remaining +=  maxr - (sumr - maxr);
        // }
        // else{
        //     cnt += sumr/2;
        //     remaining += (sumr&1) ? 1 : 0;
        // }
        int pairs2 = min(sumr/2, sumr - maxr);
        remaining += (sumr - 2*pairs2);

        cnt = pairs1 + pairs2 + min(both, remaining);
        if(both > remaining){
            cnt += min((both-remaining)/2, pairs1 + pairs2);
        }

        return cnt;
    }
};