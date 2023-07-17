class Solution {
public:
    double findMaxAverage(vector<int>& arr, int k) {
        
        int windowEnd = 0, windowStart = 0;
        double windowSum = 0, maxAvg = INT_MIN;
        
        
        for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++)
        {
            windowSum += arr[windowEnd]; 
            
            if (windowEnd >= k - 1){
                
                double avg = windowSum/(windowEnd - windowStart + 1);
                
                maxAvg = max(avg, maxAvg);
                
                windowSum -= arr[windowStart]; // subtract the element going out
                windowStart++;                 // slide the window ahead
            }
        }

        return maxAvg;
    }
};

/*
Your input
[-2]
1
*/