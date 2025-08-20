class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0, j = 0;
        int f1 = 0, f2 = -1;   // last indices of the two fruit types
        int maxi = 0;

        while (j < fruits.size()) {
            if (f2 == -1 && fruits[j] != fruits[f1]) {
                // first time we see a second fruit
                f2 = j;
            }
            else if (fruits[j] != fruits[f1] && fruits[j] != fruits[f2]) {
                // third fruit -> drop the older fruit type
                if (f1 < f2) {
                    i = f1 + 1;  // drop fruit at f1
                    f1 = j;      // new fruit becomes f1
                } else {
                    i = f2 + 1;  // drop fruit at f2
                    f2 = j;      // new fruit becomes f2
                }
            }

            // update last seen positions
            if (fruits[j] == fruits[f1]) f1 = j;
            else if (f2 != -1 && fruits[j] == fruits[f2]) f2 = j;

            maxi = max(maxi, j - i + 1);
            j++;
        }

        return maxi;
    }
};
