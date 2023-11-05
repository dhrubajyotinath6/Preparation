Given an integer array arr of distinct integers and an integer k.

A game will be played between the first two elements of the array (i.e. arr[0] and arr[1]). In each round of the game, we compare arr[0] with arr[1], the larger integer wins and remains at position 0, and the smaller integer moves to the end of the array. The game ends when an integer wins k consecutive rounds.

Return the integer which will win the game.

It is guaranteed that there will be a winner of the game.

 

Example 1:

Input: arr = [2,1,3,5,4,6,7], k = 2
Output: 5
Explanation: Let  see the rounds of the game:
Round |       arr       | winner | win_count
  1   | [2,1,3,5,4,6,7] | 2      | 1
  2   | [2,3,5,4,6,7,1] | 3      | 1
  3   | [3,5,4,6,7,1,2] | 5      | 1
  4   | [5,4,6,7,1,2,3] | 5      | 2
So we can see that 4 rounds will be played and 5 is the winner because it wins 2 consecutive games.
Example 2:

Input: arr = [3,2,1], k = 10
Output: 3
Explanation: 3 will win the first 10 rounds consecutively.



ANS:

Approach 1: Simulate Process With Queue
Intuition

We have an interesting game here. Let's try to fully understand it so that we can simulate it.

In each round, two players face each other. The player with a larger value wins.
The problem states that arr has distinct integers, so we don't need to worry about tiebreaks.
The game ends when someone wins k rounds in a row.
The game starts between the first two elements of arr. The other elements of arr represent a line.
After each round, the next round is played between the winner and the next player in line.
The loser goes to the end of the line.
The functionality of a line can be implemented using a queue. We remove from the front of the queue to determine the next player, and we add to the back of the queue when a player loses. Using a queue and some integers, we can simulate the game.

Let curr represent the winner of the most recent round. Initially, curr = arr[0].
Let winstreak represent the winstreak of the current player. Initially, winstreak = 0.
Let queue represent the line. Initially, queue holds all the elements of arr in order, except for the first element.
Now, let  simulate the game. At each round:

Remove from the front of queue and let this value be opponent.
If curr > opponent, the current player wins. Add opponent to the back of queue and increment winstreak.
Otherwise, opponent wins. Add curr to the back of queue, update curr = opponent, and set winstreak = 1.
If winstreak = k, the current player has won k rounds in a row. We can return curr.

This simulation process works, but there is an issue. If we examine the constraints, we find that 
�
k can be up to 1 billion! If we tried to simulate a billion rounds, we would exceed the time limit. How do we solve this?

We can make another observation: let the player with the largest value in arr be maxElement. Since the elements in the array are all unique, this player will never lose a round, so if the current player ever becomes maxElement, it will surely end up winning so many games as long as the simulation continues, no matter how large the required k is. Thus, if curr = maxElement, we can immediately return curr without actually simulating all the games, because we know that all future games will result in curr winning!

Algorithm

Initialize:
maxElement as the maximum element in arr.
queue as a queue with every element in arr except the first one.
curr = arr[0].
winstreak = 0.
While queue is not empty (could also do while True):
Pop opponent from the front of queue.
If curr > opponent:
Push opponent to the back of queue.
Increment winstreak.
Else:
Push curr to the back of queue.
Set curr = opponent.
Set winstreak = 1.
If winstreak = k or curr = maxElement, return curr.
The code should never reach this point since there is guaranteed to be a winner. Return anything.
Implementation

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxElement = arr[0];
        queue<int> queue;
        for (int i = 1; i < arr.size(); i++) {
            maxElement = max(maxElement, arr[i]);
            queue.push(arr[i]);
        }
        
        int curr = arr[0];
        int winstreak = 0;
        
        while (!queue.empty()) {
            int opponent = queue.front();
            queue.pop();
            
            if (curr > opponent) {
                queue.push(opponent);
                winstreak++;
            } else {
                queue.push(curr);
                curr = opponent;
                winstreak = 1;
            }
            
            if (winstreak == k || curr == maxElement) {
                return curr;
            }
        }
        
        return -1;
    }
};



//OPTIMAL APPROACH

Intuition

Each player that is not maxElement has two possibilities:

They come after maxElement in arr.
They come before maxElement in arr.
If a player comes after maxElement, they will not play any rounds in our simulation, since we immediately terminate upon finding maxElement.

If a player comes before maxElement and loses, they will move to the back of the line behind maxElement. This means they will never appear in the simulation again, because maxElement will play before them, and we immediately terminate the simulation once maxElement plays.

Thus, in our simulation, when a player loses, they never play again. That means we donot actually need the queue to maintain their positions at all! We can simply use a for loop to iterate over the opponents while implementing the same simulation.

Algorithm

Initialize:
maxElement as the maximum element in arr.
curr = arr[0].
winstreak = 0.
Iterate i over the indices of arr, starting from 1:
Set opponent = arr[i].
If curr > opponent:
Increment winstreak.
Else:
Set curr = opponent.
Set winstreak = 1.
If winstreak = k or curr = maxElement, return curr.
The code should never reach this point since we would surely find maxElement. Return anything.
Implementation

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        
        int maxi = arr[0];
        
        for(auto& num : arr){
            maxi = max(maxi, num);
        }
        
        int curr = arr[0];
        int winStreak = 0;
        
        for(int i = 1; i < arr.size(); i++){
            
            int opponent = arr[i];
            
            if(curr > opponent){
                winStreak++;
            }else{
                curr = opponent;
                winStreak = 1;
            }
            
            if(winStreak == k || curr == maxi){
                return curr;
            }
        }
        
        //never get executed
        return 0;
    }
};