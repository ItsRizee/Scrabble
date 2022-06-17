#include <stdio.h>
#include <stdlib.h>


struct tree
{
	struct tree** nodes;
	char* key;
	int cnt;
};


struct tree* init_node(char* key)
{
	struct tree* node = malloc(sizeof * node);
	*(node->key) = *key;
	node->nodes = NULL;
	node->cnt = 0;
	return node;
}

struct tree* init_root()
{
	struct tree* root = malloc(sizeof * root);
	root->key = NULL;
	root->cnt = 0;
	root->nodes = NULL;
	return root;
}

struct tree* add_new_word(struct tree* tree, char* word)
{
	int len = strlen(word);
	int index = 0;
	struct tree* walker = tree;
	while (index < len)
	{
		for (int i = 0; i < walker->cnt; i++)
		{
			if (*word == *(walker->nodes[i]->key))
			{
				walker = walker->nodes[i]->key;
				word++;
				goto forward;
			}
		}
		walker->cnt++;
		walker->nodes = realloc(walker->nodes, walker->cnt);
		walker->nodes[walker->cnt - 1] = init_node(*word);
		walker = walker->nodes[walker->cnt - 1];
		forward:
		index++;
	}

	return tree;
}

int main()
{
	struct tree* tree = init_root();

	return;
}