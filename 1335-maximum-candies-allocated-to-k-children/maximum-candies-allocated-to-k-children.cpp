class Solution {
public:
    bool check(long long num, vector<int>& arr, long long k) {
        long long count = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] >= num) {
                count += arr[i] / num; // Count how many pieces of 'num' can be made
                if(count >= k) return true;
            }
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for(int i = 0; i < candies.size(); i++){
            sum += candies[i];
        }
        if(sum < k) return 0;

        long long high = sum / k;
        long long low = 1;

        long long ans = 0;
        while(low <= high){
            long long mid = (low + high) / 2;

            if(check(mid, candies, k)){
                ans = mid;
                cout << " this ans works for candies  = " << mid <<endl;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            
        }
        return ans;

    }
};