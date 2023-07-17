class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        // calculate x overlap
        int left = max(rec1[0], rec2[0]);
        int right = min(rec1[2], rec2[2]);
        int xOverlap = right - left;

        // calculate y overlap
        int top = min(rec1[3], rec2[3]);
        int bottom = max(rec1[1], rec2[1]);
        int yOverlap = top - bottom;

        int areaOfOverlap = 0;
        // if the rectangles overlap each other, then calculate
        // the area of the overlap
        if (xOverlap > 0 && yOverlap > 0) {
            return true;
        }
        
        return false;
    }
};

/*
        // calculate x overlap
        int left = max(ax1, bx1);
        int right = min(ax2, bx2);
        int xOverlap = right - left;

        // calculate y overlap
        int top = min(ay2, by2);
        int bottom = max(ay1, by1);
        int yOverlap = top - bottom;

        int areaOfOverlap = 0;
        // if the rectangles overlap each other, then calculate
        // the area of the overlap
        if (xOverlap > 0 && yOverlap > 0) {
            areaOfOverlap = xOverlap * yOverlap;
        }


*/