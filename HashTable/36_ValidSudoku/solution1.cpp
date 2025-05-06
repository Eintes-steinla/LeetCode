class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // dùng 3 mảng 2 chiều để lưu trữ các hàng, cột và ô vuông 3x3
        // dùng hàm sort để sắp xếp các giá trị trong hàng, cột và ô vuông 3x3
        // dùng hàm binary_search để kiểm tra xem giá trị đã xuất hiện trong hàng, cột và ô vuông 3x3 hay chưa
        // nếu đã xuất hiện thì trả về false
        // trả về true nếu không có giá trị nào xuất hiện nhiều lần trong hàng, cột và ô vuông 3x3
        // Time complexity: O(n^2)
        vector<vector<char>> rows, cols, boxes;
        vector<char> tmp1, tmp2, tmp3, tmp4, tmp5;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    tmp1.push_back(board[i][j]);

                    if (j < 3)
                        tmp3.push_back(board[i][j]);
                    else if (j < 6)
                        tmp4.push_back(board[i][j]);
                    else if (j < 9)
                        tmp5.push_back(board[i][j]);
                }
                if (board[j][i] != '.')
                    tmp2.push_back(board[j][i]);
            }
            rows.push_back(tmp1);
            tmp1.clear();
            cols.push_back(tmp2);
            tmp2.clear();

            if (i == 2 || i == 5 || i == 8)
            {
                boxes.push_back(tmp3);
                boxes.push_back(tmp4);
                boxes.push_back(tmp5);
                tmp3.clear();
                tmp4.clear();
                tmp5.clear();
            }
        }

        for (int i = 0; i < 9; i++)
        {
            sort(rows[i].begin(), rows[i].end());
            sort(cols[i].begin(), cols[i].end());
            sort(boxes[i].begin(), boxes[i].end());
            int lenR = rows[i].size();
            int lenC = cols[i].size();
            int lenB = boxes[i].size();
            for (int j = 0; j < lenR; j++)
            {
                if (binary_search(rows[i].begin() + j + 1, rows[i].end(), rows[i][j]))
                {
                    return false;
                }
            }
            for (int j = 0; j < lenC; j++)
            {
                if (binary_search(cols[i].begin() + j + 1, cols[i].end(), cols[i][j]))
                {
                    return false;
                }
            }
            for (int j = 0; j < lenB; j++)
            {
                if (binary_search(boxes[i].begin() + j + 1, boxes[i].end(), boxes[i][j]))
                {
                    return false;
                }
            }
        }

        return true;
    }
};