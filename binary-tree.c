#include<stdio.h>
#include<stdlib.h>
#include "lib-binary-tree.h"

int QUIT_CMD = 9;

int value_from_stdin()
{
  printf("  Enter your value: ");

  int value;
  scanf("%d", &value);

  return value;
}

void print(Node *root)
{
  if (root->data == NULL)
  {
    printf("  Tree is empty\n");
  }
  else
  {
    print_in_order(root);
  }
}

void add_to_tree(Node *root)
{
  int value = value_from_stdin();
  insert(root, value);
}

Node* find_value(Node *root)
{
  if (root->data == NULL)
  {
    printf("  Tree is empty\n");
  }
  else
  {
    int value = value_from_stdin();
    return find(root, value);
  }
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

    printf("Enter your choice: ");

    scanf("%d", &choice);

    switch(choice) {
      case 0:
        printf("Printing the binary tree...\n");
        print(root);
        break;

      case 1:
        printf("Inserting...\n");
        add_to_tree(root);
        break;

      case 2:
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
        break;
    }

  } while (choice != QUIT_CMD);
}
