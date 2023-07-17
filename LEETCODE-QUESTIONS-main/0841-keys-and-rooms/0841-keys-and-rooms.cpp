//https://leetcode.com/problems/keys-and-rooms/solution/
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        queue<int> queue;
        vector<int> visit(rooms.size(), 0);
        
        queue.push(0);
        visit[0] = 1;
        
        /*
        [
            [1,3],
            [3,0,1],
            [2],
            [0]
        ]
        
        */
        
        while(!queue.empty()){
            
            int top = queue.front();
            queue.pop();
            
            for(auto &room : rooms[top]){
                
                if(visit[room] == 0){
                    queue.push(room);
                    visit[room] = 1;
                }
                
            }
        }
        
        for(auto &x : visit){
            if(!x) return false;
        }
        
        return true;
    }
};