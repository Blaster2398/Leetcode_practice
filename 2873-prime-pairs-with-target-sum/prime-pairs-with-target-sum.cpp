class Solution {
public:
    vector<bool> seive(int n){
        vector<bool> primes(n+1, true);
        primes[0] = primes[1] = false;
        for(int i = 2; i*i <= n; i++){
            if(primes[i]){
                for(int j = i*i; j <= n; j+=i){
                    primes[j] = false;
                }
            }
        }
        return primes;
    }
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> prime = seive(n);
        vector<vector<int>> res;
        for(int i = 2; i <= n/2; i++) if(prime[i] && prime[n - i]) res.push_back({i, n-i});
        return res;
    }
};