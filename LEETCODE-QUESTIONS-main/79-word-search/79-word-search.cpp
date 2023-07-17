// PEPCODING YOU TUBE
class Solution {
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, -1, 0, 1};
    bool explore(vector<vector<char>>& board, int i, int j, int ind, string word){
        
        if(ind == word.size()) return true;
        
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        
        if(word[ind] != board[i][j]) return false;
        
        char myChar = board[i][j];
        board[i][j] = '@';
        
        for(int d = 0; d<4; d++){
            bool res = explore(board, i + di[d], j + dj[d], ind + 1, word);
            if(res){
                board[i][j] = myChar;
                return true;
            }
        }
        board[i][j] = myChar;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(board[i][j] != word[0]) continue;
                bool res = explore(board, i, j, 0, word);
                if(res) return true;
            }
        }
        return false;
    }
};