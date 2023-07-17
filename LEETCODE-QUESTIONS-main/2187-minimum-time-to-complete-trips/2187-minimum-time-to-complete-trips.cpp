class Solution {
    
public:
    bool timeEnough(vector<int>& time, long long givenTime, int totalTrips){
        long long actualTrips = 0;
        for(auto t : time){
            actualTrips += givenTime/t;
        }
        
        return actualTrips >= totalTrips;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long left = 1, right = 1LL * *min_element(time.begin(), time.end())*totalTrips;
        
        long long ans = 0;
        
        while(left <= right){
            long long mid = (left + right)/2;
            
            if(timeEnough(time, mid, totalTrips)){
                right = mid - 1;
                ans = mid;
            }else{
                left = mid + 1;
            }
        }
        
        return ans;
    }    
    
};

/*

Input
[2]
1

Output
0

Expected
2
*/