//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
    unordered_map<int, int> mp;
    int res = 0;
    int sum = 0;
    
    // Initialize the map with sum 0 at index -1 to handle subarrays starting from the beginning
    mp[0] = -1;

    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        // If sum is seen before, update result if the current subarray length is greater
        if(mp.find(sum) != mp.end()) {
            res = max(res, i - mp[sum]);
        } else {
            // Store the first occurrence of the sum
            mp[sum] = i;
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
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends