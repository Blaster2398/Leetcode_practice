//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int XOR1toN(int n){
        if(n % 4 == 1) return 1;
        else if(n % 4 == 2) return n+1;
        else if(n % 4 == 3) return 0;
        else return n;
    }
    int findXOR(int l, int r) {
        // now to find the xor from l to r 
        // find the xor till l-1 and till r and then take their xor 
        int xorl = XOR1toN(l-1);
        int xorr = XOR1toN(r);
        return xorl ^ xorr;
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends