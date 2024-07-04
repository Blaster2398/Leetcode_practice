//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool checkCows(vector<int> &arr, int n, int k, int mid){
        // place the 1st cow on the 1st position 
        int counter = 1;
        int lastPos = 0;
        for(int i = 1; i < n; i++){
            if(counter >= k) return true;
            
            if(arr[i] - arr[lastPos] >= mid){
                counter ++;
                lastPos = i;
            }
        }
        return (counter >= k);
    }
    int solve(int n, int k, vector<int> &stalls) {
        // we have tio find the min distace b/w cows in any configuration and maximize it 
        sort(stalls.begin(), stalls.end());
        // low and high are storing the distance b/W cows  
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        int answer = 0;
        while(low <= high){
            int mid = (low + high) / 2;
            // we have to check if mid(min distace b/w cows) is possible 
            //if possible w will try to maximize it other wise go to the left
            bool check = checkCows(stalls, n, k ,mid);
            if(check){
                answer = mid;
                low = mid +1;
            }
            else{
                high = mid -1;
            }
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends