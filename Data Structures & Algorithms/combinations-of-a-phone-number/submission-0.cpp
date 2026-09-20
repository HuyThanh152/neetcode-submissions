class Solution {
public:
    vector<string> res;
    string curr;

    void backtrack(const string& s, int idx) {
        if (idx == s.size()) {
            res.push_back(curr);
            return;
        }

        int tmp = s[idx] - '0';

        // 1. Xử lý riêng Phím 7 (4 chữ cái: p, q, r, s)
        if (tmp == 7) {
            int i = 0;
            while (i < 4) {
                curr.push_back('p' + i);
                backtrack(s, idx + 1);
                curr.pop_back();
                i++;
            }
        }
        // 2. Xử lý riêng Phím 8 (3 chữ cái: t, u, v)
        else if (tmp == 8) {
            int i = 0;
            while (i < 3) {
                curr.push_back('t' + i);
                backtrack(s, idx + 1);
                curr.pop_back();
                i++;
            }
        }
        // 3. Xử lý riêng Phím 9 (4 chữ cái: w, x, y, z)
        else if (tmp == 9) {
            int i = 0;
            while (i < 4) {
                curr.push_back('w' + i);
                backtrack(s, idx + 1);
                curr.pop_back();
                i++;
            }
        }
        // 4. Các phím 2, 3, 4, 5, 6 tuân theo quy luật chuẩn (3 chữ cái)
        else {
            int i = 0;
            while (i < 3) {
                curr.push_back((char)((tmp - 2) * 3 + i + 'a'));
                backtrack(s, idx + 1);
                curr.pop_back();
                i++;
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        backtrack(digits, 0);
        return res;
    }
};