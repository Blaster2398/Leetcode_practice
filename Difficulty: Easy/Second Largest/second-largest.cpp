//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        
        // int max1 = arr[0];
        // int max2 = arr[0];
        // // cout << max1 << " " << max2 <<endl;
        // for(int i = 0; i < n; i++){
        //     // cout << " in LOOP " << endl;
        //     if(arr[i] >= max1){
        //         // cout << " here " << endl;
        //         max2 = max1;
        //         max1 = arr[i];
        //     }
        //     else if(arr[i] > max2){
        //         max2 = arr[i];
        //     }
        // }
        
        sort(arr.begin(), arr.end());
        int max = arr[n-1];
        for(int i = n-2; i >= 0; i--){
            if(arr[i] != max){
                return arr[i];
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends