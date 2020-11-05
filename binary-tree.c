#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "lib-binary-tree.h"

int QUIT_CMD = 9;

int value_from_stdin()
{
  printf("  Enter your value: ");

  int value;
  scanf("%d", &value);

  return value;
}

bool tree_is_empty(Node *root)
{
  if (root->data == NULL)
  {
    printf("  Tree is empty\n");
    return true;
  }
  return false;
}

void print(Node *root)
{
  print_in_order(root);
}

void add_to_tree(Node *root)
{
  insert(root, value_from_stdin());
}

Node* find_value(Node *root)
{
  return find(root, value_from_stdin());
}

void delete_value(Node *root)
{
  delete(root, value_from_stdin());
}

int main(void)
{
  int choice;
  Node *root = new_node(NULL);

  do
  {
    printf("0: Print\n");
    printf("1: Insert\n");
    printf("2. Find\n");
    printf("3: Delete\n");

    printf("Enter your choice: ");

    scanf("%d", &choice);

    switch(choice) {
      case 0:
        if (!tree_is_empty(root))
        {
          printf("Printing the binary tree...\n");
          print(root);
        }
        break;

      case 1:
        printf("Inserting...\n");
        add_to_tree(root);
        break;

      case 2:
        if (!tree_is_empty(root))
        {
          printf("Finding...\n");

          Node *find_result = find_value(root);
          if (find_result == NULL)
          {
            printf("  Value doesn't exist\n");
          }
          else
          {
            printf(" Found it!\n");
          }
        }
        break;

      case 3:
        if (!tree_is_empty(root))
        {
          printf("Deleting...\n");
          delete_value(root);
        }
        break;
    }

  } while (choice != QUIT_CMD);
}
