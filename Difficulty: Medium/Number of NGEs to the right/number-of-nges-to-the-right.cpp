//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &nums, int queries, vector<int> &indices){
        stack<int> s;
        // int n = nums.size();
        vector<int> greater(n, n);
        vector<int> ans;
        // we are storing the index of the NGE for now then we can search for the 2nd NGE
        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && nums[s.top()] <= nums[i]) s.pop();
            if(!s.empty()){
                greater[i] = s.top();
            }
            s.push(i);
        }
        
        
        for(int i = 0; i < queries; i++){
            int ind = indices[i];
            int l = greater[ind] + 1;
            int cnt = (greater[ind] == n) ? 0 : 1;
            for(int j = l; j < n;j ++){
                if(nums[j] > nums[ind]){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        
        return ans;
        
        
       
    }

};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> v1(n);
       for(int i = 0;i<n;i++) cin >> v1[i];
        int q; cin >> q;
        vector<int> v2(q);
        for(int i = 0;i<q;i++) cin >> v2[i];

        Solution obj;
        vector<int> ans = obj.count_NGE(n,v1,q,v2);

        for(int i = 0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends