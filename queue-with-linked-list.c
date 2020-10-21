#include <stdio.h>
#include <stdlib.h>
#include "lib-linked-list.h"

int QUIT_CMD = 9;

void empty_msg()
{
  printf("  Queue is empty.\n");
}

int value_from_stdin()
{
  printf("  Enter your value: ");

  int value;
  scanf("%d", &value);

  return value;
}

void print(Node *head)
{
  if (head == NULL)
  {
    return empty_msg();
  }

  print_linked_list(head);
}

Node* enqueue(Node *tail)
{
  Node *newnode = new_node();
  newnode->data = value_from_stdin();

  if (tail != NULL)
  {
    push_back(tail, newnode);
  }

  return newnode;
}

Node* dequeue(Node *head)
{
  if (head == NULL)
  {
    empty_msg();
    return NULL;
  }
  return pop_front(head);
}

void peek(Node *head)
{
  if (head == NULL) 
  {
    return empty_msg();
  }
  printf("  %d\n", head->data);
}

int main(void) {
  int choice;
  Node *head = NULL;
  Node *tail = NULL;

  do{
    printf("0. Print\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    switch(choice) {
      case 0:
        printf("Printing the queue...\n");
        print(head);
        break;
      
      case 1:
        printf("Adding to queue...\n");
        Node* add_result = enqueue(tail);
        
        tail = add_result;
        printf("FINAL TAIL %p\n", tail);

        if (head == NULL)
        {
          head = add_result;
        }
        break;

      case 2:
        printf("Removing from queue...\n");
        Node *remove_result = dequeue(head);

        head = remove_result;

        if (head == NULL)
        {
          tail = NULL;
        }
        break;

      case 3:
        printf("Peeking...\n");
        peek(head);
        break;
    }

  } while (choice != QUIT_CMD);
};