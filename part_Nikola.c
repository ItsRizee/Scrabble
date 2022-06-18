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

struct node_t* init_node(char* key)
{
	struct node_t* node = malloc(sizeof(struct node_t));
	node->key = key;
	node->children = NULL;
	node->num_children = 0;
	return node;
}

struct node_t* read_tree_from_file_recursion(char *data, struct node_t* tree, unsigned int *word_index)
{
	char* key;
	do
	{
		key = strtok(data + *word_index, " ");
		if (strcmp(key, ".") != 0)
		{
			tree->children = realloc(tree->children, ++(tree->num_children) * sizeof(struct node_t));
			tree->children[tree->num_children - 1] = init_node(key);
			*word_index += strlen(key) + 1;
			tree->children[tree->num_children - 1] = read_tree_from_file_recursion(data, tree->children[tree->num_children - 1], word_index);
		}
		else
		{
			*word_index += strlen(".") + 1;
			return tree;
		}
	} while (key != NULL);
	return tree;
}

struct node_t *read_tree_from_file(FILE *input)
{
	//find file lenght
	fseek(input, 0, SEEK_END);
	size_t size_input = ftell(input);
	printf("size_input: %ld\n", size_input);
	rewind(input);

	//read data from file
	char* data = malloc(size_input + 1);
	printf("data: %s, strlen(data): %ld\n", data, strlen(data));
	fread(data, 1, size_input, input);
	printf("data: %s, strlen(data): %ld\n", data, strlen(data));
	data[size_input] = NULL;
	fclose(input);

	struct node_t *tree = malloc(sizeof(struct node_t));
	tree->key = "", tree->num_children = 0, tree->children = NULL;

	unsigned int word_index = 0;
	tree = read_tree_from_file_recursion(data, tree, &word_index);
	return tree;
}

int main(int argc, char** argv)
{
	/*char* word = "aaaaaaa";
	if (add_word_to_dictionary(word, argv[1]) == 1)
	{
		printf("%s", word);
		return 0; //success
	}
	else
		return -1;*/
	/*struct node_t tree, t, a, te, to;
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

	if (write_tree_to_file(&tree, output) == 0)
		return -1;*/

	FILE* input = fopen("tree.txt", "r");
	if (input == NULL)
		return -1;

	struct node_t* tree2 = read_tree_from_file(input);
	return 0;
}
