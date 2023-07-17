class Solution {
public:
    bool judgeCircle(string moves) {
        
        int x = 0, y = 0;
        
        for(auto &move : moves){
            
            if(move == 'U') y++;
            else if(move == 'D') y--;
            else if(move == 'L') x--;
            else if(move == 'R') x++;
        }
        
        return x == 0 && y == 0;
    }
};
