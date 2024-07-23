//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool ispal(string s, int i , int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            
            i++;
            j--;
        }
        return true;
    } 
    int f(string s, int ind, int n, vector<int>& dp){
        if(ind == n){
            return -1;
        }
        
        if(dp[ind] != -1){
            return dp[ind];
        }
        
        int res = INT_MAX;
        
        for(int i = ind ; i < n; i++){
            if(ispal(s, ind, i)){
                int ways = 1 + f(s, i+1, n, dp);
                res = min(ways, res);
            }
        }
        
        
        return dp[ind] = res;
    }
    int palindromicPartition(string str)
    {
       int n = str.size();
       vector<int> dp(n, -1);
       
       return f(str, 0, n, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends