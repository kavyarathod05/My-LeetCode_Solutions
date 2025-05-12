class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result;
        set<int> uniqueNumbers;
        for (int i = 0; i < digits.size(); i++) {
            for (int j = 0; j < digits.size(); j++) {
                for (int k = 0; k < digits.size(); k++) {
                    if (i != j && j != k && i != k) {
                        int d1 = digits[i];
                        int d2 = digits[j];
                        int d3 = digits[k];

                        if (d1 == 0) continue;

                        if (d3 % 2 != 0) continue;

                        int number = d1 * 100 + d2 * 10 + d3;

                        uniqueNumbers.insert(number);
                    }
                }
            }
        }

        for (int num : uniqueNumbers) {
            result.push_back(num);
        }

        return result;
    }
};
