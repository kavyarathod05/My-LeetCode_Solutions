class Solution {
public:
    int check(vector<int>& weights, int mid) {
        int cnt = 1, curr = 0;
        for (int w : weights) {
            if (curr + w > mid) {
                cnt++;
                curr = 0;
            }
            curr += w;
        }
        return cnt;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int answer = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(weights, mid) <= days) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return answer;
    }
};
