class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        // for a deque we can push_back, push_front, pop_back , pop_front 
        deque<int> dq;
        vector<int>res;
        for(int i = 0; i < arr.size(); i++){
            if(dq.empty()){
                dq.push_back(i);
            }
            else{
                if(!dq.empty() && dq.front() < i - k + 1) {
                    dq.pop_front();
                }
                while(!dq.empty() && arr[dq.back()] <= arr[i] ){
                    dq.pop_back();
                }
                dq.push_back(i);

            }
            if(i >= k-1)  res.push_back(arr[dq.front()]);
        }
        return res;
    }
};