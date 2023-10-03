Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle. 
The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).

Return true if all the rectangles together form an exact cover of a rectangular region.

 

Example 1:


Input: rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
Output: true
Explanation: All 5 rectangles together form an exact cover of a rectangular region.
Example 2:


Input: rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
Output: false
Explanation: Because there is a gap between the two rectangular regions.
Example 3:


Input: rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
Output: false
Explanation: Because two of the rectangles overlap with each other.

//https://leetcode.com/problems/perfect-rectangle/discuss/87181/Really-Easy-Understanding-Solution(O(n)-Java)

/*
1.the large rectangle area should be equal to the sum of small rectangles

2. count of all the points should be even, and that of all the four corner points should be one

*/

/*
x1, y1, a, b
0   1   2  3

x1,b        a,b    
0, 3        2,3


x1,y1       a,y1
0, 1        2, 1
*/

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        
        if(rectangles.size() == 0 || rectangles[0].size() == 0) return false;
        if(rectangles.size() == 1) return true;
        
        
        unordered_set<string> st;
        
        int x1 = INT_MAX;
        int y1 = INT_MAX;
        int a = INT_MIN;
        int b = INT_MIN;
        
        int area = 0;
        
        for(auto& rect : rectangles){
            
            x1 = min(x1, rect[0]);
            y1 = min(y1, rect[1]);
            a = max(a, rect[2]);
            b = max(b, rect[3]);
            
            area += (rect[3] - rect[1]) * (rect[2] - rect[0]);
            
            string p1 = to_string(rect[0]) + " " + to_string(rect[1]);
            string p2 = to_string(rect[0]) + " " + to_string(rect[3]);
            string p3 = to_string(rect[2]) + " " + to_string(rect[3]);
            string p4 = to_string(rect[2]) + " " + to_string(rect[1]);
            
         if(st.find(p1) != st.end())
             st.erase(p1);
         else st.insert(p1);
            
         if(st.find(p2) != st.end())
             st.erase(p2);
         else st.insert(p2);
            
         if(st.find(p3) != st.end())
             st.erase(p3);
         else st.insert(p3);
            
         if(st.find(p4) != st.end())
             st.erase(p4);
         else st.insert(p4);
            
        }
        
        string p1 = to_string(x1) + " " + to_string(y1);
        string p2 = to_string(x1) + " " + to_string(b);
        string p3 = to_string(a) + " " + to_string(b);
        string p4 = to_string(a) + " " + to_string(y1);
        
        if(st.size() != 4 || !st.count(p1) || !st.count(p2) || !st.count(p3) || !st.count(p4)) return false;

        return area == (b-y1)*(a-x1);
    }
    
};