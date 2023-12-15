You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.

It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

 

Example 1:

Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo" 
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" - "New York" - "Lima" - "Sao Paulo".
Example 2:

Input: paths = [["B","C"],["D","B"],["C","A"]]
Output: "A"
Explanation: All possible trips are: 
"D" -> "B" -> "C" -> "A". 
"B" -> "C" -> "A". 
"C" -> "A". 
"A". 
Clearly the destination city is "A".
Example 3:

Input: paths = [["A","Z"]]
Output: "Z"


class Solution {
    
public:
    void mapCity(vector<vector<string>>& paths, unordered_map<string,string> &mpp){
        
        for(auto& path : paths){
            
            string city1 = path[0];
            string city2 = path[1];
            
            mpp[city1] = city2;
        }
    }

public:
    void findDestination(vector<vector<string>>& paths, unordered_map<string,string> &mpp, string &ans){
        
        for(auto& path : paths){
            
            string city1 = path[0];
            string city2 = path[1];
            
            if(mpp[city1] == ""){
               ans = city1;
               return;
            } 
            if(mpp[city2] == ""){
                ans = city2;
                return;
            } 
        }
    }
    
public:
    string destCity(vector<vector<string>>& paths) {
        
        unordered_map<string,string> mpp;
        mapCity(paths, mpp);
        
        string ans;
        
        findDestination(paths, mpp, ans);
        
        return ans;
    }
};


//better official solution

/*
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> hasOutgoing;
        for (int i = 0; i < paths.size(); i++) {
            hasOutgoing.insert(paths[i][0]);
        }
        
        for (int i = 0; i < paths.size(); i++) {
            string candidate = paths[i][1];
            if (hasOutgoing.find(candidate) == hasOutgoing.end()) {
                return candidate;
            }
        }
        
        return "";
    }
};


*/


