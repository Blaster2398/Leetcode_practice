class Solution {
public:
    int count = 0;
    void merge(vector<int>& arr, int low, int mid, int high){
        int left = low;
        int right = mid + 1;
        vector<int> temp;

        while(left <= mid && right <= high){
            if(arr[left] < arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }

        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }

        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }

        for(int i = low; i <= high; i++){
            arr[i] = temp[i-low];
        }

    }

    void mergeSort(vector<int>& arr, int low, int high){
        if(low >= high) return;

        int mid = (low + high)/ 2;

        //merge sort for left part 
        mergeSort(arr, low, mid);
        //merge sort for right part 
        mergeSort(arr, mid+1, high);

        countPair(arr, low, mid, high);
        merge(arr, low, mid, high);
    }

    void countPair(vector<int>& arr, int low, int mid, int high){
        int left = low;
        int right = mid+1;
        while(left <= mid && right <= high){
            if ((long long)arr[left] > 2LL * (long long)arr[right]){
                count = count + (mid - left + 1);
                right ++;
            }
            else{
                left ++;
            }
        }
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);

        return count;
    }
};