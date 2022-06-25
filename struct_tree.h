#pragma once
struct node_t {
	struct node_t** children;
	char* key;
	unsigned int num_children;
	int end_of_word;
};
