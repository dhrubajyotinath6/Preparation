// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        if(n == 1) return 1;
        
        int low = 1, high = n;
        int ans;
        
        while(low <= high){
            
            //int mid = (low + high) >> 1;
            /*
            Line 11: Char 28: runtime error: signed integer overflow: 1063376696 + 2126753390 cannot be represented in type 'int' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:22:28

Last executed input
2126753390
1702766719
            */
            int mid = low + (high - low)/2;
            
            if(isBadVersion(mid)){
                ans = mid;
                high = mid -1;
            }
            
            else if(!isBadVersion(mid)){
                low = mid + 1;
            }
        }
        
        return ans;
    }
};