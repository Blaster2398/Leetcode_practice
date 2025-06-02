class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> res(n, 1);
        int cnt = 0;

        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                res[i] = res[i-1] +1;
            }
        }

        for(int i = n-1; i > 0; i--){
            if(ratings[i-1] > ratings[i] ){
                res[i-1] = max(res[i-1], res[i] + 1);
            }
            cnt += res[i-1];
        }
        cnt += res[n - 1];

        return cnt;
    }
};