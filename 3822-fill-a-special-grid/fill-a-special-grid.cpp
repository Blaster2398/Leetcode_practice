class Solution {
public:
    void fillG(int x, int y, int size, int offset, vector<vector<int>>& g){
        if(size == 1){
            g[x][y] = offset;
            return;
        }
        // find the next smaller block size
        int half = size/2;
        int blockSize = (half)*(half);

        // fill the quadrants UR->LR->LL->UL
        fillG(x, y + half, half, offset, g);
        fillG(x + half, y + half, half, offset + 1*blockSize, g);
        fillG(x + half, y, half, offset + 2*blockSize, g);
        fillG(x, y, half, offset + 3*blockSize, g);

    }
    vector<vector<int>> specialGrid(int n) {
        // we are trying to do it by divide and concure and fore that we have  Q1 < Q2 < Q3 < Q4 
        // here the values are 
        // Q1 -> offset 
        // Q2 -> offset + blockSize
        // Q3 -> offset + 2*blockSize
        // Q4 -> offset + 3*blockSize
        // here offset is basically the starting value and then we will increase the offset for the 4 
        // pieces as 1xblocksize , 2xblockSize , 3xblockSize

        int size = (1 << n);
        vector<vector<int>> g(size , vector<int>(size));
        fillG(0,0,size,0,g);
        return g;
    }
};