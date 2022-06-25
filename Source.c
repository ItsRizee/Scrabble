#include <stdio.h>
#include <stdlib.h>

struct node_t {
	struct node_t** children;
	char* key;
	unsigned int num_children;
	int end_of_word;
};

int is_it_node(struct node_t*child, char* key)
{
	for (int i = 0; i < child->num_children; i++)
	{
		if (strcmp(child->children[i]->key, key) == 0)
		{
			return 0;
		}
	}
	return 1;
}

struct node_t* add_word_in_tree(struct node_t* root, char*word)
{
	int index = 0;
	int len = strlen(word);
	char* ptr = malloc(1);
	struct node_t* walker = root;
	while (index < strlen(word))
	{
		ptr[index] = word[index];
		ptr[index+1] = '\0';
		if (is_it_node(walker, ptr) == 0)
		{
			for (int i = 0; i < walker->num_children; i++)
			{
				if (strcmp(walker->children[i]->key, ptr) == 0)
				{
					walker = walker->children[i];
					break;
				}
			}
		}
		else
		{
			struct node_t* new_node = malloc(sizeof(new_node));
			new_node->children = NULL;
			if (index == len - 1)
				new_node->end_of_word = 1;
			else
				new_node->end_of_word = 0;
			new_node->key = malloc(sizeof(char*) * strlen(ptr));
			strcpy(new_node->key, ptr);
			
			new_node->num_children = 0;
			walker->num_children++;
			walker->children = realloc(walker->children,sizeof(struct node_t*) * walker->num_children);
			walker->children[walker->num_children - 1] = new_node;
			printf("%s\n", walker->children[0]->key);
			walker = walker->children[walker->num_children - 1];
		}
		index++;
		ptr = realloc(ptr, sizeof(char) * (index + 1));
	}
	return root;
}


int main()
{
	struct node_t* root = malloc(sizeof(root));
	root->children = NULL;
	root->end_of_word = 0;
	root->key = NULL;
	root->num_children = 0;
	root = add_word_in_tree(root, "word");
	root = add_word_in_tree(root, "words");
	root = add_word_in_tree(root, "wordse");
	printf("%s", root->children[0]->children[0]->key);
	return 0;
}
