#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} Node;

Node * initList() {
  Node * list = NULL;
  return list;
}

Node * enqueue(Node * list, int value) {
  Node * head = list;
  
  Node * node = malloc(sizeof (Node));
  node -> value = value;
  node -> next = NULL;

  if (list == NULL) {
    list = node;
    return list;
  }

  Node * tail = list;

  while (tail -> next != NULL) {
    tail = tail -> next;
  }

  tail -> next = node;

  return list;
}

int size(Node * list) {
  if (list == NULL) {
    return 0;
  }
  
  int size = 1;
  Node * temp = list;

  do {
    size++;
    temp = temp -> next;
  } while (temp -> next != NULL);

  return size;
}

int get(Node * list, int index) {
  Node * node = list;
  int value;

  if (index < 0 || size(list) - 1 < index) {
    return -1;
  }

  for (int i = 0; i < index; i++) {
    node = node -> next;
  }

  return node -> value;
}

Node * rem(Node * list, int index) {
  int listSize = size(list);

  if (index < 0 || listSize - 1 < index) {
    return list;
  }

  Node * nodeToRemove;
  if (index == 0) {
    nodeToRemove = list;
    list = list -> next;
  } else {
    Node * temp = list;

    for (int i = 0; i < index - 1; i++) {
      temp = temp -> next;
    }

    nodeToRemove = temp -> next;
    if (index == listSize - 1) {
      temp -> next = NULL;
    } else {
      temp -> next = temp -> next -> next;
    }
  }

  free(nodeToRemove);

  return list;
}

void printList(Node * list) {
  printf("%d ", list -> value);
  if (list -> next == NULL) {
    printf("\n");
    return;
  }
  printList(list -> next);
}

int main(int argc, char const *argv[])
{
  Node * list = initList();

  list = enqueue(list, 1);
  list = enqueue(list, 2);
  list = enqueue(list, 3);
  list = enqueue(list, 4);
  list = enqueue(list, 5);

  printf("Printing list... \n");
  printList(list);

  printf("Size: %d\n", size(list));

  printf("Getting element 0: %d\n", get(list, 0));

  list = rem(list, 0);
  printf("Printing list... \n");
  printList(list);

  list = rem(list, 1);
  printf("Printing list... \n");
  printList(list);

  return 0;
}
