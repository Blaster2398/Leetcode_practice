class Solution {
public:
    bool check(vector<int>& v,int mid, int h){
        double count = 0;
        for(int i = 0; i < v.size(); i++){
            count += ceil((double)(v[i]) / (double)(mid));
            
        }

        return count<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high){
            int mid = low + (high -low) /2;
            if(check(piles, mid, h)){
                high = mid-1;
                
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};