#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <stack>
#include <functional>
#include <map>


/**
 * Checks a string of parentheses to determine validity.
 *
 * Validity is determined by every open bracket having a corresponding closing bracket.
 *
 * e.g '()[]' is valid, '([)]' is not.
 *
 * @param s The input string to test. Required to only contain parentheses.
 *
 * @returns True or False depending on bracket validity.
 */
bool ValidParentheses(const std::string& s)
{
    // Initialise a stack.
    std::deque<char> Stack;

    // For each character in the string...
    for (char bracket : s)
    {
        // If the character is an open bracket, add to the stack.
        if (bracket == '(' || bracket == '[' || bracket == '{')
        {
            Stack.push_back(bracket);
        }

        // If the character is a closing bracket...
        else if (bracket == ')')
        {
            // Check if the stack is empty or if the bracket before matches.
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
    // If the stack is not empty, the brackets do not match.
    return Stack.empty();
}

/**
 * Evaluates reverse polish notation.
 *
 * @param Tokens A vector of strings, each containing a string version of an integer or an operation.
 * @returns The integer value of the evaluated expression.
 */
int ReversePolishNotation(std::vector<std::string>& Tokens)
{
    // Uses lambda functions to make the for loop simpler.
    unordered_map<std::string, std::function<int (int, int) >> map = {
            {"+", [] (int a, int b) {return a + b;} },
            {"-", [] (int a, int b) {return a - b;} },
            {"*", [] (int a, int b) {return a * b;} },
            {"/", [] (int a, int b) {return a / b;} }
    };

    // Initialise a stack.
    std::stack<int> s;

    for (std::string& val : Tokens)
    {
        if (std::map.count(val)) // If val is "+", "-", "*" or "/".
        {
            // Store and remove the top element in the stack twice.
            int op1 = s.top();
            s.pop();

            int op2 = s.top();
            s.pop();

            // Calculate the value and push back onto the stack.
            s.push(std::map[val](op2, op1));
        }
        else // If val is an integer represented as a string.
        {
            // Convert the string to an integer, then push onto the stack.
            s.push(stoi(val));
        }
    }

    return s.top();
}

int main()
{
    return 0;
}
