#define _CRT_SECURE_NO_WARNINGS
#include "yana.h"
#include <stdio.h>

void print_optins()
{
	printf("1. Start new game\n");
	printf("Settings\n");
	printf("	2. Change the number of given letters\n");
	printf("	3. Change the number of rounds\n");
	printf("4. Add new word\n");
	printf("5. Exit\n");
}

char* randomizing_letters(const int size)
{
	time_t t;
	srand((unsigned)time(&t));

	char* letters = malloc(size + 1);
	char l;
	for (int i = 0;i < size;i++)
	{
		//l = (rand() % ('Z' - 'A' + 1)) + 'A';
		l = 'A' + (rand() % 26);
		letters[i] = l;
	}
	letters[size] = 0;
	return letters;
}

int validating_word(char* letters, char* word)
{
	int size_l = strlen(letters);
	int size_w = strlen(word);
	for (int i = 0;i < size_w;i++)
	{
		for (int j = 0;j < size_l;j++)
		{
			if (word[i] == letters[j])
			{	
				letters[j] = ' ';
				break;
			}
		}
	}
	int num = 0;
	for (int b = 0;b < size_l;b++)
	{
		if (letters[b] == ' ')
			num++;
	}
	if (num == size_w)
		return 1;
	else return 0;
}

int round(char* letters)
{
	int size = strlen(letters);
	char* word = malloc(sizeof(char*));
	int score = 0;
	int num = 0;
	printf("Letters: \n");
	for (int i = 0;i < size;i++)
	{
		printf("%c ", letters[i]);
	}
	scanf("%s", word);
	if (validating_word(letters, word) == 1)//trqbva da se proveri dali e v re4nika
		score += strlen(word);

	return score;
}
