class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1); // Ensure nums1 is the smaller array

        int n = n1 + n2;
        int low = 0, high = n1;
        int left = (n1 + n2 + 1) / 2; // These many elements will be there on the left after merging 

        while (low <= high) {
            // mid1 is the number of elements from arr1 to be taken to left 
            // mid2 are the remaining one
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;

            // ideally when  the condition satisfies then l1 < r2 and l2 < r1 as the other way is anyways true 
            // so if l1 > r2 -> we have taken more elements from arr1 on which we are doing binary search so high = mid -1
            // if l2 > r1 -> then we took less elements from arr1 so low = mid +1
            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];

            if (l1 > r2) {
                high = mid1 - 1;
            } else if (l2 > r1) {
                low = mid1 + 1;
            } else {
                // Found the correct partition
                if ((n1 + n2) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return max(l1, l2);
                }
            }
        }
        return 0.0; // This should never be reached
    }
};
