class Solution {
public:
    // int search(vector<int>& arr, int target) {
    //     int low = 0; 
    //     int high = arr.size()-1;
    //     while(low <= high){
    //         int mid = (low + high) / 2;

    //         if(target == arr[mid])  return mid;
    //         // Determine if the left half is sorted
    //         if (arr[low] <= arr[mid]) {
    //             // Check if the target is in the left half
    //             if (arr[low] <= target && target < arr[mid]) {
    //                 high = mid - 1;
    //             } else {
    //                 low = mid + 1;
    //             }
    //         }
    //         // The right half must be sorted
    //         else {
    //             // Check if the target is in the right half
    //             if (arr[mid] < target && target <= arr[high]) {
    //                 low = mid + 1;
    //             } else {
    //                 high = mid - 1;
    //             }
    //         }
    //     }
    //     return -1;
    // }
    int search(vector<int>& nums, int target) {
        int ans=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target) ans=i;
        }
        return ans;
    }
};