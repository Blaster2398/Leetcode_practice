class Solution {
public:
    // int largestRectangleArea(vector<int>& heights) {
    //     // you have to 1st male 2 vectors smalles left element and smallest right element these will store the indices 
    //     // for finding the aread you can take the blocks which are ahead of the leeft smallest and before thr right smallest
    //     int n = heights.size();
        
    // }




    int largestRectangleArea(vector<int>& heights) {
        // you have to 1st male 2 vectors smalles left element and smallest right element these will store the indices 
        // for finding the aread you can take the blocks which are ahead of the leeft smallest and before thr right smallest
        int n = heights.size();
        vector<int> small;
        vector<int> large;
        stack<int> temp;
        stack<int> temp2;

        for(int i =0 ;i < n; i++){
            if(temp.empty()){
                small.push_back(-1);
            }
            else{
                if(heights[i] > heights[temp.top()]){
                    small.push_back(temp.top());
                }
                else{
                    while(!temp.empty() && heights[i] <= heights[temp.top()]){
                        temp.pop();
                    }
                    if(temp.empty()){
                        small.push_back(-1);
                    }
                    else{
                        small.push_back(temp.top());

                    }
                }
            }
            temp.push(i);
        }
        for(int i = n-1;i >= 0; i--){
            if(temp2.empty()){
                large.push_back(n);
            }
            else{
                if(heights[i] > heights[temp2.top()]){
                    large.push_back(temp2.top());
                }
                else{
                    while(!temp2.empty() && heights[i] <= heights[temp2.top()]){
                        temp2.pop();
                    }
                    if(temp2.empty()){
                        large.push_back(n);
                    }
                    else{
                        large.push_back(temp2.top());

                    }
                }
            }
            temp2.push(i);
        }

        for(auto i : small){
            cout << i << " " ;
        }
        cout << endl;
        reverse(large.begin(), large.end());
        for(auto i : large){
            cout << i << " " ;
        }
        cout << endl;

        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            int area = (large[i] - small[i] - 1) * heights[i];
            maxi = max(maxi , area);
        }

        return maxi;
    }
};