#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(string s)
    {
        std::stack<int> pilha;
        for (char c: s)
        {
            if(c == '(' || c == '{' || c == '['){
                pilha.push(c);
            }

            else if(c == ')' || c ==  '}' || c == ']'){
                if (pilha.empty())
                {
                    return false;
                }
                if (
                    (c == ')' && pilha.top() != '(') ||
                    (c == '}' && pilha.top() != '{') ||
                    (c == ']' && pilha.top() != '['))
                {
                    return false;
                }
                pilha.pop(); 
            }
        }
        return pilha.empty();
    }
};

int main()
{
    Solution sol;
    std::string s = "()";
    std::cout << sol.isValid(s) << std::endl;
    return 0;
}
