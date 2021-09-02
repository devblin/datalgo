#include <iostream>
#include <vector>
#include <map>
using namespace std;

void display(vector<vector<string>> data)
{
    if (data.size() > 0)
    {
        int row = data.size(), col, i, j;
        cout << "[";
        for (i = 0; i < row; i++)
        {
            cout << "[ ";
            for (j = 0; j < data[i].size(); j++)
            {
                cout << data[i][j] << " ";
            }
            cout << "]";
        }
        cout << "]\n";
    }
    else
    {
        cout << "[]\n";
    }
}

vector<vector<string>> dpm(string target, vector<string> wordBank, map<string, vector<vector<string>>> &cache)
{
    if (cache.find(target) != cache.end())
    {
        return cache[target];
    }
    if (target == "")
    {
        return {{}};
    }
    vector<vector<string>> res = {};
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
                vector<vector<string>> r = dpm(suffix, wordBank, cache);
                if (r.size() > 0)
                {
                    r[0].push_back(prefix);
                    res.push_back(r[0]);
                }
            }
        }
    }
    cache[target] = res;
    return res;
}

vector<vector<string>> solve(string target, vector<string> wordBank)
{
    if (target == "")
    {
        return {{}};
    }
    vector<vector<string>> res = {};
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
                vector<vector<string>> r = solve(suffix, wordBank);
                if (r.size() > 0)
                {
                    r[0].push_back(prefix);
                    res.push_back(r[0]);
                }
            }
        }
    }
    return res;
}

int main()
{
    vector<string> wordBank = {"ee", "eee", "eeeee", "e", "f"}, wordBank1 = {"ab", "abc", "cd", "def", "abcd", "ef"};
    string target = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", target1 = "abcdef";
    map<string, vector<vector<string>>> cache;
    cache[""] = {{}};
    vector<vector<string>> res;
    res = dpm(target, wordBank, cache);
    cout << "DP: ";
    display(res);
    res = solve(target, wordBank);
    cout << "BRUTE: ";
    display(res);

    return 0;
}