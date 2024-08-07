//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        vector<int> possible_cbt;
        for(int i = 0; i < n; i++){
            int flag = 0;
            for(int j = 0; j < n; j++){
                if(M[i][j] == 1){
                    flag = 1;
                }
            }
            if(flag == 0) possible_cbt.push_back(i);
        }
        
        int cbt = -1;
        for(int i : possible_cbt){
            int cbt_ = i;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                else if(M[j][i] == 0) cbt_ = -1;
            }
            if(cbt_ != -1 && cbt == -1) cbt = cbt_;
            
        }
        
        return cbt;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends