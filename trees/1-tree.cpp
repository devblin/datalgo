#include "tree.h"

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

    delete t;

    return 0;
}