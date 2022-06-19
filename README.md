# Scrabble
#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct node_t
{
	struct node_t** children;
	char* key;
	unsigned int num_children;
	int end_word;
};

int validate_word(struct node_t* tree, char* word)
{
	char* part_of_word = calloc(sizeof * part_of_word * strlen(word)+1, 1);
	for (int i = 0; i < strlen(word); i++)
	{
		int found_match = 0;
		part_of_word[i] = word[i];
		for(int j=0;j<tree->num_children;j++)
			if (!strcmp(tree->children[j]->key, part_of_word))
			{
				tree= tree->children[j];
				found_match++;
					break;
			}
		if (!found_match)
			return 0;
	}
	return tree->end_word;
}
int main()
{
	struct node_t tree, t, a, te, to, tea, ten;
	tree.key = "", t.key = "t", a.key = "a", te.key = "te", to.key = "to", tea.key = "tea", ten.key = "ten";
	t.children = malloc(2 * sizeof(struct node_t));
	tree.children = malloc(2 * sizeof(struct node_t));
	tree.children[0] = &t, tree.children[1] = &a;
	t.children[0] = &te, t.children[1] = &to;
	te.children = malloc(2 * sizeof(struct node_t));
	te.children[0] = &tea, te.children[1] = &ten;
	tea.children = NULL, ten.children = NULL, to.children = NULL, a.children = NULL;
	tree.num_children = 2, a.num_children = 0, t.num_children = 2, te.num_children = 2, to.num_children = 0, tea.num_children = 0, ten.num_children = 0;
	tea.end_word = 1; to.end_word = 0;
	char word[] = "to";
	validate_word(&tree, word, 0);
}
