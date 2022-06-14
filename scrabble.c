#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree {
	struct tree** nodes;
	char* key;
};

int add_to_dictionary(char* word, char* path_to_dictionary)
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

int main(int argc, char** argv)
{
	char* word = "aaaaaaa";
	if (add_to_dictionary(word, argv[1]) == 1)
	{
		printf("%s", word);
		return 0; //success
	}
	else
		return -1;
}