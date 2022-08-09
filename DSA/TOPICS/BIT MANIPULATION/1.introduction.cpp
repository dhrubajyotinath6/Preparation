/*
1.
https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/tutorial/

*/

#include <iostream>
#include <math.h>

using namespace std;

long largest_power(long N)
{

    // changing all right side bits to 1.
    N = N | (N >> 1);
    N = N | (N >> 2);
    N = N | (N >> 4);
    N = N | (N >> 8);

    // as now the number is 2 * x-1, where x is required answer, so adding 1 and dividing it by 2
    return (N + 1) >> 1;
}

long f(long N)
{

    int bitCount = 0;
    long n = N;
    while (n > 0)
    {
        bitCount++;
        n = n >> 1;
    }

    long ans = pow(2, bitCount - 1);

    return ans;
}

int main()
{

    long N = 17;

    cout << largest_power(N) << endl;

    cout << endl;

    cout << f(N) << endl;

    return 0;
}
