class Solution {
public:
    string givesum(string& t, int i) {
        int sum1 = t[i] - '0';
        int sum3 = t[i + 1] - '0';
        int newsum = sum1 + sum3;
        return to_string(newsum%10);
    }

    bool hasSameDigits(string s) {
        string t = s;

        while (t.size() > 2) {
            string w = "";
            for (int i = 0; i < t.size() - 1; i++) {
                w += givesum(t, i);
            }
            t = w;
        }

        return (t.size() == 2 && t[0] == t[1]);
    }
};
