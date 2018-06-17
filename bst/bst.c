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

bool _isLeaf(Node * node) {
  return node != NULL && node -> left == NULL && node -> right == NULL;
}

bool _remove(Node ** node, int value) {
  if (node != NULL && (*node) -> value == value) {
    if(_isLeaf(*node)) {
      *node = NULL;
      return true;
    } else {
      if ((*node) -> left == NULL && (*node) -> right != NULL) {
        *node = (*node) -> right;
        return true;
      } else if ((*node) -> left != NULL && (*node) -> right == NULL) {
        *node = (*node) -> left;
        return true;
      } else {
        // two children
      }
    }
  }
  return false;
}

// http://profs.sci.univr.it/~macedonio/web/Teaching/ASD2013/L03-ABR.pdf
// http://www.diit.unict.it/users/carchiol/fondamenti/lezioni/LC06.pdf
void removeNode(Node * node, int value) {
  if (node == NULL) {
    return;
  }

  bool removedOnLeft = false;
  bool removedOnRight = false;

  if (node -> left != NULL) {
    removedOnLeft = _remove(&(node -> left), value);
  }

  if (node -> right != NULL) {
    removedOnRight = _remove(&(node -> right), value);
  }

  if (removedOnLeft || removedOnRight) {
    return;
  }

  removeNode(node -> left, value);
  removeNode(node -> right, value);
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
    preorder(node -> left);
    preorder(node -> right);
  }
}

int main(int argc, char const *argv[])
{
  Node * root = createNode(8);
  addNode(root, 3);
  addNode(root, 10);
  addNode(root, 12);

  removeNode(root, 12);
  removeNode(root, 3);

  preorder(root);
  printf("Node 1 exists? %d\n", findNode(root, 6));
  
  return 0;
}
