//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> end_start(n);
        
        for(int i =0; i < n; i++){
            end_start[i].first = end[i];
            end_start[i].second = start[i];
        }
        
        sort(end_start.begin(),end_start.end());
        
        int count =1 ;
        int prev_taken_end =end_start[0].first;
        for(int i =1; i < n; i++){
            if(end_start[i].second > prev_taken_end){
                count++;
                prev_taken_end = end_start[i].first;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends