#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct node_t {
	struct node_t** children;
	char* key;
	unsigned int num_children;
};

int write_tree_to_file(struct node_t* tree, FILE* output)
{
	//int num_children = sizeof(*(tree->children)) / sizeof(struct node_t);
	for (int i = 0; i < tree->num_children; i++)
	{	
		if(fprintf(output,"%s ", tree->children[i]->key) < 0)
			return 0;
		if(write_tree_to_file(tree->children[i], output) == 0)
			return 0;
	}
	if(fprintf(output, ". ") < 0)
		return 0;
	return 1;
}

int main(int argc, char** argv)
{
	struct node_t tree, t, a, te, to;
	tree.key = "", t.key = "t", a.key = "a", te.key = "te", to.key = "to";
	t.children = malloc(2 * sizeof(struct node_t));
	tree.children = malloc(2 * sizeof(struct node_t));
	tree.children[0] = &t, tree.children[1] = &a;
	t.children[0] = &te, t.children[1] = &to;
	te.children = NULL, to.children = NULL, a.children = NULL;
	tree.num_children = 2, a.num_children = 0, t.num_children = 2, te.num_children = 0, to.num_children = 0;

	FILE* output = fopen("tree.txt", "w");
	if (output == NULL)
		return -1;

	if(write_tree_to_file(&tree, output) == 0)
		return -1;
	return 0;
}
