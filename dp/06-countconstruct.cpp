#include <iostream>
#include <vector>
#include <map>
using namespace std;

int dpm(string target, vector<string> wordBank, map<string, int> &cache)
{
    if (cache.find(target) != cache.end())
    {
        return cache[target];
    }
    if (target == "")
    {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < wordBank.size(); i++)
    {
        int size = target.size();
        int wordSize = wordBank[i].size();
        if (target.size() >= wordSize)
        {
            string prefix = target.substr(0, wordSize);
            string suffix = target.substr(wordSize);
            if (prefix == wordBank[i])
            {
                int res = dpm(suffix, wordBank, cache);
                if (res > 0)
                {
                    ans += res;
                }
            }
        }
    }
    cache[target] = ans;
    return cache[target];
}

int solve(string target, vector<string> wordBank)
{
    if (target == "")
    {
        return 1;
    }
    int res = 0;
    for (int i = 0; i < wordBank.size(); i++)
    {
        int size = target.size();
        int wordSize = wordBank[i].size();
        if (target.size() >= wordSize)
        {
            string prefix = target.substr(0, wordSize);
            string suffix = target.substr(wordSize);
            if (prefix == wordBank[i])
            {
                cout << prefix << " ";
                int r = solve(suffix, wordBank);
                if (r > 0)
                {
                    res += r;
                }
            }
        }
    }
    return res;
}

int main()
{
    vector<string> wordBank = {"ee", "eee", "eeeee", "e"}, wordBank1 = {"ab", "abc", "cd", "def", "abcd", "e", "f"};
    string target = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", target1 = "abcdef";
    map<string, int> cache;
    cache[""] = 1;
    int res;
    res = dpm(target1, wordBank1, cache);
    cout << "DP: " << res << "\n";
    res = solve(target1, wordBank1);
    cout << "BRUTE: " << res;

    return 0;
}