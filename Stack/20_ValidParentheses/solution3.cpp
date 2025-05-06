class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> brackets;
        for (const char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                brackets.push(c);
            }
            else
            {
                if (brackets.empty())
                    return false;

                char top = brackets.top();
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{'))
                {
                    return false;
                }
                brackets.pop();
            }
        }
        return brackets.empty();
    }
};
