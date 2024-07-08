#include "bintree.h"


///*** DO NOT CHANGE ANY FUNCTION DEFINITIONS ***///

// Recall node is defined in the header file

treenode *createNode(int node_id, int data) {
    treenode* newNode = malloc(sizeof(treenode));
    if (newNode != NULL) {
        newNode->node_id = node_id;
        newNode->data = data; 
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}


// Insert a new node into the binary tree with node_id and data
bool insertnode(treenode **rootptr, int node_id, int data) {
    treenode *root = *rootptr;
    if (root == NULL)
    {
        //tree empty
        (*rootptr) = createNode(node_id, data);
        return true;
    }
    if (node_id == root->node_id)
    {
        //do nothing
        return false;
    }
    if (node_id < root->node_id) {
        return insertnode(&(root->left), node_id, data);
    }
    if (node_id > root->node_id) {
        return insertnode(&(root->right), node_id, data);
    }
}

// Find the node with node_id, and return its data
int findnode(treenode * root, int node_id) {
    if(root == NULL) return -1;
    if(root->node_id == node_id) return root->data;
    if (node_id < root->node_id) {
        return findnode(root->left, node_id);
    }
    else {
        return findnode(root->right, node_id);
    }
    
}

///***** OPTIONAL: Challenge yourself w/ deletion if you want ***///
//Find and remove a node in the binary tree with node_id. 
//Children nodes are fixed appropriately.

treenode* find_min(treenode* node) {
    treenode* current = node;
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

treenode* remove_node(treenode* root, int node_id) {
    // Base case
    if (root == NULL) return root;

    // Recur down the tree
    if (node_id < root->node_id) {
        root->left = remove_node(root->left, node_id);
    } else if (node_id > root->node_id) {
        root->right = remove_node(root->right, node_id);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            treenode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            treenode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        treenode* temp = find_min(root->right);

        // Copy the inorder successor's content to this node
        root->node_id = temp->node_id;
        root->data = temp->data; // Also copy the data

        // Delete the inorder successor
        treenode* tempRightChild = remove_node(root->right, temp->node_id);
        root->right = tempRightChild;

        // Free the successor node if it's not being used anymore
        if (temp != tempRightChild) {
            free(temp);
        }
    }
    return root;
}



