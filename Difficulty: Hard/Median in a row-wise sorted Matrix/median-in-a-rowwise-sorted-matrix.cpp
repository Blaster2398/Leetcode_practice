//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // this will help to find the number of elements that can be on the left of the given number 
    // also as the indexing starts from 0 it exacrtly tells how many <= elements are there
    int upperBound(vector<int> &arr, int x, int n) {
        int low = 0, high = n - 1;
        int ans = n;
    
        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] > x) {
                ans = mid;
                //look for smaller index on the left
                high = mid - 1;
            }
            else {
                low = mid + 1; // look on the right
            }
        }
        return ans;
    }
    
    int func(vector<vector<int>> &matrix, int R, int C, int mid){
        int counter = 0;
        for(int i = 0; i < R; i++){
            counter += upperBound(matrix[i], mid, C);
        }
        return counter;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        //Use Binary search on the answer space:
        sort(matrix.begin(),matrix.end());
        
        int low = matrix[0][0], high = matrix[R-1][C-1];
        while (low <= high) {
            int mid = (low + high) / 2;
            int midN = func(matrix, R, C, mid);
            
            if (midN <= (R*C)/2) low = mid + 1;
            else if(midN > (R*C)/2) high = mid - 1;
        }
        return low;
    }
};




//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends