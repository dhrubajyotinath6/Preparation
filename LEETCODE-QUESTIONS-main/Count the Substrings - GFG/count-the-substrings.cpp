//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    
    public:
    void printSubstrings(string str, int &count)
{
  
    // First loop for starting index
    for (int i = 0; i < str.length(); i++) {
        int sum = 0;
        // Second loop is generating sub-string
        for (int j = i; j < str.length(); j++) {
            
            if(isupper(str[j])) sum += 1;
            else{
                sum -= 1;
            }
            
            if(sum == 0) count++;
        }
    }
}
    public:
    int countSubstring(string S)
    {
        // code here
        int count = 0;
        
        printSubstrings(S, count);
        
        return count;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends