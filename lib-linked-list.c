#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lib-linked-list.h"

Node *new_node()
{
  Node *newnode = (Node *)malloc(sizeof(Node));
  newnode->data = NULL;
  newnode->next = NULL;

  return newnode;
}

Node *create_linked_list()
{
  return new_node();
}

void push_front(Node *head, Node *newnode)
{
  Node *temp = head;
  head = newnode;
  newnode->next = temp;
}

void push_back(Node *tail, Node *newnode)
{
  if (tail != NULL) {
    tail->next = newnode;
  }
}

Node* pop_front(Node *head)
{
  Node *new_head_addr = head->next;
  free(head);
  return new_head_addr;
}

void print_linked_list(Node *head)
{
  int depth = 0;
  for (Node *temp = head ; temp != NULL; temp = temp->next)
  {
    printf("  @{%d}:  %d\n",depth, temp->data);
    depth++;
  }
}
