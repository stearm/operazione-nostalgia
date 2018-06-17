#include "../bool.h"

#ifndef BST_H
#define BST_H

struct node {
  int value;
  struct node *left;
  struct node *right;
};

typedef struct node Node;

Node * init(int value);
void addNode(Node * node, int value);
void removeNode(Node * node, int value);
bool findNode(Node * node, int value);

#endif