#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

Node * createNode(int value) {
  Node * node = malloc(sizeof (Node));
  node -> left = NULL;
  node -> right = NULL;
  node -> value = value;
  return node;
}

void addNode(Node * node, int value) {
  int nodeValue = node -> value;

  if (value > nodeValue) {
    if (node -> right == NULL) {
      Node * newNode = createNode(value);
      node -> right = newNode;
    } else {
      addNode(node -> right, value);
    }
  } else {
    if (node -> left == NULL) {
      Node * newNode = createNode(value);
      node -> left = newNode;
    } else {
      addNode(node -> left ,value);
    }
  }
}

void removeNode(Node * node, int value) {
  if (node == NULL) {
    return;
  }

  if (node -> value == value)
}

bool findNode(Node * node, int value) {
  if (node == NULL) {
    return false;
  }

  if (node -> value == value) {
    return true;
  } else {
    return findNode(node -> left, value) || findNode(node -> right, value);
  }
}

void preorder(Node * node) {
  if (node != NULL) {
    printf("%d\n", node -> value);
    printTree(node -> left);
    printTree(node -> right);
  }
}


int main(int argc, char const *argv[])
{
  Node * root = createNode(8);
  addNode(root, 3);
  addNode(root, 10);
  addNode(root, 1);
  addNode(root, 6);
  addNode(root, 14);
  addNode(root, 4);
  addNode(root, 7);
  addNode(root, 13);

  printTree(root);
  printf("Node 1 exists? %d\n", findNode(root, 6));
  printf("Node 7 exists? %d\n", findNode(root, 7));
  printf("Node 25 exists? %d\n", findNode(root, 25));

  return 0;
}
