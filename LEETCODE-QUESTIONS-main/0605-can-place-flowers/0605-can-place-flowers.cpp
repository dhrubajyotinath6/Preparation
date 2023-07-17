class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for(int i = 0; i < flowerbed.size(); i++){
            
            if(flowerbed[i] == 0){
                bool emptyLeftPlot = (i == 0) || (flowerbed[i-1] == 0);
                bool emptyRightPlot = (i == flowerbed.size()-1) || (flowerbed[i+1] == 0);
                
            if(emptyLeftPlot && emptyRightPlot){
                flowerbed[i] = 1;
                count++;
                
                if(count >= n) return true;
              }
            }
        }
        return count >= n;
    }
};