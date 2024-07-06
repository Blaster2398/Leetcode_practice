class Solution {
public:
// 1 method is to make prefix and suffix max arrays 
    int trap(vector<int>& heights) {\
        int n = heights.size();
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);
        // cout << n << endl;
        prefixMax[0] = heights[0];
        for (int i = 1; i < n; ++i) {
            prefixMax[i] = max(prefixMax[i-1], heights[i]);
        }
        suffixMax[n-1] = heights[n-1];
        for (int i = n-2; i >= 0; --i) {
            suffixMax[i] = max(suffixMax[i+1], heights[i]);
        }

        int sum = 0;
        for(int i = 0;i < n; i++){
            int water = min(prefixMax[i] , suffixMax[i]) - heights[i];
            sum += water;
        }
        return sum;
    }
};