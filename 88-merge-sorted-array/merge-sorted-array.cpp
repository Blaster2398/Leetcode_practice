class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // get the end of both the arrays and then iterate over m+n-1 and update from the last (here n is the smaller one )
        int end1 = m-1;
        int end2 = n-1;
        int num = m+n-1;
        while(end2 >= 0){
            if(end1 >= 0 && nums1[end1] > nums2[end2]){
                nums1[num--] = nums1[end1--];
            }
            else{
                nums1[num--] = nums2[end2--];
            }
        }
    }
};