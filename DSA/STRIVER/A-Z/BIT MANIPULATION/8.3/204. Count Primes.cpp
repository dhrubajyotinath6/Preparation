//https://leetcode.com/problems/count-primes/

class Solution {
    
    void SieveOfEratosthenes(int n, int &count){ 
        
	// Create a boolean array "prime[0..n]" and initialize 
	// all entries it as true. A value in prime[i] will 
	// finally be false if i is Not a prime, else true. 
	bool prime[n+1]; 
	memset(prime, true, sizeof(prime)); 

	for (int p=2; p*p<=n; p++) 
	{ 
		// If prime[p] is not changed, then it is a prime 
		if (prime[p] == true) 
		{ 
			// Update all multiples of p greater than or 
			// equal to the square of it 
			// numbers which are multiple of p and are 
			// less than p^2 are already been marked. 
			for (int i=p*p; i<=n; i += p) 
				prime[i] = false; 
		} 
	} 

	//all prime numbers 
	for (int p=2; p<n; p++) 
	if (prime[p]) 
		count++;
} 

public:
    int countPrimes(int n) {
        
        int count = 0;
        SieveOfEratosthenes(n, count);
        
        return count;
    }
};