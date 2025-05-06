class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // Duyệt qua từng ô board[i][j]:
        // Nếu là số (!= '.') thì:
        // Check số đó đã tồn tại trong row[i], col[j], box[(i/3)*3 + j/3] chưa
        // Nếu đã có thì return false.
        // Nếu chưa, thêm vào 3 nơi đó.
        // Sau vòng lặp, return true.
        set<string> seen;
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                char num = board[i][j];

                if (num == '.')
                    continue;

                string row = "r" + to_string(i) + num;
                string col = "c" + to_string(j) + num;
                string box = "b" + to_string(i / 3) + to_string(j / 3) + num;

                if (seen.count(row) || seen.count(col) || seen.count(box))
                {
                    return false;
                }

                seen.insert(row);
                seen.insert(col);
                seen.insert(box);
            }
        }

        return true;
    }
};
