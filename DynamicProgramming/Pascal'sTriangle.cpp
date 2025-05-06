#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> v(numRows); // Khởi tạo vector có sẵn số hàng

    for (int i = 0; i < numRows; i++)
    {
        // Đặt kích thước cho từng hàng và gán tất cả phần tử là 1
        v[i].resize(i + 1, 1);
        // Tính các giá trị giữa (không tính phần tử đầu & cuối)
        for (int j = 1; j < i; j++)
        {
            v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
        }
    }

    return v;
}

int main()
{
    cout << "Minh";
    cin.get();
}