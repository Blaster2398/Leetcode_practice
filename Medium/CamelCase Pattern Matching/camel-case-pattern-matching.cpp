//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        vector<string> result;
        for(auto ele : Dictionary){
            int counter = 0;
            for(char c : ele){
                if(isupper(c) && (Pattern[counter] == c)){
                    counter++;
                    if(counter == Pattern.length()){
                        result.push_back(ele);
                        break;
                    }
                }
                else if(isupper(c) && (Pattern[counter] != c)){
                    break;
                }
            }
        }
        if(result.size() == 0){
            result.push_back("-1");
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends