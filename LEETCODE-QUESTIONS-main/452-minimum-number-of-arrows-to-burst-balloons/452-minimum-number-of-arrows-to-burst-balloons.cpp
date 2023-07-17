//https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/solution/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        if (points.size() == 0) return 0;

        // sort by x_end
        sort(begin(points), end(points), [](const vector<int> &o1, const vector<int> &o2) {
            return (o1[1] < o2[1]);
        });

        int arrows = 1;
        int xStart, xEnd, limit = points[0][1];
        for (auto p : points) {
            xStart = p[0];
            xEnd = p[1];
            // if the current balloon starts after the end of another one,
            // one needs one more arrow
            if (limit < xStart) {
                arrows++;
                limit = xEnd;
            }
        }
        return arrows;
    }
};