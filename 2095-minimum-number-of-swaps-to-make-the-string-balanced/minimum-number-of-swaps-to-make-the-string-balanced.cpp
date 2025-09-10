class Solution {
public:
    int minSwaps(string s) {
         int open = 0;
        int counter = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '[') open++;
            else if(s[i] == ']' && open > 0) open--;
            else counter++;
        }

        // if((open + counter) % 2 == 1) return -1;

        cout << open << " " << counter << endl;
        return ((open+1)/2);
    }
};



