#ifndef TREE
#define TREE

#include "node.h"

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
    void deleteTree(Node *root);
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

void Tree::deleteTree(Node *root)
{
    if (root)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

Tree::~Tree()
{
    deleteTree(root);
}

#endif