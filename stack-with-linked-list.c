#include<stdio.h>
#include<stdlib.h>
#include "lib-linked-list.h"

int QUIT_CMD = 9;

void empty_msg()
{
  printf("  Stack is empty.\n");
}

int value_from_stdin()
{
  printf("  Enter your value: ");

  int value;
  scanf("%d", &value);

  return value;
}

Node* init_stack()
{
  return create_linked_list();
}

Node* add_to_stack(Node *head)
{
  Node *newnode = new_node();
  newnode->data = value_from_stdin();

  push_front(head, newnode);

  return newnode;
}

Node* pop_from_stack(Node *head)
{
  if (head == NULL)
  {
    empty_msg();
    return NULL;
  }

  return pop_front(head);
}

void print(Node *head)
{
  if (head == NULL)
  {
    return empty_msg();
  }

  print_linked_list(head);
}

int main(void) {
  int choice;
  Node *stack = NULL;

  do
  {
    printf("0. Print\n");
    printf("1. Add to stack\n");
    printf("2. Pop from stack\n");
    printf("9. Quit\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    switch(choice) {
      case 0:
        printf("Printing the stack...\n");
        print(stack);
        break;

      case 1:
        printf("Adding to stack...\n");
        Node *add_result = add_to_stack(stack);

        if (add_result != NULL) {
          stack = add_result;
        }
        break;

      case 2:
        printf("Popping from stack...\n");
        stack = pop_from_stack(stack);
        break;
    }
  }
  while (choice != QUIT_CMD);
};

