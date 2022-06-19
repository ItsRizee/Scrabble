#include <stdio.h>
#include <stdlib.h>

void print_optins()
{
	printf("1. Стартиране на нова игра\n");
	printf("2. Настройки\n");
	printf("	a. Променяне на броя на подаваните букви\n");
	printf("	b. Променяне на броя рундове\n");
	printf("3. Въвеждане на нова дума\n");
	printf("4. Изход\n");
}

char* randomizing_letters(const int size)
{
	char* letters=mallco(size);
	char l;
	for (int i = 0;i < size;i++)
	{
		l = (rand() % 26)+'A';
		letters[i] = l;
	}
	return letters;
}


int round(char*letters)
{
	char* word = malloc(word);
	int score;
	printf("Букви: \n");
	for (int i = 0;i < 10;i++)
	{
		printf("%s, ", letters[i]);
	}
	scanf(word);
	//proverka dali dumata e ot dadenite bukvi
	//po 1 to4ka za izpolzvana bukva
	//nakraq returnva score
	return score;
}

int main()
{
	print_optins();
	char* letters = malloc(letters);
	int option;
	int score;
	char op; char* word = malloc(word);

	scanf(option);
	switch (option)
	{
	case 1://startirane
		letters = randomizing_letters(10);
		for (int i = 0;i < 10;i++)
		{
			score += round(letters);
		}
		//vurtq 10 runda, rand bukvi, validirane duma dali e ot dadenite bukvi, validirane dali e v durvoto, 
		
	case 2:// nastroiki
		printf("Какво искаш да смениш?\n");
		scanf(op);
		if (op == 'a')
		{
			printf("Колко букви искаш?\n");
			int num;
			scanf(num);
			letters = randomizing_letters(num);
			for (int i = 0;i < num;i++)
			{
				printf("%s, ", letters[i]);
			}
		}
		else
		{
			printf("Колко рунда искаш?\n");
			int round;
			scanf(round);
		}//zapo4va igra (basically copy/paste ot case1 ili vuv funkciq)

	case 3:// vuvezhdane na nova duma
		
		printf("Каква е думата?\n");
		scnaf(word);
		struct tree* tree = init_root();
		add_new_word( tree, word);
		printf("Думата бе добавена успешно\n");
	default://izhod
		break;
	}
	return 0;
}