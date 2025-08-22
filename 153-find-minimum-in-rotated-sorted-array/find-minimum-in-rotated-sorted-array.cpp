class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0; 
        int high = arr.size()-1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low + high) / 2;

            if(arr[mid] < ans)  ans = arr[mid];
            if (arr[low] <= arr[mid]) { // left is sorted 
                ans = min(ans , arr[low]);
                low = mid + 1;
            }
            else {
                high = mid - 1;  
            }
        }
        return ans;
    }
};