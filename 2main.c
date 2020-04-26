#include "h.h"

#include <time.h>

int max = 0;
Node *maxRoot;

int findMaxNotFullTree(Node *tree)
{
    if (tree->left && tree->right)
    {
        int a = findMaxNotFullTree(tree->left);
        int b = findMaxNotFullTree(tree->right);
        if (a > b && a > max)
        {
            maxRoot = tree->left;
            max = a;
        }
        else if(a < b && b > max)
        {
            maxRoot = tree->right;
            max = b;
        }
        return -10000;
    }
    if (tree->left && !tree->right)
    {
        int a = findMaxNotFullTree(tree->left);
        return a + 1;
    }
    if (!tree->left && tree->right)
    {
        int a = findMaxNotFullTree(tree->right);
        return a + 1;
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
    int a = findMaxNotFullTree(tree);
    if (a > max)
    {
        newNewPrint(tree, 0);
        return 0;
    }
    else
    {
        newNewPrint(maxRoot, 0);
        return 0;
    }
}
