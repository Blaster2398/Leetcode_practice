class TrieNode{
public:
    TrieNode* child[2];
    TrieNode(){
        for (int i = 0; i < 2; i++) {
            child[i] = NULL;
        }
    }
};
class Solution {
    TrieNode* root;
public:
    Solution() {
        root = new TrieNode(); // Initialize root in the constructor
    }
public:
    void insert(int num) { 
        TrieNode* curr = root;
        bitset<32> bs(num);

        for( int i = 31; i>=0; i--){
            if(curr->child[bs[i]] == NULL){
                curr->child[bs[i]] =new TrieNode();
            }
            curr = curr->child[bs[i]];
        }
    }
public:
    int maxUtil(int num) {
    TrieNode* curr = root;
    bitset<32> bs(num);
    int result = 0;
    for(int i = 31; i >= 0; i--){
        if(curr->child[!bs[i]] != NULL){
            // Set the ith bit in the result as it will be one 
            result |= (1 << i);
            curr = curr->child[!bs[i]];
        }
        else {
            curr = curr->child[bs[i]];
        }
    }
    return result;
}


public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(),0);
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>> offlineQ;  // this will be of form <mi<xi,index>>
        int index =0;
        for(auto que : queries ){
            offlineQ.push_back({que[1],{que[0],index++}});
        }
        sort(offlineQ.begin(),offlineQ.end());
        int i =0 ;
        for(auto &of : offlineQ){
            while(i < nums.size() && nums[i] <= of.first){
                insert(nums[i]);
                i++;
            }
            if (i != 0){
                ans[of.second.second] = maxUtil(of.second.first);
            }
            else{
                ans[of.second.second] = -1;
            }
        }
        return ans;
    }
};