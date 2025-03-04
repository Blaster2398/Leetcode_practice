class Solution {
public:
    int power(int n){
        int res = 0;
        for(int i = 0; i < n; i++){
            if(pow(3, i) > n){
                res = i-1;
                break;
            }
        }
        return res; 
    }
    bool checkPowersOfThree(int n) {

        if(n == 0 || n == 1)  return true;

        int temp = n;
        int prev = 0;

        while(temp > 0){
            int now = power(temp);
            if(prev == now){
                return false;
            }
            temp = temp - pow(3, now);
            prev = now;
        }

        if(temp == 0){
        return true;
        }

        return false;
    }
};