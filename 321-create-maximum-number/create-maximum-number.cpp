class Solution {
public:
    vector<int> removeKDigits(vector<int>& a, int k){
        stack<int> st;
        if(k == 0) return a;
        for(int i = 0; i < a.size(); i++){
            while(!st.empty() && a[i] > st.top() && k > 0){
                st.pop();
                k--;
            }
            st.push(a[i]);
        }
        while(!st.empty() && k > 0){
            st.pop();
            k--;
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }

    vector<int> merge(vector<int>& a, vector<int>& b){
        vector<int> res;
        int i = 0, j = 0;
        while( i < a.size() && j < b.size()){
            if(a[i] > b[j]){
                res.push_back(a[i]);
                i++;
            }
            else if(b[j] > a[i]){
                res.push_back(b[j]);
                j++;
            }
            else{
                if(checka(a, b, i, j)){
                    res.push_back(a[i]);
                    i++;
                }
                else{
                    res.push_back(b[j]);
                    j++;
                }
            }
        }
        while(i < a.size()){
            res.push_back(a[i]);
            i++;
        }
        while(j < b.size()){
            res.push_back(b[j]);
            j++;
        }
        return res;
    }

    bool checka(vector<int>& a, vector<int>& b, int i, int j){
        while(i < a.size() && j < b.size() && a[i] == b[j]){
            i++, j++;

        }
        if(i == a.size()) return false;
        else if(j == b.size()) return true;
        else if(a[i] > b[j]) return true;
        else return false;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        //1 we will have to check for all possoble k values in both the arrays
        //2 for each k1 and k2 we will remove (n1 - k1) and (n2 - k2) elements from this
        //3 then use sliding window to make the max number 
        vector<int> best;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int k1 = max(0, k-n2); k1 <= min(n1, k); k1++){
            int k2 = k - k1;
            vector<int> t1 = removeKDigits(nums1, n1-k1);
            vector<int> t2 = removeKDigits(nums2, n2-k2);
            vector<int> t = merge(t1, t2);
            if(t > best) best = t;
        }
        return best;

    }

    // normal sliding window will fail in this case 
    // [2,5,6,4,4,0]
    // [7,3,8,0,6,5,7,6,2]
    // 15
};