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