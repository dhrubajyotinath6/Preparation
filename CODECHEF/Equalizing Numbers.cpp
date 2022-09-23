//https://www.codechef.com/submit/EQLZING?tab=statement

/*
Chef has two integers AA and BB. In one operation he can choose any integer d, and make one of the following two moves :

Add d to AA and subtract dd from BB.
Add d to BB and subtract dd from AA.
Chef is allowed to make as many operations as he wants. Can he make AA and BB equal?

Input Format
First line will contain TT, number of test cases. Then the test cases follow.
Each test case contains of a single line of input, two integers A, BA,B.
Output Format
For each test case, if Chef can make the two numbers equal print YES else print NO.

You may print each character of the string in uppercase or lowercase (for example, the strings yEs, Yes, YeS, and YES will all be treated as identical).

*/

/*
Instead of performing many moves, we can simply combine them into a single move by 
adding up all the dd values chosen. Also, by allowing negative values of dd, 
we can always add dd to AA and subtract dd from BB.

So, all that remains is to check if AA can be made equal to BB in a single move. C
an you see how to check this?


*************

Suppose AA and BB can be made equal. Then, for some integer dd, 
A+d = B-dA+d=B−d, which means 2d = B-A2d=B−A.

Since dd must be an integer, this means B-AB−A must be even (so we can divide it by 22).

So, the answer is "Yes" if B-AB−A is even, and "No" otherwise.

*/

A + d = B - d => 2d = B - a



=> #include <iostream>
using namespace std;

void solve(){
    
    int a, b;
    cin >> a >> b;
    
    int d = b - a;
    
    if(d%2==0){
        cout << "yes" << endl;
        return;
    }
    cout << "no" << endl;
}

int main() {
	// your code goes here
	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
	    solve();
	}
	return 0;
}
