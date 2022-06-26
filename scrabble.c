#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "yana.h"

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
				letters[j] = ' ';
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

int main()
{
	print_optins();
	char* letters;
	int option;
	int score = 0;
	int num = 0;
	char* word = malloc(sizeof(word));

	scanf("%d", &option);
	switch (option)
	{
	case 1://startirane
		for (int i = 0;i < 10;i++)
		{
			letters = randomizing_letters(10);
			score += round(letters);
			printf("%d\n", score);
		}
		break;

	case 2:// broi bukvi

		printf("How many letters do you want?\n");
		scanf("%d", &num);
		for (size_t i = 0; i < 10; i++)
		{
			letters = randomizing_letters(num);
			score += round(letters);
			printf("%d\n", score);
		}

	case 3://broi rundove
		printf("How many rounds do you want?\n");
		int r = 0;
		scanf("%d", &r);
		//zapo4va igra (basically copy/paste ot case1 ili vuv funkciq)
		for (int i = 0;i < r;i++)
		{
			letters = randomizing_letters(10);
			score += round(letters);
			printf("%d\n", score);
		}
		break;

	case 4:// vuvezhdane na nova duma v re4nika
		printf("What iS the word?\n");
		scanf("%s", word);
		//struct tree* tree = init_root();
		//add_new_word( tree, word);
		printf("Word was added\n");
		break;

	default://izhod
		break;

	}
	return 0;
}