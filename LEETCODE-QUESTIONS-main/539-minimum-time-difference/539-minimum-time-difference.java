Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 

Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
 

Constraints:

2 <= timePoints.length <= 2 * 104
timePoints[i] is in the format "HH:MM".

//https://leetcode.com/problems/minimum-time-difference/discuss/437793/Thinking-Process  --- VERY IMP

//https://leetcode.com/problems/minimum-time-difference/discuss/100640/Verbose-Java-Solution-Bucket
class Solution {
    public int findMinDifference(List<String> timePoints) {
        boolean[] minutes = new boolean[24 * 60];
        for (String timePoint : timePoints) {
            int hour = Integer.parseInt(timePoint.split(":")[0]);
            int min = Integer.parseInt(timePoint.split(":")[1]);
            if (minutes[hour * 60 + min]) // Min difference 0 exists if there are two equal timePoints
                return 0;
            minutes[hour * 60 + min] = true;
        }
        
        int min = Integer.MAX_VALUE;
        int biggestMinuteSoFar = -1;  // the biggest minute meet so far
        int smallestMinute = -1; // the smallest minute exists in timePoints
        for (int minute = 0; minute < minutes.length; minute++) {
            if (minutes[minute]) {
                // minute exists in timePoints
                if (biggestMinuteSoFar != -1)
                    min = Math.min(min, minute - biggestMinuteSoFar);
                
                biggestMinuteSoFar = minute;
                
                if (smallestMinute == -1)
                    smallestMinute = minute;
            }
            
        }
        
        // Here biggestMinuteSoFar points to the biggest minute in timePoints
        return Math.min(min,smallestMinute + 24 * 60 - biggestMinuteSoFar);
    } 
}
