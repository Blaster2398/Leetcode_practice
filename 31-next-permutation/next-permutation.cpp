class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //step1: find the break point start from last and take a ind =-1 if there is no break point then we just have to reverse the string
        //step2: if ind == -1 then its the largest permutation and just return the reverse 
        //step3: now find the closest and larghest element in the right side of brreak point and swap the elements 
        //step4: reverse the elements in the right side of the break point

        int index = -1;
        for(int i = nums.size()-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }

        if(index == -1){
            reverse(nums.begin(),nums.end());
            return;
        }

        // considering all elements in the right part are arranged in descending order 
        for(int i = nums.size()-1; i > index; i--){
            if(nums[index] < nums[i]){
                swap(nums[index], nums[i]);
                break;
            }
        }

        reverse(nums.begin()+index+1, nums.end());
    }
};