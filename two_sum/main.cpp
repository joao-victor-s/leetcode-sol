#include <iostream>
#include <vector>
#include <unordered_map>

/*
    nums = [2, 7, 11, 15]
    target = 9

    complement = 9 - 2 = 7
    for -> percorre o vetor nums O(n)
        if (map.count(7)) -> verifica se 7 nao eh a chave de um hash O(1)
            adiciona o indice de nums ao vetor de resposta
            adiciona o indice do complement
        adiciona a hash table (chave: elemento nums, valor: indice nums)
    retorna vetor
*/

class Solution{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::vector<int> resp;
        std::unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++)
        {
            int complement =  target - nums[i];
            if (map.count(complement))
            {
                resp.push_back(i);
                resp.push_back(map[complement]);
            }
            map[nums[i]] = i;
        }
        return resp;
    }
};


int main()
{
    Solution sol;
    std::vector<int> nums = {2, 7, 11, 15};
    sol.twoSum(nums, 7);
    return 0;
}
