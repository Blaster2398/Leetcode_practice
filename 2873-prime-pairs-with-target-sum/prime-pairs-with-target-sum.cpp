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
        unordered_set<int> st;
        for(int i = 0; i <= n; i++) if(prime[i]) st.insert(i);

        set<vector<int>> rs;
        for(auto i : st){ 
            if(st.find(n - i) != st.end()){
                if(i < n-i) rs.insert({i, n-i});
                else rs.insert({n-i, i});
            }
        }
        vector<vector<int>> res(rs.begin(), rs.end());
        return res;
    }
};