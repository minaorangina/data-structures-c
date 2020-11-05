typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} Node;

extern Node *new_node();

extern void print_in_order(Node *parent);

extern void insert(Node *parent, int data);

extern Node* find(Node *parent, int value);
