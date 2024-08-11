//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement1(vector<int> arr, int n) {
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
    vector<int> findTwoElement(vector<int> arr, int n) {
        // long long n = arr.size();
        int xr = 0;
        for(int i = 0; i < n; i++){
            xr = xr ^ arr[i];
            xr = xr ^ (i+1);
        }
        int bitNum = 0;
        while(1){
            if((xr  & (1 << bitNum)) != 0 ){
                break;
            }
            bitNum++;
        }

        int zero = 0;
        int one = 0;
        for(int i = 0; i  < n; i++){
            if((arr[i] & (1 << bitNum)) != 0){
                zero = zero ^ arr[i];
            }
            else{
                one = one ^ arr[i];
            }
        }

        for(int i = 1; i <= n; i++){
            if((i & (1 << bitNum)) != 0){
                zero = zero ^ i;
            }
            else{
                one = one ^ i;
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == zero){
                cnt++;
            }
        }

        if(cnt == 2){
            return {zero, one};
        }
        else{
            return {one, zero};
        }
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