//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long int count = 0;

    void merge(long long arr[], int low, int mid, int high) {
        int left = low;
        int right = mid + 1;
        int size = high - low + 1;
        long long* temp = new long long[size];  // dynamically allocate temp array on the heap
        int index = 0;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp[index++] = arr[left++];
            } else {
                temp[index++] = arr[right++];
            }
        }

        while (left <= mid) {
            temp[index++] = arr[left++];
        }

        while (right <= high) {
            temp[index++] = arr[right++];
        }

        // Copy the sorted elements back to the original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        delete[] temp;  // free the dynamically allocated memory
    }

    void countPair(long long arr[], int low, int mid, int high) {
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] > arr[right]) {
                count += (mid - left + 1);
                right++;
            } else {
                left++;
            }
        }
    }

    void mergeSort(long long arr[], int low, int high) {
        if (low >= high) return;

        int mid = (low + high) / 2;

        // Merge sort for left part 
        mergeSort(arr, low, mid);

        // Merge sort for right part 
        mergeSort(arr, mid + 1, high);

        countPair(arr, low, mid, high);
        merge(arr, low, mid, high);
    }

    long long int inversionCount(long long arr[], int n) {
        // Initialize count to zero
        count = 0;

        // Perform merge sort and count pairs
        mergeSort(arr, 0, n - 1);

        return count;
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends