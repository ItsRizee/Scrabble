#pragma once
#include "struct_tree.h"
#include <stdio.h>
int add_word_to_dictionary(char* word, char* path_to_dictionary);
int write_tree_to_file(struct node_t* tree, FILE* output);
struct node_t* init_node(char* key, unsigned int end_of_word);
struct node_t* read_tree_from_file_recursion(struct node_t* tree, FILE* input);
struct node_t *read_tree_from_file(FILE *input);
