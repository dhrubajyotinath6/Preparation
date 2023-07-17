class Solution {
public:
    int minimumSwap(string s1, string s2) {
    int xyCount = 0;
    int yxCount = 0;

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == 'x' && s2[i] == 'y')
            xyCount++;
        else if (s1[i] == 'y' && s2[i] == 'x')
            yxCount++;
    }

    int totalCount = xyCount + yxCount;
    if (totalCount % 2 != 0)
        return -1;

    int swaps = xyCount / 2 + yxCount / 2;
    if (xyCount % 2 != 0)
        swaps += 2;

    return swaps;

    }
};