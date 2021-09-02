#include <vector>
#include <iostream>
#include <map>
using namespace std;

void display(vector<int> s)
{
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
    cout << "\n";
}

//dp
vector<int> dpm(int target, vector<int> nums, map<int, vector<int>> &cache)
{
    if (cache.find(target) != cache.end())
    {
        return cache[target];
    }
    if (target == 0)
    {
        return {};
    }
    if (target < 0)
    {
        return {-1};
    }
    vector<int> final = {-1};
    for (int i = 0; i < nums.size(); i++)
    {
        int rem = target - nums[i];
        vector<int> res = dpm(rem, nums, cache);
        if (res.size() == 0 || res[0] != -1)
        {
            res.push_back(nums[i]);
            if (res.size() < final.size() || final[0] == -1)
            {
                final = res;
            }
        }
    }

    cache[target] = final;
    return final;
}

vector<int> solve(int target, vector<int> nums)
{
    if (target == 0)
    {
        return {};
    }
    if (target < 0)
    {
        return {-1};
    }
    vector<int> final = {-1};
    for (int i = 0; i < nums.size(); i++)
    {
        int rem = target - nums[i];
        vector<int> res = solve(rem, nums);
        if (res.size() == 0 || res[0] != -1)
        {
            res.push_back(nums[i]);
            if (res.size() < final.size() || final[0] == -1)
            {
                final = res;
            }
        }
    }
    return final;
}

int main()
{
    vector<int> nums = {5, 10, 20};
    map<int, vector<int>> cache;
    map<int, vector<int>>::iterator it;
    vector<int> result;
    int target = 200;

    result = dpm(target, nums, cache);
    display(result);

    result = solve(target, nums);
    display(result);

    return 0;
}