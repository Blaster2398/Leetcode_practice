class Solution {
public:
vector<int> sieve(int left, int right) {
    if (right < 2) return{}; // No primes below 2

    // Step 1: Create an array to mark primes (0 = prime, 1 = not prime)
    vector<int> primes(right + 1);

    for (int i = 0; i <= right; i++) {
        primes[i] = 0; // Assume all numbers are prime initially
    }

    // Step 2: Run the sieve from 2 to sqrt(right)
    for (int i = 2; i * i <= right; i++) {
        if (primes[i] == 0) { // If `i` is prime
            for (int j = i * i; j <= right; j += i) {
                primes[j] = 1; // Mark multiples of `i` as not prime
            }
        }
    }
    vector<int> result ;
    // Step 3: Print primes from `left` to `right` in left-to-right order
    for (int i = max(2, left); i <= right; i++) {
        if (primes[i] == 0) {
            cout << i << " ";
            result.push_back(i);
        }
    }

    return result;
}
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes = sieve(left, right);
        int min = INT_MAX;
        int a = -1;
        int b = -1;
        for (int i = primes.size() - 1; i > 0; i--) { 
            if (primes[i] - primes[i - 1] <= min) {  
                a = primes[i - 1];  
                b = primes[i];  
                min = primes[i] - primes[i - 1];
            }
        }
        return {a,b};
    }
    
};