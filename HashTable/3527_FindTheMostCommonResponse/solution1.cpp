class Solution
{
public:
    string findCommonResponse(vector<vector<string>> &responses)
    {
        // lưu từng vector vào unordered_set để phân biệt
        vector<unordered_set<string>> se;
        for (auto v : responses)
        {
            unordered_set<string> tmp(v.begin(), v.end());
            se.push_back(tmp);
        }

        // lưu các đánh giá trong unordered_set vào multiset
        multiset<string> ms;
        for (auto s : se)
        {
            for (auto i : s)
            {
                ms.insert(i);
            }
        }

        // đếm xem trong multiset đánh giá nào xuất hiện nhiều nhất
        string str = "";
        int max = 0;
        for (auto i : ms)
        {
            if (ms.count(i) > max)
            {
                max = ms.count(i);
                str = i;
            }
        }

        return str;
    }
};