class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int a = 0; a <= sqrt(c); a++){
            double b = sqrt(c-a*a);
            if(b == (int)b){
                cout << a << " " << b<< endl;
                return true;
            }
        }
        return false;
    }
};