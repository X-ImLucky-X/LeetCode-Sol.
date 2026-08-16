class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> temp(numRows);
        int i = 0;
        int z = 1;  // direction: 1 = down, -1 = up
        for (char c : s) {
            temp[i] += c;
            if (i == 0) {
                z = 1;
            } else if (i == numRows - 1) {
                z = -1;
            }

            i += z;
        }
        string res = "";
        for (auto& row : temp) {
            res += row;
        }
        return res;
    }
};