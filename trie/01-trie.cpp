#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    bool end = false;
    map<char, Node *> keys;
    void setEnd()
    {
        this->end = true;
    }
    bool isEnd()
    {
        return this->end;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        this->root = new Node();
    }
    void add(string s, Node *node = nullptr)
    {
        if (!node)
        {
            node = this->root;
        }
        if (s.size() == 0)
        {
            node->setEnd();
            return;
        }
        else if (node->keys.find(s[0]) == node->keys.end())
        {
            node->keys[s[0]] = new Node();
            add(s.substr(1), node->keys[s[0]]);
            return;
        }
        else
        {
            add(s.substr(1), node->keys[s[0]]);
            return;
        }
        return;
    }
    bool isWord(string s)
    {
        Node *node = this->root;
        while (s.size() > 1)
        {
            if (node->keys.find(s[0]) == node->keys.end())
            {
                return false;
            }
            else
            {
                node = node->keys[s[0]];
                s = s.substr(1);
            }
        }
        return ((node->keys.find(s[0]) != node->keys.end()) && node->keys[s[0]]->isEnd());
    }
};

int main()
{
    Trie *t = new Trie();
    t->add("ball");
    t->add("bat");
    t->add("doll");
    t->add("dork");
    t->add("do");
    t->add("dorm");
    t->add("send");
    cout << t->isWord("doll") << "\n";
    cout << t->isWord("dor") << "\n";
    cout << t->isWord("dorf") << "\n";
    return 0;
}