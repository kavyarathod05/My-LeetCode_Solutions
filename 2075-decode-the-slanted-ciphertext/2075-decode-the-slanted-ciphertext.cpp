class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if (rows == 0) return "";

        int cols = n / rows;

        vector<vector<char>> mat(rows, vector<char>(cols));

        int idx = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = encodedText[idx++];
            }
        }

        string ans = "";

        for (int i = 0; i < cols; i++) {
            int x = 0, y = i;

            while (x < rows && y < cols) {
                ans += mat[x][y];
                x++;
                y++;
            }
        }

        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};