//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    const long long int MOD = 1e9 + 7;
        // Top-down approach (memoization)
    long long int fibo(int n, vector<int>& dp) {
        if(n <= 1) {
            return dp[n] = n;
        }
        if(dp[n] != -1) {
            return dp[n];
        } else {
            return dp[n] = (fibo(n-1, dp) + fibo(n-2, dp)) % MOD;
        }
    }
    
    long long int topDown(int n) {
        vector<int> dp(n + 1, -1);
        return fibo(n, dp);
    }

    // Bottom-up approach (tabulation)
    long long int bottomUp(int n) {
          int prev2 = 0;
          int prev = 1;
          
          for(int i=2; i<=n; i++){
              int cur_i =( prev2+ prev) % MOD;
              prev2 = prev;
              prev= cur_i;
          }
          return prev;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends