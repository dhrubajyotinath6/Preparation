/*

https://leetcode.com/problems/simplify-path/solution/

*/
/*
how did you traverse a stack from bottom to top?

ANS: 
Apparently its due to inheritance from the base class: https://stackoverflow.com/questions/51371570/why-stack-iterator-works-in-reverse-order     --> java

https://stackoverflow.com/questions/23194548/how-to-traverse-stack-in-c   

https://www.geeksforgeeks.org/print-stack-elements-from-bottom-to-top/

So if you do a while loop pop-ing from the stack it will be in stack order, but foreach loop will do the opposite order...

Would be nice to have this explanation in the write-up. It's key to explain in an interview

***
Since C++ std::stack doesn't implement begin() nor end(), in this case a std::vector is a fine replacement. std::deque will work too.

USE THIS TECHNIQUES:

		// adding all the stack elements to res
        while(!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }
        
        |         |
        |   3     |
        |   2     |
        |___1_____|
        
        res = "/" + 3 + ""            /3
        res = "/" + 2 + "/3"          /2/3
        res = "/" + 1 + "/2/3"        /1/2/3
*/

/*
How to split string with delimiter using C++? - Stack Overflow

->https://www.geeksforgeeks.org/split-string-substrings-using-delimiter/

// C++ implementation to split string into
// substrings on the basis of delimiter
#include <bits/stdc++.h>
using namespace std;

// function to split string into substrings on the
// basis of delimiter and return the substrings
// after split
vector<string> splitStrings(string str, char dl)
{
	string word = "";

	// to count the number of split strings
	int num = 0;

	// adding delimiter character at the end
	// of 'str'
	str = str + dl;

	// length of 'str'
	int l = str.size();

	// traversing 'str' from left to right
	vector<string> substr_list;
	for (int i = 0; i < l; i++) {

		// if str[i] is not equal to the delimiter
		// character then accumulate it to 'word'
		if (str[i] != dl)
			word = word + str[i];

		else {

			// if 'word' is not an empty string,
			// then add this 'word' to the array
			// 'substr_list[]'
			if ((int)word.size() != 0)
				substr_list.push_back(word);

			// reset 'word'
			word = "";
		}
	}

	// return the splitted strings
	return substr_list;
}

// Driver program to test above
int main()
{
	string str = "geeks;for;geeks";
	char dl = ';';

	vector<string> res = splitStrings(str, dl);
	for (auto x : res)
		cout << x << endl;

	return 0;
}

*/
class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> st;
        vector<string> components = splitStrings(path, '/');
        
        // Split the input string on "/" as the delimiter
        // and process each portion one by one
        for(auto comp : components){
            
             // A no-op for a "." or an empty string
            if(comp == "." || comp.empty()) continue;
            
            else if(comp == ".."){
                // If the current component is a "..", then
                // we pop an entry from the stack if it's non-empty
                if(st.empty() == false) st.pop();
            }
            
            else{
                // Finally, a legitimate directory name, so we add it
                // to our stack
                st.push(comp);
            }
        }
        
         string res = "";
        
         while(!st.empty()){
             
            res = "/" + st.top() + res;
            st.pop();
         }
        
        return res.length() > 0 ? res : "/";
    }
    
    vector<string> splitStrings(string str, char dl){
        
	string word = "";

	// to count the number of split strings
	int num = 0;

	// adding delimiter character at the end
	// of 'str'
	str = str + dl;

	// length of 'str'
	int l = str.size();

	// traversing 'str' from left to right
	vector<string> substr_list;
	for (int i = 0; i < l; i++) {

		// if str[i] is not equal to the delimiter
		// character then accumulate it to 'word'
		if (str[i] != dl)
			word = word + str[i];

		else {

			// if 'word' is not an empty string,
			// then add this 'word' to the array
			// 'substr_list[]'
			if ((int)word.size() != 0)
				substr_list.push_back(word);

			// reset 'word'
			word = "";
		}
	}

	// return the splitted strings
	return substr_list;
}
};