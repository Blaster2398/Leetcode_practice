//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int geek(vector<vector<int>>& points, int day, int lastTask, vector<vector<int>>& dp){
        //base case for day 0
        if(day ==0){
            int maxi = 0;
            for(int  i =0 ; i < 3; i++){
                if(lastTask != i){
                    maxi = max(maxi, points[0][i]);
                }
                
            }
            return maxi;
        }
        
        // check if the element is present or not 
        if(dp[day][lastTask] != -1){
            return dp[day][lastTask];
        }
        
        // for rest of the days try all possible 
        int maxi = 0;
        for(int  i =0 ; i < 3; i++){
            if(lastTask != i){
                int score = points[day][i] + geek(points, day-1, i, dp);
                maxi = max(maxi , score);
            }
        }
        
        return dp[day][lastTask] = maxi;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n, vector<int>(4,-1));
        return geek(points, n-1, 3, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends