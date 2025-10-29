class Solution {
public:
    int crossPro(vector<int> a, vector<int> b, vector<int> c){
        // 2 vectos ab and ac are ((x2-x1)i + (y2-y1)j) and ((x3-x1)i + (y3-y1)j)
        // cross product -> (x2-x1)(y3-y1) - (y2-y1)(x3-x1)
        return ((b[0]-a[0])*(c[1]-a[1]) - (b[1]-a[1])*(c[0]-a[0]));
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if(n <= 3) return trees;
        // we will sort the trees in ascending order of x and make the upper and the lower hull
        vector<vector<int>> UHull, LHull;
        sort(trees.begin(), trees.end());

        UHull.push_back(trees[0]);
        UHull.push_back(trees[1]);

        LHull.push_back(trees[n-1]);
        LHull.push_back(trees[n-2]);

        // get the complete upper hull
        for(int i = 2; i < n; i++){
            int Us = UHull.size();
            while(UHull.size() >= 2 && crossPro(UHull[Us-2], UHull[Us-1], trees[i]) > 0){
                UHull.pop_back();
                Us--;
            }
            UHull.push_back(trees[i]);
        }

        // get the complete lower hull
        for(int i = n-3; i >= 0; i--){
            int Ls = LHull.size();
            while(LHull.size() >= 2 && crossPro(LHull[Ls-2], LHull[Ls-1], trees[i]) > 0){
                LHull.pop_back();
                Ls--;
            }
            LHull.push_back(trees[i]);
        }
       
        // now make the the complete hull by removing the dublicates
        // for(int i = 1; i < LHull.size()-1; i++){
        //     UHull.push_back(LHull[i]);
        // }

        set<vector<int>> all(UHull.begin(), UHull.end());
        all.insert(LHull.begin(), LHull.end());  

        vector<vector<int>> ans(all.begin(), all.end());

        return ans;
    }
};