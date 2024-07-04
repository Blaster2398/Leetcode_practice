//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int m, int n, int k)
    {   
        int ele = -1;
        int cnt = 0; //counter
        //apply the merge step:
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (arr1[i] < arr2[j]) {
                if (cnt == k - 1){
                    ele = arr1[i];
                    return ele;
                }
                cnt++;
                i++;
            }
            else {
                if (cnt == k - 1){
                    ele = arr2[j];
                    return ele;
                }
                // cout << arr2[j] << " don 2" ;

                cnt++;
                j++;
            }
        }
         //copy the left-out elements:
        while (i < m) {
            if (cnt == k - 1){
                    ele = arr1[i];
                    return ele;
                }
                // cout << arr1[i] << " don 3 " ;
                
            cnt++;
            i++;
        }
        while (j < n) {
            if (cnt == k - 1){
                    ele = arr2[j];
                    return ele;
                }
                // cout << arr2[j] << " don 4 " ;

            cnt++;
            j++;
        }
        return ele;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends