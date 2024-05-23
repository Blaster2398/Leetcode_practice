//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    int len = s.length();
		    vector<string> result;
		    for(int j = 1; j < pow(2,len); j++){
		        string res = "";
		        for(int i = 0; i < len; i++){
		            int check = i;
		            if(j&(1<<check)){
		                res = res + s[i];
		            }
		        }
		        result.push_back(res);
		    }
	        sort(result.begin(),result.end());
		    return result;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends