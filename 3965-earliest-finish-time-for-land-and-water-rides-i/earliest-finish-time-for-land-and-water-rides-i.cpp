class Solution {
public:
    // int earliestFinishTime(vector<int>& landS, vector<int>& landD,
    //                    vector<int>& waterS, vector<int>& waterD) {
    //     int ans = INT_MAX;

    //     for (int i = 0; i < landS.size(); i++) {
    //         for (int j = 0; j < waterS.size(); j++) {
                
    //             // Case 1: land first, then water
    //             int endLand = landS[i] + landD[i];
    //             int startWater = max(endLand, waterS[j]);
    //             ans = min(ans, startWater + waterD[j]);

    //             // Case 2: water first, then land
    //             int endWater = waterS[j] + waterD[j];
    //             int startLand = max(endWater, landS[i]);
    //             ans = min(ans, startLand + landD[i]);
    //         }
    //     }
    //     return ans;
    // }

    int earliestFinishTime(vector<int>& landS, vector<int>& landD, vector<int>& waterS, vector<int>& waterD) {
        //we have to get 2 values that is the earliest ending land ride and the earliest ending water ride;
        int n = landS.size();
        int m = waterS.size();
        int Eld = INT_MAX;
        int Ewd = INT_MAX;
        for(int i = 0; i < n; i++){
            Eld = min(landS[i] + landD[i], Eld);
        }
        for(int i = 0; i < m; i++){
            Ewd = min(waterS[i] + waterD[i], Ewd);
        }

        cout << Eld << " land " << Ewd << " water " << endl;
        int mini = INT_MAX;
        // for earliest land ride find the water ride 
        for(int i = 0; i < m; i++){
            int endTime = max(Eld, waterS[i]);
            endTime = endTime + waterD[i];
            mini = min( mini, endTime);
        }

        for(int i = 0; i < n; i++){
            int endTime = max(Ewd, landS[i]);
            endTime = endTime + landD[i];
            mini  = min(mini, endTime);
        }

        return mini;
    }
};
