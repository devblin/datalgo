#include "../bst/bst.h"

int main()
{
    BST *b = new BST();
    int A[5] = {3, 2, 4, 1, 5};
    b->create(A, 5);
    b->inorder();
    b->root = b->insertR(b->root, 0);
    cout << "\n";
    b->inorder();
    b->root = b->deleteR(b->root, 3);
    b->root = b->deleteR(b->root, 5);
    cout << "\n";
    b->inorder();
    cout << "\n";

    int B[8] = {30, 20, 10, 15, 25, 40, 50, 45};
    BST *c = new BST();
    c->create(B, 8);
    c->inorder();
    cout << "\n";

    BST *d = new BST();
    c->createFromPreorder(B, 8);
    c->inorder();
    return 0;
}