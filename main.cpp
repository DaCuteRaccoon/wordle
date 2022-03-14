#include <iostream>
#include <iomanip>
#include <time.h>
#include <strings.h>
#include <unistd.h>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>

#define RESET "\x1B[0m";
#define RED "\x1B[41m";
#define GREEN "\x1B[42m";
#define YELLOW "\x1B[103m";
#define BLUE "\x1B[44m";
#define MAGENTA "\x1B[105m";
#define GREY "\x1B[100m";
#define MINT "\x1B[102m";
#define SKY "\x1B[104m";
#define PEACH "\x1B[101m";
#define CYAN "\x1B[46m";

using namespace std;

	// Word variables
	char wordle[5];
	char word1[5];
	char word2[5];
	char word3[5];
	char word4[5];
	char word5[5];
	char word6[5];
	char win = 'n';

	// Color variables
	int color1 = 1;
	int color2 = 1;
	int color3 = 1;

void
writeflush(char const *str, size_t len)
{
	fwrite(str, 1, len, stdout);
	fflush(stdout);
}

void
clearscreen(void)
{
	static char const *screenclrseq = "\x1b[1J\x1b[H";

	fwrite(screenclrseq, 1, 7,  stdout);
}

void
titleanim(void)
{
	static const int second = 1000000;
	static char const *titletext = " W  O  R  D  L  E  ";

	clearscreen();
	writeflush(" ", 1);
	usleep(second / 2);
	clearscreen();

	for (int i = 0; i < 18; ++i) {
		writeflush(titletext + i, 1);
		usleep(second / 60);
	}

	usleep(second / 2);

	system("clear");
	cout << GREEN;
	cout << "  W  O  R  D  L  E  ";
	cout << RESET;
}

	// Color 1
	void c1()
	{
		if (color1 == 1)
		{
			cout << GREEN;
		}
		else if (color1 == 2)
		{
			cout << MAGENTA;
		}
		else if (color1 == 3)
		{
			cout << MINT;
		}
		else if (color1 == 4)
		{
			cout << CYAN;
		}
		else if (color1 == 5)
		{
			cout << GREEN;
		}
	}
