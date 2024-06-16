//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int f(vector<int>arr, int ind, int target, vector<vector<int>>& dp){
        // base cases
        if(target == 0){
            return 1;
        }
        if(ind < 0 || target < 0){
            return 0;
        }
        // return if already present 
        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        bool take = 0;
        bool not_take = f(arr, ind-1, target, dp);
        if(target >= arr[ind]){
            take = f(arr, ind-1, target-arr[ind], dp);
        }
        
        return dp[ind][target]  = (take || not_take);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp (n, vector<int>(sum+1, -1));
        
        return (f(arr, n-1, sum, dp) ? true : false); 
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends