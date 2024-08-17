class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        int Xor = start ^ goal;
        while(Xor > 0){
            cnt += Xor & 1;
            Xor = Xor >> 1;
        }
        return cnt;
    }
};