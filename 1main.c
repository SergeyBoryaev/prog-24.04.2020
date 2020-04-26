#include "h.h"

#include <time.h>

int max = 0;
Node *maxRoot;

int findMaxFullTree(Node *tree)
{
    if (tree->left && tree->right)
    {
        int a = findMaxFullTree(tree->left);
        int b = findMaxFullTree(tree->right);
        return a + b + 1;
    }
    if (tree->left && !tree->right)
    {
        int a = findMaxFullTree(tree->left);
        if (a > max)
        {
            max = a;
            maxRoot = tree->left;
        }
        return -10000;
    }
    if (!tree->left && tree->right)
    {
        int a = findMaxFullTree(tree->right);
        if (a > max)
        {
            max = a;
            maxRoot = tree->right;
        }
        return -10000;
    }
    if (!tree->left && !tree->right)
        return 1;
    return 0;
}

int main()
{
    srand(time(0));
    Node *tree = NULL;
    for (int i = 0; i < 10; i++)
        tree = add(tree, rand() % 30);
    print(tree, 0);
    printf("\n\n\n");
    int a = findMaxFullTree(tree);
    if (a > max)
    {
        newPrint(tree, 0);
        return 0;
    }
    else
    {
        newPrint(maxRoot, 0);
        return 0;
    }
}
