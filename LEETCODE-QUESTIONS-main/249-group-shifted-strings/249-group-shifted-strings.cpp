
// https://leetcode.com/problems/group-shifted-strings/solution/  --imp
//https://leetcode.com/problems/group-shifted-strings/discuss/67451/4ms-Easy-C%2B%2B-Solution-with-Explanations
/*
Syntax: If x and y are integers, then the expression: 

x % y

produces the remainder when x is divided by y. 

Return Value: 

If y completely divides x, the result of the expression is 0.
If x is not completely divisible by y, then the result will be the remainder in the range [1, x-1].
If y is 0, then division by zero is a compile-time error.

==================================================

    string s = "bcd";
    
    int x = s[0];
    
    cout << x << endl; // 98

*/

/*
Why 'a' is adding in this line...
((letter - shift + 26) % 26 + 'a')

=>Because letter - shift will give you the difference between the characters in question, but you still need to count that difference from the very first character which is 'a'. Example: 'g' - 'e' is 2 so you want to add 2 steps to the first character ('a') and then you get 'c'

a->97        x->120
b->98        y->121
c->99        z->122
d->100
e->101
f->102

*/


class Solution {
    
    string getHash(string &s){
        
        string hashKey = "";
        
        for(int i = 1; i < s.length(); i++){
            hashKey += (s[i] - s[i-1] + 26) % 26 + 'a';
        }
        
        return hashKey;
    }
    
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        
        unordered_map<string, vector<string>> mpp;
        
         // Create a hash_value (hashKey) for each string and append the string
        // to the list of hash values i.e. mapHashToList["cd"] = ["acf", "gil", "xzc"
        for(string str : strings){
            string hashKey = getHash(str);
            mpp[hashKey].push_back(str);
        }
        
         // Iterate over the map, and add the values to groups
        vector<vector<string>> groups;
        
        for(auto it : mpp){
            groups.push_back(it.second);
        }
        
        return groups;
        
    }
};