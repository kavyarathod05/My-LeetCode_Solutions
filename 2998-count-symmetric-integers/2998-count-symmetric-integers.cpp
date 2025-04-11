class Solution {
public:
    bool check(string& s) {
        int n = s.size();
        if (n % 2 != 0) return false;

        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n / 2; ++i) {
            sum1 += s[i] - '0';
        }
        for (int i = n / 2; i < n; ++i) {
            sum2 += s[i] - '0';
        }
        return sum1 == sum2;
    }

    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for (int i = low; i <= high; i++) {
            string s = to_string(i);
            if (check(s)) {
                cnt++;
            }
        }
        return cnt;
    }
};
