/*
You are playing a game that contains multiple characters, and each of the characters has two main properties: attack and defense. You are given a 2D integer array properties where properties[i] = [attacki, defensei] represents the properties of the ith character in the game.

A character is said to be weak if any other character has both attack and defense levels strictly greater than this character's attack and defense levels. More formally, a character i is said to be weak if there exists another character j where attackj > attacki and defensej > defensei.

Return the number of weak characters.

 

Example 1:

Input: properties = [[5,5],[6,3],[3,6]]
Output: 0
Explanation: No character has strictly greater attack and defense than the other.
Example 2:

Input: properties = [[2,2],[3,3]]
Output: 1
Explanation: The first character is weak because the second character has a strictly greater attack and defense.
Example 3:

Input: properties = [[1,5],[10,4],[4,3]]
Output: 1
Explanation: The third character is weak because the second character has a strictly greater attack and defense.
*/
//https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/discuss/1445186/EASY-C%2B%2B-solution-with-great-explanation-and-comments-(nlogn)-sorting
//https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/discuss/1452696/O(n)


/*
 EDGE CASE : if on sorting 2 element have same attack strength we will put the one with greater defence first because 
  we only need both parameter to be strictly greater.if we ignore this case we will increase the answer in following case
(5, 2), (5, 4) our code will give answer 1 if we dont handle edge case while the answer should be zero
example:
         -(5,2),(5,4) gives ans 1 (wrong ans as both have strength of 5 which is not strictly increasing
		 we need to tackle this that why we put (5,4) before (5,2) to tackle the case ) 
         
		 -(5,4),(5,2) gives ans 0 (which is correct)

	
	

DRY RUN:
		 [[1,5],[10,4],[4,3]] 
		- let sort this as mention above (on strength)
		 [1,5],[4,3],[10,4]
		 -now move from back that is 2 index of array and keep on storing max till now and comparing
		     when i==2
			     4 is not less than mtn(INT_MIN) so we dont increase ans but our mtn get updated to 4
		     when i==1
			    3 is less than mtn(4) so we increase our ans by 1 ( (3,4) is weaker than (10,4)  )
			when i==0
			  5 is not less than mtn(4) so we dont increase our ans
			 
			 our final ans is 1

*/

/*
in short if [6,7] [6,8] 
    two ways to sort possible
    [6,8] [6,7] it will give 0 answer
    [6,7] [6,8] it will give 1 answer 
*/
class Solution{
    
public:
     //handling the edge case while sorting
     static bool comp(vector<int> &a, vector<int> &b){
         
          if (a[0] == b[0]){
          
               return a[1] > b[1];
          }
          return a[0] < b[0];
     }
    
     int numberOfWeakCharacters(vector<vector<int>> &properties){
         
          //sorting based on attack -> properties[i] = [attacki, defensei]
          // [[5,5],[6,3],[3,6]]   -> 3,6 ; 5,5 ; 6,3 ; 
          sort(properties.begin(), properties.end(), comp); 
         
//           for(auto x : properties){
//             cout << x[0] << "," << x[1] << " ; ";
//           }
         
          int maxi = INT_MIN;                                //max till now while moving from right
         
          int ans = 0;

          for (int i = properties.size() - 1; i >= 0; i--){
              
               if (properties[i][1] < maxi) // if the second parameter is also less increase the ans
                    ans++;
              
               maxi = max(maxi, properties[i][1]);
          }
         
          return ans;
     }
};