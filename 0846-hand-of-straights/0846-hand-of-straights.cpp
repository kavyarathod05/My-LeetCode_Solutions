class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if(n % groupSize) return false;

        sort(hand.begin(), hand.end());

        vector<bool> used(n, false);

        int groups = n / groupSize;

        while(groups--) {

            int start = -1;

            for(int i = 0; i < n; i++) {
                if(!used[i]) {
                    start = hand[i];
                    used[i] = true;
                    break;
                }
            }

            int prev = start;

            for(int cnt = 1; cnt < groupSize; cnt++) {

                bool found = false;

                for(int j = 0; j < n; j++) {

                    if(!used[j] && hand[j] == prev + 1) {
                        used[j] = true;
                        prev = hand[j];
                        found = true;
                        break;
                    }
                }

                if(!found) return false;
            }
        }

        return true;
    }
}; 