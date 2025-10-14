class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size() < 2) return 0;
        map<int,vector<int>> mp;
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]].push_back(i);
        }

        queue<pair<int,int>> q;
        vector<int> vis(arr.size(), 0);
        q.push({0, 0});
        vis[0] = 1;

        while(!q.empty()){
            auto [dis,u] = q.front();
            q.pop();
            if(u == arr.size()-1) return dis;

            int val = arr[u];
            // i cna teleport to any index with the same val;
            for(auto ind : mp[val]){
                if(!vis[ind]){
                    q.push({dis+1, ind});
                    vis[ind] = 1;
                }
            }

            mp[val].clear(); // to remove all values of those indexes 

            // i can go to +1 and -1 
            if(u+1 < arr.size() && !vis[u+1]){
                q.push({dis+1, u+1});
                vis[u+1] = 1;
            }
            if(u-1 >= 0 && !vis[u-1]){
                q.push({dis+1, u-1});
                vis[u-1] = 1;
            }
        }
        return -1;
    }
};