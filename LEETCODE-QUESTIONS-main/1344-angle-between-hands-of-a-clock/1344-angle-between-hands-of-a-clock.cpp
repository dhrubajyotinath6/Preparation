class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        int oneMinAngle = 6;
        int oneHourAngle = 30;
        
        double minutesAngle = oneMinAngle * minutes;
        double hourAngle = (hour % 12 + minutes/60.0) * oneHourAngle;
        
        double diff = abs(hourAngle - minutesAngle);
        
        return min(diff, 360 - diff);
    }
};