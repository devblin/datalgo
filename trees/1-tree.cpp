#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class Tree
{
public:
    Node *root;
    Tree();
    void create(int *A, int n);
    void preorderR(Node *root);
    void preorderI(Node *root);
    void preorder();
    void inorderR(Node *root);
    void inorderI(Node *root);
    void inorder();
    void postorderR(Node *root);
    void postorderI(Node *root);
    void postorder();
    void levelorder();
    void levelorderI(Node *root);
    int heightOfTree();
    int _heightOfTree(Node *root);
    int numOfNodes();
    int _numOfNodes(Node *root);
    int leafNodes();
    int _leafNodes(Node *root);
    ~Tree();
};

Tree::Tree()
{
    root = nullptr;
}

void Tree::create(int *A, int n)
{
    Node *temp, *newnode;
    deque<Node *> Q;
    int i = 0;
    root = new Node(A[i++]);
    Q.push_back(root);
    while (i < n && !Q.empty())
    {
        temp = Q.front();
        Q.pop_front();
        if (A[i] > 0 && i % 2 != 0)
        {
            newnode = new Node(A[i]);
            Q.push_back(newnode);
            temp->left = newnode;
        }
        i++;
        if (A[i] > 0 && i % 2 == 0)
        {
            newnode = new Node(A[i]);
            Q.push_back(newnode);
            temp->right = newnode;
        }
        i++;
    }
}

void Tree::preorder()
{
    Node *temp = root;
    cout << "Preorder:\n";
    preorderI(temp);
    preorderR(temp);
    cout << "\n";
}

void Tree::preorderR(Node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preorderR(root->left);
        preorderR(root->right);
    }
}

void Tree::preorderI(Node *root)
{
    if (root)
    {
        stack<Node *> s;
        while (!s.empty() || root)
        {
            if (root)
            {
                cout << root->data << " ";
                s.push(root);
                root = root->left;
            }
            else
            {
                root = s.top();
                s.pop();
                root = root->right;
            }
        }
    }
    cout << "\n";
}

void Tree::inorder()
{
    Node *temp = root;
    cout << "Inorder:\n";
    inorderI(temp);
    inorderR(temp);
    cout << "\n";
}

void Tree::inorderR(Node *root)
{
    if (root)
    {
        inorderR(root->left);
        cout << root->data << " ";
        inorderR(root->right);
    }
}

void Tree::inorderI(Node *root)
{
    if (root)
    {
        stack<Node *> s;
        while (root || !s.empty())
        {
            if (root)
            {
                s.push(root);
                root = root->left;
            }
            else
            {
                root = s.top();
                s.pop();
                cout << root->data << " ";
                root = root->right;
            }
        }
    }
    cout << "\n";
}

void Tree::postorder()
{
    Node *temp = root;
    cout << "Postorder:\n";
    postorderI(temp);
    postorderR(temp);
    cout << "\n";
}

void Tree::postorderR(Node *root)
{
    if (root)
    {
        postorderR(root->left);
        postorderR(root->right);
        cout << root->data << " ";
    }
}

void Tree::postorderI(Node *root)
{
    if (root)
    {
        stack<long int> s;
        long int temp;
        while (!s.empty() || root)
        {
            if (root)
            {
                s.push((long int)root);
                root = root->left;
            }
            else
            {
                temp = s.top();
                s.pop();
                if (temp > 0)
                {
                    s.push(-temp);
                    root = ((Node *)temp)->right;
                }
                else
                {
                    cout << ((Node *)(-1 * temp))->data << " ";
                    root = nullptr;
                }
            }
        }
    }
    cout << "\n";
}

void Tree::levelorder()
{
    cout << "Levelorder:\n";
    Node *temp = root;
    levelorderI(temp);
}

void Tree::levelorderI(Node *root)
{
    if (root)
    {
        deque<Node *> q;
        q.push_back(root);
        while (!q.empty())
        {
            root = q.front();
            q.pop_front();
            cout << root->data << " ";

            if (root->left)
                q.push_back(root->left);
            if (root->right)
                q.push_back(root->right);
        }
    }
    cout << "\n";
}

int Tree::heightOfTree()
{
    Node *temp = root;
    return _heightOfTree(temp);
}

int Tree::_heightOfTree(Node *root)
{
    int l, r;
    if (root)
    {
        l = _heightOfTree(root->left);
        r = _heightOfTree(root->right);
        if (l > r)
            return l + 1;
        else
            return r + 1;
    }
    return -1;
}

int Tree::numOfNodes()
{
    Node *temp = root;
    return _numOfNodes(temp);
}

int Tree::_numOfNodes(Node *root)
{
    int l, r;
    if (root)
    {
        l = _numOfNodes(root->left);
        r = _numOfNodes(root->right);
        return l + r + 1;
    }
    return 0;
}

int Tree::leafNodes()
{
    Node *temp = root;
    return _leafNodes(temp);
}

int Tree::_leafNodes(Node *root)
{
    int l, r;
    if (root)
    {
        l = _leafNodes(root->left);
        r = _leafNodes(root->right);
        if (!root->right && !root->left)
            return l + r + 1;
        else
            return l + r;
    }
    return 0;
}

Tree::~Tree()
{
    delete[] root;
}

int getInorderIndex(vector<int> a, int key)
{
    int i = 0, n = a.size();
    for (i = 0; i < n; i++)
        if (a[i] == key)
            return i;
    return -1;
}

//generate tree from preorder and inorder
Node *generateTree1(vector<int> preorder, vector<int> inorder, int start, int end)
{
    static int i = 0;
    if (start > end)
        return nullptr;

    Node *newnode = new Node(preorder[i++]);
    if (start == end)
        return newnode;

    int index = getInorderIndex(inorder, newnode->data);

    newnode->left = generateTree1(preorder, inorder, start, index - 1);
    newnode->right = generateTree1(preorder, inorder, index + 1, end);

    return newnode;
}

//generate tree from postorder and inorder
Node *generateTree2(vector<int> postorder, vector<int> inorder, int start, int end)
{
    static int i = 0;
    if (start > end)
        return nullptr;

    Node *newnode = new Node(postorder[i++]);
    if (start == end)
        return newnode;

    int index = getInorderIndex(inorder, newnode->data);

    newnode->right = generateTree2(postorder, inorder, index + 1, end);
    newnode->left = generateTree2(postorder, inorder, start, index - 1);

    return newnode;
}

int main()
{
    int A[7] = {1, 2, 3, 4, -1, -1, 6};
    Tree *t = new Tree();

    t->create(A, 7);
    t->preorder();
    t->inorder();
    t->postorder();
    t->levelorder();

    vector<int> preorder = {1, 2, 4, 5, 3};
    vector<int> postorder = {4, 5, 2, 3, 1};
    vector<int> inorder = {4, 2, 5, 1, 3};
    t->root = generateTree1(preorder, inorder, 0, 4);
    t->preorder();
    t->inorder();
    t->postorder();
    t->levelorder();

    reverse(postorder.begin(), postorder.end());
    t->root = generateTree2(postorder, inorder, 0, 4);
    t->preorder();
    t->inorder();
    t->postorder();
    t->levelorder();

    cout << "Num of nodes: " << t->numOfNodes() << "\n";
    cout << "Num of leaf nodes: " << t->leafNodes() << "\n";
    cout << "Tree height: " << t->heightOfTree() << "\n";

    return 0;
}