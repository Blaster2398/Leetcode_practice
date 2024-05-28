class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      // two pointer approach
      int i = 0;
      for(int j = 0; j < nums.size(); j++){
        if(nums[i] != nums[j]){
            nums[++i] = nums[j]; //if a unique element is found then take the front of the unique pointer i
        }
      }
      return i+1;
    }
    // int removeDuplicates(vector<int>& nums) {
    //     set<int> s;
    //     for(int i =0 ; i < nums.size(); i++){
    //         s.insert(nums[i]);
    //     }

    //     int res =s.size();
    //     int i = 0;
    //     for(auto it = s.begin(); it != s.end(); it++){ //to get the element just use *it
    //         nums[i] = *it;
    //         i++;
    //     }


    //     return res;
    // }
};