// https://leetcode.com/assessment/reports/SW50ZXJ2aWV3U2Vzc2lvbk5vZGU6Mjg4NzMzMw==

/*

1. SORT COLORS
2. REMOVE K DIGITS

*/

// REMOVE K DIGITS SOLUTION
/*
https://leetcode.com/problems/remove-k-digits/solution/

https://leetcode.com/problems/remove-k-digits/discuss/1779458/C%2B%2B-oror-Easy-To-Understand-oror-Stack-oror-Short-and-Simple

https://leetcode.com/problems/remove-k-digits/discuss/88680/My-Easy-Understandable-C%2B%2B-Solution

"10200"  -> 200
K = 1,

"10200" > 0
K = 3

"10"   -> 0
1

"10001"
4

1234567890 -> 0
k = 9

100200 -> 200
K = 3

100000 -> 0
K=4, K = 1
*/

class Solution
{
public:
    string removeKdigits(string num, int k)
    {

        // number of operation greater than length we return an empty string
        if (num.length() <= k)
            return "0";

        // k is 0 , no need of removing /  preforming any operation
        if (k == 0)
            return num;

        stack<char> st;

        for (char n : num)
        {

            while (st.empty() == false && k > 0 && st.top() > n)
            {
                st.pop();
                k--;
            }

            st.push(n);

            // popping preceding zeroes
            if (st.size() == 1 && n == '0')
                st.pop();
        }

        for (int i = 0; i < k; i++)
        {
            if (st.empty() == false)
                st.pop();
        }

        string ans = "";

        while (st.size() > 0)
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans.empty() ? "0" : ans;
    }
};

/*
SIMILAR QUESTIONS
    Create Maximum Number
    Monotone Increasing Digits
    Find the Most Competitive Subsequence
    Append K Integers With Minimal Sum
    Remove Digit From Number to Maximize Result
*/