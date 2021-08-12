#ifndef BSTS
#define BSTS

#include "../trees/node.h"

class BST
{
public:
    Node *root;
    BST();
    void create(int *A, int n);
    void createFromPreorder(int *A, int n);
    void insertI(int data);
    Node *insertR(Node *root, int data);
    void inorder();
    void preorder();
    void _inorder(Node *root);
    void _preorder(Node *root);
    Node *inorderSuccessor(Node *node);
    Node *inorderPredecessor(Node *node);
    Node *deleteR(Node *root, int key);
    int height(Node *node);
    void deleteBst(Node *root);
    ~BST();
};

BST::BST()
{
    root = nullptr;
}

void BST::create(int *A, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
        insertI(A[i]);
}

void BST::insertI(int data)
{
    Node *head = root, *follow, *newnode = new Node(data);
    if (!root)
        root = newnode;
    else
    {
        while (head)
        {
            follow = head;
            if (head->data == data)
                return;
            if (data < head->data)
                head = head->left;
            else
                head = head->right;
        }
        if (data < follow->data)
            follow->left = newnode;
        else
            follow->right = newnode;
    }
}

Node *BST::insertR(Node *root, int data)
{
    Node *newnode = new Node(data);
    if (!root)
        return newnode;
    if (data < root->data)
        root->left = insertR(root->left, data);
    else
        root->right = insertR(root->right, data);
    return root;
}

void BST::inorder()
{
    Node *temp = root;
    _inorder(temp);
}

void BST::preorder()
{
    Node *temp = root;
    _preorder(temp);
}

void BST::_inorder(Node *root)
{
    if (root)
    {
        _inorder(root->left);
        cout << root->data << " ";
        _inorder(root->right);
    }
}

void BST::_preorder(Node *root)
{
    if (root)
    {
        cout << root->data << " ";
        _preorder(root->left);
        _preorder(root->right);
    }
}

Node *BST::deleteR(Node *head, int key)
{
    Node *temp;
    if (!head)
        return nullptr;
    if (!head->right && !head->left && head->data == key)
    {
        if (head == root)
            root = nullptr;
        delete head;
        return nullptr;
    }
    if (key < head->data)
        head->left = deleteR(head->left, key);
    else if (key > head->data)
        head->right = deleteR(head->right, key);
    else
    {
        if (height(head->left) > height(head->right))
        {
            temp = inorderPredecessor(head->left);
            head->data = temp->data;
            head->left = deleteR(head->left, head->data);
        }
        else
        {
            temp = inorderSuccessor(head->right);
            head->data = temp->data;
            head->right = deleteR(head->right, head->data);
        }
    }
    return head;
}

Node *BST::inorderPredecessor(Node *node)
{
    while (node && node->right)
        node = node->right;
    return node;
}

Node *BST::inorderSuccessor(Node *node)
{
    while (node && node->left)
        node = node->left;
    return node;
}

int BST::height(Node *node)
{
    int x, y;
    if (!node)
        return 0;
    x = height(node->left);
    y = height(node->right);
    return x > y ? x + 1 : y + 1;
}

void BST::createFromPreorder(int *A, int n)
{
    int i = 0;
    stack<Node *> s;
    Node *temp, *dup;
    root = new Node(A[i++]);
    dup = root;
    while (i < n)
    {
        if (A[i] < dup->data)
        {
            s.push(dup);
            temp = new Node(A[i++]);
            dup->left = temp;
            dup = temp;
        }
        else
        {
            if (A[i] > dup->data && (s.empty() || A[i] < s.top()->data))
            {
                temp = new Node(A[i++]);
                dup->right = temp;
                dup = temp;
            }
            else
            {
                dup = s.top();
                s.pop();
            }
        }
    }
}

void BST::deleteBst(Node *root)
{
    if (root)
    {
        deleteBst(root->left);
        deleteBst(root->right);
        delete root;
    }
}

BST::~BST()
{
    cout << "DESTRUCT";
    deleteBst(root);
}

#endif