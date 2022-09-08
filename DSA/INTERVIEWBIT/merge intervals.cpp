// https://github.com/dhrubajyotinath6/Preparation/blob/master/DSA/GROOKING%20THE%20CODING%20INTERVIEW/MERGE%20INTERVALS/3.Insert%20Interval%20(medium).cpp



class Solution {
public:
   vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       
        int n = intervals.size(), i = 0;
        vector<vector<int>> mergedIntervals;
       
        //case 1: no overlapping case before the merge intervals
		//compare ending point of intervals to starting point of newInterval
        while(i < n && intervals[i][1] < newInterval[0]){
            mergedIntervals.push_back(intervals[i]);
            i++;
        }   
       
		//case 2: overlapping case and merging of intervals
        while(i < n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        mergedIntervals.push_back(newInterval);
       
        // case 3: no overlapping of intervals after newinterval being merged
        while(i < n){
            mergedIntervals.push_back(intervals[i]);
            i++;
        }
        return mergedIntervals;
    }
};