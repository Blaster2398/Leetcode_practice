//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int KS(int ind,int wt, int W[], int val[], int n, vector<vector<int>>& dp){
        if(wt<= 0){
            return 0;
        }
        if(ind < 0){
            return 0;
        }
        
        if(dp[ind][wt] !=-1){
            return dp[ind][wt];
        }
        
        int take = 0;
        int not_take = KS(ind-1, wt,W,val,n,dp);
        if(wt-W[ind] >= 0 ){
            take = val[ind]+ KS(ind-1,wt-W[ind],W,val,n,dp);
        }
        
        return dp[ind][wt] = max(take,not_take);
        
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n, vector<int>(W+1,-1));
        return KS(n-1,W, wt,val,n,dp);
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends