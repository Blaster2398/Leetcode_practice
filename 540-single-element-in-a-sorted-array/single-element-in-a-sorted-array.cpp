class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        // check for edge cases
        if(n == 1){
            return arr[0];
        }
        else if(arr[0] != arr[1]){
            return arr[0];
        }
        else if(arr[n-1] != arr[n-2]){
            return arr[n-1];
        }
        
        // now for the remaining elements
        // we know that when ever we find that element the sequence will be some thing like this ( O-> odd, E-> even)
        // E O E O E O "E" O E O E O E ; or 
        // it will always be an even place 
        int low = 1;
        int high =n-2 ;
        int res = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(mid % 2 == 0 && (arr[mid] != arr[mid -1] && arr[mid] != arr[mid +1])){
                return arr[mid];
            }
            else if((mid % 2 == 0 && arr[mid] == arr[mid-1]) || (mid%2 == 1 && arr[mid] == arr[mid+1])){
                // we are on the righ side 
                high = mid -1;
            }
            else if ((mid % 2 == 0 && arr[mid] == arr[mid+1]) || (mid%2 == 1 && arr[mid] == arr[mid-1])){
                // we are on the left 
                low = mid +1;
            }
        }
        return arr[low];
    }
};