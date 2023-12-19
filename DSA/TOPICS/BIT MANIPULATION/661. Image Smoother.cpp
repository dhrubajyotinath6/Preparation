An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).


Given an m x n integer matrix img representing the grayscale of an image, return the image after applying the smoother on each cell of it.

 

Example 1:


Input: img = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[0,0,0],[0,0,0],[0,0,0]]
Explanation:
For the points (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the points (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Example 2:


Input: img = [[100,200,100],[200,50,200],[100,200,100]]
Output: [[137,141,137],[141,138,141],[137,141,137]]
Explanation:
For the points (0,0), (0,2), (2,0), (2,2): floor((100+200+200+50)/4) = floor(137.5) = 137
For the points (0,1), (1,0), (1,2), (2,1): floor((200+200+50+200+100+100)/6) = floor(141.666667) = 141
For the point (1,1): floor((50+200+200+200+200+100+100+100+100)/9) = floor(138.888889) = 138
 

Constraints:

m == img.length
n == img[i].length
1 <= m, n <= 200
0 <= img[i][j] <= 255



//1. brute force
/*
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int m = img.size(),  n = img[0].size();
        
        vector<vector<int>> newImg(m, vector<int>(n));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                int sum = 0;
                int count = 0;
                
                for(int x = i - 1; x <= i + 1; x++){
                    for(int y = j - 1; y <= j + 1; y++){
                        
                        if(0 <= x && x < m && 0 <= y && y < n){
                            sum += img[x][y];
                            count += 1;
                        }
                    }
                }
                
                newImg[i][j] = sum/count;
            }
        }
        
        return newImg;
    }
};
*/

// 2.optimised one
/*
Can we somehow store both the pre-modified and post-modified img[i][j] values in the same cell? Ideally speaking, it's possible.


we hv two numbers : p, r

Y=p⋅X+r   (X is a constant)

To extract p from Y, we can do Y/X
To extract r from Y, we can do Y%X

X value ?

r varies from 0 to X-1

0 <= r <= 255

therefore, X = 256;
*/


/*
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int m = img.size(),  n = img[0].size();
        
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                int sum = 0;
                int count = 0;
                
                for(int x = i - 1; x <= i + 1; x++){
                    for(int y = j - 1; y <= j + 1; y++){
                        
                        if(0 <= x && x < m && 0 <= y && y < n){
                            sum += img[x][y];
                            count += 1;
                        }
                    }
                }
                
                // Y = p.X + r;
                img[i][j] += (sum/count)*256;
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                img[i][j] /= 256;
            }
        }
        
        return img;
    }
};
*/


// 3. More optimised version
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // Save the dimensions of the image.
        int m = img.size();
        int n = img[0].size();

        // Iterate over the cells of the image.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Initialize the sum and count 
                int sum = 0;
                int count = 0;

                // Iterate over all plausible nine indices.
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        // If the indices form valid neighbor
                        if (0 <= x && x < m && 0 <= y && y < n) {
                            // Extract the original value of img[x][y].
                            sum += img[x][y] & 255;
                            count += 1;
                        }
                    }
                }
                
                // Encode the smoothed value in img[i][j].
                img[i][j] |= (sum / count) << 8;
            }
        }

        // Extract the smoothed value from encoded img[i][j].
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                img[i][j] >>= 8;
            }
        }

        // Return the smooth image.
        return img;
    }
};