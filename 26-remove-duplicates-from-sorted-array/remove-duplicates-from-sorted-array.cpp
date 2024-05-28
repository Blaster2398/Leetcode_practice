class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(int i =0 ; i < nums.size(); i++){
            s.insert(nums[i]);
        }

        int res =s.size();
        int i = 0;
        for(auto it = s.begin(); it != s.end(); it++){ //to get the element just use *it
            nums[i] = *it;
            i++;
        }


        return res;
    }
};