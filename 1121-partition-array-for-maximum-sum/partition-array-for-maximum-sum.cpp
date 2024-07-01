class Solution {
public:
    // // recursion
    // int f(vector<int>& arr, int k, int i){
    //     // base case 
    //     if(i == arr.size()) return 0;


    //     // do some stuff
    //     int maxi = INT_MIN;
    //     int len = 0;
    //     int maxele = arr[i];
    //     int range = min(i + k, (int)arr.size());
    //     for(int j = i; j < range; j++){
    //         len++;
    //         maxele = max(maxele, arr[j]);
    //         int sum = (len * maxele) + f(arr, k, j+1);
    //         maxi = max(maxi, sum);
    //     }
    //     return maxi;
    // }
    // int maxSumAfterPartitioning(vector<int>& arr, int k) {
    //     return f(arr, k, 0);
    // }


    // //memoizatopn
    // int f(vector<int>& arr, int k, int i, vector<int> & dp){
    //     int n = arr.size();
    //     // base case 
    //     if(i >= arr.size()) return 0;

    //     if(dp[i] != -1 ) return dp[i];
    //     // do some stuff
    //     int maxi = 0;
    //     int len = 0;
    //     int maxele = arr[i];
    //     for(int j = i; j < min(i + k, n); j++){
    //         len++;
    //         maxele = max(maxele, arr[j]);
    //         int sum = (len * maxele) + f(arr, k, j+1, dp);
    //         maxi = max(maxi, sum);
    //     }
    //     return dp[i] = maxi;
    // }
    // int maxSumAfterPartitioning(vector<int>& arr, int k) {
    //     vector<int> dp( arr.size() , -1);
    //     return f(arr, k, 0, dp);
    // }



    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp( arr.size()+ 1 , 0);
        
        for(int i = n-1; i >=0 ; i--){
            cout << "done " << i << endl;
            int maxi = 0;
            int len = 0;
            int maxele = arr[i];
            for(int j = i; j < min(i + k, n); j++){
                len++;
                maxele = max(maxele, arr[j]);
                int sum = (len * maxele) + dp[j+1];
                maxi = max(maxi, sum);
            }
            dp[i] = maxi;
        }
        return dp[0];
    }
};