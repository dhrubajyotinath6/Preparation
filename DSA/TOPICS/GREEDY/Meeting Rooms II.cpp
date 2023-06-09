
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        // sort the meetings by start time
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) { 
            return a[0] < b[0]; 
        });
        
        int minRooms = 0;
        
        struct endCompare {
            bool operator()(vector<int> &a, vector<int> &b) { return a[1] > b[1]; }
        };

        priority_queue <vector<int>, vector<vector<int>>, endCompare> minHeap;
        
        for (auto meeting : intervals) {
            
          // remove all meetings that have ended
          while (!minHeap.empty() && meeting[0] >= minHeap.top()[1]) {
            minHeap.pop();
          }
            
          // add the current meeting into the minHeap
          minHeap.push(meeting);
            
          // all active meeting are in the minHeap, so we need rooms for all of them.
          minRooms = max(minRooms, (int)minHeap.size());
    }
        
        return minRooms;
        
        
    }
};

/*
TC -> O(N)
SC -> O(1)
*/