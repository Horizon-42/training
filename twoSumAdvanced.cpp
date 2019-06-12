#include <vector>
#include <map>
using namespace std;

class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        if (nums.empty())
            return res;

        map<int, int> flags;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (flags.find(target - nums[i]) != flags.end())
            {
                res.push_back(flags[target - nums[i]]);
                res.push_back(i);
                break;
            }
            else
            {
                flags[nums[i]] = i;
            }
        }
        return res;
    }
};