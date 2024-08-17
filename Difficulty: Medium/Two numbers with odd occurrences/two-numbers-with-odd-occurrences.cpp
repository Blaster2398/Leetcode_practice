//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long int allxor = 0;
        for(int i = 0; i < N; i++){
            allxor ^= Arr[i];
        }
        long long int lastBit = (allxor & (allxor -1)) ^ allxor;
        /
        long long int one = 0;
        long long int two = 0;
        for(int i = 0; i < N; i++){
            if((lastBit & Arr[i]) > 0){
                one ^= Arr[i];
            }
            else{
                two ^= Arr[i];
            }
        }
        
        if(one > two){
            return {one, two};
        }
        else{
            return {two, one};
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends