// C++ implementation of the above approach
#include <bits/stdc++.h>
using namespace std;

void GreyCode(int n)
{
	// power of 2
	for (int i = 0; i < (1 << n); i++)
	{
		// Generating the decimal
		// values of gray code then using
		// bitset to convert them to binary form
		int val = (i ^ (i >> 1));
		
		// Using bitset
		bitset<32> r(val);
		
		// Converting to string
		string s = r.to_string();
		cout << s.substr(32 - n) << endl;
	}
}


// Driver Code
int main()
{
	int n;
	n = 4;

	// Function call
	GreyCode(n);
	
	return 0;
}
