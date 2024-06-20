class Solution {
public:
    bool possible(vector<int>& bloomDay, long long int m, long long int k, long long int day) {
        long long int cnt = 0;
        long long int numB = 0;
        for(long long int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] <= day) {
                cnt++;
                if (cnt == k) {
                    numB++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }
        return numB >= m;
    }
    int minDays(vector<int>& bloomDay, long long int m, long long int k) {
        if(m*k > bloomDay.size()) return -1;
        // ex - 7 7 7 7 12 11 13 7
        // we know that the day we requir is between (7 , 13)  we can do a linear search for each object which 
        // has a  req number of bouuets or we can do a binary search
        auto it = max_element(bloomDay.begin(), bloomDay.end());
        long long int high = *it;
        it = min_element(bloomDay.begin(), bloomDay.end());
        long long int low = *it;
        long long int n = high - low + 1;
        cout << high << " " << low << endl;
        while(low <= high) {
            long long int mid = (low + high)/2;
            if(possible(bloomDay, m, k, mid)){
                cout << mid << endl;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
        
    }
};