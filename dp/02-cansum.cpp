#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
For given array set of numbers with infinite amount, find if its
possible to generate target sum

Ex:- 
nums = {5, 3, 4, 7}
target = 7

OUTPUT: true
*/

//dp memoization
bool dpm(int target, vector<int> nums, map<int, bool> &cache)
{
    if (cache.find(target) != cache.end())
    {
        return cache[target];
    }
    if (target == 0)
    {
        return true;
    }
    if (target < 0)
    {
        return false;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        int rem = target - nums[i];
        bool res = dpm(rem, nums, cache);
        if (res)
        {
            cache[rem] = true;
            return true;
        }
    }
    cache[target] = false;
    return false;
}

//recursive
bool solve(int target, vector<int> nums)
{
    if (target == 0)
    {
        return true;
    }
    if (target < 0)
    {
        return false;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        bool res = solve(target - nums[i], nums);
        if (res)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int target = 8;
    vector<int> nums = {5, 3, 4, 7};
    map<int, bool> cache;
    cache[0] = true;
    cout << solve(target, nums) << "\n";
    cout << dpm(target, nums, cache);

    return 0;
}