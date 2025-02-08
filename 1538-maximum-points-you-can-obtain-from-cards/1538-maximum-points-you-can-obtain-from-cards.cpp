class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if (k == n) return total;
        int windowSize = n - k;
        int windowSum = accumulate(cardPoints.begin(), cardPoints.begin() + windowSize, 0);
        int minWindowSum = windowSum;

        int i = 0, j = windowSize;
        while (j < n) {
            windowSum += cardPoints[j] - cardPoints[i];  
            minWindowSum = min(minWindowSum, windowSum);
            i++;
            j++;
        }

        return total - minWindowSum; 
    }
};
