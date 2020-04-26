#ifndef H_H
#define H_h

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int num;
	struct node* left;
	struct node* right;
}Node;

void replace(Node** elem, int* a);

Node *delNode(Node *elem);

Node *del(Node *root, int a);

void in(Node *root);

Node *add(Node *root, int a);

void pre(Node *root);

void post(Node *root);

void print(Node *root, int level);

void newPrint(Node *root, int level);

void newNewPrint(Node *root, int level);

#endif