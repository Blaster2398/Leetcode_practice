class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        vector<vector<int>> res;
        vector<pair<int,int>> skyline;
        for(int i = 0; i < b.size(); i++){
            int x1 = b[i][0];
            int x2 = b[i][1];
            int h = b[i][2];
            skyline.push_back({x1, -h});
            skyline.push_back({x2, h}); 
        }

        sort(skyline.begin(), skyline.end());

        multiset<int, greater<int>> ms; // this is to check the active height 
        // if the active height changes then we have to add a point to the result
        
        ms.insert(0);
        int active_height = *ms.begin();
        for(auto [x, h] : skyline){
            // if its the begining 
            if(h < 0){
                ms.insert(abs(h));
                if(active_height != *ms.begin()){
                    res.push_back({x,abs(h)});
                }
                active_height = *ms.begin();
            }
            // if its a ending of a building
            else{
                auto it = ms.find(h);
                if (it != ms.end()) ms.erase(it);
                if(active_height != *ms.begin()){
                    res.push_back({x, *ms.begin()});
                }
                active_height = *ms.begin();
            }
        }
        return res;
    }
};