/*

You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after each character of searchWord is typed. 
Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix 
return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.

 

Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
After typing mou, mous and mouse the system suggests ["mouse","mousepad"].





Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Explanation: The only word "havana" will be always suggested while typing the search word.
 

Constraints:

1 <= products.length <= 1000
1 <= products[i].length <= 3000
1 <= sum(products[i].length) <= 2 * 104
All the strings of products are unique.
products[i] consists of lowercase English letters.
1 <= searchWord.length <= 1000
searchWord consists of lowercase English letters.


*/

//https://leetcode.com/problems/search-suggestions-system/discuss/436674/C%2B%2BJavaPython-Sort-and-Binary-Search-the-Prefix
class Solution {
public:
        vector<vector<string>> suggestedProducts(vector<string>& A, string searchWord) {
            
        for(auto &a : A){
            cout << a << "  ";
        }
        
         cout << endl;
            
        auto it = A.begin();
            
        sort(it, A.end());
            
        cout << endl;
            
        for(auto &a : A){
            cout << a << "  ";
        }
        cout << endl;
            
        vector<vector<string>> res;
            
        string cur = "";
            
        for (char c : searchWord) {
            
            cur += c;
            vector<string> suggested;
            
            it = lower_bound(it, A.end(), cur);
            
            for (int i = 0; i < 3 && it + i != A.end(); i++) {
                
                string& s = *(it + i);
                if (s.find(cur)) break;
                suggested.push_back(s);
            }
            
            res.push_back(suggested);
        }
        return res;
    }
};

/*
Your input
["mobile","mouse","moneypot","monitor","mousepad"]
"mouse"

stdout
mobile  mouse  moneypot  monitor  mousepad  

mobile  moneypot  monitor  mouse  mousepad  

Output
[["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]

Expected
[["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]

----------------------------------------------

Your input
["bags","baggage","banner","box","cloths"] 
"bags"

stdout
bags  baggage  banner  box  cloths  

baggage  bags  banner  box  cloths  

Output
[["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]

Expected
[["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]


--------------------------------------------

String find is used to find the first occurrence of sub-string in the specified string being called upon. It returns the index of the first occurrence of the substring in the string from given starting position. The default value of starting position is 0.

#include <iostream>

using namespace std;

int main()
{
   string s = "mousepad"; // 0
   
   string s2 = "padmouse"; // 3
   
   string curr = "mouse";
   
   cout << s2.find(curr) << endl;

    return 0;
}


*/
