class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(),[](const vector<int>& x, const vector<int>& y) { return x[0] < y[0]; });
        
        for (int i = 1; i < intervals.size(); i++) {
          if (intervals[i][0] < intervals[i - 1][1]) {
            // please note the comparison above, it is "<" and not "<="
            // while merging we needed "<=" comparison, as we will be merging the two
            // intervals having condition "intervals[i].start == intervals[i - 1].end" but
            // such intervals don't represent conflicting appointments as one starts right
            // after the other
            return false;
          }
        }
        return true;
        
        
    }
};