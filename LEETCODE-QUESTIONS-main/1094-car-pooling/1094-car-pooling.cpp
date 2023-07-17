//https://leetcode.com/problems/car-pooling/discuss/317611/C%2B%2BJava-O(n)-Thousand-and-One-Stops

//https://leetcode.com/problems/car-pooling/discuss/1669644/Well-Explained-2-WaysJava-C%2B%2BPythonJavaScript-oror-Easy-for-mind-to-Accept-it

//https://leetcode.com/problems/car-pooling/discuss/317610/JavaC%2B%2BPython-Meeting-Rooms-III

/*

bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> m;
        for (auto &t : trips)
            m[t[1]] += t[0], m[t[2]] -= t[0];
        for (auto &v : m)
            if ((capacity -= v.second) < 0)
                return false;
        return true;
}
*/
/*
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        // Because from and to is between 0 and 1000. Idea is to store counts in an array of size 1001.
        vector<int> lengthOfTrip = vector<int>(1001);
        
        for (auto trip : trips){
            lengthOfTrip[trip[1]] += trip[0]; // Increment when passenger is on board
            lengthOfTrip[trip[2]] -= trip[0]; // decrement when they depart
        }
        
        // Count total passenger for each bus top
        int carLoad = 0;
        
        // we have the count array, we perform a line sweep from 0 to 1000 and track its total
        for (int i = 0; i < 1001 && carLoad <= capacity; i++){
            carLoad += lengthOfTrip[i];
            // Reject when the car is overloaded somewhere
            if(carLoad > capacity) return false;
        }

    return true; // Accept only if all trip is safe
    }
    
};
*/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int> lengthOfTrip = vector<int>(1001);
        
        for (auto trip : trips){
            
            lengthOfTrip[trip[1]] += trip[0]; // Increment when passenger is on board
            lengthOfTrip[trip[2]] -= trip[0]; // decrement when they depart
        }
        
        for(auto passenger : lengthOfTrip){
            
            capacity -= passenger;
            if(capacity < 0) return false;
        }
        return true;
    }
};
    