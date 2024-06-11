//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        
        if(arr.empty()) {
            return {};
        }
        // initialize the dp array
        vector<int> dp(n, 1);
        vector<int> hash(n);

        for (int i = 1; i <= n-1; i++) {
            hash[i] = i;
            for (int prev = 0; prev <= i-1; prev++) {
                if (arr[i] > arr[prev] && 1+dp[prev] > dp[i]) {
                    dp[i] =  dp[prev] + 1;
                    hash[i] = prev;
                }
            }
        }
        // now to get the max in dp and its index
        int lastInd = -1;
        int ans = -1;
        
        for(int i = 0; i< n; i++){
            if(dp[i] > ans){
                ans = dp[i];
                lastInd = i;
            }
        }
        
        vector<int> res;
        res.push_back(arr[lastInd]);
        
        while(hash[lastInd] != lastInd){
            lastInd = hash[lastInd];
            res.push_back(arr[lastInd]);
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends