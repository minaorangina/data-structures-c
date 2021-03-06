#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
  int data;
  struct node *next;
};

struct node *head;

void push_front();
void pop_front();

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

void delete_first_occurrence()
{
  if (head == NULL)
  {
    printf("List is empty\n");
  }
  else
  {
    // this means list can't hold any negative numbers...
    // can be improved by doing more stringent checks
    int value = -1;
    do
    {
      printf("\n\n\tEnter value to delete: ");
      scanf("%d", &value);
    } while (value < -1);


    if (head->data == value)
    {
      pop_front();
      printf("\n\n\tDelete successful\n");
      return;
    }

    struct node *temp, *toBeFreed;
    temp = head;

    while (temp->next != NULL)
    {
      if (temp->next->data == value)
      {
        toBeFreed = temp->next;
        temp->next = temp->next->next;
        toBeFreed->next = NULL;
        free(toBeFreed);
        printf("\n\n\tDelete successful\n");
        return;
      }
      temp = temp->next;
    }
    printf("Value %d not found\n", value);
  }
}

void reverse()
{
  if (head == NULL)
  {
    printf("List is empty\n");
  }
  else if (size() == 1)
  {
    return;
  }
  else
  {
    struct node *cursor, *currentNode, *nextNode;

    cursor = head;
    currentNode = head;
    nextNode = currentNode->next;

    do
    {
      currentNode = nextNode;
      nextNode = nextNode->next;
      currentNode->next = cursor;
      cursor = currentNode;
    }
    while (nextNode->next != NULL); // do while?

    nextNode->next = currentNode;
    head->next = NULL;
    head = nextNode;
  }
}

void delete()
{
  if (head == NULL)
  {
    printf("List is empty\n");
  }
  else
  {
    int index;
    do
    {
      printf("\n\n\tEnter chosen index to delete: ");
      scanf("%d", &index);
    } while (index < 0 || index > size());

    if (index == 0)
    {
      pop_front();
    }
    else
    {
      struct node *temp, *toBeFreed;
      temp = head;

      for (int i = 0; i < index - 1; i++)
      {
        temp = temp->next;
      }
      toBeFreed = temp->next;
      temp->next = temp->next->next;
      toBeFreed->next = NULL;
      free(toBeFreed);
    }
  }
}

void insert()
{
  int index, entry;
  index = entry = -1;

  if (head == NULL)
  {
    printf("List is empty\n");
  }
  else
  {
    do
    {
      printf("\n\n\tEnter chosen index to insert at: ");
      scanf("%d", &index);
    } while (index < 0 || index > size());

    if (index == 0)
    {
      push_front();
      return;
    }

    struct node *newnode, *temp, *nextNode;

    do
    {
      printf("\n\n\tEnter data into the linked list: ");
      scanf("%d", &entry);
    } while (entry == -1);

    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = entry;

    // get node that precedes the index
    for (int i = 0; i < index-1; i++)
    {
      temp = temp->next;
    }
    nextNode = temp->next; // node currently at index
    temp->next = newnode;
    newnode->next = nextNode;
  }
}

void pop_back() {
  if (head == NULL)
  {
    printf("List is empty.");
  }
  else if (size() == 1)
  {
    printf("Cannot pop back on a list of length 1");
  }
  else
  {
    struct node *temp = head;
    struct node *toBeFreed;

    while (temp->next != NULL && temp->next->next != NULL)
    {
      temp = temp->next;
    }
    toBeFreed = temp->next->next;
    temp->next = NULL;
    free(toBeFreed);
  }
}

void push_back() {
  if (head == NULL)
  {
    printf("List is empty.");
  }
  else
  {
    struct node *newnode, *temp;

    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node)); // creates a new node

    printf("\n\n\t Enter data to push back into the linked list: ");
    scanf("%d", &newnode->data); // assign value to newnode->data
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newnode;
  }
}

void pop_front()
{
  struct node *temp;
  temp = head;
  head = head->next;
  free(temp);
}

void push_front()
{
  // create new node
  // copy head into temp
  // point new node at temp
  // point head at new node
  struct node *newnode, *temp;
  newnode = (struct node *)malloc(sizeof(struct node)); // creates a new node

  printf("\n\n\t Enter data to push onto the front of the linked list: ");
  scanf("%d", &newnode->data); // assign value to newnode->data

  // newnode->next = NULL; // no next node yet

  temp = head;
  newnode->next = temp;
  head = newnode;
}

void value_n_from_end()
{
  if (head == NULL)
  {
    printf("List is empty.");
  }
  else
  {
    int index_from_end;
    printf("\n\n\tEnter index from end:");
    scanf("%d", &index_from_end);

    int index_from_front = size() - 1 - index_from_end;

    // value_at

    if (index_from_front >= 0 && index_from_front <= size())
    {
      struct node *temp;
      temp = head;
      for (int i = 0; i < index_from_front; i++)
      {
        temp = temp->next;
      }
      printf("%d", temp->data);
    }
    else
    {
      printf("Index %d out of range", index_from_front);
    }
  }
}

void back()
{
  if (head == NULL)
  {
    printf("List is empty.");
  }
  else
  {
    struct node *temp = head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    printf("%d", temp->data);
  }
}

void front()
{
  if (head == NULL)
  {
    printf("List is empty.");
  }
  else
  {
    printf("%d", head->data);
  }
}

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

    if (index >= 0 && index <= size())
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
    printf("\n\n 7. Get first value");
    printf("\n\n 8. Get last value");
    printf("\n\n 9. Get value n from the end");
    printf("\n\n 10. Push value to front");
    printf("\n\n 11. Pop value from front");
    printf("\n\n 12. Push value to back");
    printf("\n\n 13. Pop value from back");
    printf("\n\n 14. Insert");
    printf("\n\n 15. Delete");
    printf("\n\n 16. Reverse");
    printf("\n\n 17. Delete first occurrence");
    printf("\n\n 18. Exit");
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
      front();
      break;
    case 8:
      back();
      break;
    case 9:
      value_n_from_end();
      break;
    case 10:
      push_front();
      break;
    case 11:
      pop_front();
      break;
    case 12:
      push_back();
      break;
    case 13:
      pop_back();
      break;
    case 14:
      insert();
      break;
    case 15:
      delete();
      break;
    case 16:
      reverse();
      break;
    case 17:
      delete_first_occurrence();
      break;
    case 18:
      break;
    default:
      printf("Invalid selection - try again.\n");
    }
  } while (choice != 18);

}
