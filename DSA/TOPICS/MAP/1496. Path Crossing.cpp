Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.

 

Example 1:


Input: path = "NES"
Output: false 
Explanation: Notice that the path doesnot cross any point more than once.
Example 2:


Input: path = "NESWW"
Output: true
Explanation: Notice that the path visits the origin twice.
 

Constraints:

1 <= path.length <= 104
path[i] is either 'N', 'S', 'E', or 'W'.



class Solution {
public:
    bool isPathCrossing(string path) {
        
        set<pair<int,int>> st;
        st.insert({0,0});
        
        int x = 0, y = 0;
        
        for(auto& p : path){
             if(p == 'N') y += 1;
             if(p == 'S') y -= 1;
             if(p == 'E') x += 1;
             if(p == 'W') x -= 1;
            
             pair<int,int> point(x, y);
            
            if(st.find(point) != st.end()){
                return true;
            }
            
            st.insert(point);
             
        }
        
        return false;
    }
};

