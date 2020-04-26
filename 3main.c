#include "h.h"

#include <time.h>

int levelMin = 100000;
Node *rightRoot;

int findRoot(Node *root, int level)
{
    int a = 0;
    if (root->left && root->right)
        a = findRoot(root->right, level + 1) + findRoot(root->right, level + 1) + 1;
    if (!root->right && root->left)
        a = findRoot(root->left, level + 1) + 1;
    if (root->right && !root->left)
        a = findRoot(root->right, level + 1) + 1;
    if (!root->right && !root->left)
        a = 1;
    if(a == root->num && levelMin > level)
    {
        rightRoot = root;
        levelMin = level;
    }
    return a;
}

int main()
{
    srand(time(0));
    Node *tree = NULL;
    for (int i = 0; i < 10; i++)
        tree = add(tree, rand() % 30);
    print(tree, 0);
    printf("\n\n\n");
    findRoot(tree, 0);
    if(levelMin == 100000)
    {
        printf("Not found\n");
        return 0;
    }
    print(rightRoot, levelMin);
}