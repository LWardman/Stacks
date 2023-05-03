#include <iostream>
#include <deque>
#include <string>

bool ValidParentheses(const std::string& s)
{
    std::deque<char> Stack;

    for (char bracket : s)
    {
        if (bracket == '(' || bracket == '[' || bracket == '{')
        {
            Stack.push_back(bracket);
        }

        else if (bracket == ')')
        {
            if (Stack.empty() || Stack.back() != '(') return false;
            Stack.pop_back();
        }

        else if (bracket == ']')
        {
            if (Stack.empty() || Stack.back() != '[') return false;
            Stack.pop_back();
        }

        else if (bracket == '}')
        {
            if (Stack.empty() || Stack.back() != '{') return false;
            Stack.pop_back();
        }
    }
    return Stack.empty();
}

int main()
{
    return 0;
}
