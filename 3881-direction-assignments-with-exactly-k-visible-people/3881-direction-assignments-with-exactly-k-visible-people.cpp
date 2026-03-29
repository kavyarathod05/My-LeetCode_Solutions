class Solution {
    long long mod = 1e9 + 7;
    vector<long long> fact, invFact;

    long long power(long a, long b) {
        long long res = 1;
        while (b) {
            if (b & 1)
                res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
    void init(int n) {
        fact.resize(n+1);
        invFact.resize(n+1);
        fact[0] = 1;
        for(int i=1;i<=n;i++){
            fact[i] = fact[i-1]*i%mod;
        }
        invFact[n]= power(fact[n], mod-2);
        for(int i=n-1;i>=0;i--){
            invFact[i] = invFact[i+1]*(i+1)%mod;
        }
    }
    long long c(long long a, long long b){
            if (b < 0 || b > a) return 0;

        return fact[a]*invFact[b]%mod*invFact[a-b]%mod;
    }


public:
    int countVisiblePeople(int n, int p, int k) {
        if (k > n - 1)
            return 0;

        init(n);

        int l = p;
        int r = n - 1 - p;

        long long ans = 0;

        for (int i = 0; i <= k; i++) {
            if (i <= l && (k - i) <= r) {
                long long a = c(l, i);
                long long b = c(r, k - i);
                ans = (ans + (a * b) % mod) % mod;
            }
        }

        return (ans * 2) % mod;
    }
};