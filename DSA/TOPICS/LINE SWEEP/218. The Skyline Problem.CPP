A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.

The geometric information of each building is given in the array buildings where buildings[i] = [lefti, righti, heighti]:

lefti is the x coordinate of the left edge of the ith building.
righti is the x coordinate of the right edge of the ith building.
heighti is the height of the ith building.
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, which always has a y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends. Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.

Note: There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...,[2 3],[4 5],[12 7],...]

 

Example 1:


Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
Explanation:
Figure A shows the buildings of the input.
Figure B shows the skyline formed by those buildings. The red points in figure B represent the key points in the output list.
Example 2:

Input: buildings = [[0,2,3],[2,5,3]]
Output: [[0,3],[5,0]]
 

Constraints:

1 <= buildings.length <= 104
0 <= lefti < righti <= 231 - 1
1 <= heighti <= 231 - 1
buildings is sorted by lefti in non-decreasing order.



class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<vector<int>> edges;
        for(int i = 0; i < buildings.size(); i++){
            edges.push_back({buildings[i][0], i});
            edges.push_back({buildings[i][1], i});
        }
        
        
        sort(edges.begin(), edges.end());
        
        priority_queue<pair<int,int>> live;
        vector<vector<int>> ans;
        
        int i = 0;
        
        while(i < edges.size()){
            
            int currEdge = edges[i][0];
            
            while(i < edges.size() && edges[i][0] == currEdge){
                
                // The index 'b' of this building in 'buildings'
                int b = edges[i][1];
                
                if(buildings[b][0] == currEdge){
                    int right = buildings[b][1];
                    int height = buildings[b][2];
                    
                    live.push({height, right});
                }
                
                i += 1;
            }
            
            while(!live.empty() && live.top().second <= currEdge){
                 live.pop();
            }
            
            int currHeight = live.empty() ? 0 : live.top().first;
            
            if(ans.empty() || ans[ans.size() - 1][1] != currHeight)
                ans.push_back({currEdge, currHeight});
        }
        
        return ans;
    }
};


/*
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Collect and sort the unique positions of all the edges.
        set<int> edgeSet;
        for (auto building : buildings) {
            edgeSet.insert(building[0]);
            edgeSet.insert(building[1]);
        }
        vector<int> positions(edgeSet.begin(), edgeSet.end());
        
        vector<vector<int>> answer;
            
        // For each position, draw an imaginary vertical line.
        for (auto position : positions) {
            int maxHeight = 0;
            // Check if any buildings intersect with the line at position.
            for (auto building : buildings) {
                int left = building[0], right = building[1], height = building[2];
                
                // Update 'maxHeight' if necessary.
                if (position >= left and position < right) {
                    maxHeight = max(maxHeight, height);
                }
            }
            
            // Add all the positions where the height changes to 'answer'.
            if (answer.empty() || answer[answer.size() - 1][1] != maxHeight) {
                answer.push_back({position, maxHeight});
            }
        }
        return answer;
    }
};

*/



/*
class Solution {
public: 
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Sort the unique positions of all the edges.
        set<int> edgeSet;
        for (auto building : buildings) {
            int left = building[0], right = building[1];
            edgeSet.insert(left);
            edgeSet.insert(right);
        }
        vector<int> edges(edgeSet.begin(), edgeSet.end());
        // Use hash table 'edgeIndexMap' to record every {position : index} pairs in edges.
        map<int, int> edgeIndexMap;
        for (int i = 0; i < edges.size(); ++i) {
            edgeIndexMap[edges[i]] = i;
        }
        
        // Use 'heights' to record maximum height at each index.
        vector<int> heights(edges.size());
        
        // Iterate over all the buildings.
        for (auto building : buildings) {
            // Find the indexes of the left and right edges
            // and update the max height within the range [left_idx, right_idx)
            int left = building[0], right = building[1], height = building[2];
            int leftIndex = edgeIndexMap[left], rightIndex = edgeIndexMap[right];
            for (int idx = leftIndex; idx < rightIndex; ++idx) {
                heights[idx] = max(heights[idx], height);
            }
        }
        
        vector<vector<int>> answer;

        // Iterate over 'heights'.
        for (int i = 0; i < heights.size(); ++i) {
            // Add all the positions where the height changes to 'answer'.
            int currHeight = heights[i], currPos = edges[i];
            if (i == 0 || currHeight != heights[i - 1]) {
                answer.push_back({currPos, currHeight});
            }
        }
        return answer;
    }
};

*/