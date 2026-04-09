class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost,
                          int crossCost) {
        int n = s.size();
        int m = t.size();
        if (n != m)
            return 0;
        int left = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i])
                left++;
        }
        long long cost = 0;
        if (left == 0)
            return 0;
        // step 1 find pairs that can be swapped without using crosscost (0,1)
        // (1,0) s[i] = 0 , t[i] = 1
        int p1 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0' && t[i] == '1')
                p1++;
        }
        // s[i] =  1 , t[i] = 0
        int p2 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1' && t[i] == '0')
                p2++;
        }
        // step2  out of this the min one that many total pairs can be formed
        int totalPair = min(p1, p2);
        left -= (totalPair * 2);
        // step 3 compare flipcost*2 < crosscost
        if (flipCost * 2 <= swapCost) {
            cost += 1LL * totalPair * flipCost * 2;
        } else {
            cost += 1LL*totalPair * swapCost;
        }

        if (left > 0) {
            int pairs = left / 2;
            int rem = left % 2;
            // here compare swapCost+crossCost<= 2*flipcost
            cost += min(1LL * (swapCost + crossCost) * pairs,
                        1LL * 2 * pairs * flipCost);
            if (rem != 0) {
                cost += rem * flipCost;
            }
        }
        return cost;
    }
};