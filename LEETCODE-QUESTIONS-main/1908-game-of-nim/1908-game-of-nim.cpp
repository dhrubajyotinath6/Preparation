/*
https://leetcode.com/problems/game-of-nim/solution/

References
MIT Lecture - Theory of impartial games -https://web.mit.edu/sp.268/www/nim.pdf

Wikipedia - https://en.wikipedia.org/wiki/Nim


Other game theory-related problems on LeetCode

Stone Game - https://leetcode.com/problems/stone-game/
Nim Game (single heap) - https://leetcode.com/problems/nim-game/
Can I Win - https://leetcode.com/problems/can-i-win/


https://cp-algorithms.com/game_theory/sprague-grundy-nim.html
https://en.wikipedia.org/wiki/Sprague%E2%80%93Grundy_theorem


using dp
https://leetcode.com/problems/game-of-nim/discuss/1388061/C%2B%2B-DP-memoization
*/

class Solution {
public:
    bool nimGame(vector<int>& piles) {
        
        int nimSum = 0;
        for (int p : piles) {
            nimSum ^= p;
        }
        return nimSum != 0; 
    }
};