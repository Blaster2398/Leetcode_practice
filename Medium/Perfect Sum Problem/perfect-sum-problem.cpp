//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    const int MOD = 1e9 + 7;
public:
    // int perfectSum(int arr[], int n, int sum) {
    //     vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        
    //     // base cases 
        
    // }
    
    
    
    
	  
	int f(int arr[], int ind, int tgt, vector<vector<int>>& dp) {
        // base cases 
        if(ind==0)
        {
            if(tgt==0 && arr[0]==0) return 2;
            if(arr[0]==tgt || tgt==0) return 1;
            return 0;
        }

        if (dp[ind][tgt] != -1) {
            return dp[ind][tgt];
        }

        // take and not take case 
        int take = 0;
        int not_take = f(arr, ind - 1, tgt, dp);
        if (arr[ind] <= tgt) {
            take = f(arr, ind - 1, tgt - arr[ind], dp);
        }

        return dp[ind][tgt] = (take + not_take) % MOD;
    }

    int perfectSum(int arr[], int n, int sum) {
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(arr, n - 1, sum, dp);
    }
};





//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends