//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int frogJump(vector<int>& height, int n,vector<int>& dp,int k){
        
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        
        int lft = abs(height[n]-height[n-1]) + frogJump(height,n-1,dp,k);
        int rgt = INT_MAX;
        for(int i =2; i <= k; i++){
            int rgt2 = rgt;
            if(n > i-1){
                rgt = abs(height[n]-height[n-i]) + frogJump(height,n-i,dp,k);
            }
            rgt = min (rgt,rgt2 );
        }
        return dp[n] = min(rgt,lft);
    }
        
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n+1,-1);
        
        return frogJump(height,n-1,dp,k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends