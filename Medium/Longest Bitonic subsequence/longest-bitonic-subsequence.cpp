//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        if (nums.empty()) return 0;
        
        // initialize the dp array
        vector<int> dp(n, 0);

        for (int i = 1; i < n; i++) {
            for (int j = i; j>=0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        
        // do this again from the back side 
        vector<int> dp2(n, 0);

        for (int i = n-1; i >=0; i--) {
            for (int j = i; j<n; j++) {
                if (nums[i] > nums[j]) {
                    dp2[i] = max(dp2[i], dp2[j] + 1);
                }
            }
        }
        
        int maax = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] + dp2[i] +1 > maax && dp[i]!=0 && dp2[i]!=0){
                int temp = dp[i] + dp2[i] +1;
                maax = temp;
            }
        }
        return maax;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> nums(n);
        Array::input(nums,n);
        
        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends