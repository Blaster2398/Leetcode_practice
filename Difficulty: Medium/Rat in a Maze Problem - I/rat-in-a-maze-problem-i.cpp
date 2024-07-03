//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool canMove(vector<vector<int>> &m, int i, int j, int n){
        if(i >= 0 && i <n && j >=0 && j < n && m[i][j] == 1){
            return true;
        }
        return false;
    }
    void f(vector<vector<int>> &m, int n, int i, int j, string& s, vector<string>& res, vector<char>& dir, vector<vector<int>>& cod, vector<vector<bool>>& visited){
        if(i == n-1 && j == n-1){
            res.push_back(s);
            return ;
        }
        else{
            visited[i][j] = true;
            // there are 4 possible directions U D L R
            // let 0 -> up , 1 -> down , 2 -> left, 3 -> right
            for(int d = 0; d < 4; d++){
                int ni = i + cod[d][0];
                int nj = j + cod[d][1];
                if(canMove(m, ni, nj, n) && !visited[ni][nj]){
                    s = s + dir[d];
                    visited[ni][nj] = true;
                    f(m, n, ni, nj, s, res, dir, cod, visited);
                    s.pop_back();
                    visited[ni][nj] = false;
                }
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0] == 0 ) return {};
        
        
        vector<string> res;
        string s = "";
        vector<char> dir = {'U', 'D', 'L', 'R'};
        vector<vector<int>> cod = {{-1,0}, {1,0}, {0,-1}, {0, 1}};
        vector<vector<bool>> visited(n , vector<bool>(n , false));
        f(m, n, 0, 0, s, res, dir, cod, visited);
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
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends