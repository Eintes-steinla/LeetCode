class Solution
{
public:
    string triangleType(vector<int> &nums)
    {
        int a = nums[0], b = nums[1], c = nums[2];
        if ((a < b + c) &&
            (b < a + c) &&
            (c < b + a))
        {
            if ((a == b) &&
                (a == c) &&
                (b == c))
            {
                return "equilateral";
            }
            if ((a == b && a != c) ||
                (a == c && a != b) ||
                (b == c && b != a))
            {
                return "isosceles";
            }
            return "scalene";
        }
        return "none";
    }
};