#include "Nikola.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add_word_to_dictionary(char* word, char* path_to_dictionary)
{
	FILE* dictionary = fopen(path_to_dictionary, "a");
	//fwrite(word, sizeof(char), strlen(word), dictionary);
	if (fprintf(dictionary, "%s ", word) < 0)//If successful, the total number of characters written is returned otherwise, a negative number is returned.
	{
		fclose(dictionary);
		return 0;
	}
	else
	{
		fclose(dictionary);
		return 1;
	}
}

int write_tree_to_file(struct node_t* tree, FILE* output)
{
	//int num_children = sizeof(*(tree->children)) / sizeof(struct node_t);
	for (unsigned int i = 0; i < tree->num_children; i++)
	{	
		if(fprintf(output,"%s %d ", tree->children[i]->key, tree->children[i]->end_of_word) < 0)
			return 0;
		if(write_tree_to_file(tree->children[i], output) == 0)
			return 0;
	}
	if(fprintf(output, ". ") < 0)
		return 0;
	return 1;
}

struct node_t* init_node(char* key, unsigned int end_of_word)
{
	struct node_t* node = malloc(sizeof(struct node_t));
	node->key = key;
	node->end_of_word = end_of_word;
	node->children = NULL;
	node->num_children = 0;
	return node;
}


struct node_t* read_tree_from_file_recursion(struct node_t* tree, FILE* input)
{
	char* key = malloc(46);//46 chars is the longest english word
	int end_of_word;
	while(fscanf(input, "%s", key) != EOF)
	{
	printf("%s ", key);
		if (strcmp(key, ".") != 0)
		{
			if(fscanf(input, "%d", &end_of_word) == EOF)
				break; 
			printf("%d ", end_of_word);
			tree->children = realloc(tree->children, ++(tree->num_children) * sizeof(struct node_t));
			tree->children[tree->num_children - 1] = init_node(key, end_of_word);
			tree->children[tree->num_children - 1] = read_tree_from_file_recursion(tree->children[tree->num_children - 1], input);
		}
		else
			return tree;
	}
	return tree;
}

struct node_t *read_tree_from_file(FILE *input)
{
	struct node_t *tree = malloc(sizeof(struct node_t));
	tree->key = "", tree->num_children = 0, tree->children = NULL;

	unsigned int word_index = 0;
	tree = read_tree_from_file_recursion(tree, input);
	return tree;
}
