#include "binary_tree.h"
#include <stdlib.h>

/*************************************************
 * Properites of binary tree.
 * 
 * The maximum no. of node at a lvl = 2^(l-1)
 * The maximum no. of nodes in a binary tree of height h = 2^h -1
 * Handshaking lemma: Handshaking lemma is about undirected graph. In every finite undirected graph number of vertices with odd degree is always even. 
 * The handshaking lemma is a consequence of the degree sum formula (also sometimes called the handshaking lemma).
 * 
 * ******************/
binary_tree* create_node(int data) {
    binary_tree* newtree= (binary_tree*)malloc(sizeof(binary_tree));
    newtree->data = data;
    newtree->left = NULL;
    newtree->right = NULL;
    return newtree;
}