class Solution
{
public:
    bool isValid(string s)
    {
        // Khi gặp ngoặc mở (, [, { → push vào stack.
        // Khi gặp ngoặc đóng ), ], } → kiểm tra top() có khớp không, rồi pop.

        int n = s.length();
        stack<char> brackets;
        for (const char i : s)
        {
            if (i == '{' || i == '[' || i == '(')
            {
                brackets.push(i);
            }
            if (brackets.empty())
                return false;
            if ((i == '}' && brackets.top() == '{') ||
                (i == ']' && brackets.top() == '[') ||
                (i == ')' && brackets.top() == '('))
            {
                brackets.pop();
                n -= 2;
            }
        }
        if (n != 0)
            return false;

        return brackets.empty() ? true : false;
    }
};