class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i =0;
        int j = height.size()-1;

        int maax = 0;
        while(i<j){
            int temp = (j-i) * min(height[i] , height[j]);
            maax = max(maax,temp);
            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }

        return maax;
    }
};