#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
    // fibonanci
    if (n <= 2)
        return n;
    int a = 1, b = 2;
    for (int i = 3; i < n; i++)
    {
        int tmp = b;
        b = b + a;
        a = tmp;
    }
    return a + b;
}
/*
lưu lại biến a = b
a gán bằng b
b gán băng c

a + b = c
    a + b = c
        a + b = c
return c
*/
int main()
{
    cout << "Minh";
    cin.get();
}
