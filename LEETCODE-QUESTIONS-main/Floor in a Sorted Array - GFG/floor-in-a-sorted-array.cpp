//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> arr, long long n, long long x){
        
        // Your code here
        int ans = -1;
        
        int low = 0, high = n - 1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            
            if(arr[mid] == x){
                return mid;
            }
            else if(arr[mid] < x){
                ans = mid;
                low = mid + 1;
            }
            else{
                //arr[mid] > x
                high = mid - 1;
            }
            
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends