class Solution {
public:
    const int mod = 1e9+7;
    int rectangleArea(vector<vector<int>>& rectangles) {
        // we need 3 types of things 
        //1-> store the unique values of x and y in inc order 
        //2-> give all of them index using map
        //3-> then store them in a vector for easy retrival
        set<int> _x, _y;
        for(auto v: rectangles){
            _x.insert(v[0]), _x.insert(v[2]);
            _y.insert(v[1]), _y.insert(v[3]);
        }

        int index = 0;
        map<int, int> cord_x, cord_y;
        for(auto i : _x){
            cord_x[i] = index;
            index++;
        }
        index = 0;
        for(auto j : _y){
            cord_y[j] = index;
            index++;
        }

        long long ans = 0;
        vector<int> x(_x.begin(), _x.end());
        vector<int> y(_y.begin(), _y.end());
        vector<vector<bool>> vis(x.size(), vector<bool>(y.size(), false));
        for(auto v: rectangles){
            for(int start_x = cord_x[v[0]]; start_x < cord_x[v[2]]; start_x++){
                for(int start_y = cord_y[v[1]]; start_y < cord_y[v[3]]; start_y++){
                    if(!vis[start_x][start_y]){
                        long long height = y[start_y+1] - y[start_y];
                        long long width = x[start_x+1] - x[start_x];
                        cout << height << " " << width << endl;
                        ans = (ans + (height*width) % mod) % mod;
                    }
                    vis[start_x][start_y] = true;
                }
            }
        }

        return (int)ans;
    }
};