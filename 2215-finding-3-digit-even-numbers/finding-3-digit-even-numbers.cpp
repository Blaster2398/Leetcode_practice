class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10,0);
        for(auto i : digits) freq[i]++;

        vector<int> res;
        for(int i = 100; i <= 998; i+= 2){
            vector<int> temp = freq;
            int a = i / 100;
            int b = (i / 10) % 10;
            int c = i % 10;

            if(--temp[a] < 0) continue;
            if(--temp[b] < 0) continue;
            if(--temp[c] < 0) continue;

            res.push_back(i);

        }


        return res;
    }
};
