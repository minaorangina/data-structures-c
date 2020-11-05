#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lib-binary-tree.h"

Node * new_node(int data)
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

// returns the parent node of the target value
Node* find_parent(Node *parent, Node *current, int value)
{
  if (current->data == value)
  {
    return parent;
  }
  if (current->data > value)
  {
    return find_parent(current, current->left, value);
  }
  return find_parent(current, current->right, value);
}

void delete_no_children(Node *target_parent, Node *node)
{
  Node *temp = NULL;
  if (node->data < target_parent->data)
  {
    temp = target_parent->left;
    target_parent->left = NULL;
  }
  else
  {
    temp = target_parent->right;
    target_parent->right = NULL;
  }

  free(temp);
}

void delete_one_child(Node *parent, Node *target, Node *child)
{
  // left or right
  if (target->data < parent->data)
  {
    parent->left = child;
  }
  else
  {
    parent->right = child;
  }
  free(target);
}

Node *get_target(Node *target_parent, int value)
{
  if (value < target_parent->data)
  {
    return target_parent->left;
  }
  return target_parent->right;
}

Node* find_leftmost_node(Node *node)
{
  if (node->left == NULL)
  {
    return node;
  }
  return find_leftmost_node(node->left);
}

    void delete (Node *root, int value)
{
  Node *target_parent = find_parent(NULL, root, value);

  // didn't exist in the first place
  // bug: doesn't help me detect the root node
  if (target_parent == NULL)
  {
    return;
  }

  // left or right
  Node *target = get_target(target_parent, value);

  // case 1: no children
  if (target->left == NULL && target->right == NULL)
  {
    return delete_no_children(target_parent, target);
  }

  // case 2: one child
  if (target->left != NULL && target->right == NULL) // left child
  {
    return delete_one_child(target_parent, target, target->left);
  }
  else if (target->left == NULL && target->right != NULL) // right child
  {
    return delete_one_child(target_parent, target, target->right);
  }

  // case 3
  Node *leftmost = find_leftmost_node(target->right);
  Node *temp = NULL;
  if (target->data < target_parent->data)
  {
    temp = target_parent->left;
    target_parent->left = leftmost;

    target_parent->left->left = temp->left;
    target_parent->left->right = temp->right;
  }
  else
  {
    temp = target_parent->right;
    target_parent->right = leftmost;

    target_parent->right->left = target->left;
    target_parent->right->right = target->right;
  }
  free(target);
}
