/*
WRONG SOLUTION
class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1 || s.size() <= 2) return s;
        
        queue<int> q;
        set<char> st;
        
        string ans = "";
        
        int x = numRows + numRows - 3;
        
        int i = 0;
        while(i < s.size()){
            ans += s[i];
            q.push(i);
            st.insert(i);
            i += x + 1;
        }
        
        cout << ans << endl;
        
        
        while(!q.empty()){
            
            int point = q.front();
            q.pop();
            
            int possibleLeftPoint = point-1;
            int possibleRightPoint = point + 1;
            
            //in the range + not included before
            if(possibleLeftPoint > 0 && st.find(possibleLeftPoint) == st.end()){
                ans += s[possibleLeftPoint];
                q.push(possibleLeftPoint);
                st.insert(possibleLeftPoint);
            }
            
            if(possibleRightPoint < s.size() && st.find(possibleRightPoint) == st.end()){
                ans += s[possibleRightPoint];
                q.push(possibleRightPoint);
                st.insert(possibleRightPoint);
            }
            
        }
        
        return ans;
        
        
    }
};
*/

class Solution{
    
public:
    string convert(string s, int numRows){
        
        if(numRows == 1) return s;
        
        vector<string> rows(min(numRows, int(s.size())));
        
        int currRow = 0;
        bool goingDown = false;
        
        for(char c : s){
            rows[currRow] += c;
            
            if(currRow == 0 || currRow == numRows - 1) goingDown = !goingDown;
            currRow += goingDown ? 1 : -1;
        }
        
        string ans;
        
        for(auto s : rows) ans += s;
        
        return ans;
    }
};
