//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        vector<bool> visited(n + 1, false);
        visited[0] = true;
        vector<int> res;
        
        for(int i = 0;  i < n; i++){
            if(visited[arr[i]] == true){
                res.push_back(arr[i]);
            }
            visited[arr[i]] = true;
        }
        
        
        for(int i = 1; i <= n; i++){
            if(visited[i] == false){
               res.push_back(i);
               break;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends