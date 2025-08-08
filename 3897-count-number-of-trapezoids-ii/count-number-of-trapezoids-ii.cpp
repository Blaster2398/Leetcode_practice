class Solution {
public:
    using pii = pair<int, int>;

    pii slope_form(int x1, int x2, int y1, int y2){
        int dx = x1-x2, dy = y1-y2;
        if(dx < 0){
            dx *= -1; dy *= -1;
        }
        if(dx == 0) return {0, 1};
        if(dy == 0) return {1, 0};
        int g = gcd(dx, abs(dy));
        return {dx/g, dy/g};
    }
    
    int countTrapezoids(vector<vector<int>>& points) {
        // for calculating the trapezoids we need map[slope][intercept] = count;
        map<pii, map<int, int>> mp;
        // for calculating all the parallelograms mp[mid_point] = count;
        map<pii, int> mids;
        // for midpoints with different slopes mp[mid_point][slope] = count;
        map<pii, map<pii, int>> mids_diff;

        // now do a n^2 loop to calculate all the slopes present
        int pgram = 0; 
        for(int i = 0; i < (int)points.size(); i++){
            for(int j = i+1; j < (int)points.size(); j++){
                int x1 = points[i][0], x2 = points[j][0];
                int y1 = points[i][1], y2 = points[j][1];
                auto slope = slope_form(x1, x2, y1, y2);
                //c = y1 - (y2 -y1)/(x2-x1) x1 -> (x2-x1)c = (y1-y2)x1 - (x1-x2)y1
                int intercept = slope.second*x1 - slope.first*y1;
                mp[slope][intercept]++;

                //check for pgram
                int mx = x1+x2;
                int my = y1+y2;
                // now pgram = pgram with with same mid point and all kind of slope - pgram with same mid point and same slope 
                pgram += (mids[{mx,my}] - mids_diff[{mx,my}][slope]);
                mids[{mx,my}]++;
                mids_diff[{mx,my}][slope]++;
            }
        }

        int ans = 0;
        for(auto &[slope, val] : mp){
            int tot = 0, sum = 0;
            for(auto &[intercept, cnt] : val){
                sum += cnt * tot;
                tot += cnt;
            }
            ans += sum;
        }

        ans -= pgram;

        return ans;
    }
};