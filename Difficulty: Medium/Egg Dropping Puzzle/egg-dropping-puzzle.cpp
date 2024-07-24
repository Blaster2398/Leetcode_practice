//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int f(int eggs, int floors, vector<vector<int>> & dp){
        // base case 
        if(eggs == 1 || floors == 0 || floors == 1){
            return floors;
        }
        
        if(eggs == 0 ){
            return 0;
        }
        
        if(dp[eggs][floors] != -1){
            return dp[eggs][floors];
        }
        // do some stuff
        int ways  = 0;
        int min_ways = INT_MAX;
        
        for(int i = 1; i <= floors; i++){
            ways =max(f(eggs-1, i-1, dp) , f(eggs, floors - i, dp));
            min_ways = min(min_ways, ways);
        }
        
        
        return  dp[eggs][floors] = 1 + min_ways;
    }
    
    int eggDrop(int n, int k) 
    
    {
        vector<vector<int>> dp(n+1, vector<int>(k + 1, -1));
        return f(n, k, dp);
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends