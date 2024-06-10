//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int> res;
    
        res.push_back(a[0]);
    
        for(int i = 1; i < n; i++){
            int value = a[i];
    
            if(value > res.back()){
                res.push_back(value);
            }
            else{
                // If not, find the position in res where this value can replace
                // the first element that is greater than or equal to the current value
                auto it = lower_bound(res.begin(), res.end(), value);
                *it = value;
            }
        }
    
        return res.size();
           
        }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends