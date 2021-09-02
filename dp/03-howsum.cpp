#include <vector>
#include <iostream>
#include <map>
#include <chrono>
using namespace std;
using namespace std::chrono;

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
        return new vector<int>;
    }
    if (target < 0)
    {
        return nullptr;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        int rem = target - nums[i];
        vector<int> *res = dpm(rem, nums, cache);
        if (res)
        {
            res->push_back(nums[i]);
            cache[target] = res;
            return cache[target];
        }
    }
    cache[target] = nullptr;
    return nullptr;
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
    for (int i = 0; i < nums.size(); i++)
    {
        int rem = target - nums[i];
        vector<int> *res = solve(rem, nums);
        if (res)
        {
            res->push_back(nums[i]);
            return res;
        }
    }
    return nullptr;
}

int main()
{
    vector<int> nums = {2, 6, 4};
    map<int, vector<int> *> cache;
    vector<int> *result;
    int target = 8;

    auto start = high_resolution_clock::now();
    result = solve(target, nums);
    if (result)
        display(result);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Normal:" << duration.count() << "\n";

    start = high_resolution_clock::now();
    result = dpm(target, nums, cache);
    if (result)
        display(result);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "DP:" << duration.count() << "\n";

    return 0;
}