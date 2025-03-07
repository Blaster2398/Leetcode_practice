class Solution {
public:
    vector<int> closestPrimes(int left, int right) {

        if (left > right) return {-1, -1};

        // this is the sieve code 
        vector<bool> primes(right + 1, true);
        primes[0] = false , primes[1] = false;
        for(long long i = 2; i <= right; i++){
            if(!primes[i]){
                continue;
            }
            else{
                for(long long  j = i*i; j <= right; j+=i){
                    primes[j] = false;
                }
            }
        }

        vector<int> res;
        for(int i = left; i < primes.size(); i++){
            if(primes[i] == true){
                res.push_back(i);
            }
        }


        int min = INT_MAX;
        int a = -1;
        int b = -1;

        for(int i = res.size()-1; i > 0; i--){
            if(res[i] - res[i-1] <= min){
                a = res[i-1];
                b = res[i];
                min = res[i] - res[i-1];
            }
        }
        return {a, b};
    }
};