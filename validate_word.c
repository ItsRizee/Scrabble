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
