#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
  int data;
  struct node *next;
};

struct node *head;

void value_at()
{
  if (head == NULL) 
  {
    printf("List is empty.");
  } 
  else
  {
    int index;
    printf("\n\n\t Enter index: ");
    scanf("%d", &index);

    if (index <= size())
    {
      struct node *temp;
      temp = head;
      for (int i = 0; i < index; i++)
      {
        temp = temp->next;
      }
      printf("%d", temp->data);
    }
    else
    {
      printf("Index %d out of range", index);
    }
  }
  
}

void is_empty()
{
  bool empty;

  empty = (head == NULL);
  printf("%d", empty);
}

int size()
{
  if (head == NULL)
  {
    return 0;
  }
  else
  {
    int count = 0;

    struct node *temp;
    temp = head;

    for (temp = head; temp != NULL; temp = temp->next)
    {
      count++;
    }
    // printf("Size of linked list: %d\n", count);
    return count;
  }
  
}

void display_address()
{
  printf("%p\n", (void *)head);
}

void display()
{
  struct node *temp;
  temp = head;

  if (head != NULL)
  {
    // traverse the nodes
    for (temp = head; temp != NULL; temp = temp->next)
    {
      printf("%d @%p\t", temp->data, (void *)temp);
    }
  }
  else
  {
    printf("\n\n\t List is empty");
  } 
}

int create_linked_list()
{
  struct node *newnode, *temp;
  newnode = (struct node*)malloc(sizeof(struct node)); // creates a new node

  printf("\n\n\t Enter data into the linked list: ");
  scanf("%d", &newnode->data); // assign value to newnode->data

  newnode->next = NULL; // no next node yet

  if (head == NULL)
  {
    head = newnode;
    return 1;
  }
  else
  {
    temp = head;
    while (temp->next != NULL) // traverse the nodes
    {
      temp = temp->next;
    }
    // found a `next` that is null. we're at the end
    temp->next = newnode;
  }
}

int main()
{
  int choice;
  head = NULL;

  do
  {
    printf("\n\n 1. Create linked list node");
    printf("\n\n 2. Display linked list");
    printf("\n\n 3. Display address of linked list");
    printf("\n\n 4. Display size of linked list");
    printf("\n\n 5. Is linked list empty?");
    printf("\n\n 6. Get value at index");
    printf("\n\n 7. Exit");
    printf("\n\n Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      create_linked_list();
      break;
    case 2:
      display();
      break;
    case 3:
      display_address();
      break;
    case 4:
      printf("Size of linked list: %d\n", size());
      break;
    case 5:
      is_empty();
      break;
    case 6:
      value_at();
      break;
    case 7:
      break;
    default:
      printf("Invalid selection - try again.\n");
    }
  } while (choice != 7);
  
}