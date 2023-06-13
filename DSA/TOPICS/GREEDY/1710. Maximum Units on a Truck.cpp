

You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, 
where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. 
You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.

 

Example 1:

Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.



Example 2:

Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
Output: 91


/*
https://leetcode.com/problems/maximum-units-on-a-truck/discuss/1272564/Short-and-Easy-Solution-w-Explanation-or-Greedily-Select-Max-UnitsBox-Ratio


https://leetcode.com/problems/maximum-units-on-a-truck/discuss/999125/JavaPython-3-Sort-by-the-units-then-apply-greedy-algorithm.


*/
/*
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
	sort(begin(boxTypes), end(boxTypes), [](auto& a, auto& b){ return a[1] > b[1];}); // sort by number of units / box
        
	int maxUnits = 0;
        
	for(auto& box : boxTypes) {
        
		if(truckSize <= 0) break;                    // keep choosing greedily till you run out of truckSize 
        
		maxUnits += min(truckSize, box[0]) * box[1]; // add (no of box * units) in that box
		truckSize -= box[0];
	}
	return maxUnits;
}
};
*/

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
	int freq[1001]{0}, maxUnits = 0;   // freq[i] = number of boxes that can hold i units
        
	for(auto& box : boxTypes) freq[box[1]] += box[0];
        
	// greedily choose starting from max units till either truckSize runs out or you choose all boxes
     
    /*
	for(int units = 1000; truckSize > 0 && units > 0; --units) { 
        
		maxUnits += min(truckSize, freq[units]) * units;
		truckSize -= freq[units];
	}
    */
    
    for(int units = 1000; truckSize > 0 && ~units; --units) { 
        
		maxUnits += min(truckSize, freq[units]) * units;
		truckSize -= freq[units];
	}
    
        
	return maxUnits;
}
};