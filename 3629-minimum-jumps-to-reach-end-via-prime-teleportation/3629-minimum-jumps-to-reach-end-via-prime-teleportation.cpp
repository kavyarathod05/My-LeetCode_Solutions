class Solution {
public:
    vector<int> getFactors(int x, vector<bool>& prime) {
        vector<int> factors;
        for (int p = 2; p * p <= x; p++) {
            if (x % p == 0) {
                if (prime[p]) {
                    factors.push_back(p);
                }
                while (x % p == 0) {
                    x /= p;
                }
            }
        }
        if (x > 1)
            factors.push_back(x);
        return factors;
    }
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<bool> prime(maxi + 1, true);
        prime[0] = false;
        prime[1] = false;
        for (int i = 2; i <= maxi; i++) {
            if (prime[i]) {
                for (int j = 2 * i; j <= maxi; j += i) {
                    prime[j] = false;
                }
            }
        }
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            if (prime[nums[i]]) {
                mp[nums[i]].push_back(i);
            }
        }

        queue<pair<int, int>> q;
        // index , count
        q.push({n - 1, 0});
        vector<int> vis(n);
        vis[n-1]=1;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int index = it.first;
            int dist = it.second;

            if (index == 0)
                return dist;

            // left
            if (index - 1 >= 0 && !vis[index - 1]) {
                vis[index - 1] = 1;
                q.push({index - 1, dist + 1});
            }

            // right
            if (index + 1 < n && !vis[index + 1]) {
                vis[index + 1] = 1;
                q.push({index + 1, dist + 1});
            }

            // prime factor jumps
            vector<int> factors = getFactors(nums[index], prime);

            for (int p : factors) {

                for (int nxt : mp[p]) {

                    if (!vis[nxt]) {
                        vis[nxt] = 1;
                        q.push({nxt, dist + 1});
                    }
                }

                mp[p].clear();
            }
        }
        return n - 1;
    }
};