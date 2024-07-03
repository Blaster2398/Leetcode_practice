//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isColourAble(bool graph[101][101], int node, vector<int> color, int c, int n){
        // check for all its adjacents if anyone has a color c 
        for(int i = 0; i < n; i++){
            if(i != node && graph[node][i] == true && color[i] == c){
                return false;
            }
        }
        return true;
        
    }
    bool f(bool graph[101][101], int m, int n, vector<int> color, int node){
        //base case 
        if(node == n){
           return true; 
        }
        // check all conditions for n nodes check m colors or N^M possibilities 
        else{
            for(int c = 1; c <= m; c++){
                if(isColourAble(graph, node, color, c, n)){
                    color[node] = c;
                    if(f(graph, m, n, color, node+1) == true){
                        return true;
                    }
                    color[node] = 0;  // backtrack
                }
            }
            return false;
        }
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        
        // m -> color 
        // n-> number of nodes ( colors are 1, 2, 3, ... m and an uncolored one is 0)
        vector<int> color(n, 0);
        
        return f(graph, m, n, color, 0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends