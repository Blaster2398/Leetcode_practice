class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if(s[n-1] != '0') return false;
        queue<int> q;
        q.push(0);
        int travelled = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(u == n-1) return true;

            // we will trqvel everything between min to max range 
            for(int k = max(travelled, u+minJump); k <= min(n-1, u+maxJump); k++){
                if(s[k] == '0') q.push(k);
            }
            travelled = max(travelled , u + maxJump+1);
        }
        return false;
    }
};