#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define N 3
int stack[N];
int i = 0;

void push(int n) {
  if (i < N) {
    stack[i] = n;
  }
  i++;
}

int pop() {
  return stack[i--];
}

int top() {
  return stack[i];
}

void make_empty() {
  i = 0;
}

bool isEmpty() {
  return i == 0;
}