//https://leetcode.com/problems/minimum-area-rectangle/discuss/900264/IntuitiveWith-PicturesC%2B%2BJavaExplanation

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> hashmap; // Key => Integer | Value => Set
        
        for(auto& single_point: points) // Iterate through every single point & store the coordinates in map.
            hashmap[single_point[0]].insert(single_point[1]); // Insert y coordinate into Value (HashSet) corresponding to Key (equal to x coordinate)
			/* Explanation : 
					single_point => refering to a single point [x,y] in vector
					x-coordinate of a single point => single_point[0]
					y-coordinate of a single point => single_point[1]

					Key => x coordinate of a point 
						=> single_point[0]

					Value => HashSet of y coordinates 
						=> hashmap[Key]
						=> hashmap[x-coordinate of a single point]
						=> hashmap[single_point[0]]

					Insert y coordinate into corresponding Value (HashSet)
						=> Value.insert(y-coordinate of a single point)
						=> hashmap[Key].insert(y-coordinate of a single point)
						=> hashmap[x-coordinate of a single point].insert(y-coordinate of a single point)
						=> hashmap[single_point[0]].insert(single_point[1])
			*/
			
        int minimum_area = INT_MAX; // Vairable to store the minimum area
        
        for(int i = 0; i < points.size(); i++) { // Iterator corresponding to different A points
            for(int j = i + 1; j < points.size(); j++) { // Iterator corresponding to different B points
			
                int x1 = points[i][0], y1 = points[i][1];  // Coordinates of Point A
				int x2 = points[j][0], y2 = points[j][1];  // Coordinates of Point B
                
                if(x1 != x2 && y1 != y2) // Point A & B must form a diagonal of the rectangle.
                    if( hashmap[x1].find(y2) != hashmap[x1].end() // Check if D exists in hashmap
											&& 
					hashmap[x2].find(y1) != hashmap[x2].end() ) // Check if C exists in hashmap
					/* Explanation : 
							Check existence of y2 in Value (HashSet) corresponding to x1 Key
								=> Value.find(y-coordinate of point B)
								=> hashmap[Key].find(y-coordinate of point B)
								=> hashmap[x-coordinate of point A].find(y-coordinate of point B)
								=> hashmap[x1].find(y2) => Checks if point D exists in hashmap 
							Check existence of y1 in Value (HashSet) corresponding to x2 Key
								=> Value.find(y-coordinate of point A)
								=> hashmap[Key].find(y-coordinate of point A)
								=> hashmap[x-coordinate of point B].find(y-coordinate of point A)
								=> hashmap[x2].find(y1) => Checks if point C exists in hashmap 
					*/
                        minimum_area = min( minimum_area , abs(x1-x2) * abs(y1-y2) ); // Store the minimum area possible
            }
        }
        return minimum_area != INT_MAX ? minimum_area : 0; // Return 0 if no rectangle exists
    }
};