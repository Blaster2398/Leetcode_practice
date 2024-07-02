//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void f(vector<int> arr, int ind, vector<int>& st, int currSum){
        if(ind == arr.size()){
            st.push_back(currSum);
            return;
        }
        
        // take case the curr sum will increase 
        f(arr, ind + 1, st, currSum + arr[ind]);
        
        // not take will only increase the ind
        f(arr, ind + 1, st, currSum);
        
        
        
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> st;
        f(arr, 0, st, 0);
        return st;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends