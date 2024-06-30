//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int util(int arr[], int i, int j , vector<vector<int>>& dp) {
        // base cases 
        if(i == j){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        // stuff to do
        int mini = 1e9;
        for(int k = i; k < j; k++){
            int steps = (arr[i-1] * arr[k] * arr[j]) + util(arr, i, k, dp) + util(arr, k+1, j, dp);
            mini = min(steps, mini);
        }
        
        // return the min
        return dp[i][j] = mini;
    }

    int matrixMultiplication(int N, int arr[]) {
        vector<vector<int>> dp(N, vector<int>(N,-1));
        return util(arr, 1, N-1, dp);
    }
    
    
    
    
//     void util(int arr[], int* low, int* mid, int* high, int& result) {
//     // Base case: if low, mid, or high overlap or are adjacent, return
//     if (low >= mid || mid >= high) {
//         return;
//     }
    
//     result += (*low) * (*mid) * (*high);
    
//     // Go to the left side
//     if (low + 1 < mid) {
//         int* mid1 = min_element(low + 1, mid);
//         // cout << *low << ' ' << *mid1 << ' ' << *mid << endl;
//         util(arr, low, mid1, mid, result);
//     }
    
//     // Go to the right side
//     if (mid + 1 < high) {
//         int* mid2 = min_element(mid + 1, high);
//         // cout << *mid << ' ' << *mid2 << ' ' << *high << endl;
//         util(arr, mid, mid2, high, result);
//     }
// }

// int matrixMultiplication(int N, int arr[]) {
//     int* mid = min_element(arr + 1, arr + N - 1);
//     int* low = &arr[0];
//     int* high = &arr[N - 1];
//     int result = 0;
//     util(arr, low, mid, high, result);
//     return result;
// }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends