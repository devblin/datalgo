#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*
Number of ways to travel a NxN grid from top-left corner to bottom-right corner
*/

// recursive
int solve(int row, int col)
{
    if (row == 1 && col == 1)
    {
        return 1;
    }
    if (row == 0 || col == 0)
    {
        return 0;
    }
    return solve(row - 1, col) + solve(row, col - 1);
}

int dpm(int row, int col, map<vector<int>, int> &cache)
{
    if (cache.find({row, col}) != cache.end())
    {
        return cache[{row, col}];
    }
    if (cache.find({col, row}) != cache.end())
    {
        return cache[{col, row}];
    }
    if (row == 1 && col == 1)
    {
        return 1;
    }
    if (row == 0 || col == 0)
    {
        return 0;
    }
    cache[{row, col}] = dpm(row - 1, col, cache) + dpm(row, col - 1, cache);
    return cache[{row, col}];
}

int main()
{
    map<vector<int>, int> cache;
    cout << solve(5, 5) << "\n";
    cout << dpm(5, 5, cache);
    return 0;
}