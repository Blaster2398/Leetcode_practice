//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int frogJump(vector<int>& height, int n,vector<int>& dp){
        
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        
        int lft = abs(height[n]-height[n-1]) + frogJump(height,n-1,dp);
        int rgt = INT_MAX;
        if(n > 1){
            rgt = abs(height[n]-height[n-2]) + frogJump(height,n-2,dp);
        }
        
        return dp[n] = min(rgt,lft);
    }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n,-1);
        
        return frogJump(height,n-1,dp);
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
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends