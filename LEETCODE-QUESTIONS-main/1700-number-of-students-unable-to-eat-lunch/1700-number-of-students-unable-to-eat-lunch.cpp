//https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/discuss/987403/JavaC%2B%2BPython-Easy-and-Concise
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        int count[] = {0, 0}, n = students.size(), k;
        
        for (int a : students)
            count[a]++;
        
        for (k = 0; k < n && count[sandwiches[k]] > 0; ++k)
            count[sandwiches[k]]--;
        
        return n - k;
        
    }
};