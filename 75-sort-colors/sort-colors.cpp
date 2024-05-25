class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> res;
        int ones = 0;
        int zero = 0;
        int c = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                zero++;
            }
            else if(nums[i] == 1){
                ones++;
            }
            else if(nums[i] == 2){
                c++;
            }
        }
        int num = ones+zero+c;
        for(int i = 0; i < num ; i++){
            if(zero>0){
                res.push_back(0);
                zero--;
            }
            else if (ones>0){
                res.push_back(1);
                ones--;
            }
            else if (c>0){
                res.push_back(2);
                c--;
            }
        }
        nums = res;
        
    }
};