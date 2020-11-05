#include <stdio.h>
#include <stdlib.h>

#include "lib-binary-tree.h"

Node *new_node(int data)
{
  Node *newnode = (Node *)malloc(sizeof(Node));
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;

  return newnode;
}

// in-order traversal
void print_in_order(Node *parent)
{
  if (parent->left != NULL)
  {
    print_in_order(parent->left);
  }
  printf("  %d\n", parent->data);
  if (parent->right != NULL)
  {
    print_in_order(parent->right);
  }
}

void insert(Node *parent, int data)
{
  if (parent->data == NULL)
  {
    parent->data = data;
    return;
  }
  if (parent->data > data)
  {
    if (parent->left == NULL)
    {
      parent->left = new_node(data);
      return;
    }
    insert(parent->left, data);
  }
  else if (parent->data < data)
  {
    if (parent->right == NULL)
    {
      parent->right = new_node(data);
      return;
    }
    insert(parent->right, data);
  }
}

Node* find(Node *parent, int value)
{
  if (parent->data == NULL)
  {
    // ain't nothing here
    return NULL;
  }
  if (parent->data == value)
  {
    // gotcha
    return parent;
  }
  if (parent->data > value)
  {
    if (parent->left != NULL)
    {
      return find(parent->left, value);
    }
  }
  else if (parent->data < value)
  {
    if (parent->right != NULL)
    {
      return find(parent->right, value);
    }
  }

  return NULL;
}