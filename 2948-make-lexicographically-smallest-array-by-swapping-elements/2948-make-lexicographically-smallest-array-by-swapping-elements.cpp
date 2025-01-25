class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        // to store it in form {nums[i],i};
        vector<pair<int, int>> indexed;
        // O(n) time
        for (int i = 0; i < n; i++) indexed.push_back({nums[i], i});
        // O(nlogn)
        sort(indexed.begin(), indexed.end());
        // make a group initially and add first in it 
        vector<vector<int>> groups = {{indexed[0].second}};
        // O(n)
        for (int i = 1; i < n; i++) {
            // if found element then push it in the existing group that will be last
            // always just element and before that as we want only group doesn't matter index and it is sorted so it works
            if (indexed[i].first - indexed[i - 1].first <= limit) {
                groups.back().push_back(indexed[i].second); // Store index instead of value
            }
            // if not in limit then make a new one
            else {
                groups.push_back({indexed[i].second}); // Store index for the new group
            }
        }
        // O(klogk)
        for (auto& group : groups) {
            vector<int> sortedGroup;
            // Extract the values corresponding to the indices in the group
            for (int i : group) sortedGroup.push_back(nums[i]);
            // sort index and its values both as we want minimum element at minimum index
            sort(sortedGroup.begin(), sortedGroup.end());
            sort(group.begin(), group.end());
            for (int i = 0; i < group.size(); i++) 
                nums[group[i]] = sortedGroup[i]; // Map sorted values back to sorted indices
        }
        return nums;
    }
};
