#include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            // ordenar o array
            sort(nums.begin(), nums.end());

            // retorno do array
            vector<vector<int>> ret;
            int right = nums.size() - 1;

            for (int i = 0; i < int(nums.size()); i++)
            {
                int left = i + 1;
                if (i > 0 && nums[i] == nums[i-1])
                {
                    continue; // pula
                }

                while (left < right)
                {
                    int total = nums[i] + nums[left] + nums[right];
                    if (total == 0)
                    {
                        ret.push_back({nums[i], nums[left], nums[right]});

                        // evitar duplicadas
                        while (left < right && nums[left] == nums[left + 1]){
                            left++;
                        }
                        while (left < right && nums[left] == nums[right - 1]){
                            right--;
                        }
                        left++;
                        right--;
                    }
                    else if (total < 0)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
            return ret;
        }
    };

int main()
{
    Solution sol;
    vector<int> nums = {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10};
    vector<vector<int>> vec = sol.threeSum(nums);
    for (vector v : vec)
    {
        for (int i : v)
        {
            cout << i << endl;
        }
    }
    return 0;
}
