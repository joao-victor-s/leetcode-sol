#include <iostream>

class Solution {
    public:
    /*
        x = 123

        digit = 123 % 10 = 3
        rev = 0 * 10 + 3 = 3
        x = x / 10 = 12

        digit = 12 % 10 = 2
        rev = 3 * 10 + 2 = 32
        x = 12 / 10 = 1

        digit = 1 % 10 = 1
        rev = 32 * 10 + 1 = 321
        x = x / 10 = 0
    */
        bool isPalindrome(int x) {
            if (x < 0 || (x % 10 == 0 && x != 0)) return false;
            int ori = x;
            u_int64_t rev = 0; // estouro de 32 bits -> int
            while(x > 0)
            {
                int digit = x % 10; // pega o ultimo elemento
                rev = rev * 10 + digit; //
                x = x / 10; // remove o ultimo elemento
            }
            return ori == rev;
        }
    };

int main()
{
    int x = -121;
    int y = 1001;
    Solution sol;
    std::cout << sol.isPalindrome(x) << std::endl; // correct = 0
    std::cout << sol.isPalindrome(y) << std::endl; // correct = 1
}
