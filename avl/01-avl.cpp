#include "../bst/bst.h"

class AVL : public BST
{
public:
    AVL() : BST() {}
    void create(int *A, int n);
    int balanceFactor(Node *node);
    void insert(int data);
    Node *deleteAvlNode(int data);
    void rotation();
    void LLRotation();
    void LRRotation();
    void RRRotation();
    void RLRotation();
};

void AVL::create(int *A, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
        insert(A[i]);
}

void AVL::insert(int data)
{
    insertI(data);
    rotation();
}

Node *AVL::deleteAvlNode(int data)
{
    root = deleteR(root, data);
    rotation();
    return root;
}

int AVL::balanceFactor(Node *node)
{
    return height(node->left) - height(node->right);
}

void AVL::rotation()
{
    if (balanceFactor(root) == 2 && balanceFactor(root->left) <= -1)
        LRRotation();
    else if (balanceFactor(root) == 2 && balanceFactor(root->left) >= 1)
        LLRotation();
    else if (balanceFactor(root) == -2 && balanceFactor(root->right) <= -1)
        RRRotation();
    else if (balanceFactor(root) == -2 && balanceFactor(root->right) >= 1)
        RLRotation();
}

void AVL::LLRotation()
{
    Node *newroot, *tempRight;
    newroot = root->left;
    tempRight = newroot->right;
    newroot->right = root;
    root->left = tempRight;
    root = newroot;
}

void AVL::RRRotation()
{
    Node *newroot, *tempLeft;
    newroot = root->right;
    tempLeft = newroot->left;
    newroot->left = root;
    root->right = tempLeft;
    root = newroot;
}

void AVL::RLRotation()
{
    Node *newroot, *pivot;
    pivot = root->right;
    newroot = pivot->left;
    root->right = newroot->left;
    pivot->left = newroot->right;
    newroot->left = root;
    newroot->right = pivot;
    root = newroot;
}

void AVL::LRRotation()
{
    Node *newroot, *pivot;
    pivot = root->left;
    newroot = pivot->right;
    root->left = newroot->right;
    pivot->right = newroot->left;
    newroot->left = pivot;
    newroot->right = root;
    root = newroot;
}

int main()
{
    BST *b = new BST();
    AVL *a = new AVL();
    int A[5] = {6, 3, 9, 5, 4};

    cout << "BST:\n";
    b->create(A, 5);
    b->inorder();
    cout << "\n";
    b->preorder();

    cout << "\nDeletion from BST:\n";
    b->deleteR(b->root, 9);
    b->inorder();
    cout << "\n";
    b->preorder();

    cout << "\nAVL:\n";
    a->create(A, 5);
    a->inorder();
    cout << "\n";
    a->preorder();

    cout << "\nDeletion from AVL:\n";
    a->root = a->deleteAvlNode(9);
    a->root = a->deleteAvlNode(6);
    a->inorder();
    cout << "\n";
    a->preorder();

    return 0;
}