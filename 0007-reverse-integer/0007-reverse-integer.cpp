class Solution {
public:
    int reverse(int x) {
        // Cast x to long long immediately to safely handle abs(INT_MIN)
        long long longX = x;
        
        long long res = rec(abs(longX), 0) * (x < 0 ? -1 : 1);
        
        // Check for 32-bit signed integer overflow
        if (res < INT_MIN || res > INT_MAX) {
            return 0;
        }
        
        return (int)res;
    }

private:
    // Changed parameter 'n' to long long to prevent any internal overflow
    long long rec(long long n, long long rev) {
        if (n == 0) {
            return rev;
        }
        rev = rev * 10 + n % 10;
        return rec(n / 10, rev);
    }
};