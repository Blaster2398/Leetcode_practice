class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a = 0, b = 0;
        for(int i =0; i < bills.size(); i++){
            int bill = bills[i];
            if(bill == 5){
                a++;
            }
            else if(bill == 10){
                if(a < 1) return false;
                a--;
                b++;
            }
            else{
                if(b >= 1 && a >= 1){
                    b--;
                    a--;
                }
                else if(b < 1 && a >= 3){
                    a -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};