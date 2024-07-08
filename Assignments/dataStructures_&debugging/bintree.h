#ifndef BINTREE_H
#define BINTREE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

// Node structure should have an int node_id, an int data, and pointers to left and right child nodes
typedef struct treenode {
    int node_id;
    int data;
    struct treenode *right, *left;

} treenode;

///*** DO NOT CHANGE ANY FUNCTION DEFINITIONS ***///
// Declare the tree modification functions below...

// Function prototypes
treenode* createNode(int node_id, int data);
bool insertnode(treenode **rootptr, int node_id, int data);
int findnode(treenode * root, int node_id);
treenode* remove_node(treenode * root, int node_id);

#endif