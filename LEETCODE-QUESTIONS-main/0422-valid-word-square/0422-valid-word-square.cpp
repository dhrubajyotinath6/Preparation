class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        // Find max size of string
        int size = 0, hehe;
        for (string i : words) hehe = i.size(), size = max(size, hehe);
        
        // If max row size is not equal to max column size,
        // then not symmetric
        if (words.size() != size) return false;
        
        // Find if whole board is symmetric or not
        for (int i = 0; i < words.size(); i++) 
            for (int j = 0; j < words[i].size(); j++) 
                if (words[i][j] != words[j][i]) 
                    return false;
        
        // If symmetric, return true
        return true;
    }
};