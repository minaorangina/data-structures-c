typedef struct node
{
  int data;
  struct node *next;
} Node;

extern void push_front(Node *head, Node *newnode);

extern void push_back(Node *tail, Node *newnode);

extern Node* pop_front(Node *head);

extern Node* create_linked_list();

extern void print_linked_list();

extern Node* new_node();
