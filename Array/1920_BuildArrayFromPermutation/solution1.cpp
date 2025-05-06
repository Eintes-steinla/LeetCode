class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        vector<int> result;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            result.push_back(nums[nums[i]]);
        }
        return result;
    }
};