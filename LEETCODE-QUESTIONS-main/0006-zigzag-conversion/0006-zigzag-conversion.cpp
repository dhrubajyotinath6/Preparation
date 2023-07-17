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
//https://leetcode.com/problems/zigzag-conversion/solution/ - check this
//check 2nd approch -it is better

//1st approach
/*
tc - O(N)
sc - O(N)
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


//2nd appeoach

Approach 2: String Traversal
Intuition
The previous approach will be accepted, the interviewer doesn't expect us to give this solution but we are listing it as there is still 
    room for some optimization, it can get hard to visualize so we will take it one step at a time so keep the pace with us.

We were storing the string in a zig-zag pattern using some additional space. Look at each row of the completed matrix. 
If we notice carefully there is a pattern between the distances between characters in each row. If we analyze the jump pattern and traverse the input string using that pattern we can avoid the use of additional space.

question

In the above image, you can see, (each color denotes one row of our previously traversed matrix when mapping it in input string) in jumps denoted by pink arrows, 
first, we jump 6 steps then 2, then 6, and then again 2.
Similarly, there is a pattern for all colors. Let's start analyzing this pattern using the same filled matrix.

Notice in the below image, in the first and last rows we can jump straight to the same position in the next section, i.e. we jump (number of characters) positions in each section.

question

But in the rest of the rows, we must traverse to the next corresponding element of the same section before jumping to the next section.

question

The hard part will be to calculate how to jump to the next character.

If we have to jump to the next section then it's simple: we only jump 
charsInSection
charsInSection characters.
So, 
currIndex += charsInSection
currIndex += charsInSection.

If we have to jump to the next character in the same section, then we will have to calculate how many characters are between these two positions and increment 
currIndex
currIndex by that value.
If the total characters in a section are 
charsInSection
charsInSection and we are in the 
i
�
ℎ
i 
th
  row, then the number of characters above the current row will be 
2
∗
i
2∗i, and the number of characters left will be 
charsInBetween = charsInSection - 2
∗
i
charsInBetween = charsInSection - 2∗i.
So, 
secondIndex = currIndex + charsInBetween
secondIndex = currIndex + charsInBetween.

question

Thus, we can iterate over the input string in line-by-line order after writing it in a zig-zag pattern directly.

Algorithm
Initialize variables:

answer, an empty string to store the final result.
n, length of the input string.
charsInSection, to store the number of characters in each section we defined.
Iterate on each row from numRows:

index will start at the first character in the current row, i.e. index is equal to currRow.
We will traverse in the current row and append all characters to the answer string. First, we append the first character of the current section. If the current row is not the first or last row then we append the second character of the current section. Then update the index to jump to the next section in the current row and repeat this process again.
Return answer.
    
   
    
    
   class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        string answer;
        int n = s.size();
        int charsInSection = 2 * (numRows - 1);

        for (int currRow = 0; currRow < numRows; ++currRow) {
            int index = currRow;

            while (index < n) {
                answer += s[index];

                // If currRow is not the first or last row
                // then we have to add one more character of current section.
                if (currRow != 0 && currRow != numRows - 1) {
                    int charsInBetween = charsInSection - 2 * currRow;
                    int secondIndex = index + charsInBetween;
                    
                    if (secondIndex < n) {
                        answer += s[secondIndex];
                    }
                }
                // Jump to same row's first character of next section.
                index += charsInSection;
            }
        }

        return answer;
    }
};
