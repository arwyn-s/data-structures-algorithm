
typedef struct _binary_tree binary_tree;
struct _binary_tree
{
    int data;
    /* data */
    binary_tree* left;
    binary_tree* right;
} ;

binary_tree* create_node (int data);
