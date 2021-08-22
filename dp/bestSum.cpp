#include <vector>
#include <iostream>
#include <map>
using namespace std;

void display(vector<int> *s)
{
    for (int i = 0; i < (*s).size(); i++)
    {
        cout << (*s)[i] << " ";
    }
    cout << "\n";
}

//dp
vector<int> *dpm(int target, vector<int> nums, map<int, vector<int> *> &cache)
{
    if (cache.find(target) != cache.end())
    {
        return cache[target];
    }
    if (target == 0)
    {
        return new vector<int>();
    }
    if (target < 0)
    {
        return nullptr;
    }
    vector<int> *final = nullptr;
    for (int i = 0; i < nums.size(); i++)
    {
        int rem = target - nums[i];
        vector<int> *res = dpm(rem, nums, cache);
        if (res)
        {
            res->push_back(nums[i]);
            if (!final || res->size() < final->size())
            {
                final = res;
            }
        }
    }
    cache[target] = new vector<int>(*final);
    return final;
}

vector<int> *solve(int target, vector<int> nums)
{
    if (target == 0)
    {
        return new vector<int>;
    }
    if (target < 0)
    {
        return nullptr;
    }
    vector<int> *final = nullptr;
    for (int i = 0; i < nums.size(); i++)
    {
        int rem = target - nums[i];
        vector<int> *res = solve(rem, nums);
        if (res)
        {
            res->push_back(nums[i]);
            if (!final || res->size() < final->size())
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
    map<int, vector<int> *> cache;
    map<int, vector<int> *>::iterator it;
    vector<int> *result;
    int target = 40;

    result = solve(target, nums);
    if (result)
        display(result);

    result = dpm(target, nums, cache);
    if (result)
        display(result);

    cout << "\n";
    for (it = cache.begin(); it != cache.end(); it++)
    {
        cout << it->first << ":";
        display(it->second);
    }

    return 0;
}