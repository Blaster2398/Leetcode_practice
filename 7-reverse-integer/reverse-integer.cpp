class Solution {
public:
    int reverse(int x) {
        int flag = (x < 0)? -1 : 1;
        long y = abs(x);
        string s = to_string(y);
        std::reverse(s.begin(), s.end());
        y = stol(s);
        if(y > INT_MAX || y < INT_MIN){
            y = 0;
        }
        return (int)(flag*y);
    }
};

// class Solution {
// public:
//     int reverse(int x) {
//         int ans=0,rem;
//         while(x!=0){
//             if(ans<INT_MIN/10 || ans> INT_MAX/10){
//                 return 0;
//             }
//             rem = x%10;
//             ans=(ans*10)+rem;
//             x= x/10;

//         }
//         return ans;
//     }
   
// };       
   