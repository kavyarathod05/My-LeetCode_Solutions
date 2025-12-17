class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq; // {value, index}
        vector<int> ans;

        // Initial window
        for (int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }
        ans.push_back(pq.top().first); // First max

        for (int r = k; r < n; r++) {
            pq.push({nums[r], r});
            int l = r - k + 1;

            while (pq.top().second < l) {
                pq.pop();
            }

            ans.push_back(pq.top().first);
        }

        return ans;
    }
};
