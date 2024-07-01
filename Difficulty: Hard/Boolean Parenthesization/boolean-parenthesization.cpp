//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
typedef long long ll;
int mod = 1e3 +3;
public:
    int f(int i, int j, bool isTrue, string s, vector<vector<vector<int>>>& dp){
        //base cases 
        if(i > j) return 0;
        if(i == j){
            if(isTrue) return (s[i] == 'T');      // take care if at last moment if we want true and there is true 
            else return (s[i] == 'F');
        }
        
        // check if its present 
        if(dp[i][j][isTrue] != -1){
            return dp[i][j][isTrue];
        }
        
        //evaluate the left and right (T/F) for each possible operator
        ll ways = 0;
        for(int k = i+1; k <= j-1; k+=2){
            ll rT = f(k+1, j, 1, s, dp);
            ll lT = f(i, k-1, 1, s, dp);
            ll lF = f(i, k-1, 0, s, dp);
            ll rF = f(k+1, j, 0, s, dp);
        //calculate the count for  
            
            if(s[k] == '|'){
                if(isTrue) ways = (ways + (lT*rT) % mod + (lF*rT) % mod + (lT*rF) % mod) % mod;
                else ways = (ways + (lF*rF) % mod) % mod;
            }
            else if(s[k] == '&'){
                if(isTrue) ways = (ways + (lT*rT) % mod) % mod;
                else ways = (ways + (lF*rT) % mod + (lT*rF) % mod +(lF*rF) % mod) % mod;
            }
            else{
                // T -> T^F / F^T  F -> T^T / F^F
                if(isTrue) ways = (ways + (lT*rF) % mod + (lF*rT) % mod) % mod;
                else ways = (ways + (lT*rT) % mod + (lF*rF) % mod) % mod;
            }
            
        }
        // return the count
        return dp[i][j][isTrue] = ways;
    }
    
    int countWays(int n, string s){
        //f(start ind , end ind , isTrue , string);
        vector<vector<vector<int>>> dp (n , vector<vector<int>> (n, vector<int> (2, -1)));
        return f(0, n-1, 1, s, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends