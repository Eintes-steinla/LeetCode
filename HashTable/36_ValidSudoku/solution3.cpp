class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // Ta cần kiểm tra từng con số (1–9) trong:
        // row, col, box
        // Mỗi lần thấy một số, ta đánh dấu nó đã xuất hiện ở row/col/box tương ứng.
        // Nếu số đó đã được đánh dấu rồi → return false.
        // Toán tử - '0' trong C++ (và hầu hết các ngôn ngữ cấp thấp hơn) là cách phổ biến để chuyển một ký tự chữ số (char) thành số nguyên (int). Dùng mã ASCII
        int row[9][9] = {0};
        int col[9][9] = {0};
        int box[9][9] = {0};

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1;
                    int k = (i / 3) * 3 + (j / 3);

                    if (row[i][num]++ > 0)
                        return false;
                    if (col[j][num]++ > 0)
                        return false;
                    if (box[k][num]++ > 0)
                        return false;
                }
            }
        }

        return true;
    }
};