/*
https://leetcode.com/problems/simplify-path/
https://leetcode.com/problems/simplify-path/solution/  --VERY VERY IMP

Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or directory 
(i.e., no period '.' or double period '..')
Return the simplified canonical path.

 

Example 1:

Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.



Example 2:

Input: path = "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.


Example 3:

Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
 

Constraints:

1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path.

*/
/*
Now suppose that to a path like /a/b/c, we add another component like /a/b/c/... 
Now, this is interesting because the .. is no longer a sub-directory name. 
It has a special meaning and an indication to the operating system to move up one level in the directory 
structure thus transforming the overall path to just /a/b. 
It's as if we popped out the subdirectory c from the overall path. 
That's the core idea of this problem. If you think about it, the only actionable special character is ..
The single dot is kind of a no-op because it simply means the current directory. 
So nothing changes in the overall path as such. 
Now that we have a general idea about how this problem can be potentially solved using the stack, 
let's get right into the algorithm and discuss the solution.

                                Algorithm

1.Initialize a stack, S that we will be using for our implementation.

2.Split the input string using / as the delimiter. This step is really important 
because no matter what, the given input is a valid path and we simply have to shorten it. 
So, that means that whatever we have between two / characters is either a directory name 
or a special character and we have to process them accordingly.

3.Once we are done splitting the input path, we will process one component at a time.

4.If the current component is a . or an empty string, we will do nothing and simply continue. 
Well if you think about it, the split string array for the string /a//b would be [a,,b]. 
yes, that's an empty string in between a and b. Again, from the perspective of the overall path, 
it doesn't mean anything.

5.If we encounter a double-dot .., we have to do some processing. This simply means go one level up 
in the current directory path. So, we will pop an entry from our stack if it's not empty.

6.Finally, if the component we are processing right now is not one of the special characters, 
then we will simply add it to our stack because it's a legitimate directory name.

7. Once we are done processing all the components, we simply have to connect all the directory names 
in our stack together using / as the delimiter and we will have our shortest path that leads us to 
the same directory as the one provided as an input.

*/

/*



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

