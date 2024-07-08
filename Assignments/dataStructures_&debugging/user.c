#include "bintree.h"
#include "bintree.c"
//Implicit declaration of funcitons
void print_tree_rec(treenode* root, int level);
void print_tab(int numtabs);
void print_tree(treenode *root);

int main() {
	/*
	Insert your test code here. Try inserting nodes then searching for them.
	*/
	treenode *root = NULL;
	insertnode(&root, 15, 234);
	insertnode(&root, 5, 35445);
	insertnode(&root, 7, 543);
	insertnode(&root, 18, 45);
	insertnode(&root, 255, 0);
	insertnode(&root, 182, 47);
	insertnode(&root, 1, 35);
	print_tree(root);

	printf("%d (%d)\n", 16, findnode(root, 16));
	printf("%d (%d)\n", 5, findnode(root, 5));
	printf("%d (%d)\n", 18, findnode(root, 18));
	printf("%d (%d)\n", 162, findnode(root, 162));

	remove_node(root, 7);
	print_tree(root);
	/*
	When we grade, we will overwrite your main function with our own sequence of
	insertions and deletions to test your implementation. If you change the
	argument or return types of the binary tree functions, our grading code
	won't work!
	*/
	return 0;
}

void print_tree_rec(treenode* root, int level){
	if (root == NULL)
	{
		print_tab(level);
		printf("---<EMPTY>---\n");
		return;
	}
	print_tab(level);
	printf("value = %d\n", root->node_id);
	print_tab(level);
    printf("Left\n");
    print_tree_rec(root->left, level+1);
	print_tab(level);
    printf("Right\n");
    print_tree_rec(root->right, level+1);
	print_tab(level);
	printf("Done\n");
}

void print_tab(int numtabs){
	for (int i = 0; i < numtabs; i++)
	{
		printf("\t");
	}
}

void print_tree(treenode *root) {
	print_tree_rec(root, 0);
}


