class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low = 0; 
        int high = arr.size()-1;
        while(low <= high){
            int mid = (low + high) / 2;
            cout << mid <<endl;
            if(target == arr[mid])  return mid;
            // Determine if the left half is sorted
            if (arr[low] <= arr[mid]) {
                // Check if the target is in the left half
                if (arr[low] <= target && target < arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // The right half must be sorted
            else {
                // Check if the target is in the right half
                if (arr[mid] < target && target <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};