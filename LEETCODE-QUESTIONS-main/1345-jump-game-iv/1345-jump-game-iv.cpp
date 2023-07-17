//https://leetcode.com/problems/jump-game-iv/discuss/502699/JavaC%2B%2B-BFS-Solution-Clean-code-O(N)


class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        if(arr.size() == 1) return 0;
        
        int n = arr.size();
        unordered_map<int, vector<int>> indicesOfValue;
        
        for (int i = 0; i < n; i++)
            indicesOfValue[arr[i]].push_back(i);
        
        vector<bool> visited(n); visited[0] = true;
        queue<int> q; q.push(0);
        
        int step = 0;
        
        while (!q.empty()) {
            
            int s = q.size();
            for (int size = 0; size < s; size++) {
                
                int i = q.front(); q.pop();
                if (i == n - 1) return step; // Reached to last index
                
                vector<int>& next = indicesOfValue[arr[i]];
                next.push_back(i - 1); next.push_back(i + 1);
                
                for (int j : next) {
                    if (j >= 0 && j < n && !visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
                next.clear(); // avoid later lookup indicesOfValue arr[i]
            }
            step++;
        }
        return 0;
    }
};