class Solution {
    long long mod = 1e9 + 7;
public:
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    int sumOfNumbers(int l, int r, int k) {
        long long count = r - l + 1;
        long long sumRange = (long long)(l + r) * count / 2;
        long long t1 = sumRange % mod;
        long long t2 = power(count, k - 1);
        long long t3 = (power(10, k) - 1 + mod) % mod * power(9, mod - 2) % mod;
        return (t1 * t2 % mod * t3 % mod);
    }
};