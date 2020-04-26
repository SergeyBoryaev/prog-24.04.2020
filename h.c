#include "h.h"

Node *add(Node *root, int a)
{
    if (!root)
    {
        Node *pnew = (Node *)malloc(sizeof(Node));
        pnew->num = a;
        pnew->left = NULL;
        pnew->right = NULL;
        root = pnew;
    }
    else if (root->num < a)
        root->right = add(root->right, a);
    else
        root->left = add(root->left, a);
    return root;
}

void in(Node *root)
{
    if (root)
    {
        in(root->left);
        printf("%d ", root->num);
        in(root->right);
    }
}

void pre(Node *root)
{
    if (root)
    {
        printf("%d ", root->num);
        pre(root->left);
        pre(root->right);
    }
}

void post(Node *root)
{
    if (root)
    {
        post(root->left);
        post(root->right);
        printf("%d ", root->num);
    }
}

void print(Node *root, int level)
{
    if (root)
        print(root->right, level + 1);
    for (int i = 0; i < level; i++)
        printf("   ");
    if (root)
        printf("%d   %d\n", root->num, level);
    else
        printf("#\n");
    if (root)
        print(root->left, level + 1);
}

Node *del(Node *root, int a)
{
    if (!root)
    {
        printf("No such element!\n");
        return NULL;
    }
    else if (root->num == a)
    {
        root = delNode(root);
        return root;
    }
    else if (root->num < a)
    {
        root->right = del(root->right, a);
        return root;
    }
    else
    {
        root->left = del(root->left, a);
        return root;
    }
}

Node *delNode(Node *elem)
{
    if (!elem->left && !elem->right)
    {
        free(elem);
        return NULL;
    }
    else if ((elem->left && !elem->right) || (!elem->left && elem->right))
    {
        Node *p = elem;
        if (elem->left)
        {
            elem = elem->left;
            p->left = NULL;
        }
        else
        {
            elem = elem->right;
            p->right = NULL;
        }
        free(p);
        return elem;
    }
    else
    {
        int a;
        replace(&(elem->right), &a);
        elem->num = a;
        return elem;
    }
}

void replace(Node **elem, int *a)
{
    if ((*elem)->left)
        replace(&((*elem)->left), a);
    else
    {
        *a = (*elem)->num;
        Node *p = *elem;
        *elem = (*elem)->right;
        p->right = NULL;
        free(p);
    }
}

void newPrint(Node *root, int level)
{
    if (root->right && root->left)
        newPrint(root->right, level + 1);
    for (int i = 0; i < level; i++)
        printf("   ");
    if (root)
        printf("%d   %d\n", root->num, level);
    else
        printf("#\n");
    if (root->right && root->left)
        newPrint(root->left, level + 1);
}

void newNewPrint(Node *root, int level)
{
    if (root->right && !root->left)
        newNewPrint(root->right, level + 1);
    for (int i = 0; i < level; i++)
        printf("   ");
    if (root)
        printf("%d   %d\n", root->num, level);
    else
        printf("#\n");
    if (!root->right && root->left)
        newNewPrint(root->left, level + 1);
}