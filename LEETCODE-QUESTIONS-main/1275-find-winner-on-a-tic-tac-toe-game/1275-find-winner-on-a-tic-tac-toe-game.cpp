//https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/solution/ -- v.v imp
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        
        // n stands for the size of the board, n = 3 for the current game.
        int n = 3;

        // Use rows and cols to record the value on each row and each column.
        // diag1 and diag2 to record value on diagonal or anti-diagonal.
        vector<int> rows(n), cols(n);
        int diag = 0;
        int anti_diag = 0;
        
        // Two players having value of 1 and -1, player_1 with value = 1 places first.
        int player = 1;
        
        for (vector<int> move : moves) {

            // Get the row number and column number for this move.
            int row = move[0];
            int col = move[1];
            
            // Update the row value and column value.
            rows[row] += player;
            cols[col] += player;
            
            // If this move is placed on diagonal or anti-diagonal, 
            // we shall update the relative value as well.
            if (row == col) {
                diag += player;
            }
            if (row + col == n - 1) {
                anti_diag += player;
            }
            
            // Check if this move meets any of the winning conditions.
            if (abs(rows[row]) == n || abs(cols[col]) == n || 
                abs(diag) == n || abs(anti_diag) == n) {
                return player == 1 ? "A" : "B";
            }
            
            // If no one wins so far, change to the other player alternatively. 
            // That is from 1 to -1, from -1 to 1.
            player *= -1;
        }
            
        // If all moves are completed and there is still no result, we shall check if
        // the grid is full or not. If so, the game ends with draw, otherwise pending.
        return moves.size() == n * n ? "Draw" : "Pending";
    }
};