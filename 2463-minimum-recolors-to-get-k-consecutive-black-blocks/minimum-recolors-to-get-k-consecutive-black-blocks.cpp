class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int st = 0;
        int en = 0;
        int count = 0;
        for(en = 0;en < k; en++){
            if(blocks[en] == 'W'){
                count++;
            }
            cout << "count for st = " << st << " en = " << en << " " << count <<endl;

        }
        int ans = count;
        // now we have p number of blockc that we have to colour in orer to get k cnsecutive B cells
        
        for(; en< blocks.size(); en++){
            if(blocks[en] == 'W'){
                count++;
            }
            if(blocks[st] == 'W'){
                count--;
            }
            st++;
            ans = min(ans, count);
            cout << "count for st = " << st << " en = " << en << " " << count <<endl;
        }

        return ans ;
    }
};