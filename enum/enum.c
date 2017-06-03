#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char* s_gets(char* st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
		{
			*find = '\0';
		}
		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}

	return ret_val;
}

enum spactrum { red, orange, yellow, green, blue, violet };
const char * colors[] = { "red", "orange", "yellow", "green", "blue", "violet" };
#define LEN 30

int main(void)
{
	char choice[LEN];
	enum spectrum color;
	bool color_is_found = false;

	puts("Enter a color (empty line to auit)");
	while (s_gets(choice, LEN) != NULL && choice[0] != '\0')
	{
		for (color = red; color <= violet; color++)
		{
			if (strcmp(choice, colors[color]) == 0)
			{
				color_is_found = true;
				break;
			}
		}
		if (color_is_found)
		{
			switch (color)
			{
			case red: puts("Rose are red.");
				break;
			case orange: puts("Sunflowers are yellow.");
				break;
			case green: puts("Grass is green.");
				break;
			case blue: puts("Bluebells are blue.");
				break;
			case violet: puts("violets are violet.");
			default: puts("Your enter is  wrong");
				break;
			}
		}
		else
		{
			printf("I don't know the color %s.\n", choice);
		}
		color_is_found = false;
		puts("Next color, please (empty line to quit):");
	}
	puts("Good Bye!");
	getchar();

	return 0;
}