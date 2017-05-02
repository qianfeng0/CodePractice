#include <vector>
#include <stdio.h>


using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target)
                { 
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};

int main()
{
    std::vector<int> num = {3, 2, 4};
    int target = 6;

    Solution solution;
    std::vector<int> result = solution.twoSum(num, target);
    
    printf("[%d, %d]", result[0], result[1]);
    return 0;
}