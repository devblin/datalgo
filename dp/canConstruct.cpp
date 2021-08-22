#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool dpm(string target, vector<string> wordBank, map<string, bool> &cache)
{
    if (cache.find(target) != cache.end())
    {
        return cache[target];
    }
    if (target == "")
    {
        return true;
    }
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
                bool res = dpm(suffix, wordBank, cache);
                if (res)
                {
                    cache[suffix] = true;
                    return cache[suffix];
                }
            }
        }
    }
    cache[target] = false;
    return cache[target];
}

bool solve(string target, vector<string> wordBank)
{
    if (target == "")
    {
        return true;
    }
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
                bool res = solve(suffix, wordBank);
                if (res)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    vector<string> wordBank = {"ee", "eee", "eeeee", "e"}, wordBank1 = {"ab", "abc", "cd", "def", "abcd", "e", "f"};
    string target = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", target1 = "abcdef";
    map<string, bool> cache;
    cache[""] = true;
    bool res;
    res = dpm(target1, wordBank1, cache);
    cout << "DP: " << res << "\n";
    res = solve(target1, wordBank1);
    cout << "BRUTE: " << res;

    return 0;
}