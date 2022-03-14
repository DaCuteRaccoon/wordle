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

  // Color 2
  void c2()
  {
    if (color2 == 1)
    {
      cout << YELLOW;
    }
    else if (color2 == 2)
    {
      cout << BLUE;
    }
    else if (color2 == 3)
    {
      cout << SKY;
    }
    else if (color2 == 4)
    {
      cout << BLUE;
    }
    else if (color2 == 5)
    {
      cout << BLUE;
    }
  }

  // Color 3
  void c3()
  {
    if (color3 == 1)
    {
      cout << RED;
    }
    else if (color3 == 2)
    {
      cout << GREY;
    }
    else if (color3 == 3)
    {
      cout << PEACH;
    }
    else if (color3 == 4)
    {
      cout << SKY;
    }
    else if (color3 == 5)
    {
      cout << RED;
    }
  }

// Word matrix function
void matrix(int n)
{
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        cout << " _ ";
      }
      cout << endl;
      cout << endl;
    }
    
}

void title1()
{
  system("clear");
  for (int i = 0; i < 6; i++)
  {
    cout << " _ ";
  }
}

void title2()
{
  system("clear");
  cout << " W ";
  for (int i = 0; i < 5; i++)
  {
    cout << " _ ";
  }
}

void title3()
{
  system("clear");
  cout << " W  O ";
  for (int i = 0; i < 4; i++)
  {
    cout << " _ ";
  }
}

void title4()
{
  system("clear");
  cout << " W  O  R ";
  for (int i = 0; i < 3; i++)
  {
    cout << " _ ";
  }
}

void title5()
{
  system("clear");
  cout << " W  O  R  D ";
  for (int i = 0; i < 2; i++)
  {
    cout << " _ ";
  }
}

void title6()
{
  system("clear");
  cout << " W  O  R  D  L ";
  for (int i = 0; i < 1; i++)
  {
    cout << " _ ";
  }
}

void title7()
{
  system("clear");
  cout << " W  O  R  D  L  E ";
}

void title8()
{
  system("clear");
  c1();
  cout << " W  O  R  D  L  E ";
  cout << RESET;
}

void theme()
{
  system("clear");
  title8();
  cout << endl;
  cout << endl;
  cout << "Choose a theme:" << endl;
  cout << endl;
  cout << "(1) Original";
  cout << endl;
  cout << GREEN;
  cout << " W  O  R  D  L  E ";
  cout << endl;
  if (color1 == 1)
  {
    cout << YELLOW;
  }
  else if (color1 == 2)
  {
    cout << BLUE;
  }
  else if (color1 == 3)
  {
    cout << SKY;
  }
  cout << " W  O  R  D  L  E ";
  cout << endl;
  if (color1 == 1)
  {
    cout << RED;
  }
  else if (color1 == 2)
  {
    cout << GREY;
  }
  else if (color1 == 3)
  {
    cout << PEACH;
  }
  cout << " W  O  R  D  L  E ";
  cout << endl;

  cout << RESET;

  cout << endl;
  cout << "(2) High Contrast";
  cout << endl;
  cout << MAGENTA;
  cout << " W  O  R  D  L  E ";
  cout << endl;
  cout << BLUE;
  cout << " W  O  R  D  L  E ";
  cout << endl;
  cout << GREY;
  cout << " W  O  R  D  L  E ";
  cout << endl;

  cout << RESET;

  cout << endl;
  cout << "(3) Bright";
  cout << endl;
  cout << MINT;
  cout << " W  O  R  D  L  E ";
  cout << endl;
  cout << SKY;
  cout << " W  O  R  D  L  E ";
  cout << endl;
  cout << PEACH;
  cout << " W  O  R  D  L  E ";
  cout << endl;

  cout << RESET;

  cout << endl;
  cout << "(4) Ocean";
  cout << endl;
  cout << CYAN;
  cout << " W  O  R  D  L  E ";
  cout << endl;
  cout << BLUE;
  cout << " W  O  R  D  L  E ";
  cout << endl;
  cout << SKY;
  cout << " W  O  R  D  L  E ";
  cout << RESET;
  cout << endl;

  

  cout << endl;
  cout << "(5) RGB";
  cout << endl;
  cout << GREEN;
  cout << " W  O  R  D  L  E ";
  cout << RESET;
  cout << endl;
  cout << BLUE;
  cout << " W  O  R  D  L  E ";
  cout << RESET;
  cout << endl;
  cout << RED;
  cout << " W  O  R  D  L  E ";
  cout << RESET;
  cout << RESET;
  cout << endl;

  

  cout << endl;

  cout << "Option: ";

  char theme = 'y';

  cin >> theme; 
  sleep(1);
  if (theme == '1')
  {
    color1 = 1;
    color2 = 1;
    color3 = 1;
  }
  else if (theme == '2')
  {
    color1 = 2;
    color2 = 2;
    color3 = 2;
  }
    else if (theme == '3')
  {
    color1 = 3;
    color2 = 3;
    color3 = 3;
  }
  else if (theme == '4')
  {
    color1 = 4;
    color2 = 4;
    color3 = 4;
  }
  else if (theme == '5')
  {
    color1 = 5;
    color2 = 5;
    color3 = 5;
  }
}

void instructions()
{
  cout << "Guess the WORDLE in 6 tries.";
  cout << endl;
  cout << endl;
  cout << "Each guess must be a valid 5 letter word. Hit the enter button to submit.";
  cout << endl;
  cout << endl;
  cout << "After each guess, the color of the tiles will change to show how close your guess was to the word.";
  cout << endl;
  cout << endl;

  cout << "------------------------------------------------------------";
  cout << endl;
  cout << endl;
  cout << "Examples";
  cout << endl;
  cout << endl;
  c1();
  cout << " W ";
  cout << RESET;
  cout << " E  A  R  Y ";
  cout << endl;
  cout << endl;
  cout << "The letter W is in the word and in the correct spot.";
  cout << endl;
  cout << endl;
  cout << " P ";
  c2();
  cout << " I ";
  cout << RESET;
  cout << " L  L  S ";
  cout << endl;
  cout << endl;
  cout << "The letter I is in the word but in the wrong spot.";
  cout << endl;
  cout << endl;
  cout << " V  A  G ";
  c3();
  cout << " U ";
  cout << RESET;
  cout << " E ";
  cout << endl;
  cout << endl;
  cout << "The letter U is not in the word in any spot.";
  cout << endl;
  cout << endl;
  cout << "------------------------------------------------------------";
  cout << endl;
  cout << endl;
  
}

// Word functions
void word1c()
{
  // Forces uppercase letters
  for (int i = 0; i < 5; i++)
  {
    word1[i] = toupper(word1[i]);
  }
  
  
  // word1 check
  if (word1[0] == wordle[0] && word1[1] == wordle[1] && word1[2] == wordle[2] && word1[3] == wordle[3] && word1[4] == wordle[4]) 
  {
    // Check each letter
    for (int i = 0; i < 5; i++)
    {
      // Correct word
      if (word1[i] == wordle[i])
      {
        c1();
        cout << " " << word1[i] << " ";
        cout << RESET;
      }
    }
    cout << endl;
    cout  << endl;
    matrix(5);
    cout << endl;
    cout << endl;
    cout << "You win! The word was ";
    c1();
    for (int i = 0; i < 5; i++)
    {
        c1();
        cout << " " << word1[i] << " ";
        cout << RESET;
    }
    win = 'y';
  }
  else
  {
    // Show letters
    for (int i = 0; i < 5; i++)
    {
      if (word1[i] == wordle[i])
      {
        c1();
        cout << " " << word1[i] << " ";
        cout << RESET;
      }
      else if (word1[i] != wordle[i] && (word1[i] == wordle[0] || word1[i] == wordle[1] || word1[i] == wordle[2] || word1[i] == wordle[3] || word1[i] == wordle[4]))
      {
        c2();
        cout << " " << word1[i] << " ";
        cout << RESET;
      }
      else 
      {
        c3();
        cout << " " << word1[i] << " ";
        cout << RESET;
      }
    }

  }
  cout << endl;
  cout << endl;
}

void word2c()
{
  // Forces uppercase letters
  for (int i = 0; i < 5; i++)
  {
    word2[i] = toupper(word2[i]);
  }
  
  // word2 check
  if (word2[0] == wordle[0] && word2[1] == wordle[1] && word2[2] == wordle[2] && word2[3] == wordle[3] && word2[4] == wordle[4]) 
  {
    // Check each letter
    for (int i = 0; i < 5; i++)
    {
      // Correct word
      if (word2[i] == wordle[i])
      {
        c1();
        cout << " " << word2[i] << " ";
        cout << RESET;
      }
    }
    cout << endl;
    cout  << endl;
    matrix(4);
    cout << endl;
    cout << endl;
    cout << "You win! The word was ";
    for (int i = 0; i < 5; i++)
    {
        c1();
        cout << " " << word2[i] << " ";
        cout << RESET;
    }
    win = 'y';
  }
  else
  {
    // Show letters
    for (int i = 0; i < 5; i++)
    {
      if (word2[i] == wordle[i])
      {
        c1();
        cout << " " << word2[i] << " ";
        cout << RESET;
      }
      else if (word2[i] != wordle[i] && (word2[i] == wordle[0] || word2[i] == wordle[1] || word2[i] == wordle[2] || word2[i] == wordle[3] || word2[i] == wordle[4]))
      {
        c2();
        cout << " " << word2[i] << " ";
        cout << RESET;
      }
      else 
      {
        c3();
        cout << " " << word2[i] << " ";
        cout << RESET;
      }
    }
  }
  cout << endl;
  cout << endl;
}

void word3c()
{
  // Forces uppercase letters
  for (int i = 0; i < 5; i++)
  {
    word3[i] = toupper(word3[i]);
  }

  // word3 check
  if (word3[0] == wordle[0] && word3[1] == wordle[1] && word3[2] == wordle[2] && word3[3] == wordle[3] && word3[4] == wordle[4]) 
  {
    // Check each letter
    for (int i = 0; i < 5; i++)
    {
      // Correct word
      if (word3[i] == wordle[i])
      {
        c1();
        cout << " " << word3[i] << " ";
        cout << RESET;
      }
    }
    cout << endl;
    cout  << endl;
    matrix(3);
    cout << endl;
    cout << endl;
    cout << "You win! The word was ";
    for (int i = 0; i < 5; i++)
    {
        c1();
        cout << " " << word3[i] << " ";
        cout << RESET;
    }
    win = 'y';
  }
  else
  {
    // Show letters
    for (int i = 0; i < 5; i++)
    {
      if (word3[i] == wordle[i])
      {
        c1();
        cout << " " << word3[i] << " ";
        cout << RESET;
      }
      else if (word3[i] != wordle[i] && (word3[i] == wordle[0] || word3[i] == wordle[1] || word3[i] == wordle[2] || word3[i] == wordle[3] || word3[i] == wordle[4]))
      {
        c2();
        cout << " " << word3[i] << " ";
        cout << RESET;
      }
      else 
      {
        c3();
        cout << " " << word3[i] << " ";
        cout << RESET;
      }
    }
  }
  cout << endl;
  cout << endl;
}

void word4c()
{  
  // Forces uppercase letters
  for (int i = 0; i < 5; i++)
  {
    word4[i] = toupper(word4[i]);
  }

  // word4 check
  if (word4[0] == wordle[0] && word4[1] == wordle[1] && word4[2] == wordle[2] && word4[3] == wordle[3] && word4[4] == wordle[4]) 
  {
    // Check each letter
    for (int i = 0; i < 5; i++)
    {
      // Correct word
      if (word4[i] == wordle[i])
      {
        c1();
        cout << " " << word4[i] << " ";
        cout << RESET;
      }
    }
    cout << endl;
    cout  << endl;
    matrix(2);
    cout << endl;
    cout << endl;
    cout << "You win! The word was ";
    for (int i = 0; i < 5; i++)
    {
        c1();
        cout << " " << word4[i] << " ";
        cout << RESET;
    }
    win = 'y';
  }
  else
  {
    // Show letters
    for (int i = 0; i < 5; i++)
    {
      if (word4[i] == wordle[i])
      {
        c1();
        cout << " " << word4[i] << " ";
        cout << RESET;
      }
      else if (word4[i] != wordle[i] && (word4[i] == wordle[0] || word4[i] == wordle[1] || word4[i] == wordle[2] || word4[i] == wordle[3] || word4[i] == wordle[4]))
      {
        c2();
        cout << " " << word4[i] << " ";
        cout << RESET;
      }
      else 
      {
        c3();
        cout << " " << word4[i] << " ";
        cout << RESET;
      }
    }
  }
  cout << endl;
  cout << endl;
}

void word5c()
{
  // Forces uppercase letters
  for (int i = 0; i < 5; i++)
  {
    word5[i] = toupper(word5[i]);
  }
  
  // word5 check
  if (word5[0] == wordle[0] && word5[1] == wordle[1] && word5[2] == wordle[2] && word5[3] == wordle[3] && word5[4] == wordle[4]) 
  {
    // Check each letter
    for (int i = 0; i < 5; i++)
    {
      // Correct word
      if (word5[i] == wordle[i])
      {
        c1();
        cout << " " << word5[i] << " ";
        cout << RESET;
      }
    }
    cout << endl;
    cout  << endl;
    matrix(1);
    cout << endl;
    cout << endl;
    cout << "You win! The word was ";
    for (int i = 0; i < 5; i++)
    {
        c1();
        cout << " " << word5[i] << " ";
        cout << RESET;
    }
    win = 'y';
  }
  else
  {
    // Show letters
    for (int i = 0; i < 5; i++)
    {
      if (word5[i] == wordle[i])
      {
        c1();
        cout << " " << word5[i] << " ";
        cout << RESET;
      }
      else if (word5[i] != wordle[i] && (word5[i] == wordle[0] || word5[i] == wordle[1] || word5[i] == wordle[2] || word5[i] == wordle[3] || word5[i] == wordle[4]))
      {
        c2();
        cout << " " << word5[i] << " ";
        cout << RESET;
      }
      else 
      {
        c3();
        cout << " " << word5[i] << " ";
        cout << RESET;
      }
    }
  }
  cout << endl;
  cout << endl;
}

void word6c()
{
  // Forces uppercase letters
  for (int i = 0; i < 5; i++)
  {
    word6[i] = toupper(word6[i]);
  }

  // word6 check
  if (word6[0] == wordle[0] && word6[1] == wordle[1] && word6[2] == wordle[2] && word6[3] == wordle[3] && word6[4] == wordle[4]) 
  {
    // Check each letter
    for (int i = 0; i < 5; i++)
    {
      // Correct word
      if (word6[i] == wordle[i])
      {
        c1();
        cout << " " << word6[i] << " ";
        cout << RESET;
      }
    }
    cout << endl;
    cout << endl;
    cout << "You win! The word was ";
    for (int i = 0; i < 5; i++)
    {
        c1();
        cout << " " << word6[i] << " ";
        cout << RESET;
    }
    win = 'y';
  }
  else
  {
    // Show letters
    for (int i = 0; i < 5; i++)
    {
      if (word6[i] == wordle[i])
      {
        c1();
        cout << " " << word6[i] << " ";
        cout << RESET;
      }
      else if (word6[i] != wordle[i] && (word6[i] == wordle[0] || word6[i] == wordle[1] || word6[i] == wordle[2] || word6[i] == wordle[3] || word6[i] == wordle[4]))
      {
        c2();
        cout << " " << word6[i] << " ";
        cout << RESET;
      }
      else 
      {
        c3();
        cout << " " << word6[i] << " ";
        cout << RESET;
      }
    }
    cout << endl;
    cout << endl;
    cout << "You lost! The word was ";
    for (int i = 0; i < 5; i++)
    {
        c1();
        cout << " " << wordle[i] << " ";
        cout << RESET;
    }
  }
  cout << endl;
  cout << endl;
}

// Show what letters they got right
void alphabet()
{
  if ((word1[0] == wordle[0] && word1[0] == 'Q') || (word1[1] == wordle[1] && word1[1] == 'Q') || (word1[2] == wordle[2] && word1[2] == 'Q') || (word1[3] == wordle[3] && word1[3] == 'Q') || (word1[4] == wordle[4] && word1[4] == 'Q') || (word2[0] == wordle[0] && word2[0] == 'Q') || (word2[1] == wordle[1] && word2[1] == 'Q') || (word2[2] == wordle[2] && word2[2] == 'Q') || (word2[3] == wordle[3] && word2[3] == 'Q') || (word2[4] == wordle[4] && word2[4] == 'Q') || (word3[0] == wordle[0] && word3[0] == 'Q') || (word3[1] == wordle[1] && word3[1] == 'Q') || (word3[2] == wordle[2] && word3[2] == 'Q') || (word3[3] == wordle[3] && word3[3] == 'Q') || (word3[4] == wordle[4] && word3[4] == 'Q') || (word4[0] == wordle[0] && word4[0] == 'Q') || (word4[1] == wordle[1] && word4[1] == 'Q') || (word4[2] == wordle[2] && word4[2] == 'Q') || (word4[3] == wordle[3] && word4[3] == 'Q') || (word4[4] == wordle[4] && word4[4] == 'Q') || (word5[0] == wordle[0] && word5[0] == 'Q') || (word5[1] == wordle[1] && word5[1] == 'Q') || (word5[2] == wordle[2] && word5[2] == 'Q') || (word5[3] == wordle[3] && word5[3] == 'Q') || (word5[4] == wordle[4] && word5[4] == 'Q') || (word6[0] == wordle[0] && word6[0] == 'Q') || (word6[1] == wordle[1] && word6[1] == 'Q') || (word6[2] == wordle[2] && word6[2] == 'Q') || (word6[3] == wordle[3] && word6[3] == 'Q') || (word6[4] == wordle[4] && word6[4] == 'Q'))
  {
    c1();
    cout << " Q ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'Q') || (word1[0] == wordle[2] && wordle[2] == 'Q') || (word1[0] == wordle[3] && wordle[3] == 'Q') || (word1[0] == wordle[4] && wordle[4] == 'Q') || (word1[1] == wordle[0] && wordle[0] == 'Q') || (word1[1] == wordle[2] && wordle[2] == 'Q') || (word1[1] == wordle[3] && wordle[3] == 'Q') || (word1[1] == wordle[4] && wordle[4] == 'Q') || (word1[2] == wordle[1] && wordle[1] == 'Q') || (word1[2] == wordle[0] && wordle[0] == 'Q') || (word1[2] == wordle[3] && wordle[3] == 'Q') || (word1[2] == wordle[4] && wordle[4] == 'Q') || (word1[3] == wordle[1] && wordle[1] == 'Q') || (word1[3] == wordle[0] && wordle[0] == 'Q') || (word1[3] == wordle[2] && wordle[2] == 'Q') || (word1[3] == wordle[4] && wordle[4] == 'Q') || (word1[4] == wordle[1] && wordle[1] == 'Q') || (word1[4] == wordle[0] && wordle[0] == 'Q') || (word1[4] == wordle[3] && wordle[3] == 'Q') || (word1[4] == wordle[2] && wordle[2] == 'Q') || (word2[0] == wordle[1] && wordle[1] == 'Q') || (word2[0] == wordle[2] && wordle[2] == 'Q') || (word2[0] == wordle[3] && wordle[3] == 'Q') || (word2[0] == wordle[4] && wordle[4] == 'Q') || (word2[1] == wordle[0] && wordle[0] == 'Q') || (word2[1] == wordle[2] && wordle[2] == 'Q') || (word2[1] == wordle[3] && wordle[3] == 'Q') || (word2[1] == wordle[4] && wordle[4] == 'Q') || (word2[2] == wordle[1] && wordle[1] == 'Q') || (word2[2] == wordle[0] && wordle[0] == 'Q') || (word2[2] == wordle[3] && wordle[3] == 'Q') || (word2[2] == wordle[4] && wordle[4] == 'Q') || (word2[3] == wordle[1] && wordle[1] == 'Q') || (word2[3] == wordle[0] && wordle[0] == 'Q') || (word2[3] == wordle[2] && wordle[2] == 'Q') || (word2[3] == wordle[4] && wordle[4] == 'Q') || (word2[4] == wordle[1] && wordle[1] == 'Q') || (word2[4] == wordle[0] && wordle[0] == 'Q') || (word2[4] == wordle[3] && wordle[3] == 'Q') || (word2[4] == wordle[2] && wordle[2] == 'Q') || (word3[0] == wordle[1] && wordle[1] == 'Q') || (word3[0] == wordle[2] && wordle[2] == 'Q') || (word3[0] == wordle[3] && wordle[3] == 'Q') || (word3[0] == wordle[4] && wordle[4] == 'Q') || (word3[1] == wordle[0] && wordle[0] == 'Q') || (word3[1] == wordle[2] && wordle[2] == 'Q') || (word3[1] == wordle[3] && wordle[3] == 'Q') || (word3[1] == wordle[4] && wordle[4] == 'Q') || (word3[2] == wordle[1] && wordle[1] == 'Q') || (word3[2] == wordle[0] && wordle[0] == 'Q') || (word3[2] == wordle[3] && wordle[3] == 'Q') || (word3[2] == wordle[4] && wordle[4] == 'Q') || (word3[3] == wordle[1] && wordle[1] == 'Q') || (word3[3] == wordle[0] && wordle[0] == 'Q') || (word3[3] == wordle[2] && wordle[2] == 'Q') || (word3[3] == wordle[4] && wordle[4] == 'Q') || (word3[4] == wordle[1] && wordle[1] == 'Q') || (word3[4] == wordle[0] && wordle[0] == 'Q') || (word3[4] == wordle[3] && wordle[3] == 'Q') || (word3[4] == wordle[2] && wordle[2] == 'Q') || (word4[0] == wordle[1] && wordle[1] == 'Q') || (word4[0] == wordle[2] && wordle[2] == 'Q') || (word4[0] == wordle[3] && wordle[3] == 'Q') || (word4[0] == wordle[4] && wordle[4] == 'Q') || (word4[1] == wordle[0] && wordle[0] == 'Q') || (word4[1] == wordle[2] && wordle[2] == 'Q') || (word4[1] == wordle[3] && wordle[3] == 'Q') || (word4[1] == wordle[4] && wordle[4] == 'Q') || (word4[2] == wordle[1] && wordle[1] == 'Q') || (word4[2] == wordle[0] && wordle[0] == 'Q') || (word4[2] == wordle[3] && wordle[3] == 'Q') || (word4[2] == wordle[4] && wordle[4] == 'Q') || (word4[3] == wordle[1] && wordle[1] == 'Q') || (word4[3] == wordle[0] && wordle[0] == 'Q') || (word4[3] == wordle[2] && wordle[2] == 'Q') || (word4[3] == wordle[4] && wordle[4] == 'Q') || (word4[4] == wordle[1] && wordle[1] == 'Q') || (word4[4] == wordle[0] && wordle[0] == 'Q') || (word4[4] == wordle[3] && wordle[3] == 'Q') || (word4[4] == wordle[2] && wordle[2] == 'Q') || (word5[0] == wordle[1] && wordle[1] == 'Q') || (word5[0] == wordle[2] && wordle[2] == 'Q') || (word5[0] == wordle[3] && wordle[3] == 'Q') || (word5[0] == wordle[4] && wordle[4] == 'Q') || (word5[1] == wordle[0] && wordle[0] == 'Q') || (word5[1] == wordle[2] && wordle[2] == 'Q') || (word5[1] == wordle[3] && wordle[3] == 'Q') || (word5[1] == wordle[4] && wordle[4] == 'Q') || (word5[2] == wordle[1] && wordle[1] == 'Q') || (word5[2] == wordle[0] && wordle[0] == 'Q') || (word5[2] == wordle[3] && wordle[3] == 'Q') || (word5[2] == wordle[4] && wordle[4] == 'Q') || (word5[3] == wordle[1] && wordle[1] == 'Q') || (word5[3] == wordle[0] && wordle[0] == 'Q') || (word5[3] == wordle[2] && wordle[2] == 'Q') || (word5[3] == wordle[4] && wordle[4] == 'Q') || (word5[4] == wordle[1] && wordle[1] == 'Q') || (word5[4] == wordle[0] && wordle[0] == 'Q') || (word5[4] == wordle[3] && wordle[3] == 'Q') || (word5[4] == wordle[2] && wordle[2] == 'Q') || (word6[0] == wordle[1] && wordle[1] == 'Q') || (word6[0] == wordle[2] && wordle[2] == 'Q') || (word6[0] == wordle[3] && wordle[3] == 'Q') || (word6[0] == wordle[4] && wordle[4] == 'Q') || (word6[1] == wordle[0] && wordle[0] == 'Q') || (word6[1] == wordle[2] && wordle[2] == 'Q') || (word6[1] == wordle[3] && wordle[3] == 'Q') || (word6[1] == wordle[4] && wordle[4] == 'Q') || (word6[2] == wordle[1] && wordle[1] == 'Q') || (word6[2] == wordle[0] && wordle[0] == 'Q') || (word6[2] == wordle[3] && wordle[3] == 'Q') || (word6[2] == wordle[4] && wordle[4] == 'Q') || (word6[3] == wordle[1] && wordle[1] == 'Q') || (word6[3] == wordle[0] && wordle[0] == 'Q') || (word6[3] == wordle[2] && wordle[2] == 'Q') || (word6[3] == wordle[4] && wordle[4] == 'Q') || (word6[4] == wordle[1] && wordle[1] == 'Q') || (word6[4] == wordle[0] && wordle[0] == 'Q') || (word6[4] == wordle[3] && wordle[3] == 'Q') || (word6[4] == wordle[2] && wordle[2] == 'Q'))
  {
    c2();
    cout << " Q ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'Q') || (word1[0] != wordle[2] && word1[0] == 'Q') || (word1[0] != wordle[3] && word1[0] == 'Q') || (word1[0] != wordle[4] && word1[0] == 'Q') || (word1[1] != wordle[0] && word1[1] == 'Q') || (word1[1] != wordle[2] && word1[1] == 'Q') || (word1[1] != wordle[3] && word1[1] == 'Q') || (word1[1] != wordle[4] && word1[1] == 'Q') || (word1[2] != wordle[1] && word1[2] == 'Q') || (word1[2] != wordle[0] && word1[2] == 'Q') || (word1[2] != wordle[3] && word1[2] == 'Q') || (word1[2] != wordle[4] && word1[2] == 'Q') || (word1[3] != wordle[1] && word1[3] == 'Q') || (word1[3] != wordle[2] && word1[3] == 'Q') || (word1[3] != wordle[0] && word1[3] == 'Q') || (word1[3] != wordle[4] && word1[3] == 'Q') || (word1[4] != wordle[1] && word1[4] == 'Q') || (word1[4] != wordle[2] && word1[4] == 'Q') || (word1[4] != wordle[3] && word1[4] == 'Q') || (word1[4] != wordle[0] && word1[4] == 'Q') || (word2[0] != wordle[1] && word2[0] == 'Q') || (word2[0] != wordle[2] && word2[0] == 'Q') || (word2[0] != wordle[3] && word2[0] == 'Q') || (word2[0] != wordle[4] && word2[0] == 'Q') || (word2[1] != wordle[0] && word2[1] == 'Q') || (word2[1] != wordle[2] && word2[1] == 'Q') || (word2[1] != wordle[3] && word2[1] == 'Q') || (word2[1] != wordle[4] && word2[1] == 'Q') || (word2[2] != wordle[1] && word2[2] == 'Q') || (word2[2] != wordle[0] && word2[2] == 'Q') || (word2[2] != wordle[3] && word2[2] == 'Q') || (word2[2] != wordle[4] && word2[2] == 'Q') || (word2[3] != wordle[1] && word2[3] == 'Q') || (word2[3] != wordle[2] && word2[3] == 'Q') || (word2[3] != wordle[0] && word2[3] == 'Q') || (word2[3] != wordle[4] && word2[3] == 'Q') || (word2[4] != wordle[1] && word2[4] == 'Q') || (word2[4] != wordle[2] && word2[4] == 'Q') || (word2[4] != wordle[3] && word2[4] == 'Q') || (word2[4] != wordle[0] && word2[4] == 'Q') || (word3[0] != wordle[1] && word3[0] == 'Q') || (word3[0] != wordle[2] && word3[0] == 'Q') || (word3[0] != wordle[3] && word3[0] == 'Q') || (word3[0] != wordle[4] && word3[0] == 'Q') || (word3[1] != wordle[0] && word3[1] == 'Q') || (word3[1] != wordle[2] && word3[1] == 'Q') || (word3[1] != wordle[3] && word3[1] == 'Q') || (word3[1] != wordle[4] && word3[1] == 'Q') || (word3[2] != wordle[1] && word3[2] == 'Q') || (word3[2] != wordle[0] && word3[2] == 'Q') || (word3[2] != wordle[3] && word3[2] == 'Q') || (word3[2] != wordle[4] && word3[2] == 'Q') || (word3[3] != wordle[1] && word3[3] == 'Q') || (word3[3] != wordle[2] && word3[3] == 'Q') || (word3[3] != wordle[0] && word3[3] == 'Q') || (word3[3] != wordle[4] && word3[3] == 'Q') || (word3[4] != wordle[1] && word3[4] == 'Q') || (word3[4] != wordle[2] && word3[4] == 'Q') || (word3[4] != wordle[3] && word3[4] == 'Q') || (word3[4] != wordle[0] && word3[4] == 'Q') || (word4[0] != wordle[1] && word4[0] == 'Q') || (word4[0] != wordle[2] && word4[0] == 'Q') || (word4[0] != wordle[3] && word4[0] == 'Q') || (word4[0] != wordle[4] && word4[0] == 'Q') || (word4[1] != wordle[0] && word4[1] == 'Q') || (word4[1] != wordle[2] && word4[1] == 'Q') || (word4[1] != wordle[3] && word4[1] == 'Q') || (word4[1] != wordle[4] && word4[1] == 'Q') || (word4[2] != wordle[1] && word4[2] == 'Q') || (word4[2] != wordle[0] && word4[2] == 'Q') || (word4[2] != wordle[3] && word4[2] == 'Q') || (word4[2] != wordle[4] && word4[2] == 'Q') || (word4[3] != wordle[1] && word4[3] == 'Q') || (word4[3] != wordle[2] && word4[3] == 'Q') || (word4[3] != wordle[0] && word4[3] == 'Q') || (word4[3] != wordle[4] && word4[3] == 'Q') || (word4[4] != wordle[1] && word4[4] == 'Q') || (word4[4] != wordle[2] && word4[4] == 'Q') || (word4[4] != wordle[3] && word4[4] == 'Q') || (word4[4] != wordle[0] && word4[4] == 'Q') || (word5[0] != wordle[1] && word5[0] == 'Q') || (word5[0] != wordle[2] && word5[0] == 'Q') || (word5[0] != wordle[3] && word5[0] == 'Q') || (word5[0] != wordle[4] && word5[0] == 'Q') || (word5[1] != wordle[0] && word5[1] == 'Q') || (word5[1] != wordle[2] && word5[1] == 'Q') || (word5[1] != wordle[3] && word5[1] == 'Q') || (word5[1] != wordle[4] && word5[1] == 'Q') || (word5[2] != wordle[1] && word5[2] == 'Q') || (word5[2] != wordle[0] && word5[2] == 'Q') || (word5[2] != wordle[3] && word5[2] == 'Q') || (word5[2] != wordle[4] && word5[2] == 'Q') || (word5[3] != wordle[1] && word5[3] == 'Q') || (word5[3] != wordle[2] && word5[3] == 'Q') || (word5[3] != wordle[0] && word5[3] == 'Q') || (word5[3] != wordle[4] && word5[3] == 'Q') || (word5[4] != wordle[1] && word5[4] == 'Q') || (word5[4] != wordle[2] && word5[4] == 'Q') || (word5[4] != wordle[3] && word5[4] == 'Q') || (word5[4] != wordle[0] && word5[4] == 'Q') || (word6[0] != wordle[1] && word6[0] == 'Q') || (word6[0] != wordle[2] && word6[0] == 'Q') || (word6[0] != wordle[3] && word6[0] == 'Q') || (word6[0] != wordle[4] && word6[0] == 'Q') || (word6[1] != wordle[0] && word6[1] == 'Q') || (word6[1] != wordle[2] && word6[1] == 'Q') || (word6[1] != wordle[3] && word6[1] == 'Q') || (word6[1] != wordle[4] && word6[1] == 'Q') || (word6[2] != wordle[1] && word6[2] == 'Q') || (word6[2] != wordle[0] && word6[2] == 'Q') || (word6[2] != wordle[3] && word6[2] == 'Q') || (word6[2] != wordle[4] && word6[2] == 'Q') || (word6[3] != wordle[1] && word6[3] == 'Q') || (word6[3] != wordle[2] && word6[3] == 'Q') || (word6[3] != wordle[0] && word6[3] == 'Q') || (word6[3] != wordle[4] && word6[3] == 'Q') || (word6[4] != wordle[1] && word6[4] == 'Q') || (word6[4] != wordle[2] && word6[4] == 'Q') || (word6[4] != wordle[3] && word6[4] == 'Q') || (word6[4] != wordle[0] && word6[4] == 'Q'))
  {
    c3();
    cout << " Q ";
    cout << RESET;
  }
  else 
  {
    cout << " Q ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'W') || (word1[1] == wordle[1] && word1[1] == 'W') || (word1[2] == wordle[2] && word1[2] == 'W') || (word1[3] == wordle[3] && word1[3] == 'W') || (word1[4] == wordle[4] && word1[4] == 'W') || (word2[0] == wordle[0] && word2[0] == 'W') || (word2[1] == wordle[1] && word2[1] == 'W') || (word2[2] == wordle[2] && word2[2] == 'W') || (word2[3] == wordle[3] && word2[3] == 'W') || (word2[4] == wordle[4] && word2[4] == 'W') || (word3[0] == wordle[0] && word3[0] == 'W') || (word3[1] == wordle[1] && word3[1] == 'W') || (word3[2] == wordle[2] && word3[2] == 'W') || (word3[3] == wordle[3] && word3[3] == 'W') || (word3[4] == wordle[4] && word3[4] == 'W') || (word4[0] == wordle[0] && word4[0] == 'W') || (word4[1] == wordle[1] && word4[1] == 'W') || (word4[2] == wordle[2] && word4[2] == 'W') || (word4[3] == wordle[3] && word4[3] == 'W') || (word4[4] == wordle[4] && word4[4] == 'W') || (word5[0] == wordle[0] && word5[0] == 'W') || (word5[1] == wordle[1] && word5[1] == 'W') || (word5[2] == wordle[2] && word5[2] == 'W') || (word5[3] == wordle[3] && word5[3] == 'W') || (word5[4] == wordle[4] && word5[4] == 'W') || (word6[0] == wordle[0] && word6[0] == 'W') || (word6[1] == wordle[1] && word6[1] == 'W') || (word6[2] == wordle[2] && word6[2] == 'W') || (word6[3] == wordle[3] && word6[3] == 'W') || (word6[4] == wordle[4] && word6[4] == 'W'))
  {
    c1();
    cout << " W ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'W') || (word1[0] == wordle[2] && wordle[2] == 'W') || (word1[0] == wordle[3] && wordle[3] == 'W') || (word1[0] == wordle[4] && wordle[4] == 'W') || (word1[1] == wordle[0] && wordle[0] == 'W') || (word1[1] == wordle[2] && wordle[2] == 'W') || (word1[1] == wordle[3] && wordle[3] == 'W') || (word1[1] == wordle[4] && wordle[4] == 'W') || (word1[2] == wordle[1] && wordle[1] == 'W') || (word1[2] == wordle[0] && wordle[0] == 'W') || (word1[2] == wordle[3] && wordle[3] == 'W') || (word1[2] == wordle[4] && wordle[4] == 'W') || (word1[3] == wordle[1] && wordle[1] == 'W') || (word1[3] == wordle[0] && wordle[0] == 'W') || (word1[3] == wordle[2] && wordle[2] == 'W') || (word1[3] == wordle[4] && wordle[4] == 'W') || (word1[4] == wordle[1] && wordle[1] == 'W') || (word1[4] == wordle[0] && wordle[0] == 'W') || (word1[4] == wordle[3] && wordle[3] == 'W') || (word1[4] == wordle[2] && wordle[2] == 'W') || (word2[0] == wordle[1] && wordle[1] == 'W') || (word2[0] == wordle[2] && wordle[2] == 'W') || (word2[0] == wordle[3] && wordle[3] == 'W') || (word2[0] == wordle[4] && wordle[4] == 'W') || (word2[1] == wordle[0] && wordle[0] == 'W') || (word2[1] == wordle[2] && wordle[2] == 'W') || (word2[1] == wordle[3] && wordle[3] == 'W') || (word2[1] == wordle[4] && wordle[4] == 'W') || (word2[2] == wordle[1] && wordle[1] == 'W') || (word2[2] == wordle[0] && wordle[0] == 'W') || (word2[2] == wordle[3] && wordle[3] == 'W') || (word2[2] == wordle[4] && wordle[4] == 'W') || (word2[3] == wordle[1] && wordle[1] == 'W') || (word2[3] == wordle[0] && wordle[0] == 'W') || (word2[3] == wordle[2] && wordle[2] == 'W') || (word2[3] == wordle[4] && wordle[4] == 'W') || (word2[4] == wordle[1] && wordle[1] == 'W') || (word2[4] == wordle[0] && wordle[0] == 'W') || (word2[4] == wordle[3] && wordle[3] == 'W') || (word2[4] == wordle[2] && wordle[2] == 'W') || (word3[0] == wordle[1] && wordle[1] == 'W') || (word3[0] == wordle[2] && wordle[2] == 'W') || (word3[0] == wordle[3] && wordle[3] == 'W') || (word3[0] == wordle[4] && wordle[4] == 'W') || (word3[1] == wordle[0] && wordle[0] == 'W') || (word3[1] == wordle[2] && wordle[2] == 'W') || (word3[1] == wordle[3] && wordle[3] == 'W') || (word3[1] == wordle[4] && wordle[4] == 'W') || (word3[2] == wordle[1] && wordle[1] == 'W') || (word3[2] == wordle[0] && wordle[0] == 'W') || (word3[2] == wordle[3] && wordle[3] == 'W') || (word3[2] == wordle[4] && wordle[4] == 'W') || (word3[3] == wordle[1] && wordle[1] == 'W') || (word3[3] == wordle[0] && wordle[0] == 'W') || (word3[3] == wordle[2] && wordle[2] == 'W') || (word3[3] == wordle[4] && wordle[4] == 'W') || (word3[4] == wordle[1] && wordle[1] == 'W') || (word3[4] == wordle[0] && wordle[0] == 'W') || (word3[4] == wordle[3] && wordle[3] == 'W') || (word3[4] == wordle[2] && wordle[2] == 'W') || (word4[0] == wordle[1] && wordle[1] == 'W') || (word4[0] == wordle[2] && wordle[2] == 'W') || (word4[0] == wordle[3] && wordle[3] == 'W') || (word4[0] == wordle[4] && wordle[4] == 'W') || (word4[1] == wordle[0] && wordle[0] == 'W') || (word4[1] == wordle[2] && wordle[2] == 'W') || (word4[1] == wordle[3] && wordle[3] == 'W') || (word4[1] == wordle[4] && wordle[4] == 'W') || (word4[2] == wordle[1] && wordle[1] == 'W') || (word4[2] == wordle[0] && wordle[0] == 'W') || (word4[2] == wordle[3] && wordle[3] == 'W') || (word4[2] == wordle[4] && wordle[4] == 'W') || (word4[3] == wordle[1] && wordle[1] == 'W') || (word4[3] == wordle[0] && wordle[0] == 'W') || (word4[3] == wordle[2] && wordle[2] == 'W') || (word4[3] == wordle[4] && wordle[4] == 'W') || (word4[4] == wordle[1] && wordle[1] == 'W') || (word4[4] == wordle[0] && wordle[0] == 'W') || (word4[4] == wordle[3] && wordle[3] == 'W') || (word4[4] == wordle[2] && wordle[2] == 'W') || (word5[0] == wordle[1] && wordle[1] == 'W') || (word5[0] == wordle[2] && wordle[2] == 'W') || (word5[0] == wordle[3] && wordle[3] == 'W') || (word5[0] == wordle[4] && wordle[4] == 'W') || (word5[1] == wordle[0] && wordle[0] == 'W') || (word5[1] == wordle[2] && wordle[2] == 'W') || (word5[1] == wordle[3] && wordle[3] == 'W') || (word5[1] == wordle[4] && wordle[4] == 'W') || (word5[2] == wordle[1] && wordle[1] == 'W') || (word5[2] == wordle[0] && wordle[0] == 'W') || (word5[2] == wordle[3] && wordle[3] == 'W') || (word5[2] == wordle[4] && wordle[4] == 'W') || (word5[3] == wordle[1] && wordle[1] == 'W') || (word5[3] == wordle[0] && wordle[0] == 'W') || (word5[3] == wordle[2] && wordle[2] == 'W') || (word5[3] == wordle[4] && wordle[4] == 'W') || (word5[4] == wordle[1] && wordle[1] == 'W') || (word5[4] == wordle[0] && wordle[0] == 'W') || (word5[4] == wordle[3] && wordle[3] == 'W') || (word5[4] == wordle[2] && wordle[2] == 'W') || (word6[0] == wordle[1] && wordle[1] == 'W') || (word6[0] == wordle[2] && wordle[2] == 'W') || (word6[0] == wordle[3] && wordle[3] == 'W') || (word6[0] == wordle[4] && wordle[4] == 'W') || (word6[1] == wordle[0] && wordle[0] == 'W') || (word6[1] == wordle[2] && wordle[2] == 'W') || (word6[1] == wordle[3] && wordle[3] == 'W') || (word6[1] == wordle[4] && wordle[4] == 'W') || (word6[2] == wordle[1] && wordle[1] == 'W') || (word6[2] == wordle[0] && wordle[0] == 'W') || (word6[2] == wordle[3] && wordle[3] == 'W') || (word6[2] == wordle[4] && wordle[4] == 'W') || (word6[3] == wordle[1] && wordle[1] == 'W') || (word6[3] == wordle[0] && wordle[0] == 'W') || (word6[3] == wordle[2] && wordle[2] == 'W') || (word6[3] == wordle[4] && wordle[4] == 'W') || (word6[4] == wordle[1] && wordle[1] == 'W') || (word6[4] == wordle[0] && wordle[0] == 'W') || (word6[4] == wordle[3] && wordle[3] == 'W') || (word6[4] == wordle[2] && wordle[2] == 'W'))
  {
    c2();
    cout << " W ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'W') || (word1[0] != wordle[2] && word1[0] == 'W') || (word1[0] != wordle[3] && word1[0] == 'W') || (word1[0] != wordle[4] && word1[0] == 'W') || (word1[1] != wordle[0] && word1[1] == 'W') || (word1[1] != wordle[2] && word1[1] == 'W') || (word1[1] != wordle[3] && word1[1] == 'W') || (word1[1] != wordle[4] && word1[1] == 'W') || (word1[2] != wordle[1] && word1[2] == 'W') || (word1[2] != wordle[0] && word1[2] == 'W') || (word1[2] != wordle[3] && word1[2] == 'W') || (word1[2] != wordle[4] && word1[2] == 'W') || (word1[3] != wordle[1] && word1[3] == 'W') || (word1[3] != wordle[2] && word1[3] == 'W') || (word1[3] != wordle[0] && word1[3] == 'W') || (word1[3] != wordle[4] && word1[3] == 'W') || (word1[4] != wordle[1] && word1[4] == 'W') || (word1[4] != wordle[2] && word1[4] == 'W') || (word1[4] != wordle[3] && word1[4] == 'W') || (word1[4] != wordle[0] && word1[4] == 'W') || (word2[0] != wordle[1] && word2[0] == 'W') || (word2[0] != wordle[2] && word2[0] == 'W') || (word2[0] != wordle[3] && word2[0] == 'W') || (word2[0] != wordle[4] && word2[0] == 'W') || (word2[1] != wordle[0] && word2[1] == 'W') || (word2[1] != wordle[2] && word2[1] == 'W') || (word2[1] != wordle[3] && word2[1] == 'W') || (word2[1] != wordle[4] && word2[1] == 'W') || (word2[2] != wordle[1] && word2[2] == 'W') || (word2[2] != wordle[0] && word2[2] == 'W') || (word2[2] != wordle[3] && word2[2] == 'W') || (word2[2] != wordle[4] && word2[2] == 'W') || (word2[3] != wordle[1] && word2[3] == 'W') || (word2[3] != wordle[2] && word2[3] == 'W') || (word2[3] != wordle[0] && word2[3] == 'W') || (word2[3] != wordle[4] && word2[3] == 'W') || (word2[4] != wordle[1] && word2[4] == 'W') || (word2[4] != wordle[2] && word2[4] == 'W') || (word2[4] != wordle[3] && word2[4] == 'W') || (word2[4] != wordle[0] && word2[4] == 'W') || (word3[0] != wordle[1] && word3[0] == 'W') || (word3[0] != wordle[2] && word3[0] == 'W') || (word3[0] != wordle[3] && word3[0] == 'W') || (word3[0] != wordle[4] && word3[0] == 'W') || (word3[1] != wordle[0] && word3[1] == 'W') || (word3[1] != wordle[2] && word3[1] == 'W') || (word3[1] != wordle[3] && word3[1] == 'W') || (word3[1] != wordle[4] && word3[1] == 'W') || (word3[2] != wordle[1] && word3[2] == 'W') || (word3[2] != wordle[0] && word3[2] == 'W') || (word3[2] != wordle[3] && word3[2] == 'W') || (word3[2] != wordle[4] && word3[2] == 'W') || (word3[3] != wordle[1] && word3[3] == 'W') || (word3[3] != wordle[2] && word3[3] == 'W') || (word3[3] != wordle[0] && word3[3] == 'W') || (word3[3] != wordle[4] && word3[3] == 'W') || (word3[4] != wordle[1] && word3[4] == 'W') || (word3[4] != wordle[2] && word3[4] == 'W') || (word3[4] != wordle[3] && word3[4] == 'W') || (word3[4] != wordle[0] && word3[4] == 'W') || (word4[0] != wordle[1] && word4[0] == 'W') || (word4[0] != wordle[2] && word4[0] == 'W') || (word4[0] != wordle[3] && word4[0] == 'W') || (word4[0] != wordle[4] && word4[0] == 'W') || (word4[1] != wordle[0] && word4[1] == 'W') || (word4[1] != wordle[2] && word4[1] == 'W') || (word4[1] != wordle[3] && word4[1] == 'W') || (word4[1] != wordle[4] && word4[1] == 'W') || (word4[2] != wordle[1] && word4[2] == 'W') || (word4[2] != wordle[0] && word4[2] == 'W') || (word4[2] != wordle[3] && word4[2] == 'W') || (word4[2] != wordle[4] && word4[2] == 'W') || (word4[3] != wordle[1] && word4[3] == 'W') || (word4[3] != wordle[2] && word4[3] == 'W') || (word4[3] != wordle[0] && word4[3] == 'W') || (word4[3] != wordle[4] && word4[3] == 'W') || (word4[4] != wordle[1] && word4[4] == 'W') || (word4[4] != wordle[2] && word4[4] == 'W') || (word4[4] != wordle[3] && word4[4] == 'W') || (word4[4] != wordle[0] && word4[4] == 'W') || (word5[0] != wordle[1] && word5[0] == 'W') || (word5[0] != wordle[2] && word5[0] == 'W') || (word5[0] != wordle[3] && word5[0] == 'W') || (word5[0] != wordle[4] && word5[0] == 'W') || (word5[1] != wordle[0] && word5[1] == 'W') || (word5[1] != wordle[2] && word5[1] == 'W') || (word5[1] != wordle[3] && word5[1] == 'W') || (word5[1] != wordle[4] && word5[1] == 'W') || (word5[2] != wordle[1] && word5[2] == 'W') || (word5[2] != wordle[0] && word5[2] == 'W') || (word5[2] != wordle[3] && word5[2] == 'W') || (word5[2] != wordle[4] && word5[2] == 'W') || (word5[3] != wordle[1] && word5[3] == 'W') || (word5[3] != wordle[2] && word5[3] == 'W') || (word5[3] != wordle[0] && word5[3] == 'W') || (word5[3] != wordle[4] && word5[3] == 'W') || (word5[4] != wordle[1] && word5[4] == 'W') || (word5[4] != wordle[2] && word5[4] == 'W') || (word5[4] != wordle[3] && word5[4] == 'W') || (word5[4] != wordle[0] && word5[4] == 'W') || (word6[0] != wordle[1] && word6[0] == 'W') || (word6[0] != wordle[2] && word6[0] == 'W') || (word6[0] != wordle[3] && word6[0] == 'W') || (word6[0] != wordle[4] && word6[0] == 'W') || (word6[1] != wordle[0] && word6[1] == 'W') || (word6[1] != wordle[2] && word6[1] == 'W') || (word6[1] != wordle[3] && word6[1] == 'W') || (word6[1] != wordle[4] && word6[1] == 'W') || (word6[2] != wordle[1] && word6[2] == 'W') || (word6[2] != wordle[0] && word6[2] == 'W') || (word6[2] != wordle[3] && word6[2] == 'W') || (word6[2] != wordle[4] && word6[2] == 'W') || (word6[3] != wordle[1] && word6[3] == 'W') || (word6[3] != wordle[2] && word6[3] == 'W') || (word6[3] != wordle[0] && word6[3] == 'W') || (word6[3] != wordle[4] && word6[3] == 'W') || (word6[4] != wordle[1] && word6[4] == 'W') || (word6[4] != wordle[2] && word6[4] == 'W') || (word6[4] != wordle[3] && word6[4] == 'W') || (word6[4] != wordle[0] && word6[4] == 'W'))
  {
    c3();
    cout << " W ";
    cout << RESET;
  }
  else 
  {
    cout << " W ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'E') || (word1[1] == wordle[1] && word1[1] == 'E') || (word1[2] == wordle[2] && word1[2] == 'E') || (word1[3] == wordle[3] && word1[3] == 'E') || (word1[4] == wordle[4] && word1[4] == 'E') || (word2[0] == wordle[0] && word2[0] == 'E') || (word2[1] == wordle[1] && word2[1] == 'E') || (word2[2] == wordle[2] && word2[2] == 'E') || (word2[3] == wordle[3] && word2[3] == 'E') || (word2[4] == wordle[4] && word2[4] == 'E') || (word3[0] == wordle[0] && word3[0] == 'E') || (word3[1] == wordle[1] && word3[1] == 'E') || (word3[2] == wordle[2] && word3[2] == 'E') || (word3[3] == wordle[3] && word3[3] == 'E') || (word3[4] == wordle[4] && word3[4] == 'E') || (word4[0] == wordle[0] && word4[0] == 'E') || (word4[1] == wordle[1] && word4[1] == 'E') || (word4[2] == wordle[2] && word4[2] == 'E') || (word4[3] == wordle[3] && word4[3] == 'E') || (word4[4] == wordle[4] && word4[4] == 'E') || (word5[0] == wordle[0] && word5[0] == 'E') || (word5[1] == wordle[1] && word5[1] == 'E') || (word5[2] == wordle[2] && word5[2] == 'E') || (word5[3] == wordle[3] && word5[3] == 'E') || (word5[4] == wordle[4] && word5[4] == 'E') || (word6[0] == wordle[0] && word6[0] == 'E') || (word6[1] == wordle[1] && word6[1] == 'E') || (word6[2] == wordle[2] && word6[2] == 'E') || (word6[3] == wordle[3] && word6[3] == 'E') || (word6[4] == wordle[4] && word6[4] == 'E'))
  {
    c1();
    cout << " E ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'E') || (word1[0] == wordle[2] && wordle[2] == 'E') || (word1[0] == wordle[3] && wordle[3] == 'E') || (word1[0] == wordle[4] && wordle[4] == 'E') || (word1[1] == wordle[0] && wordle[0] == 'E') || (word1[1] == wordle[2] && wordle[2] == 'E') || (word1[1] == wordle[3] && wordle[3] == 'E') || (word1[1] == wordle[4] && wordle[4] == 'E') || (word1[2] == wordle[1] && wordle[1] == 'E') || (word1[2] == wordle[0] && wordle[0] == 'E') || (word1[2] == wordle[3] && wordle[3] == 'E') || (word1[2] == wordle[4] && wordle[4] == 'E') || (word1[3] == wordle[1] && wordle[1] == 'E') || (word1[3] == wordle[0] && wordle[0] == 'E') || (word1[3] == wordle[2] && wordle[2] == 'E') || (word1[3] == wordle[4] && wordle[4] == 'E') || (word1[4] == wordle[1] && wordle[1] == 'E') || (word1[4] == wordle[0] && wordle[0] == 'E') || (word1[4] == wordle[3] && wordle[3] == 'E') || (word1[4] == wordle[2] && wordle[2] == 'E') || (word2[0] == wordle[1] && wordle[1] == 'E') || (word2[0] == wordle[2] && wordle[2] == 'E') || (word2[0] == wordle[3] && wordle[3] == 'E') || (word2[0] == wordle[4] && wordle[4] == 'E') || (word2[1] == wordle[0] && wordle[0] == 'E') || (word2[1] == wordle[2] && wordle[2] == 'E') || (word2[1] == wordle[3] && wordle[3] == 'E') || (word2[1] == wordle[4] && wordle[4] == 'E') || (word2[2] == wordle[1] && wordle[1] == 'E') || (word2[2] == wordle[0] && wordle[0] == 'E') || (word2[2] == wordle[3] && wordle[3] == 'E') || (word2[2] == wordle[4] && wordle[4] == 'E') || (word2[3] == wordle[1] && wordle[1] == 'E') || (word2[3] == wordle[0] && wordle[0] == 'E') || (word2[3] == wordle[2] && wordle[2] == 'E') || (word2[3] == wordle[4] && wordle[4] == 'E') || (word2[4] == wordle[1] && wordle[1] == 'E') || (word2[4] == wordle[0] && wordle[0] == 'E') || (word2[4] == wordle[3] && wordle[3] == 'E') || (word2[4] == wordle[2] && wordle[2] == 'E') || (word3[0] == wordle[1] && wordle[1] == 'E') || (word3[0] == wordle[2] && wordle[2] == 'E') || (word3[0] == wordle[3] && wordle[3] == 'E') || (word3[0] == wordle[4] && wordle[4] == 'E') || (word3[1] == wordle[0] && wordle[0] == 'E') || (word3[1] == wordle[2] && wordle[2] == 'E') || (word3[1] == wordle[3] && wordle[3] == 'E') || (word3[1] == wordle[4] && wordle[4] == 'E') || (word3[2] == wordle[1] && wordle[1] == 'E') || (word3[2] == wordle[0] && wordle[0] == 'E') || (word3[2] == wordle[3] && wordle[3] == 'E') || (word3[2] == wordle[4] && wordle[4] == 'E') || (word3[3] == wordle[1] && wordle[1] == 'E') || (word3[3] == wordle[0] && wordle[0] == 'E') || (word3[3] == wordle[2] && wordle[2] == 'E') || (word3[3] == wordle[4] && wordle[4] == 'E') || (word3[4] == wordle[1] && wordle[1] == 'E') || (word3[4] == wordle[0] && wordle[0] == 'E') || (word3[4] == wordle[3] && wordle[3] == 'E') || (word3[4] == wordle[2] && wordle[2] == 'E') || (word4[0] == wordle[1] && wordle[1] == 'E') || (word4[0] == wordle[2] && wordle[2] == 'E') || (word4[0] == wordle[3] && wordle[3] == 'E') || (word4[0] == wordle[4] && wordle[4] == 'E') || (word4[1] == wordle[0] && wordle[0] == 'E') || (word4[1] == wordle[2] && wordle[2] == 'E') || (word4[1] == wordle[3] && wordle[3] == 'E') || (word4[1] == wordle[4] && wordle[4] == 'E') || (word4[2] == wordle[1] && wordle[1] == 'E') || (word4[2] == wordle[0] && wordle[0] == 'E') || (word4[2] == wordle[3] && wordle[3] == 'E') || (word4[2] == wordle[4] && wordle[4] == 'E') || (word4[3] == wordle[1] && wordle[1] == 'E') || (word4[3] == wordle[0] && wordle[0] == 'E') || (word4[3] == wordle[2] && wordle[2] == 'E') || (word4[3] == wordle[4] && wordle[4] == 'E') || (word4[4] == wordle[1] && wordle[1] == 'E') || (word4[4] == wordle[0] && wordle[0] == 'E') || (word4[4] == wordle[3] && wordle[3] == 'E') || (word4[4] == wordle[2] && wordle[2] == 'E') || (word5[0] == wordle[1] && wordle[1] == 'E') || (word5[0] == wordle[2] && wordle[2] == 'E') || (word5[0] == wordle[3] && wordle[3] == 'E') || (word5[0] == wordle[4] && wordle[4] == 'E') || (word5[1] == wordle[0] && wordle[0] == 'E') || (word5[1] == wordle[2] && wordle[2] == 'E') || (word5[1] == wordle[3] && wordle[3] == 'E') || (word5[1] == wordle[4] && wordle[4] == 'E') || (word5[2] == wordle[1] && wordle[1] == 'E') || (word5[2] == wordle[0] && wordle[0] == 'E') || (word5[2] == wordle[3] && wordle[3] == 'E') || (word5[2] == wordle[4] && wordle[4] == 'E') || (word5[3] == wordle[1] && wordle[1] == 'E') || (word5[3] == wordle[0] && wordle[0] == 'E') || (word5[3] == wordle[2] && wordle[2] == 'E') || (word5[3] == wordle[4] && wordle[4] == 'E') || (word5[4] == wordle[1] && wordle[1] == 'E') || (word5[4] == wordle[0] && wordle[0] == 'E') || (word5[4] == wordle[3] && wordle[3] == 'E') || (word5[4] == wordle[2] && wordle[2] == 'E') || (word6[0] == wordle[1] && wordle[1] == 'E') || (word6[0] == wordle[2] && wordle[2] == 'E') || (word6[0] == wordle[3] && wordle[3] == 'E') || (word6[0] == wordle[4] && wordle[4] == 'E') || (word6[1] == wordle[0] && wordle[0] == 'E') || (word6[1] == wordle[2] && wordle[2] == 'E') || (word6[1] == wordle[3] && wordle[3] == 'E') || (word6[1] == wordle[4] && wordle[4] == 'E') || (word6[2] == wordle[1] && wordle[1] == 'E') || (word6[2] == wordle[0] && wordle[0] == 'E') || (word6[2] == wordle[3] && wordle[3] == 'E') || (word6[2] == wordle[4] && wordle[4] == 'E') || (word6[3] == wordle[1] && wordle[1] == 'E') || (word6[3] == wordle[0] && wordle[0] == 'E') || (word6[3] == wordle[2] && wordle[2] == 'E') || (word6[3] == wordle[4] && wordle[4] == 'E') || (word6[4] == wordle[1] && wordle[1] == 'E') || (word6[4] == wordle[0] && wordle[0] == 'E') || (word6[4] == wordle[3] && wordle[3] == 'E') || (word6[4] == wordle[2] && wordle[2] == 'E'))
  {
    c2();
    cout << " E ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'E') || (word1[0] != wordle[2] && word1[0] == 'E') || (word1[0] != wordle[3] && word1[0] == 'E') || (word1[0] != wordle[4] && word1[0] == 'E') || (word1[1] != wordle[0] && word1[1] == 'E') || (word1[1] != wordle[2] && word1[1] == 'E') || (word1[1] != wordle[3] && word1[1] == 'E') || (word1[1] != wordle[4] && word1[1] == 'E') || (word1[2] != wordle[1] && word1[2] == 'E') || (word1[2] != wordle[0] && word1[2] == 'E') || (word1[2] != wordle[3] && word1[2] == 'E') || (word1[2] != wordle[4] && word1[2] == 'E') || (word1[3] != wordle[1] && word1[3] == 'E') || (word1[3] != wordle[2] && word1[3] == 'E') || (word1[3] != wordle[0] && word1[3] == 'E') || (word1[3] != wordle[4] && word1[3] == 'E') || (word1[4] != wordle[1] && word1[4] == 'E') || (word1[4] != wordle[2] && word1[4] == 'E') || (word1[4] != wordle[3] && word1[4] == 'E') || (word1[4] != wordle[0] && word1[4] == 'E') || (word2[0] != wordle[1] && word2[0] == 'E') || (word2[0] != wordle[2] && word2[0] == 'E') || (word2[0] != wordle[3] && word2[0] == 'E') || (word2[0] != wordle[4] && word2[0] == 'E') || (word2[1] != wordle[0] && word2[1] == 'E') || (word2[1] != wordle[2] && word2[1] == 'E') || (word2[1] != wordle[3] && word2[1] == 'E') || (word2[1] != wordle[4] && word2[1] == 'E') || (word2[2] != wordle[1] && word2[2] == 'E') || (word2[2] != wordle[0] && word2[2] == 'E') || (word2[2] != wordle[3] && word2[2] == 'E') || (word2[2] != wordle[4] && word2[2] == 'E') || (word2[3] != wordle[1] && word2[3] == 'E') || (word2[3] != wordle[2] && word2[3] == 'E') || (word2[3] != wordle[0] && word2[3] == 'E') || (word2[3] != wordle[4] && word2[3] == 'E') || (word2[4] != wordle[1] && word2[4] == 'E') || (word2[4] != wordle[2] && word2[4] == 'E') || (word2[4] != wordle[3] && word2[4] == 'E') || (word2[4] != wordle[0] && word2[4] == 'E') || (word3[0] != wordle[1] && word3[0] == 'E') || (word3[0] != wordle[2] && word3[0] == 'E') || (word3[0] != wordle[3] && word3[0] == 'E') || (word3[0] != wordle[4] && word3[0] == 'E') || (word3[1] != wordle[0] && word3[1] == 'E') || (word3[1] != wordle[2] && word3[1] == 'E') || (word3[1] != wordle[3] && word3[1] == 'E') || (word3[1] != wordle[4] && word3[1] == 'E') || (word3[2] != wordle[1] && word3[2] == 'E') || (word3[2] != wordle[0] && word3[2] == 'E') || (word3[2] != wordle[3] && word3[2] == 'E') || (word3[2] != wordle[4] && word3[2] == 'E') || (word3[3] != wordle[1] && word3[3] == 'E') || (word3[3] != wordle[2] && word3[3] == 'E') || (word3[3] != wordle[0] && word3[3] == 'E') || (word3[3] != wordle[4] && word3[3] == 'E') || (word3[4] != wordle[1] && word3[4] == 'E') || (word3[4] != wordle[2] && word3[4] == 'E') || (word3[4] != wordle[3] && word3[4] == 'E') || (word3[4] != wordle[0] && word3[4] == 'E') || (word4[0] != wordle[1] && word4[0] == 'E') || (word4[0] != wordle[2] && word4[0] == 'E') || (word4[0] != wordle[3] && word4[0] == 'E') || (word4[0] != wordle[4] && word4[0] == 'E') || (word4[1] != wordle[0] && word4[1] == 'E') || (word4[1] != wordle[2] && word4[1] == 'E') || (word4[1] != wordle[3] && word4[1] == 'E') || (word4[1] != wordle[4] && word4[1] == 'E') || (word4[2] != wordle[1] && word4[2] == 'E') || (word4[2] != wordle[0] && word4[2] == 'E') || (word4[2] != wordle[3] && word4[2] == 'E') || (word4[2] != wordle[4] && word4[2] == 'E') || (word4[3] != wordle[1] && word4[3] == 'E') || (word4[3] != wordle[2] && word4[3] == 'E') || (word4[3] != wordle[0] && word4[3] == 'E') || (word4[3] != wordle[4] && word4[3] == 'E') || (word4[4] != wordle[1] && word4[4] == 'E') || (word4[4] != wordle[2] && word4[4] == 'E') || (word4[4] != wordle[3] && word4[4] == 'E') || (word4[4] != wordle[0] && word4[4] == 'E') || (word5[0] != wordle[1] && word5[0] == 'E') || (word5[0] != wordle[2] && word5[0] == 'E') || (word5[0] != wordle[3] && word5[0] == 'E') || (word5[0] != wordle[4] && word5[0] == 'E') || (word5[1] != wordle[0] && word5[1] == 'E') || (word5[1] != wordle[2] && word5[1] == 'E') || (word5[1] != wordle[3] && word5[1] == 'E') || (word5[1] != wordle[4] && word5[1] == 'E') || (word5[2] != wordle[1] && word5[2] == 'E') || (word5[2] != wordle[0] && word5[2] == 'E') || (word5[2] != wordle[3] && word5[2] == 'E') || (word5[2] != wordle[4] && word5[2] == 'E') || (word5[3] != wordle[1] && word5[3] == 'E') || (word5[3] != wordle[2] && word5[3] == 'E') || (word5[3] != wordle[0] && word5[3] == 'E') || (word5[3] != wordle[4] && word5[3] == 'E') || (word5[4] != wordle[1] && word5[4] == 'E') || (word5[4] != wordle[2] && word5[4] == 'E') || (word5[4] != wordle[3] && word5[4] == 'E') || (word5[4] != wordle[0] && word5[4] == 'E') || (word6[0] != wordle[1] && word6[0] == 'E') || (word6[0] != wordle[2] && word6[0] == 'E') || (word6[0] != wordle[3] && word6[0] == 'E') || (word6[0] != wordle[4] && word6[0] == 'E') || (word6[1] != wordle[0] && word6[1] == 'E') || (word6[1] != wordle[2] && word6[1] == 'E') || (word6[1] != wordle[3] && word6[1] == 'E') || (word6[1] != wordle[4] && word6[1] == 'E') || (word6[2] != wordle[1] && word6[2] == 'E') || (word6[2] != wordle[0] && word6[2] == 'E') || (word6[2] != wordle[3] && word6[2] == 'E') || (word6[2] != wordle[4] && word6[2] == 'E') || (word6[3] != wordle[1] && word6[3] == 'E') || (word6[3] != wordle[2] && word6[3] == 'E') || (word6[3] != wordle[0] && word6[3] == 'E') || (word6[3] != wordle[4] && word6[3] == 'E') || (word6[4] != wordle[1] && word6[4] == 'E') || (word6[4] != wordle[2] && word6[4] == 'E') || (word6[4] != wordle[3] && word6[4] == 'E') || (word6[4] != wordle[0] && word6[4] == 'E'))
  {
    c3();
    cout << " E ";
    cout << RESET;
  }
  else 
  {
    cout << " E ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'R') || (word1[1] == wordle[1] && word1[1] == 'R') || (word1[2] == wordle[2] && word1[2] == 'R') || (word1[3] == wordle[3] && word1[3] == 'R') || (word1[4] == wordle[4] && word1[4] == 'R') || (word2[0] == wordle[0] && word2[0] == 'R') || (word2[1] == wordle[1] && word2[1] == 'R') || (word2[2] == wordle[2] && word2[2] == 'R') || (word2[3] == wordle[3] && word2[3] == 'R') || (word2[4] == wordle[4] && word2[4] == 'R') || (word3[0] == wordle[0] && word3[0] == 'R') || (word3[1] == wordle[1] && word3[1] == 'R') || (word3[2] == wordle[2] && word3[2] == 'R') || (word3[3] == wordle[3] && word3[3] == 'R') || (word3[4] == wordle[4] && word3[4] == 'R') || (word4[0] == wordle[0] && word4[0] == 'R') || (word4[1] == wordle[1] && word4[1] == 'R') || (word4[2] == wordle[2] && word4[2] == 'R') || (word4[3] == wordle[3] && word4[3] == 'R') || (word4[4] == wordle[4] && word4[4] == 'R') || (word5[0] == wordle[0] && word5[0] == 'R') || (word5[1] == wordle[1] && word5[1] == 'R') || (word5[2] == wordle[2] && word5[2] == 'R') || (word5[3] == wordle[3] && word5[3] == 'R') || (word5[4] == wordle[4] && word5[4] == 'R') || (word6[0] == wordle[0] && word6[0] == 'R') || (word6[1] == wordle[1] && word6[1] == 'R') || (word6[2] == wordle[2] && word6[2] == 'R') || (word6[3] == wordle[3] && word6[3] == 'R') || (word6[4] == wordle[4] && word6[4] == 'R'))
  {
    c1();
    cout << " R ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'R') || (word1[0] == wordle[2] && wordle[2] == 'R') || (word1[0] == wordle[3] && wordle[3] == 'R') || (word1[0] == wordle[4] && wordle[4] == 'R') || (word1[1] == wordle[0] && wordle[0] == 'R') || (word1[1] == wordle[2] && wordle[2] == 'R') || (word1[1] == wordle[3] && wordle[3] == 'R') || (word1[1] == wordle[4] && wordle[4] == 'R') || (word1[2] == wordle[1] && wordle[1] == 'R') || (word1[2] == wordle[0] && wordle[0] == 'R') || (word1[2] == wordle[3] && wordle[3] == 'R') || (word1[2] == wordle[4] && wordle[4] == 'R') || (word1[3] == wordle[1] && wordle[1] == 'R') || (word1[3] == wordle[0] && wordle[0] == 'R') || (word1[3] == wordle[2] && wordle[2] == 'R') || (word1[3] == wordle[4] && wordle[4] == 'R') || (word1[4] == wordle[1] && wordle[1] == 'R') || (word1[4] == wordle[0] && wordle[0] == 'R') || (word1[4] == wordle[3] && wordle[3] == 'R') || (word1[4] == wordle[2] && wordle[2] == 'R') || (word2[0] == wordle[1] && wordle[1] == 'R') || (word2[0] == wordle[2] && wordle[2] == 'R') || (word2[0] == wordle[3] && wordle[3] == 'R') || (word2[0] == wordle[4] && wordle[4] == 'R') || (word2[1] == wordle[0] && wordle[0] == 'R') || (word2[1] == wordle[2] && wordle[2] == 'R') || (word2[1] == wordle[3] && wordle[3] == 'R') || (word2[1] == wordle[4] && wordle[4] == 'R') || (word2[2] == wordle[1] && wordle[1] == 'R') || (word2[2] == wordle[0] && wordle[0] == 'R') || (word2[2] == wordle[3] && wordle[3] == 'R') || (word2[2] == wordle[4] && wordle[4] == 'R') || (word2[3] == wordle[1] && wordle[1] == 'R') || (word2[3] == wordle[0] && wordle[0] == 'R') || (word2[3] == wordle[2] && wordle[2] == 'R') || (word2[3] == wordle[4] && wordle[4] == 'R') || (word2[4] == wordle[1] && wordle[1] == 'R') || (word2[4] == wordle[0] && wordle[0] == 'R') || (word2[4] == wordle[3] && wordle[3] == 'R') || (word2[4] == wordle[2] && wordle[2] == 'R') || (word3[0] == wordle[1] && wordle[1] == 'R') || (word3[0] == wordle[2] && wordle[2] == 'R') || (word3[0] == wordle[3] && wordle[3] == 'R') || (word3[0] == wordle[4] && wordle[4] == 'R') || (word3[1] == wordle[0] && wordle[0] == 'R') || (word3[1] == wordle[2] && wordle[2] == 'R') || (word3[1] == wordle[3] && wordle[3] == 'R') || (word3[1] == wordle[4] && wordle[4] == 'R') || (word3[2] == wordle[1] && wordle[1] == 'R') || (word3[2] == wordle[0] && wordle[0] == 'R') || (word3[2] == wordle[3] && wordle[3] == 'R') || (word3[2] == wordle[4] && wordle[4] == 'R') || (word3[3] == wordle[1] && wordle[1] == 'R') || (word3[3] == wordle[0] && wordle[0] == 'R') || (word3[3] == wordle[2] && wordle[2] == 'R') || (word3[3] == wordle[4] && wordle[4] == 'R') || (word3[4] == wordle[1] && wordle[1] == 'R') || (word3[4] == wordle[0] && wordle[0] == 'R') || (word3[4] == wordle[3] && wordle[3] == 'R') || (word3[4] == wordle[2] && wordle[2] == 'R') || (word4[0] == wordle[1] && wordle[1] == 'R') || (word4[0] == wordle[2] && wordle[2] == 'R') || (word4[0] == wordle[3] && wordle[3] == 'R') || (word4[0] == wordle[4] && wordle[4] == 'R') || (word4[1] == wordle[0] && wordle[0] == 'R') || (word4[1] == wordle[2] && wordle[2] == 'R') || (word4[1] == wordle[3] && wordle[3] == 'R') || (word4[1] == wordle[4] && wordle[4] == 'R') || (word4[2] == wordle[1] && wordle[1] == 'R') || (word4[2] == wordle[0] && wordle[0] == 'R') || (word4[2] == wordle[3] && wordle[3] == 'R') || (word4[2] == wordle[4] && wordle[4] == 'R') || (word4[3] == wordle[1] && wordle[1] == 'R') || (word4[3] == wordle[0] && wordle[0] == 'R') || (word4[3] == wordle[2] && wordle[2] == 'R') || (word4[3] == wordle[4] && wordle[4] == 'R') || (word4[4] == wordle[1] && wordle[1] == 'R') || (word4[4] == wordle[0] && wordle[0] == 'R') || (word4[4] == wordle[3] && wordle[3] == 'R') || (word4[4] == wordle[2] && wordle[2] == 'R') || (word5[0] == wordle[1] && wordle[1] == 'R') || (word5[0] == wordle[2] && wordle[2] == 'R') || (word5[0] == wordle[3] && wordle[3] == 'R') || (word5[0] == wordle[4] && wordle[4] == 'R') || (word5[1] == wordle[0] && wordle[0] == 'R') || (word5[1] == wordle[2] && wordle[2] == 'R') || (word5[1] == wordle[3] && wordle[3] == 'R') || (word5[1] == wordle[4] && wordle[4] == 'R') || (word5[2] == wordle[1] && wordle[1] == 'R') || (word5[2] == wordle[0] && wordle[0] == 'R') || (word5[2] == wordle[3] && wordle[3] == 'R') || (word5[2] == wordle[4] && wordle[4] == 'R') || (word5[3] == wordle[1] && wordle[1] == 'R') || (word5[3] == wordle[0] && wordle[0] == 'R') || (word5[3] == wordle[2] && wordle[2] == 'R') || (word5[3] == wordle[4] && wordle[4] == 'R') || (word5[4] == wordle[1] && wordle[1] == 'R') || (word5[4] == wordle[0] && wordle[0] == 'R') || (word5[4] == wordle[3] && wordle[3] == 'R') || (word5[4] == wordle[2] && wordle[2] == 'R') || (word6[0] == wordle[1] && wordle[1] == 'R') || (word6[0] == wordle[2] && wordle[2] == 'R') || (word6[0] == wordle[3] && wordle[3] == 'R') || (word6[0] == wordle[4] && wordle[4] == 'R') || (word6[1] == wordle[0] && wordle[0] == 'R') || (word6[1] == wordle[2] && wordle[2] == 'R') || (word6[1] == wordle[3] && wordle[3] == 'R') || (word6[1] == wordle[4] && wordle[4] == 'R') || (word6[2] == wordle[1] && wordle[1] == 'R') || (word6[2] == wordle[0] && wordle[0] == 'R') || (word6[2] == wordle[3] && wordle[3] == 'R') || (word6[2] == wordle[4] && wordle[4] == 'R') || (word6[3] == wordle[1] && wordle[1] == 'R') || (word6[3] == wordle[0] && wordle[0] == 'R') || (word6[3] == wordle[2] && wordle[2] == 'R') || (word6[3] == wordle[4] && wordle[4] == 'R') || (word6[4] == wordle[1] && wordle[1] == 'R') || (word6[4] == wordle[0] && wordle[0] == 'R') || (word6[4] == wordle[3] && wordle[3] == 'R') || (word6[4] == wordle[2] && wordle[2] == 'R'))
  {
    c2();
    cout << " R ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'R') || (word1[0] != wordle[2] && word1[0] == 'R') || (word1[0] != wordle[3] && word1[0] == 'R') || (word1[0] != wordle[4] && word1[0] == 'R') || (word1[1] != wordle[0] && word1[1] == 'R') || (word1[1] != wordle[2] && word1[1] == 'R') || (word1[1] != wordle[3] && word1[1] == 'R') || (word1[1] != wordle[4] && word1[1] == 'R') || (word1[2] != wordle[1] && word1[2] == 'R') || (word1[2] != wordle[0] && word1[2] == 'R') || (word1[2] != wordle[3] && word1[2] == 'R') || (word1[2] != wordle[4] && word1[2] == 'R') || (word1[3] != wordle[1] && word1[3] == 'R') || (word1[3] != wordle[2] && word1[3] == 'R') || (word1[3] != wordle[0] && word1[3] == 'R') || (word1[3] != wordle[4] && word1[3] == 'R') || (word1[4] != wordle[1] && word1[4] == 'R') || (word1[4] != wordle[2] && word1[4] == 'R') || (word1[4] != wordle[3] && word1[4] == 'R') || (word1[4] != wordle[0] && word1[4] == 'R') || (word2[0] != wordle[1] && word2[0] == 'R') || (word2[0] != wordle[2] && word2[0] == 'R') || (word2[0] != wordle[3] && word2[0] == 'R') || (word2[0] != wordle[4] && word2[0] == 'R') || (word2[1] != wordle[0] && word2[1] == 'R') || (word2[1] != wordle[2] && word2[1] == 'R') || (word2[1] != wordle[3] && word2[1] == 'R') || (word2[1] != wordle[4] && word2[1] == 'R') || (word2[2] != wordle[1] && word2[2] == 'R') || (word2[2] != wordle[0] && word2[2] == 'R') || (word2[2] != wordle[3] && word2[2] == 'R') || (word2[2] != wordle[4] && word2[2] == 'R') || (word2[3] != wordle[1] && word2[3] == 'R') || (word2[3] != wordle[2] && word2[3] == 'R') || (word2[3] != wordle[0] && word2[3] == 'R') || (word2[3] != wordle[4] && word2[3] == 'R') || (word2[4] != wordle[1] && word2[4] == 'R') || (word2[4] != wordle[2] && word2[4] == 'R') || (word2[4] != wordle[3] && word2[4] == 'R') || (word2[4] != wordle[0] && word2[4] == 'R') || (word3[0] != wordle[1] && word3[0] == 'R') || (word3[0] != wordle[2] && word3[0] == 'R') || (word3[0] != wordle[3] && word3[0] == 'R') || (word3[0] != wordle[4] && word3[0] == 'R') || (word3[1] != wordle[0] && word3[1] == 'R') || (word3[1] != wordle[2] && word3[1] == 'R') || (word3[1] != wordle[3] && word3[1] == 'R') || (word3[1] != wordle[4] && word3[1] == 'R') || (word3[2] != wordle[1] && word3[2] == 'R') || (word3[2] != wordle[0] && word3[2] == 'R') || (word3[2] != wordle[3] && word3[2] == 'R') || (word3[2] != wordle[4] && word3[2] == 'R') || (word3[3] != wordle[1] && word3[3] == 'R') || (word3[3] != wordle[2] && word3[3] == 'R') || (word3[3] != wordle[0] && word3[3] == 'R') || (word3[3] != wordle[4] && word3[3] == 'R') || (word3[4] != wordle[1] && word3[4] == 'R') || (word3[4] != wordle[2] && word3[4] == 'R') || (word3[4] != wordle[3] && word3[4] == 'R') || (word3[4] != wordle[0] && word3[4] == 'R') || (word4[0] != wordle[1] && word4[0] == 'R') || (word4[0] != wordle[2] && word4[0] == 'R') || (word4[0] != wordle[3] && word4[0] == 'R') || (word4[0] != wordle[4] && word4[0] == 'R') || (word4[1] != wordle[0] && word4[1] == 'R') || (word4[1] != wordle[2] && word4[1] == 'R') || (word4[1] != wordle[3] && word4[1] == 'R') || (word4[1] != wordle[4] && word4[1] == 'R') || (word4[2] != wordle[1] && word4[2] == 'R') || (word4[2] != wordle[0] && word4[2] == 'R') || (word4[2] != wordle[3] && word4[2] == 'R') || (word4[2] != wordle[4] && word4[2] == 'R') || (word4[3] != wordle[1] && word4[3] == 'R') || (word4[3] != wordle[2] && word4[3] == 'R') || (word4[3] != wordle[0] && word4[3] == 'R') || (word4[3] != wordle[4] && word4[3] == 'R') || (word4[4] != wordle[1] && word4[4] == 'R') || (word4[4] != wordle[2] && word4[4] == 'R') || (word4[4] != wordle[3] && word4[4] == 'R') || (word4[4] != wordle[0] && word4[4] == 'R') || (word5[0] != wordle[1] && word5[0] == 'R') || (word5[0] != wordle[2] && word5[0] == 'R') || (word5[0] != wordle[3] && word5[0] == 'R') || (word5[0] != wordle[4] && word5[0] == 'R') || (word5[1] != wordle[0] && word5[1] == 'R') || (word5[1] != wordle[2] && word5[1] == 'R') || (word5[1] != wordle[3] && word5[1] == 'R') || (word5[1] != wordle[4] && word5[1] == 'R') || (word5[2] != wordle[1] && word5[2] == 'R') || (word5[2] != wordle[0] && word5[2] == 'R') || (word5[2] != wordle[3] && word5[2] == 'R') || (word5[2] != wordle[4] && word5[2] == 'R') || (word5[3] != wordle[1] && word5[3] == 'R') || (word5[3] != wordle[2] && word5[3] == 'R') || (word5[3] != wordle[0] && word5[3] == 'R') || (word5[3] != wordle[4] && word5[3] == 'R') || (word5[4] != wordle[1] && word5[4] == 'R') || (word5[4] != wordle[2] && word5[4] == 'R') || (word5[4] != wordle[3] && word5[4] == 'R') || (word5[4] != wordle[0] && word5[4] == 'R') || (word6[0] != wordle[1] && word6[0] == 'R') || (word6[0] != wordle[2] && word6[0] == 'R') || (word6[0] != wordle[3] && word6[0] == 'R') || (word6[0] != wordle[4] && word6[0] == 'R') || (word6[1] != wordle[0] && word6[1] == 'R') || (word6[1] != wordle[2] && word6[1] == 'R') || (word6[1] != wordle[3] && word6[1] == 'R') || (word6[1] != wordle[4] && word6[1] == 'R') || (word6[2] != wordle[1] && word6[2] == 'R') || (word6[2] != wordle[0] && word6[2] == 'R') || (word6[2] != wordle[3] && word6[2] == 'R') || (word6[2] != wordle[4] && word6[2] == 'R') || (word6[3] != wordle[1] && word6[3] == 'R') || (word6[3] != wordle[2] && word6[3] == 'R') || (word6[3] != wordle[0] && word6[3] == 'R') || (word6[3] != wordle[4] && word6[3] == 'R') || (word6[4] != wordle[1] && word6[4] == 'R') || (word6[4] != wordle[2] && word6[4] == 'R') || (word6[4] != wordle[3] && word6[4] == 'R') || (word6[4] != wordle[0] && word6[4] == 'R'))
  {
    c3();
    cout << " R ";
    cout << RESET;
  }
  else 
  {
    cout << " R ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'T') || (word1[1] == wordle[1] && word1[1] == 'T') || (word1[2] == wordle[2] && word1[2] == 'T') || (word1[3] == wordle[3] && word1[3] == 'T') || (word1[4] == wordle[4] && word1[4] == 'T') || (word2[0] == wordle[0] && word2[0] == 'T') || (word2[1] == wordle[1] && word2[1] == 'T') || (word2[2] == wordle[2] && word2[2] == 'T') || (word2[3] == wordle[3] && word2[3] == 'T') || (word2[4] == wordle[4] && word2[4] == 'T') || (word3[0] == wordle[0] && word3[0] == 'T') || (word3[1] == wordle[1] && word3[1] == 'T') || (word3[2] == wordle[2] && word3[2] == 'T') || (word3[3] == wordle[3] && word3[3] == 'T') || (word3[4] == wordle[4] && word3[4] == 'T') || (word4[0] == wordle[0] && word4[0] == 'T') || (word4[1] == wordle[1] && word4[1] == 'T') || (word4[2] == wordle[2] && word4[2] == 'T') || (word4[3] == wordle[3] && word4[3] == 'T') || (word4[4] == wordle[4] && word4[4] == 'T') || (word5[0] == wordle[0] && word5[0] == 'T') || (word5[1] == wordle[1] && word5[1] == 'T') || (word5[2] == wordle[2] && word5[2] == 'T') || (word5[3] == wordle[3] && word5[3] == 'T') || (word5[4] == wordle[4] && word5[4] == 'T') || (word6[0] == wordle[0] && word6[0] == 'T') || (word6[1] == wordle[1] && word6[1] == 'T') || (word6[2] == wordle[2] && word6[2] == 'T') || (word6[3] == wordle[3] && word6[3] == 'T') || (word6[4] == wordle[4] && word6[4] == 'T'))
  {
    c1();
    cout << " T ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'T') || (word1[0] == wordle[2] && wordle[2] == 'T') || (word1[0] == wordle[3] && wordle[3] == 'T') || (word1[0] == wordle[4] && wordle[4] == 'T') || (word1[1] == wordle[0] && wordle[0] == 'T') || (word1[1] == wordle[2] && wordle[2] == 'T') || (word1[1] == wordle[3] && wordle[3] == 'T') || (word1[1] == wordle[4] && wordle[4] == 'T') || (word1[2] == wordle[1] && wordle[1] == 'T') || (word1[2] == wordle[0] && wordle[0] == 'T') || (word1[2] == wordle[3] && wordle[3] == 'T') || (word1[2] == wordle[4] && wordle[4] == 'T') || (word1[3] == wordle[1] && wordle[1] == 'T') || (word1[3] == wordle[0] && wordle[0] == 'T') || (word1[3] == wordle[2] && wordle[2] == 'T') || (word1[3] == wordle[4] && wordle[4] == 'T') || (word1[4] == wordle[1] && wordle[1] == 'T') || (word1[4] == wordle[0] && wordle[0] == 'T') || (word1[4] == wordle[3] && wordle[3] == 'T') || (word1[4] == wordle[2] && wordle[2] == 'T') || (word2[0] == wordle[1] && wordle[1] == 'T') || (word2[0] == wordle[2] && wordle[2] == 'T') || (word2[0] == wordle[3] && wordle[3] == 'T') || (word2[0] == wordle[4] && wordle[4] == 'T') || (word2[1] == wordle[0] && wordle[0] == 'T') || (word2[1] == wordle[2] && wordle[2] == 'T') || (word2[1] == wordle[3] && wordle[3] == 'T') || (word2[1] == wordle[4] && wordle[4] == 'T') || (word2[2] == wordle[1] && wordle[1] == 'T') || (word2[2] == wordle[0] && wordle[0] == 'T') || (word2[2] == wordle[3] && wordle[3] == 'T') || (word2[2] == wordle[4] && wordle[4] == 'T') || (word2[3] == wordle[1] && wordle[1] == 'T') || (word2[3] == wordle[0] && wordle[0] == 'T') || (word2[3] == wordle[2] && wordle[2] == 'T') || (word2[3] == wordle[4] && wordle[4] == 'T') || (word2[4] == wordle[1] && wordle[1] == 'T') || (word2[4] == wordle[0] && wordle[0] == 'T') || (word2[4] == wordle[3] && wordle[3] == 'T') || (word2[4] == wordle[2] && wordle[2] == 'T') || (word3[0] == wordle[1] && wordle[1] == 'T') || (word3[0] == wordle[2] && wordle[2] == 'T') || (word3[0] == wordle[3] && wordle[3] == 'T') || (word3[0] == wordle[4] && wordle[4] == 'T') || (word3[1] == wordle[0] && wordle[0] == 'T') || (word3[1] == wordle[2] && wordle[2] == 'T') || (word3[1] == wordle[3] && wordle[3] == 'T') || (word3[1] == wordle[4] && wordle[4] == 'T') || (word3[2] == wordle[1] && wordle[1] == 'T') || (word3[2] == wordle[0] && wordle[0] == 'T') || (word3[2] == wordle[3] && wordle[3] == 'T') || (word3[2] == wordle[4] && wordle[4] == 'T') || (word3[3] == wordle[1] && wordle[1] == 'T') || (word3[3] == wordle[0] && wordle[0] == 'T') || (word3[3] == wordle[2] && wordle[2] == 'T') || (word3[3] == wordle[4] && wordle[4] == 'T') || (word3[4] == wordle[1] && wordle[1] == 'T') || (word3[4] == wordle[0] && wordle[0] == 'T') || (word3[4] == wordle[3] && wordle[3] == 'T') || (word3[4] == wordle[2] && wordle[2] == 'T') || (word4[0] == wordle[1] && wordle[1] == 'T') || (word4[0] == wordle[2] && wordle[2] == 'T') || (word4[0] == wordle[3] && wordle[3] == 'T') || (word4[0] == wordle[4] && wordle[4] == 'T') || (word4[1] == wordle[0] && wordle[0] == 'T') || (word4[1] == wordle[2] && wordle[2] == 'T') || (word4[1] == wordle[3] && wordle[3] == 'T') || (word4[1] == wordle[4] && wordle[4] == 'T') || (word4[2] == wordle[1] && wordle[1] == 'T') || (word4[2] == wordle[0] && wordle[0] == 'T') || (word4[2] == wordle[3] && wordle[3] == 'T') || (word4[2] == wordle[4] && wordle[4] == 'T') || (word4[3] == wordle[1] && wordle[1] == 'T') || (word4[3] == wordle[0] && wordle[0] == 'T') || (word4[3] == wordle[2] && wordle[2] == 'T') || (word4[3] == wordle[4] && wordle[4] == 'T') || (word4[4] == wordle[1] && wordle[1] == 'T') || (word4[4] == wordle[0] && wordle[0] == 'T') || (word4[4] == wordle[3] && wordle[3] == 'T') || (word4[4] == wordle[2] && wordle[2] == 'T') || (word5[0] == wordle[1] && wordle[1] == 'T') || (word5[0] == wordle[2] && wordle[2] == 'T') || (word5[0] == wordle[3] && wordle[3] == 'T') || (word5[0] == wordle[4] && wordle[4] == 'T') || (word5[1] == wordle[0] && wordle[0] == 'T') || (word5[1] == wordle[2] && wordle[2] == 'T') || (word5[1] == wordle[3] && wordle[3] == 'T') || (word5[1] == wordle[4] && wordle[4] == 'T') || (word5[2] == wordle[1] && wordle[1] == 'T') || (word5[2] == wordle[0] && wordle[0] == 'T') || (word5[2] == wordle[3] && wordle[3] == 'T') || (word5[2] == wordle[4] && wordle[4] == 'T') || (word5[3] == wordle[1] && wordle[1] == 'T') || (word5[3] == wordle[0] && wordle[0] == 'T') || (word5[3] == wordle[2] && wordle[2] == 'T') || (word5[3] == wordle[4] && wordle[4] == 'T') || (word5[4] == wordle[1] && wordle[1] == 'T') || (word5[4] == wordle[0] && wordle[0] == 'T') || (word5[4] == wordle[3] && wordle[3] == 'T') || (word5[4] == wordle[2] && wordle[2] == 'T') || (word6[0] == wordle[1] && wordle[1] == 'T') || (word6[0] == wordle[2] && wordle[2] == 'T') || (word6[0] == wordle[3] && wordle[3] == 'T') || (word6[0] == wordle[4] && wordle[4] == 'T') || (word6[1] == wordle[0] && wordle[0] == 'T') || (word6[1] == wordle[2] && wordle[2] == 'T') || (word6[1] == wordle[3] && wordle[3] == 'T') || (word6[1] == wordle[4] && wordle[4] == 'T') || (word6[2] == wordle[1] && wordle[1] == 'T') || (word6[2] == wordle[0] && wordle[0] == 'T') || (word6[2] == wordle[3] && wordle[3] == 'T') || (word6[2] == wordle[4] && wordle[4] == 'T') || (word6[3] == wordle[1] && wordle[1] == 'T') || (word6[3] == wordle[0] && wordle[0] == 'T') || (word6[3] == wordle[2] && wordle[2] == 'T') || (word6[3] == wordle[4] && wordle[4] == 'T') || (word6[4] == wordle[1] && wordle[1] == 'T') || (word6[4] == wordle[0] && wordle[0] == 'T') || (word6[4] == wordle[3] && wordle[3] == 'T') || (word6[4] == wordle[2] && wordle[2] == 'T'))
  {
    c2();
    cout << " T ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'T') || (word1[0] != wordle[2] && word1[0] == 'T') || (word1[0] != wordle[3] && word1[0] == 'T') || (word1[0] != wordle[4] && word1[0] == 'T') || (word1[1] != wordle[0] && word1[1] == 'T') || (word1[1] != wordle[2] && word1[1] == 'T') || (word1[1] != wordle[3] && word1[1] == 'T') || (word1[1] != wordle[4] && word1[1] == 'T') || (word1[2] != wordle[1] && word1[2] == 'T') || (word1[2] != wordle[0] && word1[2] == 'T') || (word1[2] != wordle[3] && word1[2] == 'T') || (word1[2] != wordle[4] && word1[2] == 'T') || (word1[3] != wordle[1] && word1[3] == 'T') || (word1[3] != wordle[2] && word1[3] == 'T') || (word1[3] != wordle[0] && word1[3] == 'T') || (word1[3] != wordle[4] && word1[3] == 'T') || (word1[4] != wordle[1] && word1[4] == 'T') || (word1[4] != wordle[2] && word1[4] == 'T') || (word1[4] != wordle[3] && word1[4] == 'T') || (word1[4] != wordle[0] && word1[4] == 'T') || (word2[0] != wordle[1] && word2[0] == 'T') || (word2[0] != wordle[2] && word2[0] == 'T') || (word2[0] != wordle[3] && word2[0] == 'T') || (word2[0] != wordle[4] && word2[0] == 'T') || (word2[1] != wordle[0] && word2[1] == 'T') || (word2[1] != wordle[2] && word2[1] == 'T') || (word2[1] != wordle[3] && word2[1] == 'T') || (word2[1] != wordle[4] && word2[1] == 'T') || (word2[2] != wordle[1] && word2[2] == 'T') || (word2[2] != wordle[0] && word2[2] == 'T') || (word2[2] != wordle[3] && word2[2] == 'T') || (word2[2] != wordle[4] && word2[2] == 'T') || (word2[3] != wordle[1] && word2[3] == 'T') || (word2[3] != wordle[2] && word2[3] == 'T') || (word2[3] != wordle[0] && word2[3] == 'T') || (word2[3] != wordle[4] && word2[3] == 'T') || (word2[4] != wordle[1] && word2[4] == 'T') || (word2[4] != wordle[2] && word2[4] == 'T') || (word2[4] != wordle[3] && word2[4] == 'T') || (word2[4] != wordle[0] && word2[4] == 'T') || (word3[0] != wordle[1] && word3[0] == 'T') || (word3[0] != wordle[2] && word3[0] == 'T') || (word3[0] != wordle[3] && word3[0] == 'T') || (word3[0] != wordle[4] && word3[0] == 'T') || (word3[1] != wordle[0] && word3[1] == 'T') || (word3[1] != wordle[2] && word3[1] == 'T') || (word3[1] != wordle[3] && word3[1] == 'T') || (word3[1] != wordle[4] && word3[1] == 'T') || (word3[2] != wordle[1] && word3[2] == 'T') || (word3[2] != wordle[0] && word3[2] == 'T') || (word3[2] != wordle[3] && word3[2] == 'T') || (word3[2] != wordle[4] && word3[2] == 'T') || (word3[3] != wordle[1] && word3[3] == 'T') || (word3[3] != wordle[2] && word3[3] == 'T') || (word3[3] != wordle[0] && word3[3] == 'T') || (word3[3] != wordle[4] && word3[3] == 'T') || (word3[4] != wordle[1] && word3[4] == 'T') || (word3[4] != wordle[2] && word3[4] == 'T') || (word3[4] != wordle[3] && word3[4] == 'T') || (word3[4] != wordle[0] && word3[4] == 'T') || (word4[0] != wordle[1] && word4[0] == 'T') || (word4[0] != wordle[2] && word4[0] == 'T') || (word4[0] != wordle[3] && word4[0] == 'T') || (word4[0] != wordle[4] && word4[0] == 'T') || (word4[1] != wordle[0] && word4[1] == 'T') || (word4[1] != wordle[2] && word4[1] == 'T') || (word4[1] != wordle[3] && word4[1] == 'T') || (word4[1] != wordle[4] && word4[1] == 'T') || (word4[2] != wordle[1] && word4[2] == 'T') || (word4[2] != wordle[0] && word4[2] == 'T') || (word4[2] != wordle[3] && word4[2] == 'T') || (word4[2] != wordle[4] && word4[2] == 'T') || (word4[3] != wordle[1] && word4[3] == 'T') || (word4[3] != wordle[2] && word4[3] == 'T') || (word4[3] != wordle[0] && word4[3] == 'T') || (word4[3] != wordle[4] && word4[3] == 'T') || (word4[4] != wordle[1] && word4[4] == 'T') || (word4[4] != wordle[2] && word4[4] == 'T') || (word4[4] != wordle[3] && word4[4] == 'T') || (word4[4] != wordle[0] && word4[4] == 'T') || (word5[0] != wordle[1] && word5[0] == 'T') || (word5[0] != wordle[2] && word5[0] == 'T') || (word5[0] != wordle[3] && word5[0] == 'T') || (word5[0] != wordle[4] && word5[0] == 'T') || (word5[1] != wordle[0] && word5[1] == 'T') || (word5[1] != wordle[2] && word5[1] == 'T') || (word5[1] != wordle[3] && word5[1] == 'T') || (word5[1] != wordle[4] && word5[1] == 'T') || (word5[2] != wordle[1] && word5[2] == 'T') || (word5[2] != wordle[0] && word5[2] == 'T') || (word5[2] != wordle[3] && word5[2] == 'T') || (word5[2] != wordle[4] && word5[2] == 'T') || (word5[3] != wordle[1] && word5[3] == 'T') || (word5[3] != wordle[2] && word5[3] == 'T') || (word5[3] != wordle[0] && word5[3] == 'T') || (word5[3] != wordle[4] && word5[3] == 'T') || (word5[4] != wordle[1] && word5[4] == 'T') || (word5[4] != wordle[2] && word5[4] == 'T') || (word5[4] != wordle[3] && word5[4] == 'T') || (word5[4] != wordle[0] && word5[4] == 'T') || (word6[0] != wordle[1] && word6[0] == 'T') || (word6[0] != wordle[2] && word6[0] == 'T') || (word6[0] != wordle[3] && word6[0] == 'T') || (word6[0] != wordle[4] && word6[0] == 'T') || (word6[1] != wordle[0] && word6[1] == 'T') || (word6[1] != wordle[2] && word6[1] == 'T') || (word6[1] != wordle[3] && word6[1] == 'T') || (word6[1] != wordle[4] && word6[1] == 'T') || (word6[2] != wordle[1] && word6[2] == 'T') || (word6[2] != wordle[0] && word6[2] == 'T') || (word6[2] != wordle[3] && word6[2] == 'T') || (word6[2] != wordle[4] && word6[2] == 'T') || (word6[3] != wordle[1] && word6[3] == 'T') || (word6[3] != wordle[2] && word6[3] == 'T') || (word6[3] != wordle[0] && word6[3] == 'T') || (word6[3] != wordle[4] && word6[3] == 'T') || (word6[4] != wordle[1] && word6[4] == 'T') || (word6[4] != wordle[2] && word6[4] == 'T') || (word6[4] != wordle[3] && word6[4] == 'T') || (word6[4] != wordle[0] && word6[4] == 'T'))
  {
    c3();
    cout << " T ";
    cout << RESET;
  }
  else 
  {
    cout << " T ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'Y') || (word1[1] == wordle[1] && word1[1] == 'Y') || (word1[2] == wordle[2] && word1[2] == 'Y') || (word1[3] == wordle[3] && word1[3] == 'Y') || (word1[4] == wordle[4] && word1[4] == 'Y') || (word2[0] == wordle[0] && word2[0] == 'Y') || (word2[1] == wordle[1] && word2[1] == 'Y') || (word2[2] == wordle[2] && word2[2] == 'Y') || (word2[3] == wordle[3] && word2[3] == 'Y') || (word2[4] == wordle[4] && word2[4] == 'Y') || (word3[0] == wordle[0] && word3[0] == 'Y') || (word3[1] == wordle[1] && word3[1] == 'Y') || (word3[2] == wordle[2] && word3[2] == 'Y') || (word3[3] == wordle[3] && word3[3] == 'Y') || (word3[4] == wordle[4] && word3[4] == 'Y') || (word4[0] == wordle[0] && word4[0] == 'Y') || (word4[1] == wordle[1] && word4[1] == 'Y') || (word4[2] == wordle[2] && word4[2] == 'Y') || (word4[3] == wordle[3] && word4[3] == 'Y') || (word4[4] == wordle[4] && word4[4] == 'Y') || (word5[0] == wordle[0] && word5[0] == 'Y') || (word5[1] == wordle[1] && word5[1] == 'Y') || (word5[2] == wordle[2] && word5[2] == 'Y') || (word5[3] == wordle[3] && word5[3] == 'Y') || (word5[4] == wordle[4] && word5[4] == 'Y') || (word6[0] == wordle[0] && word6[0] == 'Y') || (word6[1] == wordle[1] && word6[1] == 'Y') || (word6[2] == wordle[2] && word6[2] == 'Y') || (word6[3] == wordle[3] && word6[3] == 'Y') || (word6[4] == wordle[4] && word6[4] == 'Y'))
  {
    c1();
    cout << " Y ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'Y') || (word1[0] == wordle[2] && wordle[2] == 'Y') || (word1[0] == wordle[3] && wordle[3] == 'Y') || (word1[0] == wordle[4] && wordle[4] == 'Y') || (word1[1] == wordle[0] && wordle[0] == 'Y') || (word1[1] == wordle[2] && wordle[2] == 'Y') || (word1[1] == wordle[3] && wordle[3] == 'Y') || (word1[1] == wordle[4] && wordle[4] == 'Y') || (word1[2] == wordle[1] && wordle[1] == 'Y') || (word1[2] == wordle[0] && wordle[0] == 'Y') || (word1[2] == wordle[3] && wordle[3] == 'Y') || (word1[2] == wordle[4] && wordle[4] == 'Y') || (word1[3] == wordle[1] && wordle[1] == 'Y') || (word1[3] == wordle[0] && wordle[0] == 'Y') || (word1[3] == wordle[2] && wordle[2] == 'Y') || (word1[3] == wordle[4] && wordle[4] == 'Y') || (word1[4] == wordle[1] && wordle[1] == 'Y') || (word1[4] == wordle[0] && wordle[0] == 'Y') || (word1[4] == wordle[3] && wordle[3] == 'Y') || (word1[4] == wordle[2] && wordle[2] == 'Y') || (word2[0] == wordle[1] && wordle[1] == 'Y') || (word2[0] == wordle[2] && wordle[2] == 'Y') || (word2[0] == wordle[3] && wordle[3] == 'Y') || (word2[0] == wordle[4] && wordle[4] == 'Y') || (word2[1] == wordle[0] && wordle[0] == 'Y') || (word2[1] == wordle[2] && wordle[2] == 'Y') || (word2[1] == wordle[3] && wordle[3] == 'Y') || (word2[1] == wordle[4] && wordle[4] == 'Y') || (word2[2] == wordle[1] && wordle[1] == 'Y') || (word2[2] == wordle[0] && wordle[0] == 'Y') || (word2[2] == wordle[3] && wordle[3] == 'Y') || (word2[2] == wordle[4] && wordle[4] == 'Y') || (word2[3] == wordle[1] && wordle[1] == 'Y') || (word2[3] == wordle[0] && wordle[0] == 'Y') || (word2[3] == wordle[2] && wordle[2] == 'Y') || (word2[3] == wordle[4] && wordle[4] == 'Y') || (word2[4] == wordle[1] && wordle[1] == 'Y') || (word2[4] == wordle[0] && wordle[0] == 'Y') || (word2[4] == wordle[3] && wordle[3] == 'Y') || (word2[4] == wordle[2] && wordle[2] == 'Y') || (word3[0] == wordle[1] && wordle[1] == 'Y') || (word3[0] == wordle[2] && wordle[2] == 'Y') || (word3[0] == wordle[3] && wordle[3] == 'Y') || (word3[0] == wordle[4] && wordle[4] == 'Y') || (word3[1] == wordle[0] && wordle[0] == 'Y') || (word3[1] == wordle[2] && wordle[2] == 'Y') || (word3[1] == wordle[3] && wordle[3] == 'Y') || (word3[1] == wordle[4] && wordle[4] == 'Y') || (word3[2] == wordle[1] && wordle[1] == 'Y') || (word3[2] == wordle[0] && wordle[0] == 'Y') || (word3[2] == wordle[3] && wordle[3] == 'Y') || (word3[2] == wordle[4] && wordle[4] == 'Y') || (word3[3] == wordle[1] && wordle[1] == 'Y') || (word3[3] == wordle[0] && wordle[0] == 'Y') || (word3[3] == wordle[2] && wordle[2] == 'Y') || (word3[3] == wordle[4] && wordle[4] == 'Y') || (word3[4] == wordle[1] && wordle[1] == 'Y') || (word3[4] == wordle[0] && wordle[0] == 'Y') || (word3[4] == wordle[3] && wordle[3] == 'Y') || (word3[4] == wordle[2] && wordle[2] == 'Y') || (word4[0] == wordle[1] && wordle[1] == 'Y') || (word4[0] == wordle[2] && wordle[2] == 'Y') || (word4[0] == wordle[3] && wordle[3] == 'Y') || (word4[0] == wordle[4] && wordle[4] == 'Y') || (word4[1] == wordle[0] && wordle[0] == 'Y') || (word4[1] == wordle[2] && wordle[2] == 'Y') || (word4[1] == wordle[3] && wordle[3] == 'Y') || (word4[1] == wordle[4] && wordle[4] == 'Y') || (word4[2] == wordle[1] && wordle[1] == 'Y') || (word4[2] == wordle[0] && wordle[0] == 'Y') || (word4[2] == wordle[3] && wordle[3] == 'Y') || (word4[2] == wordle[4] && wordle[4] == 'Y') || (word4[3] == wordle[1] && wordle[1] == 'Y') || (word4[3] == wordle[0] && wordle[0] == 'Y') || (word4[3] == wordle[2] && wordle[2] == 'Y') || (word4[3] == wordle[4] && wordle[4] == 'Y') || (word4[4] == wordle[1] && wordle[1] == 'Y') || (word4[4] == wordle[0] && wordle[0] == 'Y') || (word4[4] == wordle[3] && wordle[3] == 'Y') || (word4[4] == wordle[2] && wordle[2] == 'Y') || (word5[0] == wordle[1] && wordle[1] == 'Y') || (word5[0] == wordle[2] && wordle[2] == 'Y') || (word5[0] == wordle[3] && wordle[3] == 'Y') || (word5[0] == wordle[4] && wordle[4] == 'Y') || (word5[1] == wordle[0] && wordle[0] == 'Y') || (word5[1] == wordle[2] && wordle[2] == 'Y') || (word5[1] == wordle[3] && wordle[3] == 'Y') || (word5[1] == wordle[4] && wordle[4] == 'Y') || (word5[2] == wordle[1] && wordle[1] == 'Y') || (word5[2] == wordle[0] && wordle[0] == 'Y') || (word5[2] == wordle[3] && wordle[3] == 'Y') || (word5[2] == wordle[4] && wordle[4] == 'Y') || (word5[3] == wordle[1] && wordle[1] == 'Y') || (word5[3] == wordle[0] && wordle[0] == 'Y') || (word5[3] == wordle[2] && wordle[2] == 'Y') || (word5[3] == wordle[4] && wordle[4] == 'Y') || (word5[4] == wordle[1] && wordle[1] == 'Y') || (word5[4] == wordle[0] && wordle[0] == 'Y') || (word5[4] == wordle[3] && wordle[3] == 'Y') || (word5[4] == wordle[2] && wordle[2] == 'Y') || (word6[0] == wordle[1] && wordle[1] == 'Y') || (word6[0] == wordle[2] && wordle[2] == 'Y') || (word6[0] == wordle[3] && wordle[3] == 'Y') || (word6[0] == wordle[4] && wordle[4] == 'Y') || (word6[1] == wordle[0] && wordle[0] == 'Y') || (word6[1] == wordle[2] && wordle[2] == 'Y') || (word6[1] == wordle[3] && wordle[3] == 'Y') || (word6[1] == wordle[4] && wordle[4] == 'Y') || (word6[2] == wordle[1] && wordle[1] == 'Y') || (word6[2] == wordle[0] && wordle[0] == 'Y') || (word6[2] == wordle[3] && wordle[3] == 'Y') || (word6[2] == wordle[4] && wordle[4] == 'Y') || (word6[3] == wordle[1] && wordle[1] == 'Y') || (word6[3] == wordle[0] && wordle[0] == 'Y') || (word6[3] == wordle[2] && wordle[2] == 'Y') || (word6[3] == wordle[4] && wordle[4] == 'Y') || (word6[4] == wordle[1] && wordle[1] == 'Y') || (word6[4] == wordle[0] && wordle[0] == 'Y') || (word6[4] == wordle[3] && wordle[3] == 'Y') || (word6[4] == wordle[2] && wordle[2] == 'Y'))
  {
    c2();
    cout << " Y ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'Y') || (word1[0] != wordle[2] && word1[0] == 'Y') || (word1[0] != wordle[3] && word1[0] == 'Y') || (word1[0] != wordle[4] && word1[0] == 'Y') || (word1[1] != wordle[0] && word1[1] == 'Y') || (word1[1] != wordle[2] && word1[1] == 'Y') || (word1[1] != wordle[3] && word1[1] == 'Y') || (word1[1] != wordle[4] && word1[1] == 'Y') || (word1[2] != wordle[1] && word1[2] == 'Y') || (word1[2] != wordle[0] && word1[2] == 'Y') || (word1[2] != wordle[3] && word1[2] == 'Y') || (word1[2] != wordle[4] && word1[2] == 'Y') || (word1[3] != wordle[1] && word1[3] == 'Y') || (word1[3] != wordle[2] && word1[3] == 'Y') || (word1[3] != wordle[0] && word1[3] == 'Y') || (word1[3] != wordle[4] && word1[3] == 'Y') || (word1[4] != wordle[1] && word1[4] == 'Y') || (word1[4] != wordle[2] && word1[4] == 'Y') || (word1[4] != wordle[3] && word1[4] == 'Y') || (word1[4] != wordle[0] && word1[4] == 'Y') || (word2[0] != wordle[1] && word2[0] == 'Y') || (word2[0] != wordle[2] && word2[0] == 'Y') || (word2[0] != wordle[3] && word2[0] == 'Y') || (word2[0] != wordle[4] && word2[0] == 'Y') || (word2[1] != wordle[0] && word2[1] == 'Y') || (word2[1] != wordle[2] && word2[1] == 'Y') || (word2[1] != wordle[3] && word2[1] == 'Y') || (word2[1] != wordle[4] && word2[1] == 'Y') || (word2[2] != wordle[1] && word2[2] == 'Y') || (word2[2] != wordle[0] && word2[2] == 'Y') || (word2[2] != wordle[3] && word2[2] == 'Y') || (word2[2] != wordle[4] && word2[2] == 'Y') || (word2[3] != wordle[1] && word2[3] == 'Y') || (word2[3] != wordle[2] && word2[3] == 'Y') || (word2[3] != wordle[0] && word2[3] == 'Y') || (word2[3] != wordle[4] && word2[3] == 'Y') || (word2[4] != wordle[1] && word2[4] == 'Y') || (word2[4] != wordle[2] && word2[4] == 'Y') || (word2[4] != wordle[3] && word2[4] == 'Y') || (word2[4] != wordle[0] && word2[4] == 'Y') || (word3[0] != wordle[1] && word3[0] == 'Y') || (word3[0] != wordle[2] && word3[0] == 'Y') || (word3[0] != wordle[3] && word3[0] == 'Y') || (word3[0] != wordle[4] && word3[0] == 'Y') || (word3[1] != wordle[0] && word3[1] == 'Y') || (word3[1] != wordle[2] && word3[1] == 'Y') || (word3[1] != wordle[3] && word3[1] == 'Y') || (word3[1] != wordle[4] && word3[1] == 'Y') || (word3[2] != wordle[1] && word3[2] == 'Y') || (word3[2] != wordle[0] && word3[2] == 'Y') || (word3[2] != wordle[3] && word3[2] == 'Y') || (word3[2] != wordle[4] && word3[2] == 'Y') || (word3[3] != wordle[1] && word3[3] == 'Y') || (word3[3] != wordle[2] && word3[3] == 'Y') || (word3[3] != wordle[0] && word3[3] == 'Y') || (word3[3] != wordle[4] && word3[3] == 'Y') || (word3[4] != wordle[1] && word3[4] == 'Y') || (word3[4] != wordle[2] && word3[4] == 'Y') || (word3[4] != wordle[3] && word3[4] == 'Y') || (word3[4] != wordle[0] && word3[4] == 'Y') || (word4[0] != wordle[1] && word4[0] == 'Y') || (word4[0] != wordle[2] && word4[0] == 'Y') || (word4[0] != wordle[3] && word4[0] == 'Y') || (word4[0] != wordle[4] && word4[0] == 'Y') || (word4[1] != wordle[0] && word4[1] == 'Y') || (word4[1] != wordle[2] && word4[1] == 'Y') || (word4[1] != wordle[3] && word4[1] == 'Y') || (word4[1] != wordle[4] && word4[1] == 'Y') || (word4[2] != wordle[1] && word4[2] == 'Y') || (word4[2] != wordle[0] && word4[2] == 'Y') || (word4[2] != wordle[3] && word4[2] == 'Y') || (word4[2] != wordle[4] && word4[2] == 'Y') || (word4[3] != wordle[1] && word4[3] == 'Y') || (word4[3] != wordle[2] && word4[3] == 'Y') || (word4[3] != wordle[0] && word4[3] == 'Y') || (word4[3] != wordle[4] && word4[3] == 'Y') || (word4[4] != wordle[1] && word4[4] == 'Y') || (word4[4] != wordle[2] && word4[4] == 'Y') || (word4[4] != wordle[3] && word4[4] == 'Y') || (word4[4] != wordle[0] && word4[4] == 'Y') || (word5[0] != wordle[1] && word5[0] == 'Y') || (word5[0] != wordle[2] && word5[0] == 'Y') || (word5[0] != wordle[3] && word5[0] == 'Y') || (word5[0] != wordle[4] && word5[0] == 'Y') || (word5[1] != wordle[0] && word5[1] == 'Y') || (word5[1] != wordle[2] && word5[1] == 'Y') || (word5[1] != wordle[3] && word5[1] == 'Y') || (word5[1] != wordle[4] && word5[1] == 'Y') || (word5[2] != wordle[1] && word5[2] == 'Y') || (word5[2] != wordle[0] && word5[2] == 'Y') || (word5[2] != wordle[3] && word5[2] == 'Y') || (word5[2] != wordle[4] && word5[2] == 'Y') || (word5[3] != wordle[1] && word5[3] == 'Y') || (word5[3] != wordle[2] && word5[3] == 'Y') || (word5[3] != wordle[0] && word5[3] == 'Y') || (word5[3] != wordle[4] && word5[3] == 'Y') || (word5[4] != wordle[1] && word5[4] == 'Y') || (word5[4] != wordle[2] && word5[4] == 'Y') || (word5[4] != wordle[3] && word5[4] == 'Y') || (word5[4] != wordle[0] && word5[4] == 'Y') || (word6[0] != wordle[1] && word6[0] == 'Y') || (word6[0] != wordle[2] && word6[0] == 'Y') || (word6[0] != wordle[3] && word6[0] == 'Y') || (word6[0] != wordle[4] && word6[0] == 'Y') || (word6[1] != wordle[0] && word6[1] == 'Y') || (word6[1] != wordle[2] && word6[1] == 'Y') || (word6[1] != wordle[3] && word6[1] == 'Y') || (word6[1] != wordle[4] && word6[1] == 'Y') || (word6[2] != wordle[1] && word6[2] == 'Y') || (word6[2] != wordle[0] && word6[2] == 'Y') || (word6[2] != wordle[3] && word6[2] == 'Y') || (word6[2] != wordle[4] && word6[2] == 'Y') || (word6[3] != wordle[1] && word6[3] == 'Y') || (word6[3] != wordle[2] && word6[3] == 'Y') || (word6[3] != wordle[0] && word6[3] == 'Y') || (word6[3] != wordle[4] && word6[3] == 'Y') || (word6[4] != wordle[1] && word6[4] == 'Y') || (word6[4] != wordle[2] && word6[4] == 'Y') || (word6[4] != wordle[3] && word6[4] == 'Y') || (word6[4] != wordle[0] && word6[4] == 'Y'))
  {
    c3();
    cout << " Y ";
    cout << RESET;
  }
  else 
  {
    cout << " Y ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'U') || (word1[1] == wordle[1] && word1[1] == 'U') || (word1[2] == wordle[2] && word1[2] == 'U') || (word1[3] == wordle[3] && word1[3] == 'U') || (word1[4] == wordle[4] && word1[4] == 'U') || (word2[0] == wordle[0] && word2[0] == 'U') || (word2[1] == wordle[1] && word2[1] == 'U') || (word2[2] == wordle[2] && word2[2] == 'U') || (word2[3] == wordle[3] && word2[3] == 'U') || (word2[4] == wordle[4] && word2[4] == 'U') || (word3[0] == wordle[0] && word3[0] == 'U') || (word3[1] == wordle[1] && word3[1] == 'U') || (word3[2] == wordle[2] && word3[2] == 'U') || (word3[3] == wordle[3] && word3[3] == 'U') || (word3[4] == wordle[4] && word3[4] == 'U') || (word4[0] == wordle[0] && word4[0] == 'U') || (word4[1] == wordle[1] && word4[1] == 'U') || (word4[2] == wordle[2] && word4[2] == 'U') || (word4[3] == wordle[3] && word4[3] == 'U') || (word4[4] == wordle[4] && word4[4] == 'U') || (word5[0] == wordle[0] && word5[0] == 'U') || (word5[1] == wordle[1] && word5[1] == 'U') || (word5[2] == wordle[2] && word5[2] == 'U') || (word5[3] == wordle[3] && word5[3] == 'U') || (word5[4] == wordle[4] && word5[4] == 'U') || (word6[0] == wordle[0] && word6[0] == 'U') || (word6[1] == wordle[1] && word6[1] == 'U') || (word6[2] == wordle[2] && word6[2] == 'U') || (word6[3] == wordle[3] && word6[3] == 'U') || (word6[4] == wordle[4] && word6[4] == 'U'))
  {
    c1();
    cout << " U ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'U') || (word1[0] == wordle[2] && wordle[2] == 'U') || (word1[0] == wordle[3] && wordle[3] == 'U') || (word1[0] == wordle[4] && wordle[4] == 'U') || (word1[1] == wordle[0] && wordle[0] == 'U') || (word1[1] == wordle[2] && wordle[2] == 'U') || (word1[1] == wordle[3] && wordle[3] == 'U') || (word1[1] == wordle[4] && wordle[4] == 'U') || (word1[2] == wordle[1] && wordle[1] == 'U') || (word1[2] == wordle[0] && wordle[0] == 'U') || (word1[2] == wordle[3] && wordle[3] == 'U') || (word1[2] == wordle[4] && wordle[4] == 'U') || (word1[3] == wordle[1] && wordle[1] == 'U') || (word1[3] == wordle[0] && wordle[0] == 'U') || (word1[3] == wordle[2] && wordle[2] == 'U') || (word1[3] == wordle[4] && wordle[4] == 'U') || (word1[4] == wordle[1] && wordle[1] == 'U') || (word1[4] == wordle[0] && wordle[0] == 'U') || (word1[4] == wordle[3] && wordle[3] == 'U') || (word1[4] == wordle[2] && wordle[2] == 'U') || (word2[0] == wordle[1] && wordle[1] == 'U') || (word2[0] == wordle[2] && wordle[2] == 'U') || (word2[0] == wordle[3] && wordle[3] == 'U') || (word2[0] == wordle[4] && wordle[4] == 'U') || (word2[1] == wordle[0] && wordle[0] == 'U') || (word2[1] == wordle[2] && wordle[2] == 'U') || (word2[1] == wordle[3] && wordle[3] == 'U') || (word2[1] == wordle[4] && wordle[4] == 'U') || (word2[2] == wordle[1] && wordle[1] == 'U') || (word2[2] == wordle[0] && wordle[0] == 'U') || (word2[2] == wordle[3] && wordle[3] == 'U') || (word2[2] == wordle[4] && wordle[4] == 'U') || (word2[3] == wordle[1] && wordle[1] == 'U') || (word2[3] == wordle[0] && wordle[0] == 'U') || (word2[3] == wordle[2] && wordle[2] == 'U') || (word2[3] == wordle[4] && wordle[4] == 'U') || (word2[4] == wordle[1] && wordle[1] == 'U') || (word2[4] == wordle[0] && wordle[0] == 'U') || (word2[4] == wordle[3] && wordle[3] == 'U') || (word2[4] == wordle[2] && wordle[2] == 'U') || (word3[0] == wordle[1] && wordle[1] == 'U') || (word3[0] == wordle[2] && wordle[2] == 'U') || (word3[0] == wordle[3] && wordle[3] == 'U') || (word3[0] == wordle[4] && wordle[4] == 'U') || (word3[1] == wordle[0] && wordle[0] == 'U') || (word3[1] == wordle[2] && wordle[2] == 'U') || (word3[1] == wordle[3] && wordle[3] == 'U') || (word3[1] == wordle[4] && wordle[4] == 'U') || (word3[2] == wordle[1] && wordle[1] == 'U') || (word3[2] == wordle[0] && wordle[0] == 'U') || (word3[2] == wordle[3] && wordle[3] == 'U') || (word3[2] == wordle[4] && wordle[4] == 'U') || (word3[3] == wordle[1] && wordle[1] == 'U') || (word3[3] == wordle[0] && wordle[0] == 'U') || (word3[3] == wordle[2] && wordle[2] == 'U') || (word3[3] == wordle[4] && wordle[4] == 'U') || (word3[4] == wordle[1] && wordle[1] == 'U') || (word3[4] == wordle[0] && wordle[0] == 'U') || (word3[4] == wordle[3] && wordle[3] == 'U') || (word3[4] == wordle[2] && wordle[2] == 'U') || (word4[0] == wordle[1] && wordle[1] == 'U') || (word4[0] == wordle[2] && wordle[2] == 'U') || (word4[0] == wordle[3] && wordle[3] == 'U') || (word4[0] == wordle[4] && wordle[4] == 'U') || (word4[1] == wordle[0] && wordle[0] == 'U') || (word4[1] == wordle[2] && wordle[2] == 'U') || (word4[1] == wordle[3] && wordle[3] == 'U') || (word4[1] == wordle[4] && wordle[4] == 'U') || (word4[2] == wordle[1] && wordle[1] == 'U') || (word4[2] == wordle[0] && wordle[0] == 'U') || (word4[2] == wordle[3] && wordle[3] == 'U') || (word4[2] == wordle[4] && wordle[4] == 'U') || (word4[3] == wordle[1] && wordle[1] == 'U') || (word4[3] == wordle[0] && wordle[0] == 'U') || (word4[3] == wordle[2] && wordle[2] == 'U') || (word4[3] == wordle[4] && wordle[4] == 'U') || (word4[4] == wordle[1] && wordle[1] == 'U') || (word4[4] == wordle[0] && wordle[0] == 'U') || (word4[4] == wordle[3] && wordle[3] == 'U') || (word4[4] == wordle[2] && wordle[2] == 'U') || (word5[0] == wordle[1] && wordle[1] == 'U') || (word5[0] == wordle[2] && wordle[2] == 'U') || (word5[0] == wordle[3] && wordle[3] == 'U') || (word5[0] == wordle[4] && wordle[4] == 'U') || (word5[1] == wordle[0] && wordle[0] == 'U') || (word5[1] == wordle[2] && wordle[2] == 'U') || (word5[1] == wordle[3] && wordle[3] == 'U') || (word5[1] == wordle[4] && wordle[4] == 'U') || (word5[2] == wordle[1] && wordle[1] == 'U') || (word5[2] == wordle[0] && wordle[0] == 'U') || (word5[2] == wordle[3] && wordle[3] == 'U') || (word5[2] == wordle[4] && wordle[4] == 'U') || (word5[3] == wordle[1] && wordle[1] == 'U') || (word5[3] == wordle[0] && wordle[0] == 'U') || (word5[3] == wordle[2] && wordle[2] == 'U') || (word5[3] == wordle[4] && wordle[4] == 'U') || (word5[4] == wordle[1] && wordle[1] == 'U') || (word5[4] == wordle[0] && wordle[0] == 'U') || (word5[4] == wordle[3] && wordle[3] == 'U') || (word5[4] == wordle[2] && wordle[2] == 'U') || (word6[0] == wordle[1] && wordle[1] == 'U') || (word6[0] == wordle[2] && wordle[2] == 'U') || (word6[0] == wordle[3] && wordle[3] == 'U') || (word6[0] == wordle[4] && wordle[4] == 'U') || (word6[1] == wordle[0] && wordle[0] == 'U') || (word6[1] == wordle[2] && wordle[2] == 'U') || (word6[1] == wordle[3] && wordle[3] == 'U') || (word6[1] == wordle[4] && wordle[4] == 'U') || (word6[2] == wordle[1] && wordle[1] == 'U') || (word6[2] == wordle[0] && wordle[0] == 'U') || (word6[2] == wordle[3] && wordle[3] == 'U') || (word6[2] == wordle[4] && wordle[4] == 'U') || (word6[3] == wordle[1] && wordle[1] == 'U') || (word6[3] == wordle[0] && wordle[0] == 'U') || (word6[3] == wordle[2] && wordle[2] == 'U') || (word6[3] == wordle[4] && wordle[4] == 'U') || (word6[4] == wordle[1] && wordle[1] == 'U') || (word6[4] == wordle[0] && wordle[0] == 'U') || (word6[4] == wordle[3] && wordle[3] == 'U') || (word6[4] == wordle[2] && wordle[2] == 'U'))
  {
    c2();
    cout << " U ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'U') || (word1[0] != wordle[2] && word1[0] == 'U') || (word1[0] != wordle[3] && word1[0] == 'U') || (word1[0] != wordle[4] && word1[0] == 'U') || (word1[1] != wordle[0] && word1[1] == 'U') || (word1[1] != wordle[2] && word1[1] == 'U') || (word1[1] != wordle[3] && word1[1] == 'U') || (word1[1] != wordle[4] && word1[1] == 'U') || (word1[2] != wordle[1] && word1[2] == 'U') || (word1[2] != wordle[0] && word1[2] == 'U') || (word1[2] != wordle[3] && word1[2] == 'U') || (word1[2] != wordle[4] && word1[2] == 'U') || (word1[3] != wordle[1] && word1[3] == 'U') || (word1[3] != wordle[2] && word1[3] == 'U') || (word1[3] != wordle[0] && word1[3] == 'U') || (word1[3] != wordle[4] && word1[3] == 'U') || (word1[4] != wordle[1] && word1[4] == 'U') || (word1[4] != wordle[2] && word1[4] == 'U') || (word1[4] != wordle[3] && word1[4] == 'U') || (word1[4] != wordle[0] && word1[4] == 'U') || (word2[0] != wordle[1] && word2[0] == 'U') || (word2[0] != wordle[2] && word2[0] == 'U') || (word2[0] != wordle[3] && word2[0] == 'U') || (word2[0] != wordle[4] && word2[0] == 'U') || (word2[1] != wordle[0] && word2[1] == 'U') || (word2[1] != wordle[2] && word2[1] == 'U') || (word2[1] != wordle[3] && word2[1] == 'U') || (word2[1] != wordle[4] && word2[1] == 'U') || (word2[2] != wordle[1] && word2[2] == 'U') || (word2[2] != wordle[0] && word2[2] == 'U') || (word2[2] != wordle[3] && word2[2] == 'U') || (word2[2] != wordle[4] && word2[2] == 'U') || (word2[3] != wordle[1] && word2[3] == 'U') || (word2[3] != wordle[2] && word2[3] == 'U') || (word2[3] != wordle[0] && word2[3] == 'U') || (word2[3] != wordle[4] && word2[3] == 'U') || (word2[4] != wordle[1] && word2[4] == 'U') || (word2[4] != wordle[2] && word2[4] == 'U') || (word2[4] != wordle[3] && word2[4] == 'U') || (word2[4] != wordle[0] && word2[4] == 'U') || (word3[0] != wordle[1] && word3[0] == 'U') || (word3[0] != wordle[2] && word3[0] == 'U') || (word3[0] != wordle[3] && word3[0] == 'U') || (word3[0] != wordle[4] && word3[0] == 'U') || (word3[1] != wordle[0] && word3[1] == 'U') || (word3[1] != wordle[2] && word3[1] == 'U') || (word3[1] != wordle[3] && word3[1] == 'U') || (word3[1] != wordle[4] && word3[1] == 'U') || (word3[2] != wordle[1] && word3[2] == 'U') || (word3[2] != wordle[0] && word3[2] == 'U') || (word3[2] != wordle[3] && word3[2] == 'U') || (word3[2] != wordle[4] && word3[2] == 'U') || (word3[3] != wordle[1] && word3[3] == 'U') || (word3[3] != wordle[2] && word3[3] == 'U') || (word3[3] != wordle[0] && word3[3] == 'U') || (word3[3] != wordle[4] && word3[3] == 'U') || (word3[4] != wordle[1] && word3[4] == 'U') || (word3[4] != wordle[2] && word3[4] == 'U') || (word3[4] != wordle[3] && word3[4] == 'U') || (word3[4] != wordle[0] && word3[4] == 'U') || (word4[0] != wordle[1] && word4[0] == 'U') || (word4[0] != wordle[2] && word4[0] == 'U') || (word4[0] != wordle[3] && word4[0] == 'U') || (word4[0] != wordle[4] && word4[0] == 'U') || (word4[1] != wordle[0] && word4[1] == 'U') || (word4[1] != wordle[2] && word4[1] == 'U') || (word4[1] != wordle[3] && word4[1] == 'U') || (word4[1] != wordle[4] && word4[1] == 'U') || (word4[2] != wordle[1] && word4[2] == 'U') || (word4[2] != wordle[0] && word4[2] == 'U') || (word4[2] != wordle[3] && word4[2] == 'U') || (word4[2] != wordle[4] && word4[2] == 'U') || (word4[3] != wordle[1] && word4[3] == 'U') || (word4[3] != wordle[2] && word4[3] == 'U') || (word4[3] != wordle[0] && word4[3] == 'U') || (word4[3] != wordle[4] && word4[3] == 'U') || (word4[4] != wordle[1] && word4[4] == 'U') || (word4[4] != wordle[2] && word4[4] == 'U') || (word4[4] != wordle[3] && word4[4] == 'U') || (word4[4] != wordle[0] && word4[4] == 'U') || (word5[0] != wordle[1] && word5[0] == 'U') || (word5[0] != wordle[2] && word5[0] == 'U') || (word5[0] != wordle[3] && word5[0] == 'U') || (word5[0] != wordle[4] && word5[0] == 'U') || (word5[1] != wordle[0] && word5[1] == 'U') || (word5[1] != wordle[2] && word5[1] == 'U') || (word5[1] != wordle[3] && word5[1] == 'U') || (word5[1] != wordle[4] && word5[1] == 'U') || (word5[2] != wordle[1] && word5[2] == 'U') || (word5[2] != wordle[0] && word5[2] == 'U') || (word5[2] != wordle[3] && word5[2] == 'U') || (word5[2] != wordle[4] && word5[2] == 'U') || (word5[3] != wordle[1] && word5[3] == 'U') || (word5[3] != wordle[2] && word5[3] == 'U') || (word5[3] != wordle[0] && word5[3] == 'U') || (word5[3] != wordle[4] && word5[3] == 'U') || (word5[4] != wordle[1] && word5[4] == 'U') || (word5[4] != wordle[2] && word5[4] == 'U') || (word5[4] != wordle[3] && word5[4] == 'U') || (word5[4] != wordle[0] && word5[4] == 'U') || (word6[0] != wordle[1] && word6[0] == 'U') || (word6[0] != wordle[2] && word6[0] == 'U') || (word6[0] != wordle[3] && word6[0] == 'U') || (word6[0] != wordle[4] && word6[0] == 'U') || (word6[1] != wordle[0] && word6[1] == 'U') || (word6[1] != wordle[2] && word6[1] == 'U') || (word6[1] != wordle[3] && word6[1] == 'U') || (word6[1] != wordle[4] && word6[1] == 'U') || (word6[2] != wordle[1] && word6[2] == 'U') || (word6[2] != wordle[0] && word6[2] == 'U') || (word6[2] != wordle[3] && word6[2] == 'U') || (word6[2] != wordle[4] && word6[2] == 'U') || (word6[3] != wordle[1] && word6[3] == 'U') || (word6[3] != wordle[2] && word6[3] == 'U') || (word6[3] != wordle[0] && word6[3] == 'U') || (word6[3] != wordle[4] && word6[3] == 'U') || (word6[4] != wordle[1] && word6[4] == 'U') || (word6[4] != wordle[2] && word6[4] == 'U') || (word6[4] != wordle[3] && word6[4] == 'U') || (word6[4] != wordle[0] && word6[4] == 'U'))
  {
    c3();
    cout << " U ";
    cout << RESET;
  }
  else 
  {
    cout << " U ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'I') || (word1[1] == wordle[1] && word1[1] == 'I') || (word1[2] == wordle[2] && word1[2] == 'I') || (word1[3] == wordle[3] && word1[3] == 'I') || (word1[4] == wordle[4] && word1[4] == 'I') || (word2[0] == wordle[0] && word2[0] == 'I') || (word2[1] == wordle[1] && word2[1] == 'I') || (word2[2] == wordle[2] && word2[2] == 'I') || (word2[3] == wordle[3] && word2[3] == 'I') || (word2[4] == wordle[4] && word2[4] == 'I') || (word3[0] == wordle[0] && word3[0] == 'I') || (word3[1] == wordle[1] && word3[1] == 'I') || (word3[2] == wordle[2] && word3[2] == 'I') || (word3[3] == wordle[3] && word3[3] == 'I') || (word3[4] == wordle[4] && word3[4] == 'I') || (word4[0] == wordle[0] && word4[0] == 'I') || (word4[1] == wordle[1] && word4[1] == 'I') || (word4[2] == wordle[2] && word4[2] == 'I') || (word4[3] == wordle[3] && word4[3] == 'I') || (word4[4] == wordle[4] && word4[4] == 'I') || (word5[0] == wordle[0] && word5[0] == 'I') || (word5[1] == wordle[1] && word5[1] == 'I') || (word5[2] == wordle[2] && word5[2] == 'I') || (word5[3] == wordle[3] && word5[3] == 'I') || (word5[4] == wordle[4] && word5[4] == 'I') || (word6[0] == wordle[0] && word6[0] == 'I') || (word6[1] == wordle[1] && word6[1] == 'I') || (word6[2] == wordle[2] && word6[2] == 'I') || (word6[3] == wordle[3] && word6[3] == 'I') || (word6[4] == wordle[4] && word6[4] == 'I'))
  {
    c1();
    cout << " I ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'I') || (word1[0] == wordle[2] && wordle[2] == 'I') || (word1[0] == wordle[3] && wordle[3] == 'I') || (word1[0] == wordle[4] && wordle[4] == 'I') || (word1[1] == wordle[0] && wordle[0] == 'I') || (word1[1] == wordle[2] && wordle[2] == 'I') || (word1[1] == wordle[3] && wordle[3] == 'I') || (word1[1] == wordle[4] && wordle[4] == 'I') || (word1[2] == wordle[1] && wordle[1] == 'I') || (word1[2] == wordle[0] && wordle[0] == 'I') || (word1[2] == wordle[3] && wordle[3] == 'I') || (word1[2] == wordle[4] && wordle[4] == 'I') || (word1[3] == wordle[1] && wordle[1] == 'I') || (word1[3] == wordle[0] && wordle[0] == 'I') || (word1[3] == wordle[2] && wordle[2] == 'I') || (word1[3] == wordle[4] && wordle[4] == 'I') || (word1[4] == wordle[1] && wordle[1] == 'I') || (word1[4] == wordle[0] && wordle[0] == 'I') || (word1[4] == wordle[3] && wordle[3] == 'I') || (word1[4] == wordle[2] && wordle[2] == 'I') || (word2[0] == wordle[1] && wordle[1] == 'I') || (word2[0] == wordle[2] && wordle[2] == 'I') || (word2[0] == wordle[3] && wordle[3] == 'I') || (word2[0] == wordle[4] && wordle[4] == 'I') || (word2[1] == wordle[0] && wordle[0] == 'I') || (word2[1] == wordle[2] && wordle[2] == 'I') || (word2[1] == wordle[3] && wordle[3] == 'I') || (word2[1] == wordle[4] && wordle[4] == 'I') || (word2[2] == wordle[1] && wordle[1] == 'I') || (word2[2] == wordle[0] && wordle[0] == 'I') || (word2[2] == wordle[3] && wordle[3] == 'I') || (word2[2] == wordle[4] && wordle[4] == 'I') || (word2[3] == wordle[1] && wordle[1] == 'I') || (word2[3] == wordle[0] && wordle[0] == 'I') || (word2[3] == wordle[2] && wordle[2] == 'I') || (word2[3] == wordle[4] && wordle[4] == 'I') || (word2[4] == wordle[1] && wordle[1] == 'I') || (word2[4] == wordle[0] && wordle[0] == 'I') || (word2[4] == wordle[3] && wordle[3] == 'I') || (word2[4] == wordle[2] && wordle[2] == 'I') || (word3[0] == wordle[1] && wordle[1] == 'I') || (word3[0] == wordle[2] && wordle[2] == 'I') || (word3[0] == wordle[3] && wordle[3] == 'I') || (word3[0] == wordle[4] && wordle[4] == 'I') || (word3[1] == wordle[0] && wordle[0] == 'I') || (word3[1] == wordle[2] && wordle[2] == 'I') || (word3[1] == wordle[3] && wordle[3] == 'I') || (word3[1] == wordle[4] && wordle[4] == 'I') || (word3[2] == wordle[1] && wordle[1] == 'I') || (word3[2] == wordle[0] && wordle[0] == 'I') || (word3[2] == wordle[3] && wordle[3] == 'I') || (word3[2] == wordle[4] && wordle[4] == 'I') || (word3[3] == wordle[1] && wordle[1] == 'I') || (word3[3] == wordle[0] && wordle[0] == 'I') || (word3[3] == wordle[2] && wordle[2] == 'I') || (word3[3] == wordle[4] && wordle[4] == 'I') || (word3[4] == wordle[1] && wordle[1] == 'I') || (word3[4] == wordle[0] && wordle[0] == 'I') || (word3[4] == wordle[3] && wordle[3] == 'I') || (word3[4] == wordle[2] && wordle[2] == 'I') || (word4[0] == wordle[1] && wordle[1] == 'I') || (word4[0] == wordle[2] && wordle[2] == 'I') || (word4[0] == wordle[3] && wordle[3] == 'I') || (word4[0] == wordle[4] && wordle[4] == 'I') || (word4[1] == wordle[0] && wordle[0] == 'I') || (word4[1] == wordle[2] && wordle[2] == 'I') || (word4[1] == wordle[3] && wordle[3] == 'I') || (word4[1] == wordle[4] && wordle[4] == 'I') || (word4[2] == wordle[1] && wordle[1] == 'I') || (word4[2] == wordle[0] && wordle[0] == 'I') || (word4[2] == wordle[3] && wordle[3] == 'I') || (word4[2] == wordle[4] && wordle[4] == 'I') || (word4[3] == wordle[1] && wordle[1] == 'I') || (word4[3] == wordle[0] && wordle[0] == 'I') || (word4[3] == wordle[2] && wordle[2] == 'I') || (word4[3] == wordle[4] && wordle[4] == 'I') || (word4[4] == wordle[1] && wordle[1] == 'I') || (word4[4] == wordle[0] && wordle[0] == 'I') || (word4[4] == wordle[3] && wordle[3] == 'I') || (word4[4] == wordle[2] && wordle[2] == 'I') || (word5[0] == wordle[1] && wordle[1] == 'I') || (word5[0] == wordle[2] && wordle[2] == 'I') || (word5[0] == wordle[3] && wordle[3] == 'I') || (word5[0] == wordle[4] && wordle[4] == 'I') || (word5[1] == wordle[0] && wordle[0] == 'I') || (word5[1] == wordle[2] && wordle[2] == 'I') || (word5[1] == wordle[3] && wordle[3] == 'I') || (word5[1] == wordle[4] && wordle[4] == 'I') || (word5[2] == wordle[1] && wordle[1] == 'I') || (word5[2] == wordle[0] && wordle[0] == 'I') || (word5[2] == wordle[3] && wordle[3] == 'I') || (word5[2] == wordle[4] && wordle[4] == 'I') || (word5[3] == wordle[1] && wordle[1] == 'I') || (word5[3] == wordle[0] && wordle[0] == 'I') || (word5[3] == wordle[2] && wordle[2] == 'I') || (word5[3] == wordle[4] && wordle[4] == 'I') || (word5[4] == wordle[1] && wordle[1] == 'I') || (word5[4] == wordle[0] && wordle[0] == 'I') || (word5[4] == wordle[3] && wordle[3] == 'I') || (word5[4] == wordle[2] && wordle[2] == 'I') || (word6[0] == wordle[1] && wordle[1] == 'I') || (word6[0] == wordle[2] && wordle[2] == 'I') || (word6[0] == wordle[3] && wordle[3] == 'I') || (word6[0] == wordle[4] && wordle[4] == 'I') || (word6[1] == wordle[0] && wordle[0] == 'I') || (word6[1] == wordle[2] && wordle[2] == 'I') || (word6[1] == wordle[3] && wordle[3] == 'I') || (word6[1] == wordle[4] && wordle[4] == 'I') || (word6[2] == wordle[1] && wordle[1] == 'I') || (word6[2] == wordle[0] && wordle[0] == 'I') || (word6[2] == wordle[3] && wordle[3] == 'I') || (word6[2] == wordle[4] && wordle[4] == 'I') || (word6[3] == wordle[1] && wordle[1] == 'I') || (word6[3] == wordle[0] && wordle[0] == 'I') || (word6[3] == wordle[2] && wordle[2] == 'I') || (word6[3] == wordle[4] && wordle[4] == 'I') || (word6[4] == wordle[1] && wordle[1] == 'I') || (word6[4] == wordle[0] && wordle[0] == 'I') || (word6[4] == wordle[3] && wordle[3] == 'I') || (word6[4] == wordle[2] && wordle[2] == 'I'))
  {
    c2();
    cout << " I ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'I') || (word1[0] != wordle[2] && word1[0] == 'I') || (word1[0] != wordle[3] && word1[0] == 'I') || (word1[0] != wordle[4] && word1[0] == 'I') || (word1[1] != wordle[0] && word1[1] == 'I') || (word1[1] != wordle[2] && word1[1] == 'I') || (word1[1] != wordle[3] && word1[1] == 'I') || (word1[1] != wordle[4] && word1[1] == 'I') || (word1[2] != wordle[1] && word1[2] == 'I') || (word1[2] != wordle[0] && word1[2] == 'I') || (word1[2] != wordle[3] && word1[2] == 'I') || (word1[2] != wordle[4] && word1[2] == 'I') || (word1[3] != wordle[1] && word1[3] == 'I') || (word1[3] != wordle[2] && word1[3] == 'I') || (word1[3] != wordle[0] && word1[3] == 'I') || (word1[3] != wordle[4] && word1[3] == 'I') || (word1[4] != wordle[1] && word1[4] == 'I') || (word1[4] != wordle[2] && word1[4] == 'I') || (word1[4] != wordle[3] && word1[4] == 'I') || (word1[4] != wordle[0] && word1[4] == 'I') || (word2[0] != wordle[1] && word2[0] == 'I') || (word2[0] != wordle[2] && word2[0] == 'I') || (word2[0] != wordle[3] && word2[0] == 'I') || (word2[0] != wordle[4] && word2[0] == 'I') || (word2[1] != wordle[0] && word2[1] == 'I') || (word2[1] != wordle[2] && word2[1] == 'I') || (word2[1] != wordle[3] && word2[1] == 'I') || (word2[1] != wordle[4] && word2[1] == 'I') || (word2[2] != wordle[1] && word2[2] == 'I') || (word2[2] != wordle[0] && word2[2] == 'I') || (word2[2] != wordle[3] && word2[2] == 'I') || (word2[2] != wordle[4] && word2[2] == 'I') || (word2[3] != wordle[1] && word2[3] == 'I') || (word2[3] != wordle[2] && word2[3] == 'I') || (word2[3] != wordle[0] && word2[3] == 'I') || (word2[3] != wordle[4] && word2[3] == 'I') || (word2[4] != wordle[1] && word2[4] == 'I') || (word2[4] != wordle[2] && word2[4] == 'I') || (word2[4] != wordle[3] && word2[4] == 'I') || (word2[4] != wordle[0] && word2[4] == 'I') || (word3[0] != wordle[1] && word3[0] == 'I') || (word3[0] != wordle[2] && word3[0] == 'I') || (word3[0] != wordle[3] && word3[0] == 'I') || (word3[0] != wordle[4] && word3[0] == 'I') || (word3[1] != wordle[0] && word3[1] == 'I') || (word3[1] != wordle[2] && word3[1] == 'I') || (word3[1] != wordle[3] && word3[1] == 'I') || (word3[1] != wordle[4] && word3[1] == 'I') || (word3[2] != wordle[1] && word3[2] == 'I') || (word3[2] != wordle[0] && word3[2] == 'I') || (word3[2] != wordle[3] && word3[2] == 'I') || (word3[2] != wordle[4] && word3[2] == 'I') || (word3[3] != wordle[1] && word3[3] == 'I') || (word3[3] != wordle[2] && word3[3] == 'I') || (word3[3] != wordle[0] && word3[3] == 'I') || (word3[3] != wordle[4] && word3[3] == 'I') || (word3[4] != wordle[1] && word3[4] == 'I') || (word3[4] != wordle[2] && word3[4] == 'I') || (word3[4] != wordle[3] && word3[4] == 'I') || (word3[4] != wordle[0] && word3[4] == 'I') || (word4[0] != wordle[1] && word4[0] == 'I') || (word4[0] != wordle[2] && word4[0] == 'I') || (word4[0] != wordle[3] && word4[0] == 'I') || (word4[0] != wordle[4] && word4[0] == 'I') || (word4[1] != wordle[0] && word4[1] == 'I') || (word4[1] != wordle[2] && word4[1] == 'I') || (word4[1] != wordle[3] && word4[1] == 'I') || (word4[1] != wordle[4] && word4[1] == 'I') || (word4[2] != wordle[1] && word4[2] == 'I') || (word4[2] != wordle[0] && word4[2] == 'I') || (word4[2] != wordle[3] && word4[2] == 'I') || (word4[2] != wordle[4] && word4[2] == 'I') || (word4[3] != wordle[1] && word4[3] == 'I') || (word4[3] != wordle[2] && word4[3] == 'I') || (word4[3] != wordle[0] && word4[3] == 'I') || (word4[3] != wordle[4] && word4[3] == 'I') || (word4[4] != wordle[1] && word4[4] == 'I') || (word4[4] != wordle[2] && word4[4] == 'I') || (word4[4] != wordle[3] && word4[4] == 'I') || (word4[4] != wordle[0] && word4[4] == 'I') || (word5[0] != wordle[1] && word5[0] == 'I') || (word5[0] != wordle[2] && word5[0] == 'I') || (word5[0] != wordle[3] && word5[0] == 'I') || (word5[0] != wordle[4] && word5[0] == 'I') || (word5[1] != wordle[0] && word5[1] == 'I') || (word5[1] != wordle[2] && word5[1] == 'I') || (word5[1] != wordle[3] && word5[1] == 'I') || (word5[1] != wordle[4] && word5[1] == 'I') || (word5[2] != wordle[1] && word5[2] == 'I') || (word5[2] != wordle[0] && word5[2] == 'I') || (word5[2] != wordle[3] && word5[2] == 'I') || (word5[2] != wordle[4] && word5[2] == 'I') || (word5[3] != wordle[1] && word5[3] == 'I') || (word5[3] != wordle[2] && word5[3] == 'I') || (word5[3] != wordle[0] && word5[3] == 'I') || (word5[3] != wordle[4] && word5[3] == 'I') || (word5[4] != wordle[1] && word5[4] == 'I') || (word5[4] != wordle[2] && word5[4] == 'I') || (word5[4] != wordle[3] && word5[4] == 'I') || (word5[4] != wordle[0] && word5[4] == 'I') || (word6[0] != wordle[1] && word6[0] == 'I') || (word6[0] != wordle[2] && word6[0] == 'I') || (word6[0] != wordle[3] && word6[0] == 'I') || (word6[0] != wordle[4] && word6[0] == 'I') || (word6[1] != wordle[0] && word6[1] == 'I') || (word6[1] != wordle[2] && word6[1] == 'I') || (word6[1] != wordle[3] && word6[1] == 'I') || (word6[1] != wordle[4] && word6[1] == 'I') || (word6[2] != wordle[1] && word6[2] == 'I') || (word6[2] != wordle[0] && word6[2] == 'I') || (word6[2] != wordle[3] && word6[2] == 'I') || (word6[2] != wordle[4] && word6[2] == 'I') || (word6[3] != wordle[1] && word6[3] == 'I') || (word6[3] != wordle[2] && word6[3] == 'I') || (word6[3] != wordle[0] && word6[3] == 'I') || (word6[3] != wordle[4] && word6[3] == 'I') || (word6[4] != wordle[1] && word6[4] == 'I') || (word6[4] != wordle[2] && word6[4] == 'I') || (word6[4] != wordle[3] && word6[4] == 'I') || (word6[4] != wordle[0] && word6[4] == 'I'))
  {
    c3();
    cout << " I ";
    cout << RESET;
  }
  else 
  {
    cout << " I ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'O') || (word1[1] == wordle[1] && word1[1] == 'O') || (word1[2] == wordle[2] && word1[2] == 'O') || (word1[3] == wordle[3] && word1[3] == 'O') || (word1[4] == wordle[4] && word1[4] == 'O') || (word2[0] == wordle[0] && word2[0] == 'O') || (word2[1] == wordle[1] && word2[1] == 'O') || (word2[2] == wordle[2] && word2[2] == 'O') || (word2[3] == wordle[3] && word2[3] == 'O') || (word2[4] == wordle[4] && word2[4] == 'O') || (word3[0] == wordle[0] && word3[0] == 'O') || (word3[1] == wordle[1] && word3[1] == 'O') || (word3[2] == wordle[2] && word3[2] == 'O') || (word3[3] == wordle[3] && word3[3] == 'O') || (word3[4] == wordle[4] && word3[4] == 'O') || (word4[0] == wordle[0] && word4[0] == 'O') || (word4[1] == wordle[1] && word4[1] == 'O') || (word4[2] == wordle[2] && word4[2] == 'O') || (word4[3] == wordle[3] && word4[3] == 'O') || (word4[4] == wordle[4] && word4[4] == 'O') || (word5[0] == wordle[0] && word5[0] == 'O') || (word5[1] == wordle[1] && word5[1] == 'O') || (word5[2] == wordle[2] && word5[2] == 'O') || (word5[3] == wordle[3] && word5[3] == 'O') || (word5[4] == wordle[4] && word5[4] == 'O') || (word6[0] == wordle[0] && word6[0] == 'O') || (word6[1] == wordle[1] && word6[1] == 'O') || (word6[2] == wordle[2] && word6[2] == 'O') || (word6[3] == wordle[3] && word6[3] == 'O') || (word6[4] == wordle[4] && word6[4] == 'O'))
  {
    c1();
    cout << " O ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'O') || (word1[0] == wordle[2] && wordle[2] == 'O') || (word1[0] == wordle[3] && wordle[3] == 'O') || (word1[0] == wordle[4] && wordle[4] == 'O') || (word1[1] == wordle[0] && wordle[0] == 'O') || (word1[1] == wordle[2] && wordle[2] == 'O') || (word1[1] == wordle[3] && wordle[3] == 'O') || (word1[1] == wordle[4] && wordle[4] == 'O') || (word1[2] == wordle[1] && wordle[1] == 'O') || (word1[2] == wordle[0] && wordle[0] == 'O') || (word1[2] == wordle[3] && wordle[3] == 'O') || (word1[2] == wordle[4] && wordle[4] == 'O') || (word1[3] == wordle[1] && wordle[1] == 'O') || (word1[3] == wordle[0] && wordle[0] == 'O') || (word1[3] == wordle[2] && wordle[2] == 'O') || (word1[3] == wordle[4] && wordle[4] == 'O') || (word1[4] == wordle[1] && wordle[1] == 'O') || (word1[4] == wordle[0] && wordle[0] == 'O') || (word1[4] == wordle[3] && wordle[3] == 'O') || (word1[4] == wordle[2] && wordle[2] == 'O') || (word2[0] == wordle[1] && wordle[1] == 'O') || (word2[0] == wordle[2] && wordle[2] == 'O') || (word2[0] == wordle[3] && wordle[3] == 'O') || (word2[0] == wordle[4] && wordle[4] == 'O') || (word2[1] == wordle[0] && wordle[0] == 'O') || (word2[1] == wordle[2] && wordle[2] == 'O') || (word2[1] == wordle[3] && wordle[3] == 'O') || (word2[1] == wordle[4] && wordle[4] == 'O') || (word2[2] == wordle[1] && wordle[1] == 'O') || (word2[2] == wordle[0] && wordle[0] == 'O') || (word2[2] == wordle[3] && wordle[3] == 'O') || (word2[2] == wordle[4] && wordle[4] == 'O') || (word2[3] == wordle[1] && wordle[1] == 'O') || (word2[3] == wordle[0] && wordle[0] == 'O') || (word2[3] == wordle[2] && wordle[2] == 'O') || (word2[3] == wordle[4] && wordle[4] == 'O') || (word2[4] == wordle[1] && wordle[1] == 'O') || (word2[4] == wordle[0] && wordle[0] == 'O') || (word2[4] == wordle[3] && wordle[3] == 'O') || (word2[4] == wordle[2] && wordle[2] == 'O') || (word3[0] == wordle[1] && wordle[1] == 'O') || (word3[0] == wordle[2] && wordle[2] == 'O') || (word3[0] == wordle[3] && wordle[3] == 'O') || (word3[0] == wordle[4] && wordle[4] == 'O') || (word3[1] == wordle[0] && wordle[0] == 'O') || (word3[1] == wordle[2] && wordle[2] == 'O') || (word3[1] == wordle[3] && wordle[3] == 'O') || (word3[1] == wordle[4] && wordle[4] == 'O') || (word3[2] == wordle[1] && wordle[1] == 'O') || (word3[2] == wordle[0] && wordle[0] == 'O') || (word3[2] == wordle[3] && wordle[3] == 'O') || (word3[2] == wordle[4] && wordle[4] == 'O') || (word3[3] == wordle[1] && wordle[1] == 'O') || (word3[3] == wordle[0] && wordle[0] == 'O') || (word3[3] == wordle[2] && wordle[2] == 'O') || (word3[3] == wordle[4] && wordle[4] == 'O') || (word3[4] == wordle[1] && wordle[1] == 'O') || (word3[4] == wordle[0] && wordle[0] == 'O') || (word3[4] == wordle[3] && wordle[3] == 'O') || (word3[4] == wordle[2] && wordle[2] == 'O') || (word4[0] == wordle[1] && wordle[1] == 'O') || (word4[0] == wordle[2] && wordle[2] == 'O') || (word4[0] == wordle[3] && wordle[3] == 'O') || (word4[0] == wordle[4] && wordle[4] == 'O') || (word4[1] == wordle[0] && wordle[0] == 'O') || (word4[1] == wordle[2] && wordle[2] == 'O') || (word4[1] == wordle[3] && wordle[3] == 'O') || (word4[1] == wordle[4] && wordle[4] == 'O') || (word4[2] == wordle[1] && wordle[1] == 'O') || (word4[2] == wordle[0] && wordle[0] == 'O') || (word4[2] == wordle[3] && wordle[3] == 'O') || (word4[2] == wordle[4] && wordle[4] == 'O') || (word4[3] == wordle[1] && wordle[1] == 'O') || (word4[3] == wordle[0] && wordle[0] == 'O') || (word4[3] == wordle[2] && wordle[2] == 'O') || (word4[3] == wordle[4] && wordle[4] == 'O') || (word4[4] == wordle[1] && wordle[1] == 'O') || (word4[4] == wordle[0] && wordle[0] == 'O') || (word4[4] == wordle[3] && wordle[3] == 'O') || (word4[4] == wordle[2] && wordle[2] == 'O') || (word5[0] == wordle[1] && wordle[1] == 'O') || (word5[0] == wordle[2] && wordle[2] == 'O') || (word5[0] == wordle[3] && wordle[3] == 'O') || (word5[0] == wordle[4] && wordle[4] == 'O') || (word5[1] == wordle[0] && wordle[0] == 'O') || (word5[1] == wordle[2] && wordle[2] == 'O') || (word5[1] == wordle[3] && wordle[3] == 'O') || (word5[1] == wordle[4] && wordle[4] == 'O') || (word5[2] == wordle[1] && wordle[1] == 'O') || (word5[2] == wordle[0] && wordle[0] == 'O') || (word5[2] == wordle[3] && wordle[3] == 'O') || (word5[2] == wordle[4] && wordle[4] == 'O') || (word5[3] == wordle[1] && wordle[1] == 'O') || (word5[3] == wordle[0] && wordle[0] == 'O') || (word5[3] == wordle[2] && wordle[2] == 'O') || (word5[3] == wordle[4] && wordle[4] == 'O') || (word5[4] == wordle[1] && wordle[1] == 'O') || (word5[4] == wordle[0] && wordle[0] == 'O') || (word5[4] == wordle[3] && wordle[3] == 'O') || (word5[4] == wordle[2] && wordle[2] == 'O') || (word6[0] == wordle[1] && wordle[1] == 'O') || (word6[0] == wordle[2] && wordle[2] == 'O') || (word6[0] == wordle[3] && wordle[3] == 'O') || (word6[0] == wordle[4] && wordle[4] == 'O') || (word6[1] == wordle[0] && wordle[0] == 'O') || (word6[1] == wordle[2] && wordle[2] == 'O') || (word6[1] == wordle[3] && wordle[3] == 'O') || (word6[1] == wordle[4] && wordle[4] == 'O') || (word6[2] == wordle[1] && wordle[1] == 'O') || (word6[2] == wordle[0] && wordle[0] == 'O') || (word6[2] == wordle[3] && wordle[3] == 'O') || (word6[2] == wordle[4] && wordle[4] == 'O') || (word6[3] == wordle[1] && wordle[1] == 'O') || (word6[3] == wordle[0] && wordle[0] == 'O') || (word6[3] == wordle[2] && wordle[2] == 'O') || (word6[3] == wordle[4] && wordle[4] == 'O') || (word6[4] == wordle[1] && wordle[1] == 'O') || (word6[4] == wordle[0] && wordle[0] == 'O') || (word6[4] == wordle[3] && wordle[3] == 'O') || (word6[4] == wordle[2] && wordle[2] == 'O'))
  {
    c2();
    cout << " O ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'O') || (word1[0] != wordle[2] && word1[0] == 'O') || (word1[0] != wordle[3] && word1[0] == 'O') || (word1[0] != wordle[4] && word1[0] == 'O') || (word1[1] != wordle[0] && word1[1] == 'O') || (word1[1] != wordle[2] && word1[1] == 'O') || (word1[1] != wordle[3] && word1[1] == 'O') || (word1[1] != wordle[4] && word1[1] == 'O') || (word1[2] != wordle[1] && word1[2] == 'O') || (word1[2] != wordle[0] && word1[2] == 'O') || (word1[2] != wordle[3] && word1[2] == 'O') || (word1[2] != wordle[4] && word1[2] == 'O') || (word1[3] != wordle[1] && word1[3] == 'O') || (word1[3] != wordle[2] && word1[3] == 'O') || (word1[3] != wordle[0] && word1[3] == 'O') || (word1[3] != wordle[4] && word1[3] == 'O') || (word1[4] != wordle[1] && word1[4] == 'O') || (word1[4] != wordle[2] && word1[4] == 'O') || (word1[4] != wordle[3] && word1[4] == 'O') || (word1[4] != wordle[0] && word1[4] == 'O') || (word2[0] != wordle[1] && word2[0] == 'O') || (word2[0] != wordle[2] && word2[0] == 'O') || (word2[0] != wordle[3] && word2[0] == 'O') || (word2[0] != wordle[4] && word2[0] == 'O') || (word2[1] != wordle[0] && word2[1] == 'O') || (word2[1] != wordle[2] && word2[1] == 'O') || (word2[1] != wordle[3] && word2[1] == 'O') || (word2[1] != wordle[4] && word2[1] == 'O') || (word2[2] != wordle[1] && word2[2] == 'O') || (word2[2] != wordle[0] && word2[2] == 'O') || (word2[2] != wordle[3] && word2[2] == 'O') || (word2[2] != wordle[4] && word2[2] == 'O') || (word2[3] != wordle[1] && word2[3] == 'O') || (word2[3] != wordle[2] && word2[3] == 'O') || (word2[3] != wordle[0] && word2[3] == 'O') || (word2[3] != wordle[4] && word2[3] == 'O') || (word2[4] != wordle[1] && word2[4] == 'O') || (word2[4] != wordle[2] && word2[4] == 'O') || (word2[4] != wordle[3] && word2[4] == 'O') || (word2[4] != wordle[0] && word2[4] == 'O') || (word3[0] != wordle[1] && word3[0] == 'O') || (word3[0] != wordle[2] && word3[0] == 'O') || (word3[0] != wordle[3] && word3[0] == 'O') || (word3[0] != wordle[4] && word3[0] == 'O') || (word3[1] != wordle[0] && word3[1] == 'O') || (word3[1] != wordle[2] && word3[1] == 'O') || (word3[1] != wordle[3] && word3[1] == 'O') || (word3[1] != wordle[4] && word3[1] == 'O') || (word3[2] != wordle[1] && word3[2] == 'O') || (word3[2] != wordle[0] && word3[2] == 'O') || (word3[2] != wordle[3] && word3[2] == 'O') || (word3[2] != wordle[4] && word3[2] == 'O') || (word3[3] != wordle[1] && word3[3] == 'O') || (word3[3] != wordle[2] && word3[3] == 'O') || (word3[3] != wordle[0] && word3[3] == 'O') || (word3[3] != wordle[4] && word3[3] == 'O') || (word3[4] != wordle[1] && word3[4] == 'O') || (word3[4] != wordle[2] && word3[4] == 'O') || (word3[4] != wordle[3] && word3[4] == 'O') || (word3[4] != wordle[0] && word3[4] == 'O') || (word4[0] != wordle[1] && word4[0] == 'O') || (word4[0] != wordle[2] && word4[0] == 'O') || (word4[0] != wordle[3] && word4[0] == 'O') || (word4[0] != wordle[4] && word4[0] == 'O') || (word4[1] != wordle[0] && word4[1] == 'O') || (word4[1] != wordle[2] && word4[1] == 'O') || (word4[1] != wordle[3] && word4[1] == 'O') || (word4[1] != wordle[4] && word4[1] == 'O') || (word4[2] != wordle[1] && word4[2] == 'O') || (word4[2] != wordle[0] && word4[2] == 'O') || (word4[2] != wordle[3] && word4[2] == 'O') || (word4[2] != wordle[4] && word4[2] == 'O') || (word4[3] != wordle[1] && word4[3] == 'O') || (word4[3] != wordle[2] && word4[3] == 'O') || (word4[3] != wordle[0] && word4[3] == 'O') || (word4[3] != wordle[4] && word4[3] == 'O') || (word4[4] != wordle[1] && word4[4] == 'O') || (word4[4] != wordle[2] && word4[4] == 'O') || (word4[4] != wordle[3] && word4[4] == 'O') || (word4[4] != wordle[0] && word4[4] == 'O') || (word5[0] != wordle[1] && word5[0] == 'O') || (word5[0] != wordle[2] && word5[0] == 'O') || (word5[0] != wordle[3] && word5[0] == 'O') || (word5[0] != wordle[4] && word5[0] == 'O') || (word5[1] != wordle[0] && word5[1] == 'O') || (word5[1] != wordle[2] && word5[1] == 'O') || (word5[1] != wordle[3] && word5[1] == 'O') || (word5[1] != wordle[4] && word5[1] == 'O') || (word5[2] != wordle[1] && word5[2] == 'O') || (word5[2] != wordle[0] && word5[2] == 'O') || (word5[2] != wordle[3] && word5[2] == 'O') || (word5[2] != wordle[4] && word5[2] == 'O') || (word5[3] != wordle[1] && word5[3] == 'O') || (word5[3] != wordle[2] && word5[3] == 'O') || (word5[3] != wordle[0] && word5[3] == 'O') || (word5[3] != wordle[4] && word5[3] == 'O') || (word5[4] != wordle[1] && word5[4] == 'O') || (word5[4] != wordle[2] && word5[4] == 'O') || (word5[4] != wordle[3] && word5[4] == 'O') || (word5[4] != wordle[0] && word5[4] == 'O') || (word6[0] != wordle[1] && word6[0] == 'O') || (word6[0] != wordle[2] && word6[0] == 'O') || (word6[0] != wordle[3] && word6[0] == 'O') || (word6[0] != wordle[4] && word6[0] == 'O') || (word6[1] != wordle[0] && word6[1] == 'O') || (word6[1] != wordle[2] && word6[1] == 'O') || (word6[1] != wordle[3] && word6[1] == 'O') || (word6[1] != wordle[4] && word6[1] == 'O') || (word6[2] != wordle[1] && word6[2] == 'O') || (word6[2] != wordle[0] && word6[2] == 'O') || (word6[2] != wordle[3] && word6[2] == 'O') || (word6[2] != wordle[4] && word6[2] == 'O') || (word6[3] != wordle[1] && word6[3] == 'O') || (word6[3] != wordle[2] && word6[3] == 'O') || (word6[3] != wordle[0] && word6[3] == 'O') || (word6[3] != wordle[4] && word6[3] == 'O') || (word6[4] != wordle[1] && word6[4] == 'O') || (word6[4] != wordle[2] && word6[4] == 'O') || (word6[4] != wordle[3] && word6[4] == 'O') || (word6[4] != wordle[0] && word6[4] == 'O'))
  {
    c3();
    cout << " O ";
    cout << RESET;
  }
  else 
  {
    cout << " O ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'P') || (word1[1] == wordle[1] && word1[1] == 'P') || (word1[2] == wordle[2] && word1[2] == 'P') || (word1[3] == wordle[3] && word1[3] == 'P') || (word1[4] == wordle[4] && word1[4] == 'P') || (word2[0] == wordle[0] && word2[0] == 'P') || (word2[1] == wordle[1] && word2[1] == 'P') || (word2[2] == wordle[2] && word2[2] == 'P') || (word2[3] == wordle[3] && word2[3] == 'P') || (word2[4] == wordle[4] && word2[4] == 'P') || (word3[0] == wordle[0] && word3[0] == 'P') || (word3[1] == wordle[1] && word3[1] == 'P') || (word3[2] == wordle[2] && word3[2] == 'P') || (word3[3] == wordle[3] && word3[3] == 'P') || (word3[4] == wordle[4] && word3[4] == 'P') || (word4[0] == wordle[0] && word4[0] == 'P') || (word4[1] == wordle[1] && word4[1] == 'P') || (word4[2] == wordle[2] && word4[2] == 'P') || (word4[3] == wordle[3] && word4[3] == 'P') || (word4[4] == wordle[4] && word4[4] == 'P') || (word5[0] == wordle[0] && word5[0] == 'P') || (word5[1] == wordle[1] && word5[1] == 'P') || (word5[2] == wordle[2] && word5[2] == 'P') || (word5[3] == wordle[3] && word5[3] == 'P') || (word5[4] == wordle[4] && word5[4] == 'P') || (word6[0] == wordle[0] && word6[0] == 'P') || (word6[1] == wordle[1] && word6[1] == 'P') || (word6[2] == wordle[2] && word6[2] == 'P') || (word6[3] == wordle[3] && word6[3] == 'P') || (word6[4] == wordle[4] && word6[4] == 'P'))
  {
    c1();
    cout << " P ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'P') || (word1[0] == wordle[2] && wordle[2] == 'P') || (word1[0] == wordle[3] && wordle[3] == 'P') || (word1[0] == wordle[4] && wordle[4] == 'P') || (word1[1] == wordle[0] && wordle[0] == 'P') || (word1[1] == wordle[2] && wordle[2] == 'P') || (word1[1] == wordle[3] && wordle[3] == 'P') || (word1[1] == wordle[4] && wordle[4] == 'P') || (word1[2] == wordle[1] && wordle[1] == 'P') || (word1[2] == wordle[0] && wordle[0] == 'P') || (word1[2] == wordle[3] && wordle[3] == 'P') || (word1[2] == wordle[4] && wordle[4] == 'P') || (word1[3] == wordle[1] && wordle[1] == 'P') || (word1[3] == wordle[0] && wordle[0] == 'P') || (word1[3] == wordle[2] && wordle[2] == 'P') || (word1[3] == wordle[4] && wordle[4] == 'P') || (word1[4] == wordle[1] && wordle[1] == 'P') || (word1[4] == wordle[0] && wordle[0] == 'P') || (word1[4] == wordle[3] && wordle[3] == 'P') || (word1[4] == wordle[2] && wordle[2] == 'P') || (word2[0] == wordle[1] && wordle[1] == 'P') || (word2[0] == wordle[2] && wordle[2] == 'P') || (word2[0] == wordle[3] && wordle[3] == 'P') || (word2[0] == wordle[4] && wordle[4] == 'P') || (word2[1] == wordle[0] && wordle[0] == 'P') || (word2[1] == wordle[2] && wordle[2] == 'P') || (word2[1] == wordle[3] && wordle[3] == 'P') || (word2[1] == wordle[4] && wordle[4] == 'P') || (word2[2] == wordle[1] && wordle[1] == 'P') || (word2[2] == wordle[0] && wordle[0] == 'P') || (word2[2] == wordle[3] && wordle[3] == 'P') || (word2[2] == wordle[4] && wordle[4] == 'P') || (word2[3] == wordle[1] && wordle[1] == 'P') || (word2[3] == wordle[0] && wordle[0] == 'P') || (word2[3] == wordle[2] && wordle[2] == 'P') || (word2[3] == wordle[4] && wordle[4] == 'P') || (word2[4] == wordle[1] && wordle[1] == 'P') || (word2[4] == wordle[0] && wordle[0] == 'P') || (word2[4] == wordle[3] && wordle[3] == 'P') || (word2[4] == wordle[2] && wordle[2] == 'P') || (word3[0] == wordle[1] && wordle[1] == 'P') || (word3[0] == wordle[2] && wordle[2] == 'P') || (word3[0] == wordle[3] && wordle[3] == 'P') || (word3[0] == wordle[4] && wordle[4] == 'P') || (word3[1] == wordle[0] && wordle[0] == 'P') || (word3[1] == wordle[2] && wordle[2] == 'P') || (word3[1] == wordle[3] && wordle[3] == 'P') || (word3[1] == wordle[4] && wordle[4] == 'P') || (word3[2] == wordle[1] && wordle[1] == 'P') || (word3[2] == wordle[0] && wordle[0] == 'P') || (word3[2] == wordle[3] && wordle[3] == 'P') || (word3[2] == wordle[4] && wordle[4] == 'P') || (word3[3] == wordle[1] && wordle[1] == 'P') || (word3[3] == wordle[0] && wordle[0] == 'P') || (word3[3] == wordle[2] && wordle[2] == 'P') || (word3[3] == wordle[4] && wordle[4] == 'P') || (word3[4] == wordle[1] && wordle[1] == 'P') || (word3[4] == wordle[0] && wordle[0] == 'P') || (word3[4] == wordle[3] && wordle[3] == 'P') || (word3[4] == wordle[2] && wordle[2] == 'P') || (word4[0] == wordle[1] && wordle[1] == 'P') || (word4[0] == wordle[2] && wordle[2] == 'P') || (word4[0] == wordle[3] && wordle[3] == 'P') || (word4[0] == wordle[4] && wordle[4] == 'P') || (word4[1] == wordle[0] && wordle[0] == 'P') || (word4[1] == wordle[2] && wordle[2] == 'P') || (word4[1] == wordle[3] && wordle[3] == 'P') || (word4[1] == wordle[4] && wordle[4] == 'P') || (word4[2] == wordle[1] && wordle[1] == 'P') || (word4[2] == wordle[0] && wordle[0] == 'P') || (word4[2] == wordle[3] && wordle[3] == 'P') || (word4[2] == wordle[4] && wordle[4] == 'P') || (word4[3] == wordle[1] && wordle[1] == 'P') || (word4[3] == wordle[0] && wordle[0] == 'P') || (word4[3] == wordle[2] && wordle[2] == 'P') || (word4[3] == wordle[4] && wordle[4] == 'P') || (word4[4] == wordle[1] && wordle[1] == 'P') || (word4[4] == wordle[0] && wordle[0] == 'P') || (word4[4] == wordle[3] && wordle[3] == 'P') || (word4[4] == wordle[2] && wordle[2] == 'P') || (word5[0] == wordle[1] && wordle[1] == 'P') || (word5[0] == wordle[2] && wordle[2] == 'P') || (word5[0] == wordle[3] && wordle[3] == 'P') || (word5[0] == wordle[4] && wordle[4] == 'P') || (word5[1] == wordle[0] && wordle[0] == 'P') || (word5[1] == wordle[2] && wordle[2] == 'P') || (word5[1] == wordle[3] && wordle[3] == 'P') || (word5[1] == wordle[4] && wordle[4] == 'P') || (word5[2] == wordle[1] && wordle[1] == 'P') || (word5[2] == wordle[0] && wordle[0] == 'P') || (word5[2] == wordle[3] && wordle[3] == 'P') || (word5[2] == wordle[4] && wordle[4] == 'P') || (word5[3] == wordle[1] && wordle[1] == 'P') || (word5[3] == wordle[0] && wordle[0] == 'P') || (word5[3] == wordle[2] && wordle[2] == 'P') || (word5[3] == wordle[4] && wordle[4] == 'P') || (word5[4] == wordle[1] && wordle[1] == 'P') || (word5[4] == wordle[0] && wordle[0] == 'P') || (word5[4] == wordle[3] && wordle[3] == 'P') || (word5[4] == wordle[2] && wordle[2] == 'P') || (word6[0] == wordle[1] && wordle[1] == 'P') || (word6[0] == wordle[2] && wordle[2] == 'P') || (word6[0] == wordle[3] && wordle[3] == 'P') || (word6[0] == wordle[4] && wordle[4] == 'P') || (word6[1] == wordle[0] && wordle[0] == 'P') || (word6[1] == wordle[2] && wordle[2] == 'P') || (word6[1] == wordle[3] && wordle[3] == 'P') || (word6[1] == wordle[4] && wordle[4] == 'P') || (word6[2] == wordle[1] && wordle[1] == 'P') || (word6[2] == wordle[0] && wordle[0] == 'P') || (word6[2] == wordle[3] && wordle[3] == 'P') || (word6[2] == wordle[4] && wordle[4] == 'P') || (word6[3] == wordle[1] && wordle[1] == 'P') || (word6[3] == wordle[0] && wordle[0] == 'P') || (word6[3] == wordle[2] && wordle[2] == 'P') || (word6[3] == wordle[4] && wordle[4] == 'P') || (word6[4] == wordle[1] && wordle[1] == 'P') || (word6[4] == wordle[0] && wordle[0] == 'P') || (word6[4] == wordle[3] && wordle[3] == 'P') || (word6[4] == wordle[2] && wordle[2] == 'P'))
  {
    c2();
    cout << " P ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'P') || (word1[0] != wordle[2] && word1[0] == 'P') || (word1[0] != wordle[3] && word1[0] == 'P') || (word1[0] != wordle[4] && word1[0] == 'P') || (word1[1] != wordle[0] && word1[1] == 'P') || (word1[1] != wordle[2] && word1[1] == 'P') || (word1[1] != wordle[3] && word1[1] == 'P') || (word1[1] != wordle[4] && word1[1] == 'P') || (word1[2] != wordle[1] && word1[2] == 'P') || (word1[2] != wordle[0] && word1[2] == 'P') || (word1[2] != wordle[3] && word1[2] == 'P') || (word1[2] != wordle[4] && word1[2] == 'P') || (word1[3] != wordle[1] && word1[3] == 'P') || (word1[3] != wordle[2] && word1[3] == 'P') || (word1[3] != wordle[0] && word1[3] == 'P') || (word1[3] != wordle[4] && word1[3] == 'P') || (word1[4] != wordle[1] && word1[4] == 'P') || (word1[4] != wordle[2] && word1[4] == 'P') || (word1[4] != wordle[3] && word1[4] == 'P') || (word1[4] != wordle[0] && word1[4] == 'P') || (word2[0] != wordle[1] && word2[0] == 'P') || (word2[0] != wordle[2] && word2[0] == 'P') || (word2[0] != wordle[3] && word2[0] == 'P') || (word2[0] != wordle[4] && word2[0] == 'P') || (word2[1] != wordle[0] && word2[1] == 'P') || (word2[1] != wordle[2] && word2[1] == 'P') || (word2[1] != wordle[3] && word2[1] == 'P') || (word2[1] != wordle[4] && word2[1] == 'P') || (word2[2] != wordle[1] && word2[2] == 'P') || (word2[2] != wordle[0] && word2[2] == 'P') || (word2[2] != wordle[3] && word2[2] == 'P') || (word2[2] != wordle[4] && word2[2] == 'P') || (word2[3] != wordle[1] && word2[3] == 'P') || (word2[3] != wordle[2] && word2[3] == 'P') || (word2[3] != wordle[0] && word2[3] == 'P') || (word2[3] != wordle[4] && word2[3] == 'P') || (word2[4] != wordle[1] && word2[4] == 'P') || (word2[4] != wordle[2] && word2[4] == 'P') || (word2[4] != wordle[3] && word2[4] == 'P') || (word2[4] != wordle[0] && word2[4] == 'P') || (word3[0] != wordle[1] && word3[0] == 'P') || (word3[0] != wordle[2] && word3[0] == 'P') || (word3[0] != wordle[3] && word3[0] == 'P') || (word3[0] != wordle[4] && word3[0] == 'P') || (word3[1] != wordle[0] && word3[1] == 'P') || (word3[1] != wordle[2] && word3[1] == 'P') || (word3[1] != wordle[3] && word3[1] == 'P') || (word3[1] != wordle[4] && word3[1] == 'P') || (word3[2] != wordle[1] && word3[2] == 'P') || (word3[2] != wordle[0] && word3[2] == 'P') || (word3[2] != wordle[3] && word3[2] == 'P') || (word3[2] != wordle[4] && word3[2] == 'P') || (word3[3] != wordle[1] && word3[3] == 'P') || (word3[3] != wordle[2] && word3[3] == 'P') || (word3[3] != wordle[0] && word3[3] == 'P') || (word3[3] != wordle[4] && word3[3] == 'P') || (word3[4] != wordle[1] && word3[4] == 'P') || (word3[4] != wordle[2] && word3[4] == 'P') || (word3[4] != wordle[3] && word3[4] == 'P') || (word3[4] != wordle[0] && word3[4] == 'P') || (word4[0] != wordle[1] && word4[0] == 'P') || (word4[0] != wordle[2] && word4[0] == 'P') || (word4[0] != wordle[3] && word4[0] == 'P') || (word4[0] != wordle[4] && word4[0] == 'P') || (word4[1] != wordle[0] && word4[1] == 'P') || (word4[1] != wordle[2] && word4[1] == 'P') || (word4[1] != wordle[3] && word4[1] == 'P') || (word4[1] != wordle[4] && word4[1] == 'P') || (word4[2] != wordle[1] && word4[2] == 'P') || (word4[2] != wordle[0] && word4[2] == 'P') || (word4[2] != wordle[3] && word4[2] == 'P') || (word4[2] != wordle[4] && word4[2] == 'P') || (word4[3] != wordle[1] && word4[3] == 'P') || (word4[3] != wordle[2] && word4[3] == 'P') || (word4[3] != wordle[0] && word4[3] == 'P') || (word4[3] != wordle[4] && word4[3] == 'P') || (word4[4] != wordle[1] && word4[4] == 'P') || (word4[4] != wordle[2] && word4[4] == 'P') || (word4[4] != wordle[3] && word4[4] == 'P') || (word4[4] != wordle[0] && word4[4] == 'P') || (word5[0] != wordle[1] && word5[0] == 'P') || (word5[0] != wordle[2] && word5[0] == 'P') || (word5[0] != wordle[3] && word5[0] == 'P') || (word5[0] != wordle[4] && word5[0] == 'P') || (word5[1] != wordle[0] && word5[1] == 'P') || (word5[1] != wordle[2] && word5[1] == 'P') || (word5[1] != wordle[3] && word5[1] == 'P') || (word5[1] != wordle[4] && word5[1] == 'P') || (word5[2] != wordle[1] && word5[2] == 'P') || (word5[2] != wordle[0] && word5[2] == 'P') || (word5[2] != wordle[3] && word5[2] == 'P') || (word5[2] != wordle[4] && word5[2] == 'P') || (word5[3] != wordle[1] && word5[3] == 'P') || (word5[3] != wordle[2] && word5[3] == 'P') || (word5[3] != wordle[0] && word5[3] == 'P') || (word5[3] != wordle[4] && word5[3] == 'P') || (word5[4] != wordle[1] && word5[4] == 'P') || (word5[4] != wordle[2] && word5[4] == 'P') || (word5[4] != wordle[3] && word5[4] == 'P') || (word5[4] != wordle[0] && word5[4] == 'P') || (word6[0] != wordle[1] && word6[0] == 'P') || (word6[0] != wordle[2] && word6[0] == 'P') || (word6[0] != wordle[3] && word6[0] == 'P') || (word6[0] != wordle[4] && word6[0] == 'P') || (word6[1] != wordle[0] && word6[1] == 'P') || (word6[1] != wordle[2] && word6[1] == 'P') || (word6[1] != wordle[3] && word6[1] == 'P') || (word6[1] != wordle[4] && word6[1] == 'P') || (word6[2] != wordle[1] && word6[2] == 'P') || (word6[2] != wordle[0] && word6[2] == 'P') || (word6[2] != wordle[3] && word6[2] == 'P') || (word6[2] != wordle[4] && word6[2] == 'P') || (word6[3] != wordle[1] && word6[3] == 'P') || (word6[3] != wordle[2] && word6[3] == 'P') || (word6[3] != wordle[0] && word6[3] == 'P') || (word6[3] != wordle[4] && word6[3] == 'P') || (word6[4] != wordle[1] && word6[4] == 'P') || (word6[4] != wordle[2] && word6[4] == 'P') || (word6[4] != wordle[3] && word6[4] == 'P') || (word6[4] != wordle[0] && word6[4] == 'P'))
  {
    c3();
    cout << " P ";
    cout << RESET;
  }
  else 
  {
    cout << " P ";
  }
  cout << endl;
  cout << endl;
  cout << "  ";
  if ((word1[0] == wordle[0] && word1[0] == 'A') || (word1[1] == wordle[1] && word1[1] == 'A') || (word1[2] == wordle[2] && word1[2] == 'A') || (word1[3] == wordle[3] && word1[3] == 'A') || (word1[4] == wordle[4] && word1[4] == 'A') || (word2[0] == wordle[0] && word2[0] == 'A') || (word2[1] == wordle[1] && word2[1] == 'A') || (word2[2] == wordle[2] && word2[2] == 'A') || (word2[3] == wordle[3] && word2[3] == 'A') || (word2[4] == wordle[4] && word2[4] == 'A') || (word3[0] == wordle[0] && word3[0] == 'A') || (word3[1] == wordle[1] && word3[1] == 'A') || (word3[2] == wordle[2] && word3[2] == 'A') || (word3[3] == wordle[3] && word3[3] == 'A') || (word3[4] == wordle[4] && word3[4] == 'A') || (word4[0] == wordle[0] && word4[0] == 'A') || (word4[1] == wordle[1] && word4[1] == 'A') || (word4[2] == wordle[2] && word4[2] == 'A') || (word4[3] == wordle[3] && word4[3] == 'A') || (word4[4] == wordle[4] && word4[4] == 'A') || (word5[0] == wordle[0] && word5[0] == 'A') || (word5[1] == wordle[1] && word5[1] == 'A') || (word5[2] == wordle[2] && word5[2] == 'A') || (word5[3] == wordle[3] && word5[3] == 'A') || (word5[4] == wordle[4] && word5[4] == 'A') || (word6[0] == wordle[0] && word6[0] == 'A') || (word6[1] == wordle[1] && word6[1] == 'A') || (word6[2] == wordle[2] && word6[2] == 'A') || (word6[3] == wordle[3] && word6[3] == 'A') || (word6[4] == wordle[4] && word6[4] == 'A'))
  {
    c1();
    cout << " A ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'A') || (word1[0] == wordle[2] && wordle[2] == 'A') || (word1[0] == wordle[3] && wordle[3] == 'A') || (word1[0] == wordle[4] && wordle[4] == 'A') || (word1[1] == wordle[0] && wordle[0] == 'A') || (word1[1] == wordle[2] && wordle[2] == 'A') || (word1[1] == wordle[3] && wordle[3] == 'A') || (word1[1] == wordle[4] && wordle[4] == 'A') || (word1[2] == wordle[1] && wordle[1] == 'A') || (word1[2] == wordle[0] && wordle[0] == 'A') || (word1[2] == wordle[3] && wordle[3] == 'A') || (word1[2] == wordle[4] && wordle[4] == 'A') || (word1[3] == wordle[1] && wordle[1] == 'A') || (word1[3] == wordle[0] && wordle[0] == 'A') || (word1[3] == wordle[2] && wordle[2] == 'A') || (word1[3] == wordle[4] && wordle[4] == 'A') || (word1[4] == wordle[1] && wordle[1] == 'A') || (word1[4] == wordle[0] && wordle[0] == 'A') || (word1[4] == wordle[3] && wordle[3] == 'A') || (word1[4] == wordle[2] && wordle[2] == 'A') || (word2[0] == wordle[1] && wordle[1] == 'A') || (word2[0] == wordle[2] && wordle[2] == 'A') || (word2[0] == wordle[3] && wordle[3] == 'A') || (word2[0] == wordle[4] && wordle[4] == 'A') || (word2[1] == wordle[0] && wordle[0] == 'A') || (word2[1] == wordle[2] && wordle[2] == 'A') || (word2[1] == wordle[3] && wordle[3] == 'A') || (word2[1] == wordle[4] && wordle[4] == 'A') || (word2[2] == wordle[1] && wordle[1] == 'A') || (word2[2] == wordle[0] && wordle[0] == 'A') || (word2[2] == wordle[3] && wordle[3] == 'A') || (word2[2] == wordle[4] && wordle[4] == 'A') || (word2[3] == wordle[1] && wordle[1] == 'A') || (word2[3] == wordle[0] && wordle[0] == 'A') || (word2[3] == wordle[2] && wordle[2] == 'A') || (word2[3] == wordle[4] && wordle[4] == 'A') || (word2[4] == wordle[1] && wordle[1] == 'A') || (word2[4] == wordle[0] && wordle[0] == 'A') || (word2[4] == wordle[3] && wordle[3] == 'A') || (word2[4] == wordle[2] && wordle[2] == 'A') || (word3[0] == wordle[1] && wordle[1] == 'A') || (word3[0] == wordle[2] && wordle[2] == 'A') || (word3[0] == wordle[3] && wordle[3] == 'A') || (word3[0] == wordle[4] && wordle[4] == 'A') || (word3[1] == wordle[0] && wordle[0] == 'A') || (word3[1] == wordle[2] && wordle[2] == 'A') || (word3[1] == wordle[3] && wordle[3] == 'A') || (word3[1] == wordle[4] && wordle[4] == 'A') || (word3[2] == wordle[1] && wordle[1] == 'A') || (word3[2] == wordle[0] && wordle[0] == 'A') || (word3[2] == wordle[3] && wordle[3] == 'A') || (word3[2] == wordle[4] && wordle[4] == 'A') || (word3[3] == wordle[1] && wordle[1] == 'A') || (word3[3] == wordle[0] && wordle[0] == 'A') || (word3[3] == wordle[2] && wordle[2] == 'A') || (word3[3] == wordle[4] && wordle[4] == 'A') || (word3[4] == wordle[1] && wordle[1] == 'A') || (word3[4] == wordle[0] && wordle[0] == 'A') || (word3[4] == wordle[3] && wordle[3] == 'A') || (word3[4] == wordle[2] && wordle[2] == 'A') || (word4[0] == wordle[1] && wordle[1] == 'A') || (word4[0] == wordle[2] && wordle[2] == 'A') || (word4[0] == wordle[3] && wordle[3] == 'A') || (word4[0] == wordle[4] && wordle[4] == 'A') || (word4[1] == wordle[0] && wordle[0] == 'A') || (word4[1] == wordle[2] && wordle[2] == 'A') || (word4[1] == wordle[3] && wordle[3] == 'A') || (word4[1] == wordle[4] && wordle[4] == 'A') || (word4[2] == wordle[1] && wordle[1] == 'A') || (word4[2] == wordle[0] && wordle[0] == 'A') || (word4[2] == wordle[3] && wordle[3] == 'A') || (word4[2] == wordle[4] && wordle[4] == 'A') || (word4[3] == wordle[1] && wordle[1] == 'A') || (word4[3] == wordle[0] && wordle[0] == 'A') || (word4[3] == wordle[2] && wordle[2] == 'A') || (word4[3] == wordle[4] && wordle[4] == 'A') || (word4[4] == wordle[1] && wordle[1] == 'A') || (word4[4] == wordle[0] && wordle[0] == 'A') || (word4[4] == wordle[3] && wordle[3] == 'A') || (word4[4] == wordle[2] && wordle[2] == 'A') || (word5[0] == wordle[1] && wordle[1] == 'A') || (word5[0] == wordle[2] && wordle[2] == 'A') || (word5[0] == wordle[3] && wordle[3] == 'A') || (word5[0] == wordle[4] && wordle[4] == 'A') || (word5[1] == wordle[0] && wordle[0] == 'A') || (word5[1] == wordle[2] && wordle[2] == 'A') || (word5[1] == wordle[3] && wordle[3] == 'A') || (word5[1] == wordle[4] && wordle[4] == 'A') || (word5[2] == wordle[1] && wordle[1] == 'A') || (word5[2] == wordle[0] && wordle[0] == 'A') || (word5[2] == wordle[3] && wordle[3] == 'A') || (word5[2] == wordle[4] && wordle[4] == 'A') || (word5[3] == wordle[1] && wordle[1] == 'A') || (word5[3] == wordle[0] && wordle[0] == 'A') || (word5[3] == wordle[2] && wordle[2] == 'A') || (word5[3] == wordle[4] && wordle[4] == 'A') || (word5[4] == wordle[1] && wordle[1] == 'A') || (word5[4] == wordle[0] && wordle[0] == 'A') || (word5[4] == wordle[3] && wordle[3] == 'A') || (word5[4] == wordle[2] && wordle[2] == 'A') || (word6[0] == wordle[1] && wordle[1] == 'A') || (word6[0] == wordle[2] && wordle[2] == 'A') || (word6[0] == wordle[3] && wordle[3] == 'A') || (word6[0] == wordle[4] && wordle[4] == 'A') || (word6[1] == wordle[0] && wordle[0] == 'A') || (word6[1] == wordle[2] && wordle[2] == 'A') || (word6[1] == wordle[3] && wordle[3] == 'A') || (word6[1] == wordle[4] && wordle[4] == 'A') || (word6[2] == wordle[1] && wordle[1] == 'A') || (word6[2] == wordle[0] && wordle[0] == 'A') || (word6[2] == wordle[3] && wordle[3] == 'A') || (word6[2] == wordle[4] && wordle[4] == 'A') || (word6[3] == wordle[1] && wordle[1] == 'A') || (word6[3] == wordle[0] && wordle[0] == 'A') || (word6[3] == wordle[2] && wordle[2] == 'A') || (word6[3] == wordle[4] && wordle[4] == 'A') || (word6[4] == wordle[1] && wordle[1] == 'A') || (word6[4] == wordle[0] && wordle[0] == 'A') || (word6[4] == wordle[3] && wordle[3] == 'A') || (word6[4] == wordle[2] && wordle[2] == 'A'))
  {
    c2();
    cout << " A ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'A') || (word1[0] != wordle[2] && word1[0] == 'A') || (word1[0] != wordle[3] && word1[0] == 'A') || (word1[0] != wordle[4] && word1[0] == 'A') || (word1[1] != wordle[0] && word1[1] == 'A') || (word1[1] != wordle[2] && word1[1] == 'A') || (word1[1] != wordle[3] && word1[1] == 'A') || (word1[1] != wordle[4] && word1[1] == 'A') || (word1[2] != wordle[1] && word1[2] == 'A') || (word1[2] != wordle[0] && word1[2] == 'A') || (word1[2] != wordle[3] && word1[2] == 'A') || (word1[2] != wordle[4] && word1[2] == 'A') || (word1[3] != wordle[1] && word1[3] == 'A') || (word1[3] != wordle[2] && word1[3] == 'A') || (word1[3] != wordle[0] && word1[3] == 'A') || (word1[3] != wordle[4] && word1[3] == 'A') || (word1[4] != wordle[1] && word1[4] == 'A') || (word1[4] != wordle[2] && word1[4] == 'A') || (word1[4] != wordle[3] && word1[4] == 'A') || (word1[4] != wordle[0] && word1[4] == 'A') || (word2[0] != wordle[1] && word2[0] == 'A') || (word2[0] != wordle[2] && word2[0] == 'A') || (word2[0] != wordle[3] && word2[0] == 'A') || (word2[0] != wordle[4] && word2[0] == 'A') || (word2[1] != wordle[0] && word2[1] == 'A') || (word2[1] != wordle[2] && word2[1] == 'A') || (word2[1] != wordle[3] && word2[1] == 'A') || (word2[1] != wordle[4] && word2[1] == 'A') || (word2[2] != wordle[1] && word2[2] == 'A') || (word2[2] != wordle[0] && word2[2] == 'A') || (word2[2] != wordle[3] && word2[2] == 'A') || (word2[2] != wordle[4] && word2[2] == 'A') || (word2[3] != wordle[1] && word2[3] == 'A') || (word2[3] != wordle[2] && word2[3] == 'A') || (word2[3] != wordle[0] && word2[3] == 'A') || (word2[3] != wordle[4] && word2[3] == 'A') || (word2[4] != wordle[1] && word2[4] == 'A') || (word2[4] != wordle[2] && word2[4] == 'A') || (word2[4] != wordle[3] && word2[4] == 'A') || (word2[4] != wordle[0] && word2[4] == 'A') || (word3[0] != wordle[1] && word3[0] == 'A') || (word3[0] != wordle[2] && word3[0] == 'A') || (word3[0] != wordle[3] && word3[0] == 'A') || (word3[0] != wordle[4] && word3[0] == 'A') || (word3[1] != wordle[0] && word3[1] == 'A') || (word3[1] != wordle[2] && word3[1] == 'A') || (word3[1] != wordle[3] && word3[1] == 'A') || (word3[1] != wordle[4] && word3[1] == 'A') || (word3[2] != wordle[1] && word3[2] == 'A') || (word3[2] != wordle[0] && word3[2] == 'A') || (word3[2] != wordle[3] && word3[2] == 'A') || (word3[2] != wordle[4] && word3[2] == 'A') || (word3[3] != wordle[1] && word3[3] == 'A') || (word3[3] != wordle[2] && word3[3] == 'A') || (word3[3] != wordle[0] && word3[3] == 'A') || (word3[3] != wordle[4] && word3[3] == 'A') || (word3[4] != wordle[1] && word3[4] == 'A') || (word3[4] != wordle[2] && word3[4] == 'A') || (word3[4] != wordle[3] && word3[4] == 'A') || (word3[4] != wordle[0] && word3[4] == 'A') || (word4[0] != wordle[1] && word4[0] == 'A') || (word4[0] != wordle[2] && word4[0] == 'A') || (word4[0] != wordle[3] && word4[0] == 'A') || (word4[0] != wordle[4] && word4[0] == 'A') || (word4[1] != wordle[0] && word4[1] == 'A') || (word4[1] != wordle[2] && word4[1] == 'A') || (word4[1] != wordle[3] && word4[1] == 'A') || (word4[1] != wordle[4] && word4[1] == 'A') || (word4[2] != wordle[1] && word4[2] == 'A') || (word4[2] != wordle[0] && word4[2] == 'A') || (word4[2] != wordle[3] && word4[2] == 'A') || (word4[2] != wordle[4] && word4[2] == 'A') || (word4[3] != wordle[1] && word4[3] == 'A') || (word4[3] != wordle[2] && word4[3] == 'A') || (word4[3] != wordle[0] && word4[3] == 'A') || (word4[3] != wordle[4] && word4[3] == 'A') || (word4[4] != wordle[1] && word4[4] == 'A') || (word4[4] != wordle[2] && word4[4] == 'A') || (word4[4] != wordle[3] && word4[4] == 'A') || (word4[4] != wordle[0] && word4[4] == 'A') || (word5[0] != wordle[1] && word5[0] == 'A') || (word5[0] != wordle[2] && word5[0] == 'A') || (word5[0] != wordle[3] && word5[0] == 'A') || (word5[0] != wordle[4] && word5[0] == 'A') || (word5[1] != wordle[0] && word5[1] == 'A') || (word5[1] != wordle[2] && word5[1] == 'A') || (word5[1] != wordle[3] && word5[1] == 'A') || (word5[1] != wordle[4] && word5[1] == 'A') || (word5[2] != wordle[1] && word5[2] == 'A') || (word5[2] != wordle[0] && word5[2] == 'A') || (word5[2] != wordle[3] && word5[2] == 'A') || (word5[2] != wordle[4] && word5[2] == 'A') || (word5[3] != wordle[1] && word5[3] == 'A') || (word5[3] != wordle[2] && word5[3] == 'A') || (word5[3] != wordle[0] && word5[3] == 'A') || (word5[3] != wordle[4] && word5[3] == 'A') || (word5[4] != wordle[1] && word5[4] == 'A') || (word5[4] != wordle[2] && word5[4] == 'A') || (word5[4] != wordle[3] && word5[4] == 'A') || (word5[4] != wordle[0] && word5[4] == 'A') || (word6[0] != wordle[1] && word6[0] == 'A') || (word6[0] != wordle[2] && word6[0] == 'A') || (word6[0] != wordle[3] && word6[0] == 'A') || (word6[0] != wordle[4] && word6[0] == 'A') || (word6[1] != wordle[0] && word6[1] == 'A') || (word6[1] != wordle[2] && word6[1] == 'A') || (word6[1] != wordle[3] && word6[1] == 'A') || (word6[1] != wordle[4] && word6[1] == 'A') || (word6[2] != wordle[1] && word6[2] == 'A') || (word6[2] != wordle[0] && word6[2] == 'A') || (word6[2] != wordle[3] && word6[2] == 'A') || (word6[2] != wordle[4] && word6[2] == 'A') || (word6[3] != wordle[1] && word6[3] == 'A') || (word6[3] != wordle[2] && word6[3] == 'A') || (word6[3] != wordle[0] && word6[3] == 'A') || (word6[3] != wordle[4] && word6[3] == 'A') || (word6[4] != wordle[1] && word6[4] == 'A') || (word6[4] != wordle[2] && word6[4] == 'A') || (word6[4] != wordle[3] && word6[4] == 'A') || (word6[4] != wordle[0] && word6[4] == 'A'))
  {
    c3();
    cout << " A ";
    cout << RESET;
  }
  else 
  {
    cout << " A ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'S') || (word1[1] == wordle[1] && word1[1] == 'S') || (word1[2] == wordle[2] && word1[2] == 'S') || (word1[3] == wordle[3] && word1[3] == 'S') || (word1[4] == wordle[4] && word1[4] == 'S') || (word2[0] == wordle[0] && word2[0] == 'S') || (word2[1] == wordle[1] && word2[1] == 'S') || (word2[2] == wordle[2] && word2[2] == 'S') || (word2[3] == wordle[3] && word2[3] == 'S') || (word2[4] == wordle[4] && word2[4] == 'S') || (word3[0] == wordle[0] && word3[0] == 'S') || (word3[1] == wordle[1] && word3[1] == 'S') || (word3[2] == wordle[2] && word3[2] == 'S') || (word3[3] == wordle[3] && word3[3] == 'S') || (word3[4] == wordle[4] && word3[4] == 'S') || (word4[0] == wordle[0] && word4[0] == 'S') || (word4[1] == wordle[1] && word4[1] == 'S') || (word4[2] == wordle[2] && word4[2] == 'S') || (word4[3] == wordle[3] && word4[3] == 'S') || (word4[4] == wordle[4] && word4[4] == 'S') || (word5[0] == wordle[0] && word5[0] == 'S') || (word5[1] == wordle[1] && word5[1] == 'S') || (word5[2] == wordle[2] && word5[2] == 'S') || (word5[3] == wordle[3] && word5[3] == 'S') || (word5[4] == wordle[4] && word5[4] == 'S') || (word6[0] == wordle[0] && word6[0] == 'S') || (word6[1] == wordle[1] && word6[1] == 'S') || (word6[2] == wordle[2] && word6[2] == 'S') || (word6[3] == wordle[3] && word6[3] == 'S') || (word6[4] == wordle[4] && word6[4] == 'S'))
  {
    c1();
    cout << " S ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'S') || (word1[0] == wordle[2] && wordle[2] == 'S') || (word1[0] == wordle[3] && wordle[3] == 'S') || (word1[0] == wordle[4] && wordle[4] == 'S') || (word1[1] == wordle[0] && wordle[0] == 'S') || (word1[1] == wordle[2] && wordle[2] == 'S') || (word1[1] == wordle[3] && wordle[3] == 'S') || (word1[1] == wordle[4] && wordle[4] == 'S') || (word1[2] == wordle[1] && wordle[1] == 'S') || (word1[2] == wordle[0] && wordle[0] == 'S') || (word1[2] == wordle[3] && wordle[3] == 'S') || (word1[2] == wordle[4] && wordle[4] == 'S') || (word1[3] == wordle[1] && wordle[1] == 'S') || (word1[3] == wordle[0] && wordle[0] == 'S') || (word1[3] == wordle[2] && wordle[2] == 'S') || (word1[3] == wordle[4] && wordle[4] == 'S') || (word1[4] == wordle[1] && wordle[1] == 'S') || (word1[4] == wordle[0] && wordle[0] == 'S') || (word1[4] == wordle[3] && wordle[3] == 'S') || (word1[4] == wordle[2] && wordle[2] == 'S') || (word2[0] == wordle[1] && wordle[1] == 'S') || (word2[0] == wordle[2] && wordle[2] == 'S') || (word2[0] == wordle[3] && wordle[3] == 'S') || (word2[0] == wordle[4] && wordle[4] == 'S') || (word2[1] == wordle[0] && wordle[0] == 'S') || (word2[1] == wordle[2] && wordle[2] == 'S') || (word2[1] == wordle[3] && wordle[3] == 'S') || (word2[1] == wordle[4] && wordle[4] == 'S') || (word2[2] == wordle[1] && wordle[1] == 'S') || (word2[2] == wordle[0] && wordle[0] == 'S') || (word2[2] == wordle[3] && wordle[3] == 'S') || (word2[2] == wordle[4] && wordle[4] == 'S') || (word2[3] == wordle[1] && wordle[1] == 'S') || (word2[3] == wordle[0] && wordle[0] == 'S') || (word2[3] == wordle[2] && wordle[2] == 'S') || (word2[3] == wordle[4] && wordle[4] == 'S') || (word2[4] == wordle[1] && wordle[1] == 'S') || (word2[4] == wordle[0] && wordle[0] == 'S') || (word2[4] == wordle[3] && wordle[3] == 'S') || (word2[4] == wordle[2] && wordle[2] == 'S') || (word3[0] == wordle[1] && wordle[1] == 'S') || (word3[0] == wordle[2] && wordle[2] == 'S') || (word3[0] == wordle[3] && wordle[3] == 'S') || (word3[0] == wordle[4] && wordle[4] == 'S') || (word3[1] == wordle[0] && wordle[0] == 'S') || (word3[1] == wordle[2] && wordle[2] == 'S') || (word3[1] == wordle[3] && wordle[3] == 'S') || (word3[1] == wordle[4] && wordle[4] == 'S') || (word3[2] == wordle[1] && wordle[1] == 'S') || (word3[2] == wordle[0] && wordle[0] == 'S') || (word3[2] == wordle[3] && wordle[3] == 'S') || (word3[2] == wordle[4] && wordle[4] == 'S') || (word3[3] == wordle[1] && wordle[1] == 'S') || (word3[3] == wordle[0] && wordle[0] == 'S') || (word3[3] == wordle[2] && wordle[2] == 'S') || (word3[3] == wordle[4] && wordle[4] == 'S') || (word3[4] == wordle[1] && wordle[1] == 'S') || (word3[4] == wordle[0] && wordle[0] == 'S') || (word3[4] == wordle[3] && wordle[3] == 'S') || (word3[4] == wordle[2] && wordle[2] == 'S') || (word4[0] == wordle[1] && wordle[1] == 'S') || (word4[0] == wordle[2] && wordle[2] == 'S') || (word4[0] == wordle[3] && wordle[3] == 'S') || (word4[0] == wordle[4] && wordle[4] == 'S') || (word4[1] == wordle[0] && wordle[0] == 'S') || (word4[1] == wordle[2] && wordle[2] == 'S') || (word4[1] == wordle[3] && wordle[3] == 'S') || (word4[1] == wordle[4] && wordle[4] == 'S') || (word4[2] == wordle[1] && wordle[1] == 'S') || (word4[2] == wordle[0] && wordle[0] == 'S') || (word4[2] == wordle[3] && wordle[3] == 'S') || (word4[2] == wordle[4] && wordle[4] == 'S') || (word4[3] == wordle[1] && wordle[1] == 'S') || (word4[3] == wordle[0] && wordle[0] == 'S') || (word4[3] == wordle[2] && wordle[2] == 'S') || (word4[3] == wordle[4] && wordle[4] == 'S') || (word4[4] == wordle[1] && wordle[1] == 'S') || (word4[4] == wordle[0] && wordle[0] == 'S') || (word4[4] == wordle[3] && wordle[3] == 'S') || (word4[4] == wordle[2] && wordle[2] == 'S') || (word5[0] == wordle[1] && wordle[1] == 'S') || (word5[0] == wordle[2] && wordle[2] == 'S') || (word5[0] == wordle[3] && wordle[3] == 'S') || (word5[0] == wordle[4] && wordle[4] == 'S') || (word5[1] == wordle[0] && wordle[0] == 'S') || (word5[1] == wordle[2] && wordle[2] == 'S') || (word5[1] == wordle[3] && wordle[3] == 'S') || (word5[1] == wordle[4] && wordle[4] == 'S') || (word5[2] == wordle[1] && wordle[1] == 'S') || (word5[2] == wordle[0] && wordle[0] == 'S') || (word5[2] == wordle[3] && wordle[3] == 'S') || (word5[2] == wordle[4] && wordle[4] == 'S') || (word5[3] == wordle[1] && wordle[1] == 'S') || (word5[3] == wordle[0] && wordle[0] == 'S') || (word5[3] == wordle[2] && wordle[2] == 'S') || (word5[3] == wordle[4] && wordle[4] == 'S') || (word5[4] == wordle[1] && wordle[1] == 'S') || (word5[4] == wordle[0] && wordle[0] == 'S') || (word5[4] == wordle[3] && wordle[3] == 'S') || (word5[4] == wordle[2] && wordle[2] == 'S') || (word6[0] == wordle[1] && wordle[1] == 'S') || (word6[0] == wordle[2] && wordle[2] == 'S') || (word6[0] == wordle[3] && wordle[3] == 'S') || (word6[0] == wordle[4] && wordle[4] == 'S') || (word6[1] == wordle[0] && wordle[0] == 'S') || (word6[1] == wordle[2] && wordle[2] == 'S') || (word6[1] == wordle[3] && wordle[3] == 'S') || (word6[1] == wordle[4] && wordle[4] == 'S') || (word6[2] == wordle[1] && wordle[1] == 'S') || (word6[2] == wordle[0] && wordle[0] == 'S') || (word6[2] == wordle[3] && wordle[3] == 'S') || (word6[2] == wordle[4] && wordle[4] == 'S') || (word6[3] == wordle[1] && wordle[1] == 'S') || (word6[3] == wordle[0] && wordle[0] == 'S') || (word6[3] == wordle[2] && wordle[2] == 'S') || (word6[3] == wordle[4] && wordle[4] == 'S') || (word6[4] == wordle[1] && wordle[1] == 'S') || (word6[4] == wordle[0] && wordle[0] == 'S') || (word6[4] == wordle[3] && wordle[3] == 'S') || (word6[4] == wordle[2] && wordle[2] == 'S'))
  {
    c2();
    cout << " S ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'S') || (word1[0] != wordle[2] && word1[0] == 'S') || (word1[0] != wordle[3] && word1[0] == 'S') || (word1[0] != wordle[4] && word1[0] == 'S') || (word1[1] != wordle[0] && word1[1] == 'S') || (word1[1] != wordle[2] && word1[1] == 'S') || (word1[1] != wordle[3] && word1[1] == 'S') || (word1[1] != wordle[4] && word1[1] == 'S') || (word1[2] != wordle[1] && word1[2] == 'S') || (word1[2] != wordle[0] && word1[2] == 'S') || (word1[2] != wordle[3] && word1[2] == 'S') || (word1[2] != wordle[4] && word1[2] == 'S') || (word1[3] != wordle[1] && word1[3] == 'S') || (word1[3] != wordle[2] && word1[3] == 'S') || (word1[3] != wordle[0] && word1[3] == 'S') || (word1[3] != wordle[4] && word1[3] == 'S') || (word1[4] != wordle[1] && word1[4] == 'S') || (word1[4] != wordle[2] && word1[4] == 'S') || (word1[4] != wordle[3] && word1[4] == 'S') || (word1[4] != wordle[0] && word1[4] == 'S') || (word2[0] != wordle[1] && word2[0] == 'S') || (word2[0] != wordle[2] && word2[0] == 'S') || (word2[0] != wordle[3] && word2[0] == 'S') || (word2[0] != wordle[4] && word2[0] == 'S') || (word2[1] != wordle[0] && word2[1] == 'S') || (word2[1] != wordle[2] && word2[1] == 'S') || (word2[1] != wordle[3] && word2[1] == 'S') || (word2[1] != wordle[4] && word2[1] == 'S') || (word2[2] != wordle[1] && word2[2] == 'S') || (word2[2] != wordle[0] && word2[2] == 'S') || (word2[2] != wordle[3] && word2[2] == 'S') || (word2[2] != wordle[4] && word2[2] == 'S') || (word2[3] != wordle[1] && word2[3] == 'S') || (word2[3] != wordle[2] && word2[3] == 'S') || (word2[3] != wordle[0] && word2[3] == 'S') || (word2[3] != wordle[4] && word2[3] == 'S') || (word2[4] != wordle[1] && word2[4] == 'S') || (word2[4] != wordle[2] && word2[4] == 'S') || (word2[4] != wordle[3] && word2[4] == 'S') || (word2[4] != wordle[0] && word2[4] == 'S') || (word3[0] != wordle[1] && word3[0] == 'S') || (word3[0] != wordle[2] && word3[0] == 'S') || (word3[0] != wordle[3] && word3[0] == 'S') || (word3[0] != wordle[4] && word3[0] == 'S') || (word3[1] != wordle[0] && word3[1] == 'S') || (word3[1] != wordle[2] && word3[1] == 'S') || (word3[1] != wordle[3] && word3[1] == 'S') || (word3[1] != wordle[4] && word3[1] == 'S') || (word3[2] != wordle[1] && word3[2] == 'S') || (word3[2] != wordle[0] && word3[2] == 'S') || (word3[2] != wordle[3] && word3[2] == 'S') || (word3[2] != wordle[4] && word3[2] == 'S') || (word3[3] != wordle[1] && word3[3] == 'S') || (word3[3] != wordle[2] && word3[3] == 'S') || (word3[3] != wordle[0] && word3[3] == 'S') || (word3[3] != wordle[4] && word3[3] == 'S') || (word3[4] != wordle[1] && word3[4] == 'S') || (word3[4] != wordle[2] && word3[4] == 'S') || (word3[4] != wordle[3] && word3[4] == 'S') || (word3[4] != wordle[0] && word3[4] == 'S') || (word4[0] != wordle[1] && word4[0] == 'S') || (word4[0] != wordle[2] && word4[0] == 'S') || (word4[0] != wordle[3] && word4[0] == 'S') || (word4[0] != wordle[4] && word4[0] == 'S') || (word4[1] != wordle[0] && word4[1] == 'S') || (word4[1] != wordle[2] && word4[1] == 'S') || (word4[1] != wordle[3] && word4[1] == 'S') || (word4[1] != wordle[4] && word4[1] == 'S') || (word4[2] != wordle[1] && word4[2] == 'S') || (word4[2] != wordle[0] && word4[2] == 'S') || (word4[2] != wordle[3] && word4[2] == 'S') || (word4[2] != wordle[4] && word4[2] == 'S') || (word4[3] != wordle[1] && word4[3] == 'S') || (word4[3] != wordle[2] && word4[3] == 'S') || (word4[3] != wordle[0] && word4[3] == 'S') || (word4[3] != wordle[4] && word4[3] == 'S') || (word4[4] != wordle[1] && word4[4] == 'S') || (word4[4] != wordle[2] && word4[4] == 'S') || (word4[4] != wordle[3] && word4[4] == 'S') || (word4[4] != wordle[0] && word4[4] == 'S') || (word5[0] != wordle[1] && word5[0] == 'S') || (word5[0] != wordle[2] && word5[0] == 'S') || (word5[0] != wordle[3] && word5[0] == 'S') || (word5[0] != wordle[4] && word5[0] == 'S') || (word5[1] != wordle[0] && word5[1] == 'S') || (word5[1] != wordle[2] && word5[1] == 'S') || (word5[1] != wordle[3] && word5[1] == 'S') || (word5[1] != wordle[4] && word5[1] == 'S') || (word5[2] != wordle[1] && word5[2] == 'S') || (word5[2] != wordle[0] && word5[2] == 'S') || (word5[2] != wordle[3] && word5[2] == 'S') || (word5[2] != wordle[4] && word5[2] == 'S') || (word5[3] != wordle[1] && word5[3] == 'S') || (word5[3] != wordle[2] && word5[3] == 'S') || (word5[3] != wordle[0] && word5[3] == 'S') || (word5[3] != wordle[4] && word5[3] == 'S') || (word5[4] != wordle[1] && word5[4] == 'S') || (word5[4] != wordle[2] && word5[4] == 'S') || (word5[4] != wordle[3] && word5[4] == 'S') || (word5[4] != wordle[0] && word5[4] == 'S') || (word6[0] != wordle[1] && word6[0] == 'S') || (word6[0] != wordle[2] && word6[0] == 'S') || (word6[0] != wordle[3] && word6[0] == 'S') || (word6[0] != wordle[4] && word6[0] == 'S') || (word6[1] != wordle[0] && word6[1] == 'S') || (word6[1] != wordle[2] && word6[1] == 'S') || (word6[1] != wordle[3] && word6[1] == 'S') || (word6[1] != wordle[4] && word6[1] == 'S') || (word6[2] != wordle[1] && word6[2] == 'S') || (word6[2] != wordle[0] && word6[2] == 'S') || (word6[2] != wordle[3] && word6[2] == 'S') || (word6[2] != wordle[4] && word6[2] == 'S') || (word6[3] != wordle[1] && word6[3] == 'S') || (word6[3] != wordle[2] && word6[3] == 'S') || (word6[3] != wordle[0] && word6[3] == 'S') || (word6[3] != wordle[4] && word6[3] == 'S') || (word6[4] != wordle[1] && word6[4] == 'S') || (word6[4] != wordle[2] && word6[4] == 'S') || (word6[4] != wordle[3] && word6[4] == 'S') || (word6[4] != wordle[0] && word6[4] == 'S'))
  {
    c3();
    cout << " S ";
    cout << RESET;
  }
  else 
  {
    cout << " S ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'D') || (word1[1] == wordle[1] && word1[1] == 'D') || (word1[2] == wordle[2] && word1[2] == 'D') || (word1[3] == wordle[3] && word1[3] == 'D') || (word1[4] == wordle[4] && word1[4] == 'D') || (word2[0] == wordle[0] && word2[0] == 'D') || (word2[1] == wordle[1] && word2[1] == 'D') || (word2[2] == wordle[2] && word2[2] == 'D') || (word2[3] == wordle[3] && word2[3] == 'D') || (word2[4] == wordle[4] && word2[4] == 'D') || (word3[0] == wordle[0] && word3[0] == 'D') || (word3[1] == wordle[1] && word3[1] == 'D') || (word3[2] == wordle[2] && word3[2] == 'D') || (word3[3] == wordle[3] && word3[3] == 'D') || (word3[4] == wordle[4] && word3[4] == 'D') || (word4[0] == wordle[0] && word4[0] == 'D') || (word4[1] == wordle[1] && word4[1] == 'D') || (word4[2] == wordle[2] && word4[2] == 'D') || (word4[3] == wordle[3] && word4[3] == 'D') || (word4[4] == wordle[4] && word4[4] == 'D') || (word5[0] == wordle[0] && word5[0] == 'D') || (word5[1] == wordle[1] && word5[1] == 'D') || (word5[2] == wordle[2] && word5[2] == 'D') || (word5[3] == wordle[3] && word5[3] == 'D') || (word5[4] == wordle[4] && word5[4] == 'D') || (word6[0] == wordle[0] && word6[0] == 'D') || (word6[1] == wordle[1] && word6[1] == 'D') || (word6[2] == wordle[2] && word6[2] == 'D') || (word6[3] == wordle[3] && word6[3] == 'D') || (word6[4] == wordle[4] && word6[4] == 'D'))
  {
    c1();
    cout << " D ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'D') || (word1[0] == wordle[2] && wordle[2] == 'D') || (word1[0] == wordle[3] && wordle[3] == 'D') || (word1[0] == wordle[4] && wordle[4] == 'D') || (word1[1] == wordle[0] && wordle[0] == 'D') || (word1[1] == wordle[2] && wordle[2] == 'D') || (word1[1] == wordle[3] && wordle[3] == 'D') || (word1[1] == wordle[4] && wordle[4] == 'D') || (word1[2] == wordle[1] && wordle[1] == 'D') || (word1[2] == wordle[0] && wordle[0] == 'D') || (word1[2] == wordle[3] && wordle[3] == 'D') || (word1[2] == wordle[4] && wordle[4] == 'D') || (word1[3] == wordle[1] && wordle[1] == 'D') || (word1[3] == wordle[0] && wordle[0] == 'D') || (word1[3] == wordle[2] && wordle[2] == 'D') || (word1[3] == wordle[4] && wordle[4] == 'D') || (word1[4] == wordle[1] && wordle[1] == 'D') || (word1[4] == wordle[0] && wordle[0] == 'D') || (word1[4] == wordle[3] && wordle[3] == 'D') || (word1[4] == wordle[2] && wordle[2] == 'D') || (word2[0] == wordle[1] && wordle[1] == 'D') || (word2[0] == wordle[2] && wordle[2] == 'D') || (word2[0] == wordle[3] && wordle[3] == 'D') || (word2[0] == wordle[4] && wordle[4] == 'D') || (word2[1] == wordle[0] && wordle[0] == 'D') || (word2[1] == wordle[2] && wordle[2] == 'D') || (word2[1] == wordle[3] && wordle[3] == 'D') || (word2[1] == wordle[4] && wordle[4] == 'D') || (word2[2] == wordle[1] && wordle[1] == 'D') || (word2[2] == wordle[0] && wordle[0] == 'D') || (word2[2] == wordle[3] && wordle[3] == 'D') || (word2[2] == wordle[4] && wordle[4] == 'D') || (word2[3] == wordle[1] && wordle[1] == 'D') || (word2[3] == wordle[0] && wordle[0] == 'D') || (word2[3] == wordle[2] && wordle[2] == 'D') || (word2[3] == wordle[4] && wordle[4] == 'D') || (word2[4] == wordle[1] && wordle[1] == 'D') || (word2[4] == wordle[0] && wordle[0] == 'D') || (word2[4] == wordle[3] && wordle[3] == 'D') || (word2[4] == wordle[2] && wordle[2] == 'D') || (word3[0] == wordle[1] && wordle[1] == 'D') || (word3[0] == wordle[2] && wordle[2] == 'D') || (word3[0] == wordle[3] && wordle[3] == 'D') || (word3[0] == wordle[4] && wordle[4] == 'D') || (word3[1] == wordle[0] && wordle[0] == 'D') || (word3[1] == wordle[2] && wordle[2] == 'D') || (word3[1] == wordle[3] && wordle[3] == 'D') || (word3[1] == wordle[4] && wordle[4] == 'D') || (word3[2] == wordle[1] && wordle[1] == 'D') || (word3[2] == wordle[0] && wordle[0] == 'D') || (word3[2] == wordle[3] && wordle[3] == 'D') || (word3[2] == wordle[4] && wordle[4] == 'D') || (word3[3] == wordle[1] && wordle[1] == 'D') || (word3[3] == wordle[0] && wordle[0] == 'D') || (word3[3] == wordle[2] && wordle[2] == 'D') || (word3[3] == wordle[4] && wordle[4] == 'D') || (word3[4] == wordle[1] && wordle[1] == 'D') || (word3[4] == wordle[0] && wordle[0] == 'D') || (word3[4] == wordle[3] && wordle[3] == 'D') || (word3[4] == wordle[2] && wordle[2] == 'D') || (word4[0] == wordle[1] && wordle[1] == 'D') || (word4[0] == wordle[2] && wordle[2] == 'D') || (word4[0] == wordle[3] && wordle[3] == 'D') || (word4[0] == wordle[4] && wordle[4] == 'D') || (word4[1] == wordle[0] && wordle[0] == 'D') || (word4[1] == wordle[2] && wordle[2] == 'D') || (word4[1] == wordle[3] && wordle[3] == 'D') || (word4[1] == wordle[4] && wordle[4] == 'D') || (word4[2] == wordle[1] && wordle[1] == 'D') || (word4[2] == wordle[0] && wordle[0] == 'D') || (word4[2] == wordle[3] && wordle[3] == 'D') || (word4[2] == wordle[4] && wordle[4] == 'D') || (word4[3] == wordle[1] && wordle[1] == 'D') || (word4[3] == wordle[0] && wordle[0] == 'D') || (word4[3] == wordle[2] && wordle[2] == 'D') || (word4[3] == wordle[4] && wordle[4] == 'D') || (word4[4] == wordle[1] && wordle[1] == 'D') || (word4[4] == wordle[0] && wordle[0] == 'D') || (word4[4] == wordle[3] && wordle[3] == 'D') || (word4[4] == wordle[2] && wordle[2] == 'D') || (word5[0] == wordle[1] && wordle[1] == 'D') || (word5[0] == wordle[2] && wordle[2] == 'D') || (word5[0] == wordle[3] && wordle[3] == 'D') || (word5[0] == wordle[4] && wordle[4] == 'D') || (word5[1] == wordle[0] && wordle[0] == 'D') || (word5[1] == wordle[2] && wordle[2] == 'D') || (word5[1] == wordle[3] && wordle[3] == 'D') || (word5[1] == wordle[4] && wordle[4] == 'D') || (word5[2] == wordle[1] && wordle[1] == 'D') || (word5[2] == wordle[0] && wordle[0] == 'D') || (word5[2] == wordle[3] && wordle[3] == 'D') || (word5[2] == wordle[4] && wordle[4] == 'D') || (word5[3] == wordle[1] && wordle[1] == 'D') || (word5[3] == wordle[0] && wordle[0] == 'D') || (word5[3] == wordle[2] && wordle[2] == 'D') || (word5[3] == wordle[4] && wordle[4] == 'D') || (word5[4] == wordle[1] && wordle[1] == 'D') || (word5[4] == wordle[0] && wordle[0] == 'D') || (word5[4] == wordle[3] && wordle[3] == 'D') || (word5[4] == wordle[2] && wordle[2] == 'D') || (word6[0] == wordle[1] && wordle[1] == 'D') || (word6[0] == wordle[2] && wordle[2] == 'D') || (word6[0] == wordle[3] && wordle[3] == 'D') || (word6[0] == wordle[4] && wordle[4] == 'D') || (word6[1] == wordle[0] && wordle[0] == 'D') || (word6[1] == wordle[2] && wordle[2] == 'D') || (word6[1] == wordle[3] && wordle[3] == 'D') || (word6[1] == wordle[4] && wordle[4] == 'D') || (word6[2] == wordle[1] && wordle[1] == 'D') || (word6[2] == wordle[0] && wordle[0] == 'D') || (word6[2] == wordle[3] && wordle[3] == 'D') || (word6[2] == wordle[4] && wordle[4] == 'D') || (word6[3] == wordle[1] && wordle[1] == 'D') || (word6[3] == wordle[0] && wordle[0] == 'D') || (word6[3] == wordle[2] && wordle[2] == 'D') || (word6[3] == wordle[4] && wordle[4] == 'D') || (word6[4] == wordle[1] && wordle[1] == 'D') || (word6[4] == wordle[0] && wordle[0] == 'D') || (word6[4] == wordle[3] && wordle[3] == 'D') || (word6[4] == wordle[2] && wordle[2] == 'D'))
  {
    c2();
    cout << " D ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'D') || (word1[0] != wordle[2] && word1[0] == 'D') || (word1[0] != wordle[3] && word1[0] == 'D') || (word1[0] != wordle[4] && word1[0] == 'D') || (word1[1] != wordle[0] && word1[1] == 'D') || (word1[1] != wordle[2] && word1[1] == 'D') || (word1[1] != wordle[3] && word1[1] == 'D') || (word1[1] != wordle[4] && word1[1] == 'D') || (word1[2] != wordle[1] && word1[2] == 'D') || (word1[2] != wordle[0] && word1[2] == 'D') || (word1[2] != wordle[3] && word1[2] == 'D') || (word1[2] != wordle[4] && word1[2] == 'D') || (word1[3] != wordle[1] && word1[3] == 'D') || (word1[3] != wordle[2] && word1[3] == 'D') || (word1[3] != wordle[0] && word1[3] == 'D') || (word1[3] != wordle[4] && word1[3] == 'D') || (word1[4] != wordle[1] && word1[4] == 'D') || (word1[4] != wordle[2] && word1[4] == 'D') || (word1[4] != wordle[3] && word1[4] == 'D') || (word1[4] != wordle[0] && word1[4] == 'D') || (word2[0] != wordle[1] && word2[0] == 'D') || (word2[0] != wordle[2] && word2[0] == 'D') || (word2[0] != wordle[3] && word2[0] == 'D') || (word2[0] != wordle[4] && word2[0] == 'D') || (word2[1] != wordle[0] && word2[1] == 'D') || (word2[1] != wordle[2] && word2[1] == 'D') || (word2[1] != wordle[3] && word2[1] == 'D') || (word2[1] != wordle[4] && word2[1] == 'D') || (word2[2] != wordle[1] && word2[2] == 'D') || (word2[2] != wordle[0] && word2[2] == 'D') || (word2[2] != wordle[3] && word2[2] == 'D') || (word2[2] != wordle[4] && word2[2] == 'D') || (word2[3] != wordle[1] && word2[3] == 'D') || (word2[3] != wordle[2] && word2[3] == 'D') || (word2[3] != wordle[0] && word2[3] == 'D') || (word2[3] != wordle[4] && word2[3] == 'D') || (word2[4] != wordle[1] && word2[4] == 'D') || (word2[4] != wordle[2] && word2[4] == 'D') || (word2[4] != wordle[3] && word2[4] == 'D') || (word2[4] != wordle[0] && word2[4] == 'D') || (word3[0] != wordle[1] && word3[0] == 'D') || (word3[0] != wordle[2] && word3[0] == 'D') || (word3[0] != wordle[3] && word3[0] == 'D') || (word3[0] != wordle[4] && word3[0] == 'D') || (word3[1] != wordle[0] && word3[1] == 'D') || (word3[1] != wordle[2] && word3[1] == 'D') || (word3[1] != wordle[3] && word3[1] == 'D') || (word3[1] != wordle[4] && word3[1] == 'D') || (word3[2] != wordle[1] && word3[2] == 'D') || (word3[2] != wordle[0] && word3[2] == 'D') || (word3[2] != wordle[3] && word3[2] == 'D') || (word3[2] != wordle[4] && word3[2] == 'D') || (word3[3] != wordle[1] && word3[3] == 'D') || (word3[3] != wordle[2] && word3[3] == 'D') || (word3[3] != wordle[0] && word3[3] == 'D') || (word3[3] != wordle[4] && word3[3] == 'D') || (word3[4] != wordle[1] && word3[4] == 'D') || (word3[4] != wordle[2] && word3[4] == 'D') || (word3[4] != wordle[3] && word3[4] == 'D') || (word3[4] != wordle[0] && word3[4] == 'D') || (word4[0] != wordle[1] && word4[0] == 'D') || (word4[0] != wordle[2] && word4[0] == 'D') || (word4[0] != wordle[3] && word4[0] == 'D') || (word4[0] != wordle[4] && word4[0] == 'D') || (word4[1] != wordle[0] && word4[1] == 'D') || (word4[1] != wordle[2] && word4[1] == 'D') || (word4[1] != wordle[3] && word4[1] == 'D') || (word4[1] != wordle[4] && word4[1] == 'D') || (word4[2] != wordle[1] && word4[2] == 'D') || (word4[2] != wordle[0] && word4[2] == 'D') || (word4[2] != wordle[3] && word4[2] == 'D') || (word4[2] != wordle[4] && word4[2] == 'D') || (word4[3] != wordle[1] && word4[3] == 'D') || (word4[3] != wordle[2] && word4[3] == 'D') || (word4[3] != wordle[0] && word4[3] == 'D') || (word4[3] != wordle[4] && word4[3] == 'D') || (word4[4] != wordle[1] && word4[4] == 'D') || (word4[4] != wordle[2] && word4[4] == 'D') || (word4[4] != wordle[3] && word4[4] == 'D') || (word4[4] != wordle[0] && word4[4] == 'D') || (word5[0] != wordle[1] && word5[0] == 'D') || (word5[0] != wordle[2] && word5[0] == 'D') || (word5[0] != wordle[3] && word5[0] == 'D') || (word5[0] != wordle[4] && word5[0] == 'D') || (word5[1] != wordle[0] && word5[1] == 'D') || (word5[1] != wordle[2] && word5[1] == 'D') || (word5[1] != wordle[3] && word5[1] == 'D') || (word5[1] != wordle[4] && word5[1] == 'D') || (word5[2] != wordle[1] && word5[2] == 'D') || (word5[2] != wordle[0] && word5[2] == 'D') || (word5[2] != wordle[3] && word5[2] == 'D') || (word5[2] != wordle[4] && word5[2] == 'D') || (word5[3] != wordle[1] && word5[3] == 'D') || (word5[3] != wordle[2] && word5[3] == 'D') || (word5[3] != wordle[0] && word5[3] == 'D') || (word5[3] != wordle[4] && word5[3] == 'D') || (word5[4] != wordle[1] && word5[4] == 'D') || (word5[4] != wordle[2] && word5[4] == 'D') || (word5[4] != wordle[3] && word5[4] == 'D') || (word5[4] != wordle[0] && word5[4] == 'D') || (word6[0] != wordle[1] && word6[0] == 'D') || (word6[0] != wordle[2] && word6[0] == 'D') || (word6[0] != wordle[3] && word6[0] == 'D') || (word6[0] != wordle[4] && word6[0] == 'D') || (word6[1] != wordle[0] && word6[1] == 'D') || (word6[1] != wordle[2] && word6[1] == 'D') || (word6[1] != wordle[3] && word6[1] == 'D') || (word6[1] != wordle[4] && word6[1] == 'D') || (word6[2] != wordle[1] && word6[2] == 'D') || (word6[2] != wordle[0] && word6[2] == 'D') || (word6[2] != wordle[3] && word6[2] == 'D') || (word6[2] != wordle[4] && word6[2] == 'D') || (word6[3] != wordle[1] && word6[3] == 'D') || (word6[3] != wordle[2] && word6[3] == 'D') || (word6[3] != wordle[0] && word6[3] == 'D') || (word6[3] != wordle[4] && word6[3] == 'D') || (word6[4] != wordle[1] && word6[4] == 'D') || (word6[4] != wordle[2] && word6[4] == 'D') || (word6[4] != wordle[3] && word6[4] == 'D') || (word6[4] != wordle[0] && word6[4] == 'D'))
  {
    c3();
    cout << " D ";
    cout << RESET;
  }
  else 
  {
    cout << " D ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'F') || (word1[1] == wordle[1] && word1[1] == 'F') || (word1[2] == wordle[2] && word1[2] == 'F') || (word1[3] == wordle[3] && word1[3] == 'F') || (word1[4] == wordle[4] && word1[4] == 'F') || (word2[0] == wordle[0] && word2[0] == 'F') || (word2[1] == wordle[1] && word2[1] == 'F') || (word2[2] == wordle[2] && word2[2] == 'F') || (word2[3] == wordle[3] && word2[3] == 'F') || (word2[4] == wordle[4] && word2[4] == 'F') || (word3[0] == wordle[0] && word3[0] == 'F') || (word3[1] == wordle[1] && word3[1] == 'F') || (word3[2] == wordle[2] && word3[2] == 'F') || (word3[3] == wordle[3] && word3[3] == 'F') || (word3[4] == wordle[4] && word3[4] == 'F') || (word4[0] == wordle[0] && word4[0] == 'F') || (word4[1] == wordle[1] && word4[1] == 'F') || (word4[2] == wordle[2] && word4[2] == 'F') || (word4[3] == wordle[3] && word4[3] == 'F') || (word4[4] == wordle[4] && word4[4] == 'F') || (word5[0] == wordle[0] && word5[0] == 'F') || (word5[1] == wordle[1] && word5[1] == 'F') || (word5[2] == wordle[2] && word5[2] == 'F') || (word5[3] == wordle[3] && word5[3] == 'F') || (word5[4] == wordle[4] && word5[4] == 'F') || (word6[0] == wordle[0] && word6[0] == 'F') || (word6[1] == wordle[1] && word6[1] == 'F') || (word6[2] == wordle[2] && word6[2] == 'F') || (word6[3] == wordle[3] && word6[3] == 'F') || (word6[4] == wordle[4] && word6[4] == 'F'))
  {
    c1();
    cout << " F ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'F') || (word1[0] == wordle[2] && wordle[2] == 'F') || (word1[0] == wordle[3] && wordle[3] == 'F') || (word1[0] == wordle[4] && wordle[4] == 'F') || (word1[1] == wordle[0] && wordle[0] == 'F') || (word1[1] == wordle[2] && wordle[2] == 'F') || (word1[1] == wordle[3] && wordle[3] == 'F') || (word1[1] == wordle[4] && wordle[4] == 'F') || (word1[2] == wordle[1] && wordle[1] == 'F') || (word1[2] == wordle[0] && wordle[0] == 'F') || (word1[2] == wordle[3] && wordle[3] == 'F') || (word1[2] == wordle[4] && wordle[4] == 'F') || (word1[3] == wordle[1] && wordle[1] == 'F') || (word1[3] == wordle[0] && wordle[0] == 'F') || (word1[3] == wordle[2] && wordle[2] == 'F') || (word1[3] == wordle[4] && wordle[4] == 'F') || (word1[4] == wordle[1] && wordle[1] == 'F') || (word1[4] == wordle[0] && wordle[0] == 'F') || (word1[4] == wordle[3] && wordle[3] == 'F') || (word1[4] == wordle[2] && wordle[2] == 'F') || (word2[0] == wordle[1] && wordle[1] == 'F') || (word2[0] == wordle[2] && wordle[2] == 'F') || (word2[0] == wordle[3] && wordle[3] == 'F') || (word2[0] == wordle[4] && wordle[4] == 'F') || (word2[1] == wordle[0] && wordle[0] == 'F') || (word2[1] == wordle[2] && wordle[2] == 'F') || (word2[1] == wordle[3] && wordle[3] == 'F') || (word2[1] == wordle[4] && wordle[4] == 'F') || (word2[2] == wordle[1] && wordle[1] == 'F') || (word2[2] == wordle[0] && wordle[0] == 'F') || (word2[2] == wordle[3] && wordle[3] == 'F') || (word2[2] == wordle[4] && wordle[4] == 'F') || (word2[3] == wordle[1] && wordle[1] == 'F') || (word2[3] == wordle[0] && wordle[0] == 'F') || (word2[3] == wordle[2] && wordle[2] == 'F') || (word2[3] == wordle[4] && wordle[4] == 'F') || (word2[4] == wordle[1] && wordle[1] == 'F') || (word2[4] == wordle[0] && wordle[0] == 'F') || (word2[4] == wordle[3] && wordle[3] == 'F') || (word2[4] == wordle[2] && wordle[2] == 'F') || (word3[0] == wordle[1] && wordle[1] == 'F') || (word3[0] == wordle[2] && wordle[2] == 'F') || (word3[0] == wordle[3] && wordle[3] == 'F') || (word3[0] == wordle[4] && wordle[4] == 'F') || (word3[1] == wordle[0] && wordle[0] == 'F') || (word3[1] == wordle[2] && wordle[2] == 'F') || (word3[1] == wordle[3] && wordle[3] == 'F') || (word3[1] == wordle[4] && wordle[4] == 'F') || (word3[2] == wordle[1] && wordle[1] == 'F') || (word3[2] == wordle[0] && wordle[0] == 'F') || (word3[2] == wordle[3] && wordle[3] == 'F') || (word3[2] == wordle[4] && wordle[4] == 'F') || (word3[3] == wordle[1] && wordle[1] == 'F') || (word3[3] == wordle[0] && wordle[0] == 'F') || (word3[3] == wordle[2] && wordle[2] == 'F') || (word3[3] == wordle[4] && wordle[4] == 'F') || (word3[4] == wordle[1] && wordle[1] == 'F') || (word3[4] == wordle[0] && wordle[0] == 'F') || (word3[4] == wordle[3] && wordle[3] == 'F') || (word3[4] == wordle[2] && wordle[2] == 'F') || (word4[0] == wordle[1] && wordle[1] == 'F') || (word4[0] == wordle[2] && wordle[2] == 'F') || (word4[0] == wordle[3] && wordle[3] == 'F') || (word4[0] == wordle[4] && wordle[4] == 'F') || (word4[1] == wordle[0] && wordle[0] == 'F') || (word4[1] == wordle[2] && wordle[2] == 'F') || (word4[1] == wordle[3] && wordle[3] == 'F') || (word4[1] == wordle[4] && wordle[4] == 'F') || (word4[2] == wordle[1] && wordle[1] == 'F') || (word4[2] == wordle[0] && wordle[0] == 'F') || (word4[2] == wordle[3] && wordle[3] == 'F') || (word4[2] == wordle[4] && wordle[4] == 'F') || (word4[3] == wordle[1] && wordle[1] == 'F') || (word4[3] == wordle[0] && wordle[0] == 'F') || (word4[3] == wordle[2] && wordle[2] == 'F') || (word4[3] == wordle[4] && wordle[4] == 'F') || (word4[4] == wordle[1] && wordle[1] == 'F') || (word4[4] == wordle[0] && wordle[0] == 'F') || (word4[4] == wordle[3] && wordle[3] == 'F') || (word4[4] == wordle[2] && wordle[2] == 'F') || (word5[0] == wordle[1] && wordle[1] == 'F') || (word5[0] == wordle[2] && wordle[2] == 'F') || (word5[0] == wordle[3] && wordle[3] == 'F') || (word5[0] == wordle[4] && wordle[4] == 'F') || (word5[1] == wordle[0] && wordle[0] == 'F') || (word5[1] == wordle[2] && wordle[2] == 'F') || (word5[1] == wordle[3] && wordle[3] == 'F') || (word5[1] == wordle[4] && wordle[4] == 'F') || (word5[2] == wordle[1] && wordle[1] == 'F') || (word5[2] == wordle[0] && wordle[0] == 'F') || (word5[2] == wordle[3] && wordle[3] == 'F') || (word5[2] == wordle[4] && wordle[4] == 'F') || (word5[3] == wordle[1] && wordle[1] == 'F') || (word5[3] == wordle[0] && wordle[0] == 'F') || (word5[3] == wordle[2] && wordle[2] == 'F') || (word5[3] == wordle[4] && wordle[4] == 'F') || (word5[4] == wordle[1] && wordle[1] == 'F') || (word5[4] == wordle[0] && wordle[0] == 'F') || (word5[4] == wordle[3] && wordle[3] == 'F') || (word5[4] == wordle[2] && wordle[2] == 'F') || (word6[0] == wordle[1] && wordle[1] == 'F') || (word6[0] == wordle[2] && wordle[2] == 'F') || (word6[0] == wordle[3] && wordle[3] == 'F') || (word6[0] == wordle[4] && wordle[4] == 'F') || (word6[1] == wordle[0] && wordle[0] == 'F') || (word6[1] == wordle[2] && wordle[2] == 'F') || (word6[1] == wordle[3] && wordle[3] == 'F') || (word6[1] == wordle[4] && wordle[4] == 'F') || (word6[2] == wordle[1] && wordle[1] == 'F') || (word6[2] == wordle[0] && wordle[0] == 'F') || (word6[2] == wordle[3] && wordle[3] == 'F') || (word6[2] == wordle[4] && wordle[4] == 'F') || (word6[3] == wordle[1] && wordle[1] == 'F') || (word6[3] == wordle[0] && wordle[0] == 'F') || (word6[3] == wordle[2] && wordle[2] == 'F') || (word6[3] == wordle[4] && wordle[4] == 'F') || (word6[4] == wordle[1] && wordle[1] == 'F') || (word6[4] == wordle[0] && wordle[0] == 'F') || (word6[4] == wordle[3] && wordle[3] == 'F') || (word6[4] == wordle[2] && wordle[2] == 'F'))
  {
    c2();
    cout << " F ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'F') || (word1[0] != wordle[2] && word1[0] == 'F') || (word1[0] != wordle[3] && word1[0] == 'F') || (word1[0] != wordle[4] && word1[0] == 'F') || (word1[1] != wordle[0] && word1[1] == 'F') || (word1[1] != wordle[2] && word1[1] == 'F') || (word1[1] != wordle[3] && word1[1] == 'F') || (word1[1] != wordle[4] && word1[1] == 'F') || (word1[2] != wordle[1] && word1[2] == 'F') || (word1[2] != wordle[0] && word1[2] == 'F') || (word1[2] != wordle[3] && word1[2] == 'F') || (word1[2] != wordle[4] && word1[2] == 'F') || (word1[3] != wordle[1] && word1[3] == 'F') || (word1[3] != wordle[2] && word1[3] == 'F') || (word1[3] != wordle[0] && word1[3] == 'F') || (word1[3] != wordle[4] && word1[3] == 'F') || (word1[4] != wordle[1] && word1[4] == 'F') || (word1[4] != wordle[2] && word1[4] == 'F') || (word1[4] != wordle[3] && word1[4] == 'F') || (word1[4] != wordle[0] && word1[4] == 'F') || (word2[0] != wordle[1] && word2[0] == 'F') || (word2[0] != wordle[2] && word2[0] == 'F') || (word2[0] != wordle[3] && word2[0] == 'F') || (word2[0] != wordle[4] && word2[0] == 'F') || (word2[1] != wordle[0] && word2[1] == 'F') || (word2[1] != wordle[2] && word2[1] == 'F') || (word2[1] != wordle[3] && word2[1] == 'F') || (word2[1] != wordle[4] && word2[1] == 'F') || (word2[2] != wordle[1] && word2[2] == 'F') || (word2[2] != wordle[0] && word2[2] == 'F') || (word2[2] != wordle[3] && word2[2] == 'F') || (word2[2] != wordle[4] && word2[2] == 'F') || (word2[3] != wordle[1] && word2[3] == 'F') || (word2[3] != wordle[2] && word2[3] == 'F') || (word2[3] != wordle[0] && word2[3] == 'F') || (word2[3] != wordle[4] && word2[3] == 'F') || (word2[4] != wordle[1] && word2[4] == 'F') || (word2[4] != wordle[2] && word2[4] == 'F') || (word2[4] != wordle[3] && word2[4] == 'F') || (word2[4] != wordle[0] && word2[4] == 'F') || (word3[0] != wordle[1] && word3[0] == 'F') || (word3[0] != wordle[2] && word3[0] == 'F') || (word3[0] != wordle[3] && word3[0] == 'F') || (word3[0] != wordle[4] && word3[0] == 'F') || (word3[1] != wordle[0] && word3[1] == 'F') || (word3[1] != wordle[2] && word3[1] == 'F') || (word3[1] != wordle[3] && word3[1] == 'F') || (word3[1] != wordle[4] && word3[1] == 'F') || (word3[2] != wordle[1] && word3[2] == 'F') || (word3[2] != wordle[0] && word3[2] == 'F') || (word3[2] != wordle[3] && word3[2] == 'F') || (word3[2] != wordle[4] && word3[2] == 'F') || (word3[3] != wordle[1] && word3[3] == 'F') || (word3[3] != wordle[2] && word3[3] == 'F') || (word3[3] != wordle[0] && word3[3] == 'F') || (word3[3] != wordle[4] && word3[3] == 'F') || (word3[4] != wordle[1] && word3[4] == 'F') || (word3[4] != wordle[2] && word3[4] == 'F') || (word3[4] != wordle[3] && word3[4] == 'F') || (word3[4] != wordle[0] && word3[4] == 'F') || (word4[0] != wordle[1] && word4[0] == 'F') || (word4[0] != wordle[2] && word4[0] == 'F') || (word4[0] != wordle[3] && word4[0] == 'F') || (word4[0] != wordle[4] && word4[0] == 'F') || (word4[1] != wordle[0] && word4[1] == 'F') || (word4[1] != wordle[2] && word4[1] == 'F') || (word4[1] != wordle[3] && word4[1] == 'F') || (word4[1] != wordle[4] && word4[1] == 'F') || (word4[2] != wordle[1] && word4[2] == 'F') || (word4[2] != wordle[0] && word4[2] == 'F') || (word4[2] != wordle[3] && word4[2] == 'F') || (word4[2] != wordle[4] && word4[2] == 'F') || (word4[3] != wordle[1] && word4[3] == 'F') || (word4[3] != wordle[2] && word4[3] == 'F') || (word4[3] != wordle[0] && word4[3] == 'F') || (word4[3] != wordle[4] && word4[3] == 'F') || (word4[4] != wordle[1] && word4[4] == 'F') || (word4[4] != wordle[2] && word4[4] == 'F') || (word4[4] != wordle[3] && word4[4] == 'F') || (word4[4] != wordle[0] && word4[4] == 'F') || (word5[0] != wordle[1] && word5[0] == 'F') || (word5[0] != wordle[2] && word5[0] == 'F') || (word5[0] != wordle[3] && word5[0] == 'F') || (word5[0] != wordle[4] && word5[0] == 'F') || (word5[1] != wordle[0] && word5[1] == 'F') || (word5[1] != wordle[2] && word5[1] == 'F') || (word5[1] != wordle[3] && word5[1] == 'F') || (word5[1] != wordle[4] && word5[1] == 'F') || (word5[2] != wordle[1] && word5[2] == 'F') || (word5[2] != wordle[0] && word5[2] == 'F') || (word5[2] != wordle[3] && word5[2] == 'F') || (word5[2] != wordle[4] && word5[2] == 'F') || (word5[3] != wordle[1] && word5[3] == 'F') || (word5[3] != wordle[2] && word5[3] == 'F') || (word5[3] != wordle[0] && word5[3] == 'F') || (word5[3] != wordle[4] && word5[3] == 'F') || (word5[4] != wordle[1] && word5[4] == 'F') || (word5[4] != wordle[2] && word5[4] == 'F') || (word5[4] != wordle[3] && word5[4] == 'F') || (word5[4] != wordle[0] && word5[4] == 'F') || (word6[0] != wordle[1] && word6[0] == 'F') || (word6[0] != wordle[2] && word6[0] == 'F') || (word6[0] != wordle[3] && word6[0] == 'F') || (word6[0] != wordle[4] && word6[0] == 'F') || (word6[1] != wordle[0] && word6[1] == 'F') || (word6[1] != wordle[2] && word6[1] == 'F') || (word6[1] != wordle[3] && word6[1] == 'F') || (word6[1] != wordle[4] && word6[1] == 'F') || (word6[2] != wordle[1] && word6[2] == 'F') || (word6[2] != wordle[0] && word6[2] == 'F') || (word6[2] != wordle[3] && word6[2] == 'F') || (word6[2] != wordle[4] && word6[2] == 'F') || (word6[3] != wordle[1] && word6[3] == 'F') || (word6[3] != wordle[2] && word6[3] == 'F') || (word6[3] != wordle[0] && word6[3] == 'F') || (word6[3] != wordle[4] && word6[3] == 'F') || (word6[4] != wordle[1] && word6[4] == 'F') || (word6[4] != wordle[2] && word6[4] == 'F') || (word6[4] != wordle[3] && word6[4] == 'F') || (word6[4] != wordle[0] && word6[4] == 'F'))
  {
    c3();
    cout << " F ";
    cout << RESET;
  }
  else 
  {
    cout << " F ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'G') || (word1[1] == wordle[1] && word1[1] == 'G') || (word1[2] == wordle[2] && word1[2] == 'G') || (word1[3] == wordle[3] && word1[3] == 'G') || (word1[4] == wordle[4] && word1[4] == 'G') || (word2[0] == wordle[0] && word2[0] == 'G') || (word2[1] == wordle[1] && word2[1] == 'G') || (word2[2] == wordle[2] && word2[2] == 'G') || (word2[3] == wordle[3] && word2[3] == 'G') || (word2[4] == wordle[4] && word2[4] == 'G') || (word3[0] == wordle[0] && word3[0] == 'G') || (word3[1] == wordle[1] && word3[1] == 'G') || (word3[2] == wordle[2] && word3[2] == 'G') || (word3[3] == wordle[3] && word3[3] == 'G') || (word3[4] == wordle[4] && word3[4] == 'G') || (word4[0] == wordle[0] && word4[0] == 'G') || (word4[1] == wordle[1] && word4[1] == 'G') || (word4[2] == wordle[2] && word4[2] == 'G') || (word4[3] == wordle[3] && word4[3] == 'G') || (word4[4] == wordle[4] && word4[4] == 'G') || (word5[0] == wordle[0] && word5[0] == 'G') || (word5[1] == wordle[1] && word5[1] == 'G') || (word5[2] == wordle[2] && word5[2] == 'G') || (word5[3] == wordle[3] && word5[3] == 'G') || (word5[4] == wordle[4] && word5[4] == 'G') || (word6[0] == wordle[0] && word6[0] == 'G') || (word6[1] == wordle[1] && word6[1] == 'G') || (word6[2] == wordle[2] && word6[2] == 'G') || (word6[3] == wordle[3] && word6[3] == 'G') || (word6[4] == wordle[4] && word6[4] == 'G'))
  {
    c1();
    cout << " G ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'G') || (word1[0] == wordle[2] && wordle[2] == 'G') || (word1[0] == wordle[3] && wordle[3] == 'G') || (word1[0] == wordle[4] && wordle[4] == 'G') || (word1[1] == wordle[0] && wordle[0] == 'G') || (word1[1] == wordle[2] && wordle[2] == 'G') || (word1[1] == wordle[3] && wordle[3] == 'G') || (word1[1] == wordle[4] && wordle[4] == 'G') || (word1[2] == wordle[1] && wordle[1] == 'G') || (word1[2] == wordle[0] && wordle[0] == 'G') || (word1[2] == wordle[3] && wordle[3] == 'G') || (word1[2] == wordle[4] && wordle[4] == 'G') || (word1[3] == wordle[1] && wordle[1] == 'G') || (word1[3] == wordle[0] && wordle[0] == 'G') || (word1[3] == wordle[2] && wordle[2] == 'G') || (word1[3] == wordle[4] && wordle[4] == 'G') || (word1[4] == wordle[1] && wordle[1] == 'G') || (word1[4] == wordle[0] && wordle[0] == 'G') || (word1[4] == wordle[3] && wordle[3] == 'G') || (word1[4] == wordle[2] && wordle[2] == 'G') || (word2[0] == wordle[1] && wordle[1] == 'G') || (word2[0] == wordle[2] && wordle[2] == 'G') || (word2[0] == wordle[3] && wordle[3] == 'G') || (word2[0] == wordle[4] && wordle[4] == 'G') || (word2[1] == wordle[0] && wordle[0] == 'G') || (word2[1] == wordle[2] && wordle[2] == 'G') || (word2[1] == wordle[3] && wordle[3] == 'G') || (word2[1] == wordle[4] && wordle[4] == 'G') || (word2[2] == wordle[1] && wordle[1] == 'G') || (word2[2] == wordle[0] && wordle[0] == 'G') || (word2[2] == wordle[3] && wordle[3] == 'G') || (word2[2] == wordle[4] && wordle[4] == 'G') || (word2[3] == wordle[1] && wordle[1] == 'G') || (word2[3] == wordle[0] && wordle[0] == 'G') || (word2[3] == wordle[2] && wordle[2] == 'G') || (word2[3] == wordle[4] && wordle[4] == 'G') || (word2[4] == wordle[1] && wordle[1] == 'G') || (word2[4] == wordle[0] && wordle[0] == 'G') || (word2[4] == wordle[3] && wordle[3] == 'G') || (word2[4] == wordle[2] && wordle[2] == 'G') || (word3[0] == wordle[1] && wordle[1] == 'G') || (word3[0] == wordle[2] && wordle[2] == 'G') || (word3[0] == wordle[3] && wordle[3] == 'G') || (word3[0] == wordle[4] && wordle[4] == 'G') || (word3[1] == wordle[0] && wordle[0] == 'G') || (word3[1] == wordle[2] && wordle[2] == 'G') || (word3[1] == wordle[3] && wordle[3] == 'G') || (word3[1] == wordle[4] && wordle[4] == 'G') || (word3[2] == wordle[1] && wordle[1] == 'G') || (word3[2] == wordle[0] && wordle[0] == 'G') || (word3[2] == wordle[3] && wordle[3] == 'G') || (word3[2] == wordle[4] && wordle[4] == 'G') || (word3[3] == wordle[1] && wordle[1] == 'G') || (word3[3] == wordle[0] && wordle[0] == 'G') || (word3[3] == wordle[2] && wordle[2] == 'G') || (word3[3] == wordle[4] && wordle[4] == 'G') || (word3[4] == wordle[1] && wordle[1] == 'G') || (word3[4] == wordle[0] && wordle[0] == 'G') || (word3[4] == wordle[3] && wordle[3] == 'G') || (word3[4] == wordle[2] && wordle[2] == 'G') || (word4[0] == wordle[1] && wordle[1] == 'G') || (word4[0] == wordle[2] && wordle[2] == 'G') || (word4[0] == wordle[3] && wordle[3] == 'G') || (word4[0] == wordle[4] && wordle[4] == 'G') || (word4[1] == wordle[0] && wordle[0] == 'G') || (word4[1] == wordle[2] && wordle[2] == 'G') || (word4[1] == wordle[3] && wordle[3] == 'G') || (word4[1] == wordle[4] && wordle[4] == 'G') || (word4[2] == wordle[1] && wordle[1] == 'G') || (word4[2] == wordle[0] && wordle[0] == 'G') || (word4[2] == wordle[3] && wordle[3] == 'G') || (word4[2] == wordle[4] && wordle[4] == 'G') || (word4[3] == wordle[1] && wordle[1] == 'G') || (word4[3] == wordle[0] && wordle[0] == 'G') || (word4[3] == wordle[2] && wordle[2] == 'G') || (word4[3] == wordle[4] && wordle[4] == 'G') || (word4[4] == wordle[1] && wordle[1] == 'G') || (word4[4] == wordle[0] && wordle[0] == 'G') || (word4[4] == wordle[3] && wordle[3] == 'G') || (word4[4] == wordle[2] && wordle[2] == 'G') || (word5[0] == wordle[1] && wordle[1] == 'G') || (word5[0] == wordle[2] && wordle[2] == 'G') || (word5[0] == wordle[3] && wordle[3] == 'G') || (word5[0] == wordle[4] && wordle[4] == 'G') || (word5[1] == wordle[0] && wordle[0] == 'G') || (word5[1] == wordle[2] && wordle[2] == 'G') || (word5[1] == wordle[3] && wordle[3] == 'G') || (word5[1] == wordle[4] && wordle[4] == 'G') || (word5[2] == wordle[1] && wordle[1] == 'G') || (word5[2] == wordle[0] && wordle[0] == 'G') || (word5[2] == wordle[3] && wordle[3] == 'G') || (word5[2] == wordle[4] && wordle[4] == 'G') || (word5[3] == wordle[1] && wordle[1] == 'G') || (word5[3] == wordle[0] && wordle[0] == 'G') || (word5[3] == wordle[2] && wordle[2] == 'G') || (word5[3] == wordle[4] && wordle[4] == 'G') || (word5[4] == wordle[1] && wordle[1] == 'G') || (word5[4] == wordle[0] && wordle[0] == 'G') || (word5[4] == wordle[3] && wordle[3] == 'G') || (word5[4] == wordle[2] && wordle[2] == 'G') || (word6[0] == wordle[1] && wordle[1] == 'G') || (word6[0] == wordle[2] && wordle[2] == 'G') || (word6[0] == wordle[3] && wordle[3] == 'G') || (word6[0] == wordle[4] && wordle[4] == 'G') || (word6[1] == wordle[0] && wordle[0] == 'G') || (word6[1] == wordle[2] && wordle[2] == 'G') || (word6[1] == wordle[3] && wordle[3] == 'G') || (word6[1] == wordle[4] && wordle[4] == 'G') || (word6[2] == wordle[1] && wordle[1] == 'G') || (word6[2] == wordle[0] && wordle[0] == 'G') || (word6[2] == wordle[3] && wordle[3] == 'G') || (word6[2] == wordle[4] && wordle[4] == 'G') || (word6[3] == wordle[1] && wordle[1] == 'G') || (word6[3] == wordle[0] && wordle[0] == 'G') || (word6[3] == wordle[2] && wordle[2] == 'G') || (word6[3] == wordle[4] && wordle[4] == 'G') || (word6[4] == wordle[1] && wordle[1] == 'G') || (word6[4] == wordle[0] && wordle[0] == 'G') || (word6[4] == wordle[3] && wordle[3] == 'G') || (word6[4] == wordle[2] && wordle[2] == 'G'))
  {
    c2();
    cout << " G ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'G') || (word1[0] != wordle[2] && word1[0] == 'G') || (word1[0] != wordle[3] && word1[0] == 'G') || (word1[0] != wordle[4] && word1[0] == 'G') || (word1[1] != wordle[0] && word1[1] == 'G') || (word1[1] != wordle[2] && word1[1] == 'G') || (word1[1] != wordle[3] && word1[1] == 'G') || (word1[1] != wordle[4] && word1[1] == 'G') || (word1[2] != wordle[1] && word1[2] == 'G') || (word1[2] != wordle[0] && word1[2] == 'G') || (word1[2] != wordle[3] && word1[2] == 'G') || (word1[2] != wordle[4] && word1[2] == 'G') || (word1[3] != wordle[1] && word1[3] == 'G') || (word1[3] != wordle[2] && word1[3] == 'G') || (word1[3] != wordle[0] && word1[3] == 'G') || (word1[3] != wordle[4] && word1[3] == 'G') || (word1[4] != wordle[1] && word1[4] == 'G') || (word1[4] != wordle[2] && word1[4] == 'G') || (word1[4] != wordle[3] && word1[4] == 'G') || (word1[4] != wordle[0] && word1[4] == 'G') || (word2[0] != wordle[1] && word2[0] == 'G') || (word2[0] != wordle[2] && word2[0] == 'G') || (word2[0] != wordle[3] && word2[0] == 'G') || (word2[0] != wordle[4] && word2[0] == 'G') || (word2[1] != wordle[0] && word2[1] == 'G') || (word2[1] != wordle[2] && word2[1] == 'G') || (word2[1] != wordle[3] && word2[1] == 'G') || (word2[1] != wordle[4] && word2[1] == 'G') || (word2[2] != wordle[1] && word2[2] == 'G') || (word2[2] != wordle[0] && word2[2] == 'G') || (word2[2] != wordle[3] && word2[2] == 'G') || (word2[2] != wordle[4] && word2[2] == 'G') || (word2[3] != wordle[1] && word2[3] == 'G') || (word2[3] != wordle[2] && word2[3] == 'G') || (word2[3] != wordle[0] && word2[3] == 'G') || (word2[3] != wordle[4] && word2[3] == 'G') || (word2[4] != wordle[1] && word2[4] == 'G') || (word2[4] != wordle[2] && word2[4] == 'G') || (word2[4] != wordle[3] && word2[4] == 'G') || (word2[4] != wordle[0] && word2[4] == 'G') || (word3[0] != wordle[1] && word3[0] == 'G') || (word3[0] != wordle[2] && word3[0] == 'G') || (word3[0] != wordle[3] && word3[0] == 'G') || (word3[0] != wordle[4] && word3[0] == 'G') || (word3[1] != wordle[0] && word3[1] == 'G') || (word3[1] != wordle[2] && word3[1] == 'G') || (word3[1] != wordle[3] && word3[1] == 'G') || (word3[1] != wordle[4] && word3[1] == 'G') || (word3[2] != wordle[1] && word3[2] == 'G') || (word3[2] != wordle[0] && word3[2] == 'G') || (word3[2] != wordle[3] && word3[2] == 'G') || (word3[2] != wordle[4] && word3[2] == 'G') || (word3[3] != wordle[1] && word3[3] == 'G') || (word3[3] != wordle[2] && word3[3] == 'G') || (word3[3] != wordle[0] && word3[3] == 'G') || (word3[3] != wordle[4] && word3[3] == 'G') || (word3[4] != wordle[1] && word3[4] == 'G') || (word3[4] != wordle[2] && word3[4] == 'G') || (word3[4] != wordle[3] && word3[4] == 'G') || (word3[4] != wordle[0] && word3[4] == 'G') || (word4[0] != wordle[1] && word4[0] == 'G') || (word4[0] != wordle[2] && word4[0] == 'G') || (word4[0] != wordle[3] && word4[0] == 'G') || (word4[0] != wordle[4] && word4[0] == 'G') || (word4[1] != wordle[0] && word4[1] == 'G') || (word4[1] != wordle[2] && word4[1] == 'G') || (word4[1] != wordle[3] && word4[1] == 'G') || (word4[1] != wordle[4] && word4[1] == 'G') || (word4[2] != wordle[1] && word4[2] == 'G') || (word4[2] != wordle[0] && word4[2] == 'G') || (word4[2] != wordle[3] && word4[2] == 'G') || (word4[2] != wordle[4] && word4[2] == 'G') || (word4[3] != wordle[1] && word4[3] == 'G') || (word4[3] != wordle[2] && word4[3] == 'G') || (word4[3] != wordle[0] && word4[3] == 'G') || (word4[3] != wordle[4] && word4[3] == 'G') || (word4[4] != wordle[1] && word4[4] == 'G') || (word4[4] != wordle[2] && word4[4] == 'G') || (word4[4] != wordle[3] && word4[4] == 'G') || (word4[4] != wordle[0] && word4[4] == 'G') || (word5[0] != wordle[1] && word5[0] == 'G') || (word5[0] != wordle[2] && word5[0] == 'G') || (word5[0] != wordle[3] && word5[0] == 'G') || (word5[0] != wordle[4] && word5[0] == 'G') || (word5[1] != wordle[0] && word5[1] == 'G') || (word5[1] != wordle[2] && word5[1] == 'G') || (word5[1] != wordle[3] && word5[1] == 'G') || (word5[1] != wordle[4] && word5[1] == 'G') || (word5[2] != wordle[1] && word5[2] == 'G') || (word5[2] != wordle[0] && word5[2] == 'G') || (word5[2] != wordle[3] && word5[2] == 'G') || (word5[2] != wordle[4] && word5[2] == 'G') || (word5[3] != wordle[1] && word5[3] == 'G') || (word5[3] != wordle[2] && word5[3] == 'G') || (word5[3] != wordle[0] && word5[3] == 'G') || (word5[3] != wordle[4] && word5[3] == 'G') || (word5[4] != wordle[1] && word5[4] == 'G') || (word5[4] != wordle[2] && word5[4] == 'G') || (word5[4] != wordle[3] && word5[4] == 'G') || (word5[4] != wordle[0] && word5[4] == 'G') || (word6[0] != wordle[1] && word6[0] == 'G') || (word6[0] != wordle[2] && word6[0] == 'G') || (word6[0] != wordle[3] && word6[0] == 'G') || (word6[0] != wordle[4] && word6[0] == 'G') || (word6[1] != wordle[0] && word6[1] == 'G') || (word6[1] != wordle[2] && word6[1] == 'G') || (word6[1] != wordle[3] && word6[1] == 'G') || (word6[1] != wordle[4] && word6[1] == 'G') || (word6[2] != wordle[1] && word6[2] == 'G') || (word6[2] != wordle[0] && word6[2] == 'G') || (word6[2] != wordle[3] && word6[2] == 'G') || (word6[2] != wordle[4] && word6[2] == 'G') || (word6[3] != wordle[1] && word6[3] == 'G') || (word6[3] != wordle[2] && word6[3] == 'G') || (word6[3] != wordle[0] && word6[3] == 'G') || (word6[3] != wordle[4] && word6[3] == 'G') || (word6[4] != wordle[1] && word6[4] == 'G') || (word6[4] != wordle[2] && word6[4] == 'G') || (word6[4] != wordle[3] && word6[4] == 'G') || (word6[4] != wordle[0] && word6[4] == 'G'))
  {
    c3();
    cout << " G ";
    cout << RESET;
  }
  else 
  {
    cout << " G ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'H') || (word1[1] == wordle[1] && word1[1] == 'H') || (word1[2] == wordle[2] && word1[2] == 'H') || (word1[3] == wordle[3] && word1[3] == 'H') || (word1[4] == wordle[4] && word1[4] == 'H') || (word2[0] == wordle[0] && word2[0] == 'H') || (word2[1] == wordle[1] && word2[1] == 'H') || (word2[2] == wordle[2] && word2[2] == 'H') || (word2[3] == wordle[3] && word2[3] == 'H') || (word2[4] == wordle[4] && word2[4] == 'H') || (word3[0] == wordle[0] && word3[0] == 'H') || (word3[1] == wordle[1] && word3[1] == 'H') || (word3[2] == wordle[2] && word3[2] == 'H') || (word3[3] == wordle[3] && word3[3] == 'H') || (word3[4] == wordle[4] && word3[4] == 'H') || (word4[0] == wordle[0] && word4[0] == 'H') || (word4[1] == wordle[1] && word4[1] == 'H') || (word4[2] == wordle[2] && word4[2] == 'H') || (word4[3] == wordle[3] && word4[3] == 'H') || (word4[4] == wordle[4] && word4[4] == 'H') || (word5[0] == wordle[0] && word5[0] == 'H') || (word5[1] == wordle[1] && word5[1] == 'H') || (word5[2] == wordle[2] && word5[2] == 'H') || (word5[3] == wordle[3] && word5[3] == 'H') || (word5[4] == wordle[4] && word5[4] == 'H') || (word6[0] == wordle[0] && word6[0] == 'H') || (word6[1] == wordle[1] && word6[1] == 'H') || (word6[2] == wordle[2] && word6[2] == 'H') || (word6[3] == wordle[3] && word6[3] == 'H') || (word6[4] == wordle[4] && word6[4] == 'H'))
  {
    c1();
    cout << " H ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'H') || (word1[0] == wordle[2] && wordle[2] == 'H') || (word1[0] == wordle[3] && wordle[3] == 'H') || (word1[0] == wordle[4] && wordle[4] == 'H') || (word1[1] == wordle[0] && wordle[0] == 'H') || (word1[1] == wordle[2] && wordle[2] == 'H') || (word1[1] == wordle[3] && wordle[3] == 'H') || (word1[1] == wordle[4] && wordle[4] == 'H') || (word1[2] == wordle[1] && wordle[1] == 'H') || (word1[2] == wordle[0] && wordle[0] == 'H') || (word1[2] == wordle[3] && wordle[3] == 'H') || (word1[2] == wordle[4] && wordle[4] == 'H') || (word1[3] == wordle[1] && wordle[1] == 'H') || (word1[3] == wordle[0] && wordle[0] == 'H') || (word1[3] == wordle[2] && wordle[2] == 'H') || (word1[3] == wordle[4] && wordle[4] == 'H') || (word1[4] == wordle[1] && wordle[1] == 'H') || (word1[4] == wordle[0] && wordle[0] == 'H') || (word1[4] == wordle[3] && wordle[3] == 'H') || (word1[4] == wordle[2] && wordle[2] == 'H') || (word2[0] == wordle[1] && wordle[1] == 'H') || (word2[0] == wordle[2] && wordle[2] == 'H') || (word2[0] == wordle[3] && wordle[3] == 'H') || (word2[0] == wordle[4] && wordle[4] == 'H') || (word2[1] == wordle[0] && wordle[0] == 'H') || (word2[1] == wordle[2] && wordle[2] == 'H') || (word2[1] == wordle[3] && wordle[3] == 'H') || (word2[1] == wordle[4] && wordle[4] == 'H') || (word2[2] == wordle[1] && wordle[1] == 'H') || (word2[2] == wordle[0] && wordle[0] == 'H') || (word2[2] == wordle[3] && wordle[3] == 'H') || (word2[2] == wordle[4] && wordle[4] == 'H') || (word2[3] == wordle[1] && wordle[1] == 'H') || (word2[3] == wordle[0] && wordle[0] == 'H') || (word2[3] == wordle[2] && wordle[2] == 'H') || (word2[3] == wordle[4] && wordle[4] == 'H') || (word2[4] == wordle[1] && wordle[1] == 'H') || (word2[4] == wordle[0] && wordle[0] == 'H') || (word2[4] == wordle[3] && wordle[3] == 'H') || (word2[4] == wordle[2] && wordle[2] == 'H') || (word3[0] == wordle[1] && wordle[1] == 'H') || (word3[0] == wordle[2] && wordle[2] == 'H') || (word3[0] == wordle[3] && wordle[3] == 'H') || (word3[0] == wordle[4] && wordle[4] == 'H') || (word3[1] == wordle[0] && wordle[0] == 'H') || (word3[1] == wordle[2] && wordle[2] == 'H') || (word3[1] == wordle[3] && wordle[3] == 'H') || (word3[1] == wordle[4] && wordle[4] == 'H') || (word3[2] == wordle[1] && wordle[1] == 'H') || (word3[2] == wordle[0] && wordle[0] == 'H') || (word3[2] == wordle[3] && wordle[3] == 'H') || (word3[2] == wordle[4] && wordle[4] == 'H') || (word3[3] == wordle[1] && wordle[1] == 'H') || (word3[3] == wordle[0] && wordle[0] == 'H') || (word3[3] == wordle[2] && wordle[2] == 'H') || (word3[3] == wordle[4] && wordle[4] == 'H') || (word3[4] == wordle[1] && wordle[1] == 'H') || (word3[4] == wordle[0] && wordle[0] == 'H') || (word3[4] == wordle[3] && wordle[3] == 'H') || (word3[4] == wordle[2] && wordle[2] == 'H') || (word4[0] == wordle[1] && wordle[1] == 'H') || (word4[0] == wordle[2] && wordle[2] == 'H') || (word4[0] == wordle[3] && wordle[3] == 'H') || (word4[0] == wordle[4] && wordle[4] == 'H') || (word4[1] == wordle[0] && wordle[0] == 'H') || (word4[1] == wordle[2] && wordle[2] == 'H') || (word4[1] == wordle[3] && wordle[3] == 'H') || (word4[1] == wordle[4] && wordle[4] == 'H') || (word4[2] == wordle[1] && wordle[1] == 'H') || (word4[2] == wordle[0] && wordle[0] == 'H') || (word4[2] == wordle[3] && wordle[3] == 'H') || (word4[2] == wordle[4] && wordle[4] == 'H') || (word4[3] == wordle[1] && wordle[1] == 'H') || (word4[3] == wordle[0] && wordle[0] == 'H') || (word4[3] == wordle[2] && wordle[2] == 'H') || (word4[3] == wordle[4] && wordle[4] == 'H') || (word4[4] == wordle[1] && wordle[1] == 'H') || (word4[4] == wordle[0] && wordle[0] == 'H') || (word4[4] == wordle[3] && wordle[3] == 'H') || (word4[4] == wordle[2] && wordle[2] == 'H') || (word5[0] == wordle[1] && wordle[1] == 'H') || (word5[0] == wordle[2] && wordle[2] == 'H') || (word5[0] == wordle[3] && wordle[3] == 'H') || (word5[0] == wordle[4] && wordle[4] == 'H') || (word5[1] == wordle[0] && wordle[0] == 'H') || (word5[1] == wordle[2] && wordle[2] == 'H') || (word5[1] == wordle[3] && wordle[3] == 'H') || (word5[1] == wordle[4] && wordle[4] == 'H') || (word5[2] == wordle[1] && wordle[1] == 'H') || (word5[2] == wordle[0] && wordle[0] == 'H') || (word5[2] == wordle[3] && wordle[3] == 'H') || (word5[2] == wordle[4] && wordle[4] == 'H') || (word5[3] == wordle[1] && wordle[1] == 'H') || (word5[3] == wordle[0] && wordle[0] == 'H') || (word5[3] == wordle[2] && wordle[2] == 'H') || (word5[3] == wordle[4] && wordle[4] == 'H') || (word5[4] == wordle[1] && wordle[1] == 'H') || (word5[4] == wordle[0] && wordle[0] == 'H') || (word5[4] == wordle[3] && wordle[3] == 'H') || (word5[4] == wordle[2] && wordle[2] == 'H') || (word6[0] == wordle[1] && wordle[1] == 'H') || (word6[0] == wordle[2] && wordle[2] == 'H') || (word6[0] == wordle[3] && wordle[3] == 'H') || (word6[0] == wordle[4] && wordle[4] == 'H') || (word6[1] == wordle[0] && wordle[0] == 'H') || (word6[1] == wordle[2] && wordle[2] == 'H') || (word6[1] == wordle[3] && wordle[3] == 'H') || (word6[1] == wordle[4] && wordle[4] == 'H') || (word6[2] == wordle[1] && wordle[1] == 'H') || (word6[2] == wordle[0] && wordle[0] == 'H') || (word6[2] == wordle[3] && wordle[3] == 'H') || (word6[2] == wordle[4] && wordle[4] == 'H') || (word6[3] == wordle[1] && wordle[1] == 'H') || (word6[3] == wordle[0] && wordle[0] == 'H') || (word6[3] == wordle[2] && wordle[2] == 'H') || (word6[3] == wordle[4] && wordle[4] == 'H') || (word6[4] == wordle[1] && wordle[1] == 'H') || (word6[4] == wordle[0] && wordle[0] == 'H') || (word6[4] == wordle[3] && wordle[3] == 'H') || (word6[4] == wordle[2] && wordle[2] == 'H'))
  {
    c2();
    cout << " H ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'H') || (word1[0] != wordle[2] && word1[0] == 'H') || (word1[0] != wordle[3] && word1[0] == 'H') || (word1[0] != wordle[4] && word1[0] == 'H') || (word1[1] != wordle[0] && word1[1] == 'H') || (word1[1] != wordle[2] && word1[1] == 'H') || (word1[1] != wordle[3] && word1[1] == 'H') || (word1[1] != wordle[4] && word1[1] == 'H') || (word1[2] != wordle[1] && word1[2] == 'H') || (word1[2] != wordle[0] && word1[2] == 'H') || (word1[2] != wordle[3] && word1[2] == 'H') || (word1[2] != wordle[4] && word1[2] == 'H') || (word1[3] != wordle[1] && word1[3] == 'H') || (word1[3] != wordle[2] && word1[3] == 'H') || (word1[3] != wordle[0] && word1[3] == 'H') || (word1[3] != wordle[4] && word1[3] == 'H') || (word1[4] != wordle[1] && word1[4] == 'H') || (word1[4] != wordle[2] && word1[4] == 'H') || (word1[4] != wordle[3] && word1[4] == 'H') || (word1[4] != wordle[0] && word1[4] == 'H') || (word2[0] != wordle[1] && word2[0] == 'H') || (word2[0] != wordle[2] && word2[0] == 'H') || (word2[0] != wordle[3] && word2[0] == 'H') || (word2[0] != wordle[4] && word2[0] == 'H') || (word2[1] != wordle[0] && word2[1] == 'H') || (word2[1] != wordle[2] && word2[1] == 'H') || (word2[1] != wordle[3] && word2[1] == 'H') || (word2[1] != wordle[4] && word2[1] == 'H') || (word2[2] != wordle[1] && word2[2] == 'H') || (word2[2] != wordle[0] && word2[2] == 'H') || (word2[2] != wordle[3] && word2[2] == 'H') || (word2[2] != wordle[4] && word2[2] == 'H') || (word2[3] != wordle[1] && word2[3] == 'H') || (word2[3] != wordle[2] && word2[3] == 'H') || (word2[3] != wordle[0] && word2[3] == 'H') || (word2[3] != wordle[4] && word2[3] == 'H') || (word2[4] != wordle[1] && word2[4] == 'H') || (word2[4] != wordle[2] && word2[4] == 'H') || (word2[4] != wordle[3] && word2[4] == 'H') || (word2[4] != wordle[0] && word2[4] == 'H') || (word3[0] != wordle[1] && word3[0] == 'H') || (word3[0] != wordle[2] && word3[0] == 'H') || (word3[0] != wordle[3] && word3[0] == 'H') || (word3[0] != wordle[4] && word3[0] == 'H') || (word3[1] != wordle[0] && word3[1] == 'H') || (word3[1] != wordle[2] && word3[1] == 'H') || (word3[1] != wordle[3] && word3[1] == 'H') || (word3[1] != wordle[4] && word3[1] == 'H') || (word3[2] != wordle[1] && word3[2] == 'H') || (word3[2] != wordle[0] && word3[2] == 'H') || (word3[2] != wordle[3] && word3[2] == 'H') || (word3[2] != wordle[4] && word3[2] == 'H') || (word3[3] != wordle[1] && word3[3] == 'H') || (word3[3] != wordle[2] && word3[3] == 'H') || (word3[3] != wordle[0] && word3[3] == 'H') || (word3[3] != wordle[4] && word3[3] == 'H') || (word3[4] != wordle[1] && word3[4] == 'H') || (word3[4] != wordle[2] && word3[4] == 'H') || (word3[4] != wordle[3] && word3[4] == 'H') || (word3[4] != wordle[0] && word3[4] == 'H') || (word4[0] != wordle[1] && word4[0] == 'H') || (word4[0] != wordle[2] && word4[0] == 'H') || (word4[0] != wordle[3] && word4[0] == 'H') || (word4[0] != wordle[4] && word4[0] == 'H') || (word4[1] != wordle[0] && word4[1] == 'H') || (word4[1] != wordle[2] && word4[1] == 'H') || (word4[1] != wordle[3] && word4[1] == 'H') || (word4[1] != wordle[4] && word4[1] == 'H') || (word4[2] != wordle[1] && word4[2] == 'H') || (word4[2] != wordle[0] && word4[2] == 'H') || (word4[2] != wordle[3] && word4[2] == 'H') || (word4[2] != wordle[4] && word4[2] == 'H') || (word4[3] != wordle[1] && word4[3] == 'H') || (word4[3] != wordle[2] && word4[3] == 'H') || (word4[3] != wordle[0] && word4[3] == 'H') || (word4[3] != wordle[4] && word4[3] == 'H') || (word4[4] != wordle[1] && word4[4] == 'H') || (word4[4] != wordle[2] && word4[4] == 'H') || (word4[4] != wordle[3] && word4[4] == 'H') || (word4[4] != wordle[0] && word4[4] == 'H') || (word5[0] != wordle[1] && word5[0] == 'H') || (word5[0] != wordle[2] && word5[0] == 'H') || (word5[0] != wordle[3] && word5[0] == 'H') || (word5[0] != wordle[4] && word5[0] == 'H') || (word5[1] != wordle[0] && word5[1] == 'H') || (word5[1] != wordle[2] && word5[1] == 'H') || (word5[1] != wordle[3] && word5[1] == 'H') || (word5[1] != wordle[4] && word5[1] == 'H') || (word5[2] != wordle[1] && word5[2] == 'H') || (word5[2] != wordle[0] && word5[2] == 'H') || (word5[2] != wordle[3] && word5[2] == 'H') || (word5[2] != wordle[4] && word5[2] == 'H') || (word5[3] != wordle[1] && word5[3] == 'H') || (word5[3] != wordle[2] && word5[3] == 'H') || (word5[3] != wordle[0] && word5[3] == 'H') || (word5[3] != wordle[4] && word5[3] == 'H') || (word5[4] != wordle[1] && word5[4] == 'H') || (word5[4] != wordle[2] && word5[4] == 'H') || (word5[4] != wordle[3] && word5[4] == 'H') || (word5[4] != wordle[0] && word5[4] == 'H') || (word6[0] != wordle[1] && word6[0] == 'H') || (word6[0] != wordle[2] && word6[0] == 'H') || (word6[0] != wordle[3] && word6[0] == 'H') || (word6[0] != wordle[4] && word6[0] == 'H') || (word6[1] != wordle[0] && word6[1] == 'H') || (word6[1] != wordle[2] && word6[1] == 'H') || (word6[1] != wordle[3] && word6[1] == 'H') || (word6[1] != wordle[4] && word6[1] == 'H') || (word6[2] != wordle[1] && word6[2] == 'H') || (word6[2] != wordle[0] && word6[2] == 'H') || (word6[2] != wordle[3] && word6[2] == 'H') || (word6[2] != wordle[4] && word6[2] == 'H') || (word6[3] != wordle[1] && word6[3] == 'H') || (word6[3] != wordle[2] && word6[3] == 'H') || (word6[3] != wordle[0] && word6[3] == 'H') || (word6[3] != wordle[4] && word6[3] == 'H') || (word6[4] != wordle[1] && word6[4] == 'H') || (word6[4] != wordle[2] && word6[4] == 'H') || (word6[4] != wordle[3] && word6[4] == 'H') || (word6[4] != wordle[0] && word6[4] == 'H'))
  {
    c3();
    cout << " H ";
    cout << RESET;
  }
  else 
  {
    cout << " H ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'J') || (word1[1] == wordle[1] && word1[1] == 'J') || (word1[2] == wordle[2] && word1[2] == 'J') || (word1[3] == wordle[3] && word1[3] == 'J') || (word1[4] == wordle[4] && word1[4] == 'J') || (word2[0] == wordle[0] && word2[0] == 'J') || (word2[1] == wordle[1] && word2[1] == 'J') || (word2[2] == wordle[2] && word2[2] == 'J') || (word2[3] == wordle[3] && word2[3] == 'J') || (word2[4] == wordle[4] && word2[4] == 'J') || (word3[0] == wordle[0] && word3[0] == 'J') || (word3[1] == wordle[1] && word3[1] == 'J') || (word3[2] == wordle[2] && word3[2] == 'J') || (word3[3] == wordle[3] && word3[3] == 'J') || (word3[4] == wordle[4] && word3[4] == 'J') || (word4[0] == wordle[0] && word4[0] == 'J') || (word4[1] == wordle[1] && word4[1] == 'J') || (word4[2] == wordle[2] && word4[2] == 'J') || (word4[3] == wordle[3] && word4[3] == 'J') || (word4[4] == wordle[4] && word4[4] == 'J') || (word5[0] == wordle[0] && word5[0] == 'J') || (word5[1] == wordle[1] && word5[1] == 'J') || (word5[2] == wordle[2] && word5[2] == 'J') || (word5[3] == wordle[3] && word5[3] == 'J') || (word5[4] == wordle[4] && word5[4] == 'J') || (word6[0] == wordle[0] && word6[0] == 'J') || (word6[1] == wordle[1] && word6[1] == 'J') || (word6[2] == wordle[2] && word6[2] == 'J') || (word6[3] == wordle[3] && word6[3] == 'J') || (word6[4] == wordle[4] && word6[4] == 'J'))
  {
    c1();
    cout << " J ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'J') || (word1[0] == wordle[2] && wordle[2] == 'J') || (word1[0] == wordle[3] && wordle[3] == 'J') || (word1[0] == wordle[4] && wordle[4] == 'J') || (word1[1] == wordle[0] && wordle[0] == 'J') || (word1[1] == wordle[2] && wordle[2] == 'J') || (word1[1] == wordle[3] && wordle[3] == 'J') || (word1[1] == wordle[4] && wordle[4] == 'J') || (word1[2] == wordle[1] && wordle[1] == 'J') || (word1[2] == wordle[0] && wordle[0] == 'J') || (word1[2] == wordle[3] && wordle[3] == 'J') || (word1[2] == wordle[4] && wordle[4] == 'J') || (word1[3] == wordle[1] && wordle[1] == 'J') || (word1[3] == wordle[0] && wordle[0] == 'J') || (word1[3] == wordle[2] && wordle[2] == 'J') || (word1[3] == wordle[4] && wordle[4] == 'J') || (word1[4] == wordle[1] && wordle[1] == 'J') || (word1[4] == wordle[0] && wordle[0] == 'J') || (word1[4] == wordle[3] && wordle[3] == 'J') || (word1[4] == wordle[2] && wordle[2] == 'J') || (word2[0] == wordle[1] && wordle[1] == 'J') || (word2[0] == wordle[2] && wordle[2] == 'J') || (word2[0] == wordle[3] && wordle[3] == 'J') || (word2[0] == wordle[4] && wordle[4] == 'J') || (word2[1] == wordle[0] && wordle[0] == 'J') || (word2[1] == wordle[2] && wordle[2] == 'J') || (word2[1] == wordle[3] && wordle[3] == 'J') || (word2[1] == wordle[4] && wordle[4] == 'J') || (word2[2] == wordle[1] && wordle[1] == 'J') || (word2[2] == wordle[0] && wordle[0] == 'J') || (word2[2] == wordle[3] && wordle[3] == 'J') || (word2[2] == wordle[4] && wordle[4] == 'J') || (word2[3] == wordle[1] && wordle[1] == 'J') || (word2[3] == wordle[0] && wordle[0] == 'J') || (word2[3] == wordle[2] && wordle[2] == 'J') || (word2[3] == wordle[4] && wordle[4] == 'J') || (word2[4] == wordle[1] && wordle[1] == 'J') || (word2[4] == wordle[0] && wordle[0] == 'J') || (word2[4] == wordle[3] && wordle[3] == 'J') || (word2[4] == wordle[2] && wordle[2] == 'J') || (word3[0] == wordle[1] && wordle[1] == 'J') || (word3[0] == wordle[2] && wordle[2] == 'J') || (word3[0] == wordle[3] && wordle[3] == 'J') || (word3[0] == wordle[4] && wordle[4] == 'J') || (word3[1] == wordle[0] && wordle[0] == 'J') || (word3[1] == wordle[2] && wordle[2] == 'J') || (word3[1] == wordle[3] && wordle[3] == 'J') || (word3[1] == wordle[4] && wordle[4] == 'J') || (word3[2] == wordle[1] && wordle[1] == 'J') || (word3[2] == wordle[0] && wordle[0] == 'J') || (word3[2] == wordle[3] && wordle[3] == 'J') || (word3[2] == wordle[4] && wordle[4] == 'J') || (word3[3] == wordle[1] && wordle[1] == 'J') || (word3[3] == wordle[0] && wordle[0] == 'J') || (word3[3] == wordle[2] && wordle[2] == 'J') || (word3[3] == wordle[4] && wordle[4] == 'J') || (word3[4] == wordle[1] && wordle[1] == 'J') || (word3[4] == wordle[0] && wordle[0] == 'J') || (word3[4] == wordle[3] && wordle[3] == 'J') || (word3[4] == wordle[2] && wordle[2] == 'J') || (word4[0] == wordle[1] && wordle[1] == 'J') || (word4[0] == wordle[2] && wordle[2] == 'J') || (word4[0] == wordle[3] && wordle[3] == 'J') || (word4[0] == wordle[4] && wordle[4] == 'J') || (word4[1] == wordle[0] && wordle[0] == 'J') || (word4[1] == wordle[2] && wordle[2] == 'J') || (word4[1] == wordle[3] && wordle[3] == 'J') || (word4[1] == wordle[4] && wordle[4] == 'J') || (word4[2] == wordle[1] && wordle[1] == 'J') || (word4[2] == wordle[0] && wordle[0] == 'J') || (word4[2] == wordle[3] && wordle[3] == 'J') || (word4[2] == wordle[4] && wordle[4] == 'J') || (word4[3] == wordle[1] && wordle[1] == 'J') || (word4[3] == wordle[0] && wordle[0] == 'J') || (word4[3] == wordle[2] && wordle[2] == 'J') || (word4[3] == wordle[4] && wordle[4] == 'J') || (word4[4] == wordle[1] && wordle[1] == 'J') || (word4[4] == wordle[0] && wordle[0] == 'J') || (word4[4] == wordle[3] && wordle[3] == 'J') || (word4[4] == wordle[2] && wordle[2] == 'J') || (word5[0] == wordle[1] && wordle[1] == 'J') || (word5[0] == wordle[2] && wordle[2] == 'J') || (word5[0] == wordle[3] && wordle[3] == 'J') || (word5[0] == wordle[4] && wordle[4] == 'J') || (word5[1] == wordle[0] && wordle[0] == 'J') || (word5[1] == wordle[2] && wordle[2] == 'J') || (word5[1] == wordle[3] && wordle[3] == 'J') || (word5[1] == wordle[4] && wordle[4] == 'J') || (word5[2] == wordle[1] && wordle[1] == 'J') || (word5[2] == wordle[0] && wordle[0] == 'J') || (word5[2] == wordle[3] && wordle[3] == 'J') || (word5[2] == wordle[4] && wordle[4] == 'J') || (word5[3] == wordle[1] && wordle[1] == 'J') || (word5[3] == wordle[0] && wordle[0] == 'J') || (word5[3] == wordle[2] && wordle[2] == 'J') || (word5[3] == wordle[4] && wordle[4] == 'J') || (word5[4] == wordle[1] && wordle[1] == 'J') || (word5[4] == wordle[0] && wordle[0] == 'J') || (word5[4] == wordle[3] && wordle[3] == 'J') || (word5[4] == wordle[2] && wordle[2] == 'J') || (word6[0] == wordle[1] && wordle[1] == 'J') || (word6[0] == wordle[2] && wordle[2] == 'J') || (word6[0] == wordle[3] && wordle[3] == 'J') || (word6[0] == wordle[4] && wordle[4] == 'J') || (word6[1] == wordle[0] && wordle[0] == 'J') || (word6[1] == wordle[2] && wordle[2] == 'J') || (word6[1] == wordle[3] && wordle[3] == 'J') || (word6[1] == wordle[4] && wordle[4] == 'J') || (word6[2] == wordle[1] && wordle[1] == 'J') || (word6[2] == wordle[0] && wordle[0] == 'J') || (word6[2] == wordle[3] && wordle[3] == 'J') || (word6[2] == wordle[4] && wordle[4] == 'J') || (word6[3] == wordle[1] && wordle[1] == 'J') || (word6[3] == wordle[0] && wordle[0] == 'J') || (word6[3] == wordle[2] && wordle[2] == 'J') || (word6[3] == wordle[4] && wordle[4] == 'J') || (word6[4] == wordle[1] && wordle[1] == 'J') || (word6[4] == wordle[0] && wordle[0] == 'J') || (word6[4] == wordle[3] && wordle[3] == 'J') || (word6[4] == wordle[2] && wordle[2] == 'J'))
  {
    c2();
    cout << " J ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'J') || (word1[0] != wordle[2] && word1[0] == 'J') || (word1[0] != wordle[3] && word1[0] == 'J') || (word1[0] != wordle[4] && word1[0] == 'J') || (word1[1] != wordle[0] && word1[1] == 'J') || (word1[1] != wordle[2] && word1[1] == 'J') || (word1[1] != wordle[3] && word1[1] == 'J') || (word1[1] != wordle[4] && word1[1] == 'J') || (word1[2] != wordle[1] && word1[2] == 'J') || (word1[2] != wordle[0] && word1[2] == 'J') || (word1[2] != wordle[3] && word1[2] == 'J') || (word1[2] != wordle[4] && word1[2] == 'J') || (word1[3] != wordle[1] && word1[3] == 'J') || (word1[3] != wordle[2] && word1[3] == 'J') || (word1[3] != wordle[0] && word1[3] == 'J') || (word1[3] != wordle[4] && word1[3] == 'J') || (word1[4] != wordle[1] && word1[4] == 'J') || (word1[4] != wordle[2] && word1[4] == 'J') || (word1[4] != wordle[3] && word1[4] == 'J') || (word1[4] != wordle[0] && word1[4] == 'J') || (word2[0] != wordle[1] && word2[0] == 'J') || (word2[0] != wordle[2] && word2[0] == 'J') || (word2[0] != wordle[3] && word2[0] == 'J') || (word2[0] != wordle[4] && word2[0] == 'J') || (word2[1] != wordle[0] && word2[1] == 'J') || (word2[1] != wordle[2] && word2[1] == 'J') || (word2[1] != wordle[3] && word2[1] == 'J') || (word2[1] != wordle[4] && word2[1] == 'J') || (word2[2] != wordle[1] && word2[2] == 'J') || (word2[2] != wordle[0] && word2[2] == 'J') || (word2[2] != wordle[3] && word2[2] == 'J') || (word2[2] != wordle[4] && word2[2] == 'J') || (word2[3] != wordle[1] && word2[3] == 'J') || (word2[3] != wordle[2] && word2[3] == 'J') || (word2[3] != wordle[0] && word2[3] == 'J') || (word2[3] != wordle[4] && word2[3] == 'J') || (word2[4] != wordle[1] && word2[4] == 'J') || (word2[4] != wordle[2] && word2[4] == 'J') || (word2[4] != wordle[3] && word2[4] == 'J') || (word2[4] != wordle[0] && word2[4] == 'J') || (word3[0] != wordle[1] && word3[0] == 'J') || (word3[0] != wordle[2] && word3[0] == 'J') || (word3[0] != wordle[3] && word3[0] == 'J') || (word3[0] != wordle[4] && word3[0] == 'J') || (word3[1] != wordle[0] && word3[1] == 'J') || (word3[1] != wordle[2] && word3[1] == 'J') || (word3[1] != wordle[3] && word3[1] == 'J') || (word3[1] != wordle[4] && word3[1] == 'J') || (word3[2] != wordle[1] && word3[2] == 'J') || (word3[2] != wordle[0] && word3[2] == 'J') || (word3[2] != wordle[3] && word3[2] == 'J') || (word3[2] != wordle[4] && word3[2] == 'J') || (word3[3] != wordle[1] && word3[3] == 'J') || (word3[3] != wordle[2] && word3[3] == 'J') || (word3[3] != wordle[0] && word3[3] == 'J') || (word3[3] != wordle[4] && word3[3] == 'J') || (word3[4] != wordle[1] && word3[4] == 'J') || (word3[4] != wordle[2] && word3[4] == 'J') || (word3[4] != wordle[3] && word3[4] == 'J') || (word3[4] != wordle[0] && word3[4] == 'J') || (word4[0] != wordle[1] && word4[0] == 'J') || (word4[0] != wordle[2] && word4[0] == 'J') || (word4[0] != wordle[3] && word4[0] == 'J') || (word4[0] != wordle[4] && word4[0] == 'J') || (word4[1] != wordle[0] && word4[1] == 'J') || (word4[1] != wordle[2] && word4[1] == 'J') || (word4[1] != wordle[3] && word4[1] == 'J') || (word4[1] != wordle[4] && word4[1] == 'J') || (word4[2] != wordle[1] && word4[2] == 'J') || (word4[2] != wordle[0] && word4[2] == 'J') || (word4[2] != wordle[3] && word4[2] == 'J') || (word4[2] != wordle[4] && word4[2] == 'J') || (word4[3] != wordle[1] && word4[3] == 'J') || (word4[3] != wordle[2] && word4[3] == 'J') || (word4[3] != wordle[0] && word4[3] == 'J') || (word4[3] != wordle[4] && word4[3] == 'J') || (word4[4] != wordle[1] && word4[4] == 'J') || (word4[4] != wordle[2] && word4[4] == 'J') || (word4[4] != wordle[3] && word4[4] == 'J') || (word4[4] != wordle[0] && word4[4] == 'J') || (word5[0] != wordle[1] && word5[0] == 'J') || (word5[0] != wordle[2] && word5[0] == 'J') || (word5[0] != wordle[3] && word5[0] == 'J') || (word5[0] != wordle[4] && word5[0] == 'J') || (word5[1] != wordle[0] && word5[1] == 'J') || (word5[1] != wordle[2] && word5[1] == 'J') || (word5[1] != wordle[3] && word5[1] == 'J') || (word5[1] != wordle[4] && word5[1] == 'J') || (word5[2] != wordle[1] && word5[2] == 'J') || (word5[2] != wordle[0] && word5[2] == 'J') || (word5[2] != wordle[3] && word5[2] == 'J') || (word5[2] != wordle[4] && word5[2] == 'J') || (word5[3] != wordle[1] && word5[3] == 'J') || (word5[3] != wordle[2] && word5[3] == 'J') || (word5[3] != wordle[0] && word5[3] == 'J') || (word5[3] != wordle[4] && word5[3] == 'J') || (word5[4] != wordle[1] && word5[4] == 'J') || (word5[4] != wordle[2] && word5[4] == 'J') || (word5[4] != wordle[3] && word5[4] == 'J') || (word5[4] != wordle[0] && word5[4] == 'J') || (word6[0] != wordle[1] && word6[0] == 'J') || (word6[0] != wordle[2] && word6[0] == 'J') || (word6[0] != wordle[3] && word6[0] == 'J') || (word6[0] != wordle[4] && word6[0] == 'J') || (word6[1] != wordle[0] && word6[1] == 'J') || (word6[1] != wordle[2] && word6[1] == 'J') || (word6[1] != wordle[3] && word6[1] == 'J') || (word6[1] != wordle[4] && word6[1] == 'J') || (word6[2] != wordle[1] && word6[2] == 'J') || (word6[2] != wordle[0] && word6[2] == 'J') || (word6[2] != wordle[3] && word6[2] == 'J') || (word6[2] != wordle[4] && word6[2] == 'J') || (word6[3] != wordle[1] && word6[3] == 'J') || (word6[3] != wordle[2] && word6[3] == 'J') || (word6[3] != wordle[0] && word6[3] == 'J') || (word6[3] != wordle[4] && word6[3] == 'J') || (word6[4] != wordle[1] && word6[4] == 'J') || (word6[4] != wordle[2] && word6[4] == 'J') || (word6[4] != wordle[3] && word6[4] == 'J') || (word6[4] != wordle[0] && word6[4] == 'J'))
  {
    c3();
    cout << " J ";
    cout << RESET;
  }
  else 
  {
    cout << " J ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'K') || (word1[1] == wordle[1] && word1[1] == 'K') || (word1[2] == wordle[2] && word1[2] == 'K') || (word1[3] == wordle[3] && word1[3] == 'K') || (word1[4] == wordle[4] && word1[4] == 'K') || (word2[0] == wordle[0] && word2[0] == 'K') || (word2[1] == wordle[1] && word2[1] == 'K') || (word2[2] == wordle[2] && word2[2] == 'K') || (word2[3] == wordle[3] && word2[3] == 'K') || (word2[4] == wordle[4] && word2[4] == 'K') || (word3[0] == wordle[0] && word3[0] == 'K') || (word3[1] == wordle[1] && word3[1] == 'K') || (word3[2] == wordle[2] && word3[2] == 'K') || (word3[3] == wordle[3] && word3[3] == 'K') || (word3[4] == wordle[4] && word3[4] == 'K') || (word4[0] == wordle[0] && word4[0] == 'K') || (word4[1] == wordle[1] && word4[1] == 'K') || (word4[2] == wordle[2] && word4[2] == 'K') || (word4[3] == wordle[3] && word4[3] == 'K') || (word4[4] == wordle[4] && word4[4] == 'K') || (word5[0] == wordle[0] && word5[0] == 'K') || (word5[1] == wordle[1] && word5[1] == 'K') || (word5[2] == wordle[2] && word5[2] == 'K') || (word5[3] == wordle[3] && word5[3] == 'K') || (word5[4] == wordle[4] && word5[4] == 'K') || (word6[0] == wordle[0] && word6[0] == 'K') || (word6[1] == wordle[1] && word6[1] == 'K') || (word6[2] == wordle[2] && word6[2] == 'K') || (word6[3] == wordle[3] && word6[3] == 'K') || (word6[4] == wordle[4] && word6[4] == 'K'))
  {
    c1();
    cout << " K ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'K') || (word1[0] == wordle[2] && wordle[2] == 'K') || (word1[0] == wordle[3] && wordle[3] == 'K') || (word1[0] == wordle[4] && wordle[4] == 'K') || (word1[1] == wordle[0] && wordle[0] == 'K') || (word1[1] == wordle[2] && wordle[2] == 'K') || (word1[1] == wordle[3] && wordle[3] == 'K') || (word1[1] == wordle[4] && wordle[4] == 'K') || (word1[2] == wordle[1] && wordle[1] == 'K') || (word1[2] == wordle[0] && wordle[0] == 'K') || (word1[2] == wordle[3] && wordle[3] == 'K') || (word1[2] == wordle[4] && wordle[4] == 'K') || (word1[3] == wordle[1] && wordle[1] == 'K') || (word1[3] == wordle[0] && wordle[0] == 'K') || (word1[3] == wordle[2] && wordle[2] == 'K') || (word1[3] == wordle[4] && wordle[4] == 'K') || (word1[4] == wordle[1] && wordle[1] == 'K') || (word1[4] == wordle[0] && wordle[0] == 'K') || (word1[4] == wordle[3] && wordle[3] == 'K') || (word1[4] == wordle[2] && wordle[2] == 'K') || (word2[0] == wordle[1] && wordle[1] == 'K') || (word2[0] == wordle[2] && wordle[2] == 'K') || (word2[0] == wordle[3] && wordle[3] == 'K') || (word2[0] == wordle[4] && wordle[4] == 'K') || (word2[1] == wordle[0] && wordle[0] == 'K') || (word2[1] == wordle[2] && wordle[2] == 'K') || (word2[1] == wordle[3] && wordle[3] == 'K') || (word2[1] == wordle[4] && wordle[4] == 'K') || (word2[2] == wordle[1] && wordle[1] == 'K') || (word2[2] == wordle[0] && wordle[0] == 'K') || (word2[2] == wordle[3] && wordle[3] == 'K') || (word2[2] == wordle[4] && wordle[4] == 'K') || (word2[3] == wordle[1] && wordle[1] == 'K') || (word2[3] == wordle[0] && wordle[0] == 'K') || (word2[3] == wordle[2] && wordle[2] == 'K') || (word2[3] == wordle[4] && wordle[4] == 'K') || (word2[4] == wordle[1] && wordle[1] == 'K') || (word2[4] == wordle[0] && wordle[0] == 'K') || (word2[4] == wordle[3] && wordle[3] == 'K') || (word2[4] == wordle[2] && wordle[2] == 'K') || (word3[0] == wordle[1] && wordle[1] == 'K') || (word3[0] == wordle[2] && wordle[2] == 'K') || (word3[0] == wordle[3] && wordle[3] == 'K') || (word3[0] == wordle[4] && wordle[4] == 'K') || (word3[1] == wordle[0] && wordle[0] == 'K') || (word3[1] == wordle[2] && wordle[2] == 'K') || (word3[1] == wordle[3] && wordle[3] == 'K') || (word3[1] == wordle[4] && wordle[4] == 'K') || (word3[2] == wordle[1] && wordle[1] == 'K') || (word3[2] == wordle[0] && wordle[0] == 'K') || (word3[2] == wordle[3] && wordle[3] == 'K') || (word3[2] == wordle[4] && wordle[4] == 'K') || (word3[3] == wordle[1] && wordle[1] == 'K') || (word3[3] == wordle[0] && wordle[0] == 'K') || (word3[3] == wordle[2] && wordle[2] == 'K') || (word3[3] == wordle[4] && wordle[4] == 'K') || (word3[4] == wordle[1] && wordle[1] == 'K') || (word3[4] == wordle[0] && wordle[0] == 'K') || (word3[4] == wordle[3] && wordle[3] == 'K') || (word3[4] == wordle[2] && wordle[2] == 'K') || (word4[0] == wordle[1] && wordle[1] == 'K') || (word4[0] == wordle[2] && wordle[2] == 'K') || (word4[0] == wordle[3] && wordle[3] == 'K') || (word4[0] == wordle[4] && wordle[4] == 'K') || (word4[1] == wordle[0] && wordle[0] == 'K') || (word4[1] == wordle[2] && wordle[2] == 'K') || (word4[1] == wordle[3] && wordle[3] == 'K') || (word4[1] == wordle[4] && wordle[4] == 'K') || (word4[2] == wordle[1] && wordle[1] == 'K') || (word4[2] == wordle[0] && wordle[0] == 'K') || (word4[2] == wordle[3] && wordle[3] == 'K') || (word4[2] == wordle[4] && wordle[4] == 'K') || (word4[3] == wordle[1] && wordle[1] == 'K') || (word4[3] == wordle[0] && wordle[0] == 'K') || (word4[3] == wordle[2] && wordle[2] == 'K') || (word4[3] == wordle[4] && wordle[4] == 'K') || (word4[4] == wordle[1] && wordle[1] == 'K') || (word4[4] == wordle[0] && wordle[0] == 'K') || (word4[4] == wordle[3] && wordle[3] == 'K') || (word4[4] == wordle[2] && wordle[2] == 'K') || (word5[0] == wordle[1] && wordle[1] == 'K') || (word5[0] == wordle[2] && wordle[2] == 'K') || (word5[0] == wordle[3] && wordle[3] == 'K') || (word5[0] == wordle[4] && wordle[4] == 'K') || (word5[1] == wordle[0] && wordle[0] == 'K') || (word5[1] == wordle[2] && wordle[2] == 'K') || (word5[1] == wordle[3] && wordle[3] == 'K') || (word5[1] == wordle[4] && wordle[4] == 'K') || (word5[2] == wordle[1] && wordle[1] == 'K') || (word5[2] == wordle[0] && wordle[0] == 'K') || (word5[2] == wordle[3] && wordle[3] == 'K') || (word5[2] == wordle[4] && wordle[4] == 'K') || (word5[3] == wordle[1] && wordle[1] == 'K') || (word5[3] == wordle[0] && wordle[0] == 'K') || (word5[3] == wordle[2] && wordle[2] == 'K') || (word5[3] == wordle[4] && wordle[4] == 'K') || (word5[4] == wordle[1] && wordle[1] == 'K') || (word5[4] == wordle[0] && wordle[0] == 'K') || (word5[4] == wordle[3] && wordle[3] == 'K') || (word5[4] == wordle[2] && wordle[2] == 'K') || (word6[0] == wordle[1] && wordle[1] == 'K') || (word6[0] == wordle[2] && wordle[2] == 'K') || (word6[0] == wordle[3] && wordle[3] == 'K') || (word6[0] == wordle[4] && wordle[4] == 'K') || (word6[1] == wordle[0] && wordle[0] == 'K') || (word6[1] == wordle[2] && wordle[2] == 'K') || (word6[1] == wordle[3] && wordle[3] == 'K') || (word6[1] == wordle[4] && wordle[4] == 'K') || (word6[2] == wordle[1] && wordle[1] == 'K') || (word6[2] == wordle[0] && wordle[0] == 'K') || (word6[2] == wordle[3] && wordle[3] == 'K') || (word6[2] == wordle[4] && wordle[4] == 'K') || (word6[3] == wordle[1] && wordle[1] == 'K') || (word6[3] == wordle[0] && wordle[0] == 'K') || (word6[3] == wordle[2] && wordle[2] == 'K') || (word6[3] == wordle[4] && wordle[4] == 'K') || (word6[4] == wordle[1] && wordle[1] == 'K') || (word6[4] == wordle[0] && wordle[0] == 'K') || (word6[4] == wordle[3] && wordle[3] == 'K') || (word6[4] == wordle[2] && wordle[2] == 'K'))
  {
    c2();
    cout << " K ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'K') || (word1[0] != wordle[2] && word1[0] == 'K') || (word1[0] != wordle[3] && word1[0] == 'K') || (word1[0] != wordle[4] && word1[0] == 'K') || (word1[1] != wordle[0] && word1[1] == 'K') || (word1[1] != wordle[2] && word1[1] == 'K') || (word1[1] != wordle[3] && word1[1] == 'K') || (word1[1] != wordle[4] && word1[1] == 'K') || (word1[2] != wordle[1] && word1[2] == 'K') || (word1[2] != wordle[0] && word1[2] == 'K') || (word1[2] != wordle[3] && word1[2] == 'K') || (word1[2] != wordle[4] && word1[2] == 'K') || (word1[3] != wordle[1] && word1[3] == 'K') || (word1[3] != wordle[2] && word1[3] == 'K') || (word1[3] != wordle[0] && word1[3] == 'K') || (word1[3] != wordle[4] && word1[3] == 'K') || (word1[4] != wordle[1] && word1[4] == 'K') || (word1[4] != wordle[2] && word1[4] == 'K') || (word1[4] != wordle[3] && word1[4] == 'K') || (word1[4] != wordle[0] && word1[4] == 'K') || (word2[0] != wordle[1] && word2[0] == 'K') || (word2[0] != wordle[2] && word2[0] == 'K') || (word2[0] != wordle[3] && word2[0] == 'K') || (word2[0] != wordle[4] && word2[0] == 'K') || (word2[1] != wordle[0] && word2[1] == 'K') || (word2[1] != wordle[2] && word2[1] == 'K') || (word2[1] != wordle[3] && word2[1] == 'K') || (word2[1] != wordle[4] && word2[1] == 'K') || (word2[2] != wordle[1] && word2[2] == 'K') || (word2[2] != wordle[0] && word2[2] == 'K') || (word2[2] != wordle[3] && word2[2] == 'K') || (word2[2] != wordle[4] && word2[2] == 'K') || (word2[3] != wordle[1] && word2[3] == 'K') || (word2[3] != wordle[2] && word2[3] == 'K') || (word2[3] != wordle[0] && word2[3] == 'K') || (word2[3] != wordle[4] && word2[3] == 'K') || (word2[4] != wordle[1] && word2[4] == 'K') || (word2[4] != wordle[2] && word2[4] == 'K') || (word2[4] != wordle[3] && word2[4] == 'K') || (word2[4] != wordle[0] && word2[4] == 'K') || (word3[0] != wordle[1] && word3[0] == 'K') || (word3[0] != wordle[2] && word3[0] == 'K') || (word3[0] != wordle[3] && word3[0] == 'K') || (word3[0] != wordle[4] && word3[0] == 'K') || (word3[1] != wordle[0] && word3[1] == 'K') || (word3[1] != wordle[2] && word3[1] == 'K') || (word3[1] != wordle[3] && word3[1] == 'K') || (word3[1] != wordle[4] && word3[1] == 'K') || (word3[2] != wordle[1] && word3[2] == 'K') || (word3[2] != wordle[0] && word3[2] == 'K') || (word3[2] != wordle[3] && word3[2] == 'K') || (word3[2] != wordle[4] && word3[2] == 'K') || (word3[3] != wordle[1] && word3[3] == 'K') || (word3[3] != wordle[2] && word3[3] == 'K') || (word3[3] != wordle[0] && word3[3] == 'K') || (word3[3] != wordle[4] && word3[3] == 'K') || (word3[4] != wordle[1] && word3[4] == 'K') || (word3[4] != wordle[2] && word3[4] == 'K') || (word3[4] != wordle[3] && word3[4] == 'K') || (word3[4] != wordle[0] && word3[4] == 'K') || (word4[0] != wordle[1] && word4[0] == 'K') || (word4[0] != wordle[2] && word4[0] == 'K') || (word4[0] != wordle[3] && word4[0] == 'K') || (word4[0] != wordle[4] && word4[0] == 'K') || (word4[1] != wordle[0] && word4[1] == 'K') || (word4[1] != wordle[2] && word4[1] == 'K') || (word4[1] != wordle[3] && word4[1] == 'K') || (word4[1] != wordle[4] && word4[1] == 'K') || (word4[2] != wordle[1] && word4[2] == 'K') || (word4[2] != wordle[0] && word4[2] == 'K') || (word4[2] != wordle[3] && word4[2] == 'K') || (word4[2] != wordle[4] && word4[2] == 'K') || (word4[3] != wordle[1] && word4[3] == 'K') || (word4[3] != wordle[2] && word4[3] == 'K') || (word4[3] != wordle[0] && word4[3] == 'K') || (word4[3] != wordle[4] && word4[3] == 'K') || (word4[4] != wordle[1] && word4[4] == 'K') || (word4[4] != wordle[2] && word4[4] == 'K') || (word4[4] != wordle[3] && word4[4] == 'K') || (word4[4] != wordle[0] && word4[4] == 'K') || (word5[0] != wordle[1] && word5[0] == 'K') || (word5[0] != wordle[2] && word5[0] == 'K') || (word5[0] != wordle[3] && word5[0] == 'K') || (word5[0] != wordle[4] && word5[0] == 'K') || (word5[1] != wordle[0] && word5[1] == 'K') || (word5[1] != wordle[2] && word5[1] == 'K') || (word5[1] != wordle[3] && word5[1] == 'K') || (word5[1] != wordle[4] && word5[1] == 'K') || (word5[2] != wordle[1] && word5[2] == 'K') || (word5[2] != wordle[0] && word5[2] == 'K') || (word5[2] != wordle[3] && word5[2] == 'K') || (word5[2] != wordle[4] && word5[2] == 'K') || (word5[3] != wordle[1] && word5[3] == 'K') || (word5[3] != wordle[2] && word5[3] == 'K') || (word5[3] != wordle[0] && word5[3] == 'K') || (word5[3] != wordle[4] && word5[3] == 'K') || (word5[4] != wordle[1] && word5[4] == 'K') || (word5[4] != wordle[2] && word5[4] == 'K') || (word5[4] != wordle[3] && word5[4] == 'K') || (word5[4] != wordle[0] && word5[4] == 'K') || (word6[0] != wordle[1] && word6[0] == 'K') || (word6[0] != wordle[2] && word6[0] == 'K') || (word6[0] != wordle[3] && word6[0] == 'K') || (word6[0] != wordle[4] && word6[0] == 'K') || (word6[1] != wordle[0] && word6[1] == 'K') || (word6[1] != wordle[2] && word6[1] == 'K') || (word6[1] != wordle[3] && word6[1] == 'K') || (word6[1] != wordle[4] && word6[1] == 'K') || (word6[2] != wordle[1] && word6[2] == 'K') || (word6[2] != wordle[0] && word6[2] == 'K') || (word6[2] != wordle[3] && word6[2] == 'K') || (word6[2] != wordle[4] && word6[2] == 'K') || (word6[3] != wordle[1] && word6[3] == 'K') || (word6[3] != wordle[2] && word6[3] == 'K') || (word6[3] != wordle[0] && word6[3] == 'K') || (word6[3] != wordle[4] && word6[3] == 'K') || (word6[4] != wordle[1] && word6[4] == 'K') || (word6[4] != wordle[2] && word6[4] == 'K') || (word6[4] != wordle[3] && word6[4] == 'K') || (word6[4] != wordle[0] && word6[4] == 'K'))
  {
    c3();
    cout << " K ";
    cout << RESET;
  }
  else 
  {
    cout << " K ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'L') || (word1[1] == wordle[1] && word1[1] == 'L') || (word1[2] == wordle[2] && word1[2] == 'L') || (word1[3] == wordle[3] && word1[3] == 'L') || (word1[4] == wordle[4] && word1[4] == 'L') || (word2[0] == wordle[0] && word2[0] == 'L') || (word2[1] == wordle[1] && word2[1] == 'L') || (word2[2] == wordle[2] && word2[2] == 'L') || (word2[3] == wordle[3] && word2[3] == 'L') || (word2[4] == wordle[4] && word2[4] == 'L') || (word3[0] == wordle[0] && word3[0] == 'L') || (word3[1] == wordle[1] && word3[1] == 'L') || (word3[2] == wordle[2] && word3[2] == 'L') || (word3[3] == wordle[3] && word3[3] == 'L') || (word3[4] == wordle[4] && word3[4] == 'L') || (word4[0] == wordle[0] && word4[0] == 'L') || (word4[1] == wordle[1] && word4[1] == 'L') || (word4[2] == wordle[2] && word4[2] == 'L') || (word4[3] == wordle[3] && word4[3] == 'L') || (word4[4] == wordle[4] && word4[4] == 'L') || (word5[0] == wordle[0] && word5[0] == 'L') || (word5[1] == wordle[1] && word5[1] == 'L') || (word5[2] == wordle[2] && word5[2] == 'L') || (word5[3] == wordle[3] && word5[3] == 'L') || (word5[4] == wordle[4] && word5[4] == 'L') || (word6[0] == wordle[0] && word6[0] == 'L') || (word6[1] == wordle[1] && word6[1] == 'L') || (word6[2] == wordle[2] && word6[2] == 'L') || (word6[3] == wordle[3] && word6[3] == 'L') || (word6[4] == wordle[4] && word6[4] == 'L'))
  {
    c1();
    cout << " L ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'L') || (word1[0] == wordle[2] && wordle[2] == 'L') || (word1[0] == wordle[3] && wordle[3] == 'L') || (word1[0] == wordle[4] && wordle[4] == 'L') || (word1[1] == wordle[0] && wordle[0] == 'L') || (word1[1] == wordle[2] && wordle[2] == 'L') || (word1[1] == wordle[3] && wordle[3] == 'L') || (word1[1] == wordle[4] && wordle[4] == 'L') || (word1[2] == wordle[1] && wordle[1] == 'L') || (word1[2] == wordle[0] && wordle[0] == 'L') || (word1[2] == wordle[3] && wordle[3] == 'L') || (word1[2] == wordle[4] && wordle[4] == 'L') || (word1[3] == wordle[1] && wordle[1] == 'L') || (word1[3] == wordle[0] && wordle[0] == 'L') || (word1[3] == wordle[2] && wordle[2] == 'L') || (word1[3] == wordle[4] && wordle[4] == 'L') || (word1[4] == wordle[1] && wordle[1] == 'L') || (word1[4] == wordle[0] && wordle[0] == 'L') || (word1[4] == wordle[3] && wordle[3] == 'L') || (word1[4] == wordle[2] && wordle[2] == 'L') || (word2[0] == wordle[1] && wordle[1] == 'L') || (word2[0] == wordle[2] && wordle[2] == 'L') || (word2[0] == wordle[3] && wordle[3] == 'L') || (word2[0] == wordle[4] && wordle[4] == 'L') || (word2[1] == wordle[0] && wordle[0] == 'L') || (word2[1] == wordle[2] && wordle[2] == 'L') || (word2[1] == wordle[3] && wordle[3] == 'L') || (word2[1] == wordle[4] && wordle[4] == 'L') || (word2[2] == wordle[1] && wordle[1] == 'L') || (word2[2] == wordle[0] && wordle[0] == 'L') || (word2[2] == wordle[3] && wordle[3] == 'L') || (word2[2] == wordle[4] && wordle[4] == 'L') || (word2[3] == wordle[1] && wordle[1] == 'L') || (word2[3] == wordle[0] && wordle[0] == 'L') || (word2[3] == wordle[2] && wordle[2] == 'L') || (word2[3] == wordle[4] && wordle[4] == 'L') || (word2[4] == wordle[1] && wordle[1] == 'L') || (word2[4] == wordle[0] && wordle[0] == 'L') || (word2[4] == wordle[3] && wordle[3] == 'L') || (word2[4] == wordle[2] && wordle[2] == 'L') || (word3[0] == wordle[1] && wordle[1] == 'L') || (word3[0] == wordle[2] && wordle[2] == 'L') || (word3[0] == wordle[3] && wordle[3] == 'L') || (word3[0] == wordle[4] && wordle[4] == 'L') || (word3[1] == wordle[0] && wordle[0] == 'L') || (word3[1] == wordle[2] && wordle[2] == 'L') || (word3[1] == wordle[3] && wordle[3] == 'L') || (word3[1] == wordle[4] && wordle[4] == 'L') || (word3[2] == wordle[1] && wordle[1] == 'L') || (word3[2] == wordle[0] && wordle[0] == 'L') || (word3[2] == wordle[3] && wordle[3] == 'L') || (word3[2] == wordle[4] && wordle[4] == 'L') || (word3[3] == wordle[1] && wordle[1] == 'L') || (word3[3] == wordle[0] && wordle[0] == 'L') || (word3[3] == wordle[2] && wordle[2] == 'L') || (word3[3] == wordle[4] && wordle[4] == 'L') || (word3[4] == wordle[1] && wordle[1] == 'L') || (word3[4] == wordle[0] && wordle[0] == 'L') || (word3[4] == wordle[3] && wordle[3] == 'L') || (word3[4] == wordle[2] && wordle[2] == 'L') || (word4[0] == wordle[1] && wordle[1] == 'L') || (word4[0] == wordle[2] && wordle[2] == 'L') || (word4[0] == wordle[3] && wordle[3] == 'L') || (word4[0] == wordle[4] && wordle[4] == 'L') || (word4[1] == wordle[0] && wordle[0] == 'L') || (word4[1] == wordle[2] && wordle[2] == 'L') || (word4[1] == wordle[3] && wordle[3] == 'L') || (word4[1] == wordle[4] && wordle[4] == 'L') || (word4[2] == wordle[1] && wordle[1] == 'L') || (word4[2] == wordle[0] && wordle[0] == 'L') || (word4[2] == wordle[3] && wordle[3] == 'L') || (word4[2] == wordle[4] && wordle[4] == 'L') || (word4[3] == wordle[1] && wordle[1] == 'L') || (word4[3] == wordle[0] && wordle[0] == 'L') || (word4[3] == wordle[2] && wordle[2] == 'L') || (word4[3] == wordle[4] && wordle[4] == 'L') || (word4[4] == wordle[1] && wordle[1] == 'L') || (word4[4] == wordle[0] && wordle[0] == 'L') || (word4[4] == wordle[3] && wordle[3] == 'L') || (word4[4] == wordle[2] && wordle[2] == 'L') || (word5[0] == wordle[1] && wordle[1] == 'L') || (word5[0] == wordle[2] && wordle[2] == 'L') || (word5[0] == wordle[3] && wordle[3] == 'L') || (word5[0] == wordle[4] && wordle[4] == 'L') || (word5[1] == wordle[0] && wordle[0] == 'L') || (word5[1] == wordle[2] && wordle[2] == 'L') || (word5[1] == wordle[3] && wordle[3] == 'L') || (word5[1] == wordle[4] && wordle[4] == 'L') || (word5[2] == wordle[1] && wordle[1] == 'L') || (word5[2] == wordle[0] && wordle[0] == 'L') || (word5[2] == wordle[3] && wordle[3] == 'L') || (word5[2] == wordle[4] && wordle[4] == 'L') || (word5[3] == wordle[1] && wordle[1] == 'L') || (word5[3] == wordle[0] && wordle[0] == 'L') || (word5[3] == wordle[2] && wordle[2] == 'L') || (word5[3] == wordle[4] && wordle[4] == 'L') || (word5[4] == wordle[1] && wordle[1] == 'L') || (word5[4] == wordle[0] && wordle[0] == 'L') || (word5[4] == wordle[3] && wordle[3] == 'L') || (word5[4] == wordle[2] && wordle[2] == 'L') || (word6[0] == wordle[1] && wordle[1] == 'L') || (word6[0] == wordle[2] && wordle[2] == 'L') || (word6[0] == wordle[3] && wordle[3] == 'L') || (word6[0] == wordle[4] && wordle[4] == 'L') || (word6[1] == wordle[0] && wordle[0] == 'L') || (word6[1] == wordle[2] && wordle[2] == 'L') || (word6[1] == wordle[3] && wordle[3] == 'L') || (word6[1] == wordle[4] && wordle[4] == 'L') || (word6[2] == wordle[1] && wordle[1] == 'L') || (word6[2] == wordle[0] && wordle[0] == 'L') || (word6[2] == wordle[3] && wordle[3] == 'L') || (word6[2] == wordle[4] && wordle[4] == 'L') || (word6[3] == wordle[1] && wordle[1] == 'L') || (word6[3] == wordle[0] && wordle[0] == 'L') || (word6[3] == wordle[2] && wordle[2] == 'L') || (word6[3] == wordle[4] && wordle[4] == 'L') || (word6[4] == wordle[1] && wordle[1] == 'L') || (word6[4] == wordle[0] && wordle[0] == 'L') || (word6[4] == wordle[3] && wordle[3] == 'L') || (word6[4] == wordle[2] && wordle[2] == 'L'))
  {
    c2();
    cout << " L ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'L') || (word1[0] != wordle[2] && word1[0] == 'L') || (word1[0] != wordle[3] && word1[0] == 'L') || (word1[0] != wordle[4] && word1[0] == 'L') || (word1[1] != wordle[0] && word1[1] == 'L') || (word1[1] != wordle[2] && word1[1] == 'L') || (word1[1] != wordle[3] && word1[1] == 'L') || (word1[1] != wordle[4] && word1[1] == 'L') || (word1[2] != wordle[1] && word1[2] == 'L') || (word1[2] != wordle[0] && word1[2] == 'L') || (word1[2] != wordle[3] && word1[2] == 'L') || (word1[2] != wordle[4] && word1[2] == 'L') || (word1[3] != wordle[1] && word1[3] == 'L') || (word1[3] != wordle[2] && word1[3] == 'L') || (word1[3] != wordle[0] && word1[3] == 'L') || (word1[3] != wordle[4] && word1[3] == 'L') || (word1[4] != wordle[1] && word1[4] == 'L') || (word1[4] != wordle[2] && word1[4] == 'L') || (word1[4] != wordle[3] && word1[4] == 'L') || (word1[4] != wordle[0] && word1[4] == 'L') || (word2[0] != wordle[1] && word2[0] == 'L') || (word2[0] != wordle[2] && word2[0] == 'L') || (word2[0] != wordle[3] && word2[0] == 'L') || (word2[0] != wordle[4] && word2[0] == 'L') || (word2[1] != wordle[0] && word2[1] == 'L') || (word2[1] != wordle[2] && word2[1] == 'L') || (word2[1] != wordle[3] && word2[1] == 'L') || (word2[1] != wordle[4] && word2[1] == 'L') || (word2[2] != wordle[1] && word2[2] == 'L') || (word2[2] != wordle[0] && word2[2] == 'L') || (word2[2] != wordle[3] && word2[2] == 'L') || (word2[2] != wordle[4] && word2[2] == 'L') || (word2[3] != wordle[1] && word2[3] == 'L') || (word2[3] != wordle[2] && word2[3] == 'L') || (word2[3] != wordle[0] && word2[3] == 'L') || (word2[3] != wordle[4] && word2[3] == 'L') || (word2[4] != wordle[1] && word2[4] == 'L') || (word2[4] != wordle[2] && word2[4] == 'L') || (word2[4] != wordle[3] && word2[4] == 'L') || (word2[4] != wordle[0] && word2[4] == 'L') || (word3[0] != wordle[1] && word3[0] == 'L') || (word3[0] != wordle[2] && word3[0] == 'L') || (word3[0] != wordle[3] && word3[0] == 'L') || (word3[0] != wordle[4] && word3[0] == 'L') || (word3[1] != wordle[0] && word3[1] == 'L') || (word3[1] != wordle[2] && word3[1] == 'L') || (word3[1] != wordle[3] && word3[1] == 'L') || (word3[1] != wordle[4] && word3[1] == 'L') || (word3[2] != wordle[1] && word3[2] == 'L') || (word3[2] != wordle[0] && word3[2] == 'L') || (word3[2] != wordle[3] && word3[2] == 'L') || (word3[2] != wordle[4] && word3[2] == 'L') || (word3[3] != wordle[1] && word3[3] == 'L') || (word3[3] != wordle[2] && word3[3] == 'L') || (word3[3] != wordle[0] && word3[3] == 'L') || (word3[3] != wordle[4] && word3[3] == 'L') || (word3[4] != wordle[1] && word3[4] == 'L') || (word3[4] != wordle[2] && word3[4] == 'L') || (word3[4] != wordle[3] && word3[4] == 'L') || (word3[4] != wordle[0] && word3[4] == 'L') || (word4[0] != wordle[1] && word4[0] == 'L') || (word4[0] != wordle[2] && word4[0] == 'L') || (word4[0] != wordle[3] && word4[0] == 'L') || (word4[0] != wordle[4] && word4[0] == 'L') || (word4[1] != wordle[0] && word4[1] == 'L') || (word4[1] != wordle[2] && word4[1] == 'L') || (word4[1] != wordle[3] && word4[1] == 'L') || (word4[1] != wordle[4] && word4[1] == 'L') || (word4[2] != wordle[1] && word4[2] == 'L') || (word4[2] != wordle[0] && word4[2] == 'L') || (word4[2] != wordle[3] && word4[2] == 'L') || (word4[2] != wordle[4] && word4[2] == 'L') || (word4[3] != wordle[1] && word4[3] == 'L') || (word4[3] != wordle[2] && word4[3] == 'L') || (word4[3] != wordle[0] && word4[3] == 'L') || (word4[3] != wordle[4] && word4[3] == 'L') || (word4[4] != wordle[1] && word4[4] == 'L') || (word4[4] != wordle[2] && word4[4] == 'L') || (word4[4] != wordle[3] && word4[4] == 'L') || (word4[4] != wordle[0] && word4[4] == 'L') || (word5[0] != wordle[1] && word5[0] == 'L') || (word5[0] != wordle[2] && word5[0] == 'L') || (word5[0] != wordle[3] && word5[0] == 'L') || (word5[0] != wordle[4] && word5[0] == 'L') || (word5[1] != wordle[0] && word5[1] == 'L') || (word5[1] != wordle[2] && word5[1] == 'L') || (word5[1] != wordle[3] && word5[1] == 'L') || (word5[1] != wordle[4] && word5[1] == 'L') || (word5[2] != wordle[1] && word5[2] == 'L') || (word5[2] != wordle[0] && word5[2] == 'L') || (word5[2] != wordle[3] && word5[2] == 'L') || (word5[2] != wordle[4] && word5[2] == 'L') || (word5[3] != wordle[1] && word5[3] == 'L') || (word5[3] != wordle[2] && word5[3] == 'L') || (word5[3] != wordle[0] && word5[3] == 'L') || (word5[3] != wordle[4] && word5[3] == 'L') || (word5[4] != wordle[1] && word5[4] == 'L') || (word5[4] != wordle[2] && word5[4] == 'L') || (word5[4] != wordle[3] && word5[4] == 'L') || (word5[4] != wordle[0] && word5[4] == 'L') || (word6[0] != wordle[1] && word6[0] == 'L') || (word6[0] != wordle[2] && word6[0] == 'L') || (word6[0] != wordle[3] && word6[0] == 'L') || (word6[0] != wordle[4] && word6[0] == 'L') || (word6[1] != wordle[0] && word6[1] == 'L') || (word6[1] != wordle[2] && word6[1] == 'L') || (word6[1] != wordle[3] && word6[1] == 'L') || (word6[1] != wordle[4] && word6[1] == 'L') || (word6[2] != wordle[1] && word6[2] == 'L') || (word6[2] != wordle[0] && word6[2] == 'L') || (word6[2] != wordle[3] && word6[2] == 'L') || (word6[2] != wordle[4] && word6[2] == 'L') || (word6[3] != wordle[1] && word6[3] == 'L') || (word6[3] != wordle[2] && word6[3] == 'L') || (word6[3] != wordle[0] && word6[3] == 'L') || (word6[3] != wordle[4] && word6[3] == 'L') || (word6[4] != wordle[1] && word6[4] == 'L') || (word6[4] != wordle[2] && word6[4] == 'L') || (word6[4] != wordle[3] && word6[4] == 'L') || (word6[4] != wordle[0] && word6[4] == 'L'))
  {
    c3();
    cout << " L ";
    cout << RESET;
  }
  else 
  {
    cout << " L ";
  }
  cout << endl;
  cout << endl;
  cout << "     ";
  if ((word1[0] == wordle[0] && word1[0] == 'Z') || (word1[1] == wordle[1] && word1[1] == 'Z') || (word1[2] == wordle[2] && word1[2] == 'Z') || (word1[3] == wordle[3] && word1[3] == 'Z') || (word1[4] == wordle[4] && word1[4] == 'Z') || (word2[0] == wordle[0] && word2[0] == 'Z') || (word2[1] == wordle[1] && word2[1] == 'Z') || (word2[2] == wordle[2] && word2[2] == 'Z') || (word2[3] == wordle[3] && word2[3] == 'Z') || (word2[4] == wordle[4] && word2[4] == 'Z') || (word3[0] == wordle[0] && word3[0] == 'Z') || (word3[1] == wordle[1] && word3[1] == 'Z') || (word3[2] == wordle[2] && word3[2] == 'Z') || (word3[3] == wordle[3] && word3[3] == 'Z') || (word3[4] == wordle[4] && word3[4] == 'Z') || (word4[0] == wordle[0] && word4[0] == 'Z') || (word4[1] == wordle[1] && word4[1] == 'Z') || (word4[2] == wordle[2] && word4[2] == 'Z') || (word4[3] == wordle[3] && word4[3] == 'Z') || (word4[4] == wordle[4] && word4[4] == 'Z') || (word5[0] == wordle[0] && word5[0] == 'Z') || (word5[1] == wordle[1] && word5[1] == 'Z') || (word5[2] == wordle[2] && word5[2] == 'Z') || (word5[3] == wordle[3] && word5[3] == 'Z') || (word5[4] == wordle[4] && word5[4] == 'Z') || (word6[0] == wordle[0] && word6[0] == 'Z') || (word6[1] == wordle[1] && word6[1] == 'Z') || (word6[2] == wordle[2] && word6[2] == 'Z') || (word6[3] == wordle[3] && word6[3] == 'Z') || (word6[4] == wordle[4] && word6[4] == 'Z'))
  {
    c1();
    cout << " Z ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'Z') || (word1[0] == wordle[2] && wordle[2] == 'Z') || (word1[0] == wordle[3] && wordle[3] == 'Z') || (word1[0] == wordle[4] && wordle[4] == 'Z') || (word1[1] == wordle[0] && wordle[0] == 'Z') || (word1[1] == wordle[2] && wordle[2] == 'Z') || (word1[1] == wordle[3] && wordle[3] == 'Z') || (word1[1] == wordle[4] && wordle[4] == 'Z') || (word1[2] == wordle[1] && wordle[1] == 'Z') || (word1[2] == wordle[0] && wordle[0] == 'Z') || (word1[2] == wordle[3] && wordle[3] == 'Z') || (word1[2] == wordle[4] && wordle[4] == 'Z') || (word1[3] == wordle[1] && wordle[1] == 'Z') || (word1[3] == wordle[0] && wordle[0] == 'Z') || (word1[3] == wordle[2] && wordle[2] == 'Z') || (word1[3] == wordle[4] && wordle[4] == 'Z') || (word1[4] == wordle[1] && wordle[1] == 'Z') || (word1[4] == wordle[0] && wordle[0] == 'Z') || (word1[4] == wordle[3] && wordle[3] == 'Z') || (word1[4] == wordle[2] && wordle[2] == 'Z') || (word2[0] == wordle[1] && wordle[1] == 'Z') || (word2[0] == wordle[2] && wordle[2] == 'Z') || (word2[0] == wordle[3] && wordle[3] == 'Z') || (word2[0] == wordle[4] && wordle[4] == 'Z') || (word2[1] == wordle[0] && wordle[0] == 'Z') || (word2[1] == wordle[2] && wordle[2] == 'Z') || (word2[1] == wordle[3] && wordle[3] == 'Z') || (word2[1] == wordle[4] && wordle[4] == 'Z') || (word2[2] == wordle[1] && wordle[1] == 'Z') || (word2[2] == wordle[0] && wordle[0] == 'Z') || (word2[2] == wordle[3] && wordle[3] == 'Z') || (word2[2] == wordle[4] && wordle[4] == 'Z') || (word2[3] == wordle[1] && wordle[1] == 'Z') || (word2[3] == wordle[0] && wordle[0] == 'Z') || (word2[3] == wordle[2] && wordle[2] == 'Z') || (word2[3] == wordle[4] && wordle[4] == 'Z') || (word2[4] == wordle[1] && wordle[1] == 'Z') || (word2[4] == wordle[0] && wordle[0] == 'Z') || (word2[4] == wordle[3] && wordle[3] == 'Z') || (word2[4] == wordle[2] && wordle[2] == 'Z') || (word3[0] == wordle[1] && wordle[1] == 'Z') || (word3[0] == wordle[2] && wordle[2] == 'Z') || (word3[0] == wordle[3] && wordle[3] == 'Z') || (word3[0] == wordle[4] && wordle[4] == 'Z') || (word3[1] == wordle[0] && wordle[0] == 'Z') || (word3[1] == wordle[2] && wordle[2] == 'Z') || (word3[1] == wordle[3] && wordle[3] == 'Z') || (word3[1] == wordle[4] && wordle[4] == 'Z') || (word3[2] == wordle[1] && wordle[1] == 'Z') || (word3[2] == wordle[0] && wordle[0] == 'Z') || (word3[2] == wordle[3] && wordle[3] == 'Z') || (word3[2] == wordle[4] && wordle[4] == 'Z') || (word3[3] == wordle[1] && wordle[1] == 'Z') || (word3[3] == wordle[0] && wordle[0] == 'Z') || (word3[3] == wordle[2] && wordle[2] == 'Z') || (word3[3] == wordle[4] && wordle[4] == 'Z') || (word3[4] == wordle[1] && wordle[1] == 'Z') || (word3[4] == wordle[0] && wordle[0] == 'Z') || (word3[4] == wordle[3] && wordle[3] == 'Z') || (word3[4] == wordle[2] && wordle[2] == 'Z') || (word4[0] == wordle[1] && wordle[1] == 'Z') || (word4[0] == wordle[2] && wordle[2] == 'Z') || (word4[0] == wordle[3] && wordle[3] == 'Z') || (word4[0] == wordle[4] && wordle[4] == 'Z') || (word4[1] == wordle[0] && wordle[0] == 'Z') || (word4[1] == wordle[2] && wordle[2] == 'Z') || (word4[1] == wordle[3] && wordle[3] == 'Z') || (word4[1] == wordle[4] && wordle[4] == 'Z') || (word4[2] == wordle[1] && wordle[1] == 'Z') || (word4[2] == wordle[0] && wordle[0] == 'Z') || (word4[2] == wordle[3] && wordle[3] == 'Z') || (word4[2] == wordle[4] && wordle[4] == 'Z') || (word4[3] == wordle[1] && wordle[1] == 'Z') || (word4[3] == wordle[0] && wordle[0] == 'Z') || (word4[3] == wordle[2] && wordle[2] == 'Z') || (word4[3] == wordle[4] && wordle[4] == 'Z') || (word4[4] == wordle[1] && wordle[1] == 'Z') || (word4[4] == wordle[0] && wordle[0] == 'Z') || (word4[4] == wordle[3] && wordle[3] == 'Z') || (word4[4] == wordle[2] && wordle[2] == 'Z') || (word5[0] == wordle[1] && wordle[1] == 'Z') || (word5[0] == wordle[2] && wordle[2] == 'Z') || (word5[0] == wordle[3] && wordle[3] == 'Z') || (word5[0] == wordle[4] && wordle[4] == 'Z') || (word5[1] == wordle[0] && wordle[0] == 'Z') || (word5[1] == wordle[2] && wordle[2] == 'Z') || (word5[1] == wordle[3] && wordle[3] == 'Z') || (word5[1] == wordle[4] && wordle[4] == 'Z') || (word5[2] == wordle[1] && wordle[1] == 'Z') || (word5[2] == wordle[0] && wordle[0] == 'Z') || (word5[2] == wordle[3] && wordle[3] == 'Z') || (word5[2] == wordle[4] && wordle[4] == 'Z') || (word5[3] == wordle[1] && wordle[1] == 'Z') || (word5[3] == wordle[0] && wordle[0] == 'Z') || (word5[3] == wordle[2] && wordle[2] == 'Z') || (word5[3] == wordle[4] && wordle[4] == 'Z') || (word5[4] == wordle[1] && wordle[1] == 'Z') || (word5[4] == wordle[0] && wordle[0] == 'Z') || (word5[4] == wordle[3] && wordle[3] == 'Z') || (word5[4] == wordle[2] && wordle[2] == 'Z') || (word6[0] == wordle[1] && wordle[1] == 'Z') || (word6[0] == wordle[2] && wordle[2] == 'Z') || (word6[0] == wordle[3] && wordle[3] == 'Z') || (word6[0] == wordle[4] && wordle[4] == 'Z') || (word6[1] == wordle[0] && wordle[0] == 'Z') || (word6[1] == wordle[2] && wordle[2] == 'Z') || (word6[1] == wordle[3] && wordle[3] == 'Z') || (word6[1] == wordle[4] && wordle[4] == 'Z') || (word6[2] == wordle[1] && wordle[1] == 'Z') || (word6[2] == wordle[0] && wordle[0] == 'Z') || (word6[2] == wordle[3] && wordle[3] == 'Z') || (word6[2] == wordle[4] && wordle[4] == 'Z') || (word6[3] == wordle[1] && wordle[1] == 'Z') || (word6[3] == wordle[0] && wordle[0] == 'Z') || (word6[3] == wordle[2] && wordle[2] == 'Z') || (word6[3] == wordle[4] && wordle[4] == 'Z') || (word6[4] == wordle[1] && wordle[1] == 'Z') || (word6[4] == wordle[0] && wordle[0] == 'Z') || (word6[4] == wordle[3] && wordle[3] == 'Z') || (word6[4] == wordle[2] && wordle[2] == 'Z'))
  {
    c2();
    cout << " Z ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'Z') || (word1[0] != wordle[2] && word1[0] == 'Z') || (word1[0] != wordle[3] && word1[0] == 'Z') || (word1[0] != wordle[4] && word1[0] == 'Z') || (word1[1] != wordle[0] && word1[1] == 'Z') || (word1[1] != wordle[2] && word1[1] == 'Z') || (word1[1] != wordle[3] && word1[1] == 'Z') || (word1[1] != wordle[4] && word1[1] == 'Z') || (word1[2] != wordle[1] && word1[2] == 'Z') || (word1[2] != wordle[0] && word1[2] == 'Z') || (word1[2] != wordle[3] && word1[2] == 'Z') || (word1[2] != wordle[4] && word1[2] == 'Z') || (word1[3] != wordle[1] && word1[3] == 'Z') || (word1[3] != wordle[2] && word1[3] == 'Z') || (word1[3] != wordle[0] && word1[3] == 'Z') || (word1[3] != wordle[4] && word1[3] == 'Z') || (word1[4] != wordle[1] && word1[4] == 'Z') || (word1[4] != wordle[2] && word1[4] == 'Z') || (word1[4] != wordle[3] && word1[4] == 'Z') || (word1[4] != wordle[0] && word1[4] == 'Z') || (word2[0] != wordle[1] && word2[0] == 'Z') || (word2[0] != wordle[2] && word2[0] == 'Z') || (word2[0] != wordle[3] && word2[0] == 'Z') || (word2[0] != wordle[4] && word2[0] == 'Z') || (word2[1] != wordle[0] && word2[1] == 'Z') || (word2[1] != wordle[2] && word2[1] == 'Z') || (word2[1] != wordle[3] && word2[1] == 'Z') || (word2[1] != wordle[4] && word2[1] == 'Z') || (word2[2] != wordle[1] && word2[2] == 'Z') || (word2[2] != wordle[0] && word2[2] == 'Z') || (word2[2] != wordle[3] && word2[2] == 'Z') || (word2[2] != wordle[4] && word2[2] == 'Z') || (word2[3] != wordle[1] && word2[3] == 'Z') || (word2[3] != wordle[2] && word2[3] == 'Z') || (word2[3] != wordle[0] && word2[3] == 'Z') || (word2[3] != wordle[4] && word2[3] == 'Z') || (word2[4] != wordle[1] && word2[4] == 'Z') || (word2[4] != wordle[2] && word2[4] == 'Z') || (word2[4] != wordle[3] && word2[4] == 'Z') || (word2[4] != wordle[0] && word2[4] == 'Z') || (word3[0] != wordle[1] && word3[0] == 'Z') || (word3[0] != wordle[2] && word3[0] == 'Z') || (word3[0] != wordle[3] && word3[0] == 'Z') || (word3[0] != wordle[4] && word3[0] == 'Z') || (word3[1] != wordle[0] && word3[1] == 'Z') || (word3[1] != wordle[2] && word3[1] == 'Z') || (word3[1] != wordle[3] && word3[1] == 'Z') || (word3[1] != wordle[4] && word3[1] == 'Z') || (word3[2] != wordle[1] && word3[2] == 'Z') || (word3[2] != wordle[0] && word3[2] == 'Z') || (word3[2] != wordle[3] && word3[2] == 'Z') || (word3[2] != wordle[4] && word3[2] == 'Z') || (word3[3] != wordle[1] && word3[3] == 'Z') || (word3[3] != wordle[2] && word3[3] == 'Z') || (word3[3] != wordle[0] && word3[3] == 'Z') || (word3[3] != wordle[4] && word3[3] == 'Z') || (word3[4] != wordle[1] && word3[4] == 'Z') || (word3[4] != wordle[2] && word3[4] == 'Z') || (word3[4] != wordle[3] && word3[4] == 'Z') || (word3[4] != wordle[0] && word3[4] == 'Z') || (word4[0] != wordle[1] && word4[0] == 'Z') || (word4[0] != wordle[2] && word4[0] == 'Z') || (word4[0] != wordle[3] && word4[0] == 'Z') || (word4[0] != wordle[4] && word4[0] == 'Z') || (word4[1] != wordle[0] && word4[1] == 'Z') || (word4[1] != wordle[2] && word4[1] == 'Z') || (word4[1] != wordle[3] && word4[1] == 'Z') || (word4[1] != wordle[4] && word4[1] == 'Z') || (word4[2] != wordle[1] && word4[2] == 'Z') || (word4[2] != wordle[0] && word4[2] == 'Z') || (word4[2] != wordle[3] && word4[2] == 'Z') || (word4[2] != wordle[4] && word4[2] == 'Z') || (word4[3] != wordle[1] && word4[3] == 'Z') || (word4[3] != wordle[2] && word4[3] == 'Z') || (word4[3] != wordle[0] && word4[3] == 'Z') || (word4[3] != wordle[4] && word4[3] == 'Z') || (word4[4] != wordle[1] && word4[4] == 'Z') || (word4[4] != wordle[2] && word4[4] == 'Z') || (word4[4] != wordle[3] && word4[4] == 'Z') || (word4[4] != wordle[0] && word4[4] == 'Z') || (word5[0] != wordle[1] && word5[0] == 'Z') || (word5[0] != wordle[2] && word5[0] == 'Z') || (word5[0] != wordle[3] && word5[0] == 'Z') || (word5[0] != wordle[4] && word5[0] == 'Z') || (word5[1] != wordle[0] && word5[1] == 'Z') || (word5[1] != wordle[2] && word5[1] == 'Z') || (word5[1] != wordle[3] && word5[1] == 'Z') || (word5[1] != wordle[4] && word5[1] == 'Z') || (word5[2] != wordle[1] && word5[2] == 'Z') || (word5[2] != wordle[0] && word5[2] == 'Z') || (word5[2] != wordle[3] && word5[2] == 'Z') || (word5[2] != wordle[4] && word5[2] == 'Z') || (word5[3] != wordle[1] && word5[3] == 'Z') || (word5[3] != wordle[2] && word5[3] == 'Z') || (word5[3] != wordle[0] && word5[3] == 'Z') || (word5[3] != wordle[4] && word5[3] == 'Z') || (word5[4] != wordle[1] && word5[4] == 'Z') || (word5[4] != wordle[2] && word5[4] == 'Z') || (word5[4] != wordle[3] && word5[4] == 'Z') || (word5[4] != wordle[0] && word5[4] == 'Z') || (word6[0] != wordle[1] && word6[0] == 'Z') || (word6[0] != wordle[2] && word6[0] == 'Z') || (word6[0] != wordle[3] && word6[0] == 'Z') || (word6[0] != wordle[4] && word6[0] == 'Z') || (word6[1] != wordle[0] && word6[1] == 'Z') || (word6[1] != wordle[2] && word6[1] == 'Z') || (word6[1] != wordle[3] && word6[1] == 'Z') || (word6[1] != wordle[4] && word6[1] == 'Z') || (word6[2] != wordle[1] && word6[2] == 'Z') || (word6[2] != wordle[0] && word6[2] == 'Z') || (word6[2] != wordle[3] && word6[2] == 'Z') || (word6[2] != wordle[4] && word6[2] == 'Z') || (word6[3] != wordle[1] && word6[3] == 'Z') || (word6[3] != wordle[2] && word6[3] == 'Z') || (word6[3] != wordle[0] && word6[3] == 'Z') || (word6[3] != wordle[4] && word6[3] == 'Z') || (word6[4] != wordle[1] && word6[4] == 'Z') || (word6[4] != wordle[2] && word6[4] == 'Z') || (word6[4] != wordle[3] && word6[4] == 'Z') || (word6[4] != wordle[0] && word6[4] == 'Z'))
  {
    c3();
    cout << " Z ";
    cout << RESET;
  }
  else 
  {
    cout << " Z ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'X') || (word1[1] == wordle[1] && word1[1] == 'X') || (word1[2] == wordle[2] && word1[2] == 'X') || (word1[3] == wordle[3] && word1[3] == 'X') || (word1[4] == wordle[4] && word1[4] == 'X') || (word2[0] == wordle[0] && word2[0] == 'X') || (word2[1] == wordle[1] && word2[1] == 'X') || (word2[2] == wordle[2] && word2[2] == 'X') || (word2[3] == wordle[3] && word2[3] == 'X') || (word2[4] == wordle[4] && word2[4] == 'X') || (word3[0] == wordle[0] && word3[0] == 'X') || (word3[1] == wordle[1] && word3[1] == 'X') || (word3[2] == wordle[2] && word3[2] == 'X') || (word3[3] == wordle[3] && word3[3] == 'X') || (word3[4] == wordle[4] && word3[4] == 'X') || (word4[0] == wordle[0] && word4[0] == 'X') || (word4[1] == wordle[1] && word4[1] == 'X') || (word4[2] == wordle[2] && word4[2] == 'X') || (word4[3] == wordle[3] && word4[3] == 'X') || (word4[4] == wordle[4] && word4[4] == 'X') || (word5[0] == wordle[0] && word5[0] == 'X') || (word5[1] == wordle[1] && word5[1] == 'X') || (word5[2] == wordle[2] && word5[2] == 'X') || (word5[3] == wordle[3] && word5[3] == 'X') || (word5[4] == wordle[4] && word5[4] == 'X') || (word6[0] == wordle[0] && word6[0] == 'X') || (word6[1] == wordle[1] && word6[1] == 'X') || (word6[2] == wordle[2] && word6[2] == 'X') || (word6[3] == wordle[3] && word6[3] == 'X') || (word6[4] == wordle[4] && word6[4] == 'X'))
  {
    c1();
    cout << " X ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'X') || (word1[0] == wordle[2] && wordle[2] == 'X') || (word1[0] == wordle[3] && wordle[3] == 'X') || (word1[0] == wordle[4] && wordle[4] == 'X') || (word1[1] == wordle[0] && wordle[0] == 'X') || (word1[1] == wordle[2] && wordle[2] == 'X') || (word1[1] == wordle[3] && wordle[3] == 'X') || (word1[1] == wordle[4] && wordle[4] == 'X') || (word1[2] == wordle[1] && wordle[1] == 'X') || (word1[2] == wordle[0] && wordle[0] == 'X') || (word1[2] == wordle[3] && wordle[3] == 'X') || (word1[2] == wordle[4] && wordle[4] == 'X') || (word1[3] == wordle[1] && wordle[1] == 'X') || (word1[3] == wordle[0] && wordle[0] == 'X') || (word1[3] == wordle[2] && wordle[2] == 'X') || (word1[3] == wordle[4] && wordle[4] == 'X') || (word1[4] == wordle[1] && wordle[1] == 'X') || (word1[4] == wordle[0] && wordle[0] == 'X') || (word1[4] == wordle[3] && wordle[3] == 'X') || (word1[4] == wordle[2] && wordle[2] == 'X') || (word2[0] == wordle[1] && wordle[1] == 'X') || (word2[0] == wordle[2] && wordle[2] == 'X') || (word2[0] == wordle[3] && wordle[3] == 'X') || (word2[0] == wordle[4] && wordle[4] == 'X') || (word2[1] == wordle[0] && wordle[0] == 'X') || (word2[1] == wordle[2] && wordle[2] == 'X') || (word2[1] == wordle[3] && wordle[3] == 'X') || (word2[1] == wordle[4] && wordle[4] == 'X') || (word2[2] == wordle[1] && wordle[1] == 'X') || (word2[2] == wordle[0] && wordle[0] == 'X') || (word2[2] == wordle[3] && wordle[3] == 'X') || (word2[2] == wordle[4] && wordle[4] == 'X') || (word2[3] == wordle[1] && wordle[1] == 'X') || (word2[3] == wordle[0] && wordle[0] == 'X') || (word2[3] == wordle[2] && wordle[2] == 'X') || (word2[3] == wordle[4] && wordle[4] == 'X') || (word2[4] == wordle[1] && wordle[1] == 'X') || (word2[4] == wordle[0] && wordle[0] == 'X') || (word2[4] == wordle[3] && wordle[3] == 'X') || (word2[4] == wordle[2] && wordle[2] == 'X') || (word3[0] == wordle[1] && wordle[1] == 'X') || (word3[0] == wordle[2] && wordle[2] == 'X') || (word3[0] == wordle[3] && wordle[3] == 'X') || (word3[0] == wordle[4] && wordle[4] == 'X') || (word3[1] == wordle[0] && wordle[0] == 'X') || (word3[1] == wordle[2] && wordle[2] == 'X') || (word3[1] == wordle[3] && wordle[3] == 'X') || (word3[1] == wordle[4] && wordle[4] == 'X') || (word3[2] == wordle[1] && wordle[1] == 'X') || (word3[2] == wordle[0] && wordle[0] == 'X') || (word3[2] == wordle[3] && wordle[3] == 'X') || (word3[2] == wordle[4] && wordle[4] == 'X') || (word3[3] == wordle[1] && wordle[1] == 'X') || (word3[3] == wordle[0] && wordle[0] == 'X') || (word3[3] == wordle[2] && wordle[2] == 'X') || (word3[3] == wordle[4] && wordle[4] == 'X') || (word3[4] == wordle[1] && wordle[1] == 'X') || (word3[4] == wordle[0] && wordle[0] == 'X') || (word3[4] == wordle[3] && wordle[3] == 'X') || (word3[4] == wordle[2] && wordle[2] == 'X') || (word4[0] == wordle[1] && wordle[1] == 'X') || (word4[0] == wordle[2] && wordle[2] == 'X') || (word4[0] == wordle[3] && wordle[3] == 'X') || (word4[0] == wordle[4] && wordle[4] == 'X') || (word4[1] == wordle[0] && wordle[0] == 'X') || (word4[1] == wordle[2] && wordle[2] == 'X') || (word4[1] == wordle[3] && wordle[3] == 'X') || (word4[1] == wordle[4] && wordle[4] == 'X') || (word4[2] == wordle[1] && wordle[1] == 'X') || (word4[2] == wordle[0] && wordle[0] == 'X') || (word4[2] == wordle[3] && wordle[3] == 'X') || (word4[2] == wordle[4] && wordle[4] == 'X') || (word4[3] == wordle[1] && wordle[1] == 'X') || (word4[3] == wordle[0] && wordle[0] == 'X') || (word4[3] == wordle[2] && wordle[2] == 'X') || (word4[3] == wordle[4] && wordle[4] == 'X') || (word4[4] == wordle[1] && wordle[1] == 'X') || (word4[4] == wordle[0] && wordle[0] == 'X') || (word4[4] == wordle[3] && wordle[3] == 'X') || (word4[4] == wordle[2] && wordle[2] == 'X') || (word5[0] == wordle[1] && wordle[1] == 'X') || (word5[0] == wordle[2] && wordle[2] == 'X') || (word5[0] == wordle[3] && wordle[3] == 'X') || (word5[0] == wordle[4] && wordle[4] == 'X') || (word5[1] == wordle[0] && wordle[0] == 'X') || (word5[1] == wordle[2] && wordle[2] == 'X') || (word5[1] == wordle[3] && wordle[3] == 'X') || (word5[1] == wordle[4] && wordle[4] == 'X') || (word5[2] == wordle[1] && wordle[1] == 'X') || (word5[2] == wordle[0] && wordle[0] == 'X') || (word5[2] == wordle[3] && wordle[3] == 'X') || (word5[2] == wordle[4] && wordle[4] == 'X') || (word5[3] == wordle[1] && wordle[1] == 'X') || (word5[3] == wordle[0] && wordle[0] == 'X') || (word5[3] == wordle[2] && wordle[2] == 'X') || (word5[3] == wordle[4] && wordle[4] == 'X') || (word5[4] == wordle[1] && wordle[1] == 'X') || (word5[4] == wordle[0] && wordle[0] == 'X') || (word5[4] == wordle[3] && wordle[3] == 'X') || (word5[4] == wordle[2] && wordle[2] == 'X') || (word6[0] == wordle[1] && wordle[1] == 'X') || (word6[0] == wordle[2] && wordle[2] == 'X') || (word6[0] == wordle[3] && wordle[3] == 'X') || (word6[0] == wordle[4] && wordle[4] == 'X') || (word6[1] == wordle[0] && wordle[0] == 'X') || (word6[1] == wordle[2] && wordle[2] == 'X') || (word6[1] == wordle[3] && wordle[3] == 'X') || (word6[1] == wordle[4] && wordle[4] == 'X') || (word6[2] == wordle[1] && wordle[1] == 'X') || (word6[2] == wordle[0] && wordle[0] == 'X') || (word6[2] == wordle[3] && wordle[3] == 'X') || (word6[2] == wordle[4] && wordle[4] == 'X') || (word6[3] == wordle[1] && wordle[1] == 'X') || (word6[3] == wordle[0] && wordle[0] == 'X') || (word6[3] == wordle[2] && wordle[2] == 'X') || (word6[3] == wordle[4] && wordle[4] == 'X') || (word6[4] == wordle[1] && wordle[1] == 'X') || (word6[4] == wordle[0] && wordle[0] == 'X') || (word6[4] == wordle[3] && wordle[3] == 'X') || (word6[4] == wordle[2] && wordle[2] == 'X'))
  {
    c2();
    cout << " X ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'X') || (word1[0] != wordle[2] && word1[0] == 'X') || (word1[0] != wordle[3] && word1[0] == 'X') || (word1[0] != wordle[4] && word1[0] == 'X') || (word1[1] != wordle[0] && word1[1] == 'X') || (word1[1] != wordle[2] && word1[1] == 'X') || (word1[1] != wordle[3] && word1[1] == 'X') || (word1[1] != wordle[4] && word1[1] == 'X') || (word1[2] != wordle[1] && word1[2] == 'X') || (word1[2] != wordle[0] && word1[2] == 'X') || (word1[2] != wordle[3] && word1[2] == 'X') || (word1[2] != wordle[4] && word1[2] == 'X') || (word1[3] != wordle[1] && word1[3] == 'X') || (word1[3] != wordle[2] && word1[3] == 'X') || (word1[3] != wordle[0] && word1[3] == 'X') || (word1[3] != wordle[4] && word1[3] == 'X') || (word1[4] != wordle[1] && word1[4] == 'X') || (word1[4] != wordle[2] && word1[4] == 'X') || (word1[4] != wordle[3] && word1[4] == 'X') || (word1[4] != wordle[0] && word1[4] == 'X') || (word2[0] != wordle[1] && word2[0] == 'X') || (word2[0] != wordle[2] && word2[0] == 'X') || (word2[0] != wordle[3] && word2[0] == 'X') || (word2[0] != wordle[4] && word2[0] == 'X') || (word2[1] != wordle[0] && word2[1] == 'X') || (word2[1] != wordle[2] && word2[1] == 'X') || (word2[1] != wordle[3] && word2[1] == 'X') || (word2[1] != wordle[4] && word2[1] == 'X') || (word2[2] != wordle[1] && word2[2] == 'X') || (word2[2] != wordle[0] && word2[2] == 'X') || (word2[2] != wordle[3] && word2[2] == 'X') || (word2[2] != wordle[4] && word2[2] == 'X') || (word2[3] != wordle[1] && word2[3] == 'X') || (word2[3] != wordle[2] && word2[3] == 'X') || (word2[3] != wordle[0] && word2[3] == 'X') || (word2[3] != wordle[4] && word2[3] == 'X') || (word2[4] != wordle[1] && word2[4] == 'X') || (word2[4] != wordle[2] && word2[4] == 'X') || (word2[4] != wordle[3] && word2[4] == 'X') || (word2[4] != wordle[0] && word2[4] == 'X') || (word3[0] != wordle[1] && word3[0] == 'X') || (word3[0] != wordle[2] && word3[0] == 'X') || (word3[0] != wordle[3] && word3[0] == 'X') || (word3[0] != wordle[4] && word3[0] == 'X') || (word3[1] != wordle[0] && word3[1] == 'X') || (word3[1] != wordle[2] && word3[1] == 'X') || (word3[1] != wordle[3] && word3[1] == 'X') || (word3[1] != wordle[4] && word3[1] == 'X') || (word3[2] != wordle[1] && word3[2] == 'X') || (word3[2] != wordle[0] && word3[2] == 'X') || (word3[2] != wordle[3] && word3[2] == 'X') || (word3[2] != wordle[4] && word3[2] == 'X') || (word3[3] != wordle[1] && word3[3] == 'X') || (word3[3] != wordle[2] && word3[3] == 'X') || (word3[3] != wordle[0] && word3[3] == 'X') || (word3[3] != wordle[4] && word3[3] == 'X') || (word3[4] != wordle[1] && word3[4] == 'X') || (word3[4] != wordle[2] && word3[4] == 'X') || (word3[4] != wordle[3] && word3[4] == 'X') || (word3[4] != wordle[0] && word3[4] == 'X') || (word4[0] != wordle[1] && word4[0] == 'X') || (word4[0] != wordle[2] && word4[0] == 'X') || (word4[0] != wordle[3] && word4[0] == 'X') || (word4[0] != wordle[4] && word4[0] == 'X') || (word4[1] != wordle[0] && word4[1] == 'X') || (word4[1] != wordle[2] && word4[1] == 'X') || (word4[1] != wordle[3] && word4[1] == 'X') || (word4[1] != wordle[4] && word4[1] == 'X') || (word4[2] != wordle[1] && word4[2] == 'X') || (word4[2] != wordle[0] && word4[2] == 'X') || (word4[2] != wordle[3] && word4[2] == 'X') || (word4[2] != wordle[4] && word4[2] == 'X') || (word4[3] != wordle[1] && word4[3] == 'X') || (word4[3] != wordle[2] && word4[3] == 'X') || (word4[3] != wordle[0] && word4[3] == 'X') || (word4[3] != wordle[4] && word4[3] == 'X') || (word4[4] != wordle[1] && word4[4] == 'X') || (word4[4] != wordle[2] && word4[4] == 'X') || (word4[4] != wordle[3] && word4[4] == 'X') || (word4[4] != wordle[0] && word4[4] == 'X') || (word5[0] != wordle[1] && word5[0] == 'X') || (word5[0] != wordle[2] && word5[0] == 'X') || (word5[0] != wordle[3] && word5[0] == 'X') || (word5[0] != wordle[4] && word5[0] == 'X') || (word5[1] != wordle[0] && word5[1] == 'X') || (word5[1] != wordle[2] && word5[1] == 'X') || (word5[1] != wordle[3] && word5[1] == 'X') || (word5[1] != wordle[4] && word5[1] == 'X') || (word5[2] != wordle[1] && word5[2] == 'X') || (word5[2] != wordle[0] && word5[2] == 'X') || (word5[2] != wordle[3] && word5[2] == 'X') || (word5[2] != wordle[4] && word5[2] == 'X') || (word5[3] != wordle[1] && word5[3] == 'X') || (word5[3] != wordle[2] && word5[3] == 'X') || (word5[3] != wordle[0] && word5[3] == 'X') || (word5[3] != wordle[4] && word5[3] == 'X') || (word5[4] != wordle[1] && word5[4] == 'X') || (word5[4] != wordle[2] && word5[4] == 'X') || (word5[4] != wordle[3] && word5[4] == 'X') || (word5[4] != wordle[0] && word5[4] == 'X') || (word6[0] != wordle[1] && word6[0] == 'X') || (word6[0] != wordle[2] && word6[0] == 'X') || (word6[0] != wordle[3] && word6[0] == 'X') || (word6[0] != wordle[4] && word6[0] == 'X') || (word6[1] != wordle[0] && word6[1] == 'X') || (word6[1] != wordle[2] && word6[1] == 'X') || (word6[1] != wordle[3] && word6[1] == 'X') || (word6[1] != wordle[4] && word6[1] == 'X') || (word6[2] != wordle[1] && word6[2] == 'X') || (word6[2] != wordle[0] && word6[2] == 'X') || (word6[2] != wordle[3] && word6[2] == 'X') || (word6[2] != wordle[4] && word6[2] == 'X') || (word6[3] != wordle[1] && word6[3] == 'X') || (word6[3] != wordle[2] && word6[3] == 'X') || (word6[3] != wordle[0] && word6[3] == 'X') || (word6[3] != wordle[4] && word6[3] == 'X') || (word6[4] != wordle[1] && word6[4] == 'X') || (word6[4] != wordle[2] && word6[4] == 'X') || (word6[4] != wordle[3] && word6[4] == 'X') || (word6[4] != wordle[0] && word6[4] == 'X'))
  {
    c3();
    cout << " X ";
    cout << RESET;
  }
  else 
  {
    cout << " X ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'C') || (word1[1] == wordle[1] && word1[1] == 'C') || (word1[2] == wordle[2] && word1[2] == 'C') || (word1[3] == wordle[3] && word1[3] == 'C') || (word1[4] == wordle[4] && word1[4] == 'C') || (word2[0] == wordle[0] && word2[0] == 'C') || (word2[1] == wordle[1] && word2[1] == 'C') || (word2[2] == wordle[2] && word2[2] == 'C') || (word2[3] == wordle[3] && word2[3] == 'C') || (word2[4] == wordle[4] && word2[4] == 'C') || (word3[0] == wordle[0] && word3[0] == 'C') || (word3[1] == wordle[1] && word3[1] == 'C') || (word3[2] == wordle[2] && word3[2] == 'C') || (word3[3] == wordle[3] && word3[3] == 'C') || (word3[4] == wordle[4] && word3[4] == 'C') || (word4[0] == wordle[0] && word4[0] == 'C') || (word4[1] == wordle[1] && word4[1] == 'C') || (word4[2] == wordle[2] && word4[2] == 'C') || (word4[3] == wordle[3] && word4[3] == 'C') || (word4[4] == wordle[4] && word4[4] == 'C') || (word5[0] == wordle[0] && word5[0] == 'C') || (word5[1] == wordle[1] && word5[1] == 'C') || (word5[2] == wordle[2] && word5[2] == 'C') || (word5[3] == wordle[3] && word5[3] == 'C') || (word5[4] == wordle[4] && word5[4] == 'C') || (word6[0] == wordle[0] && word6[0] == 'C') || (word6[1] == wordle[1] && word6[1] == 'C') || (word6[2] == wordle[2] && word6[2] == 'C') || (word6[3] == wordle[3] && word6[3] == 'C') || (word6[4] == wordle[4] && word6[4] == 'C'))
  {
    c1();
    cout << " C ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'C') || (word1[0] == wordle[2] && wordle[2] == 'C') || (word1[0] == wordle[3] && wordle[3] == 'C') || (word1[0] == wordle[4] && wordle[4] == 'C') || (word1[1] == wordle[0] && wordle[0] == 'C') || (word1[1] == wordle[2] && wordle[2] == 'C') || (word1[1] == wordle[3] && wordle[3] == 'C') || (word1[1] == wordle[4] && wordle[4] == 'C') || (word1[2] == wordle[1] && wordle[1] == 'C') || (word1[2] == wordle[0] && wordle[0] == 'C') || (word1[2] == wordle[3] && wordle[3] == 'C') || (word1[2] == wordle[4] && wordle[4] == 'C') || (word1[3] == wordle[1] && wordle[1] == 'C') || (word1[3] == wordle[0] && wordle[0] == 'C') || (word1[3] == wordle[2] && wordle[2] == 'C') || (word1[3] == wordle[4] && wordle[4] == 'C') || (word1[4] == wordle[1] && wordle[1] == 'C') || (word1[4] == wordle[0] && wordle[0] == 'C') || (word1[4] == wordle[3] && wordle[3] == 'C') || (word1[4] == wordle[2] && wordle[2] == 'C') || (word2[0] == wordle[1] && wordle[1] == 'C') || (word2[0] == wordle[2] && wordle[2] == 'C') || (word2[0] == wordle[3] && wordle[3] == 'C') || (word2[0] == wordle[4] && wordle[4] == 'C') || (word2[1] == wordle[0] && wordle[0] == 'C') || (word2[1] == wordle[2] && wordle[2] == 'C') || (word2[1] == wordle[3] && wordle[3] == 'C') || (word2[1] == wordle[4] && wordle[4] == 'C') || (word2[2] == wordle[1] && wordle[1] == 'C') || (word2[2] == wordle[0] && wordle[0] == 'C') || (word2[2] == wordle[3] && wordle[3] == 'C') || (word2[2] == wordle[4] && wordle[4] == 'C') || (word2[3] == wordle[1] && wordle[1] == 'C') || (word2[3] == wordle[0] && wordle[0] == 'C') || (word2[3] == wordle[2] && wordle[2] == 'C') || (word2[3] == wordle[4] && wordle[4] == 'C') || (word2[4] == wordle[1] && wordle[1] == 'C') || (word2[4] == wordle[0] && wordle[0] == 'C') || (word2[4] == wordle[3] && wordle[3] == 'C') || (word2[4] == wordle[2] && wordle[2] == 'C') || (word3[0] == wordle[1] && wordle[1] == 'C') || (word3[0] == wordle[2] && wordle[2] == 'C') || (word3[0] == wordle[3] && wordle[3] == 'C') || (word3[0] == wordle[4] && wordle[4] == 'C') || (word3[1] == wordle[0] && wordle[0] == 'C') || (word3[1] == wordle[2] && wordle[2] == 'C') || (word3[1] == wordle[3] && wordle[3] == 'C') || (word3[1] == wordle[4] && wordle[4] == 'C') || (word3[2] == wordle[1] && wordle[1] == 'C') || (word3[2] == wordle[0] && wordle[0] == 'C') || (word3[2] == wordle[3] && wordle[3] == 'C') || (word3[2] == wordle[4] && wordle[4] == 'C') || (word3[3] == wordle[1] && wordle[1] == 'C') || (word3[3] == wordle[0] && wordle[0] == 'C') || (word3[3] == wordle[2] && wordle[2] == 'C') || (word3[3] == wordle[4] && wordle[4] == 'C') || (word3[4] == wordle[1] && wordle[1] == 'C') || (word3[4] == wordle[0] && wordle[0] == 'C') || (word3[4] == wordle[3] && wordle[3] == 'C') || (word3[4] == wordle[2] && wordle[2] == 'C') || (word4[0] == wordle[1] && wordle[1] == 'C') || (word4[0] == wordle[2] && wordle[2] == 'C') || (word4[0] == wordle[3] && wordle[3] == 'C') || (word4[0] == wordle[4] && wordle[4] == 'C') || (word4[1] == wordle[0] && wordle[0] == 'C') || (word4[1] == wordle[2] && wordle[2] == 'C') || (word4[1] == wordle[3] && wordle[3] == 'C') || (word4[1] == wordle[4] && wordle[4] == 'C') || (word4[2] == wordle[1] && wordle[1] == 'C') || (word4[2] == wordle[0] && wordle[0] == 'C') || (word4[2] == wordle[3] && wordle[3] == 'C') || (word4[2] == wordle[4] && wordle[4] == 'C') || (word4[3] == wordle[1] && wordle[1] == 'C') || (word4[3] == wordle[0] && wordle[0] == 'C') || (word4[3] == wordle[2] && wordle[2] == 'C') || (word4[3] == wordle[4] && wordle[4] == 'C') || (word4[4] == wordle[1] && wordle[1] == 'C') || (word4[4] == wordle[0] && wordle[0] == 'C') || (word4[4] == wordle[3] && wordle[3] == 'C') || (word4[4] == wordle[2] && wordle[2] == 'C') || (word5[0] == wordle[1] && wordle[1] == 'C') || (word5[0] == wordle[2] && wordle[2] == 'C') || (word5[0] == wordle[3] && wordle[3] == 'C') || (word5[0] == wordle[4] && wordle[4] == 'C') || (word5[1] == wordle[0] && wordle[0] == 'C') || (word5[1] == wordle[2] && wordle[2] == 'C') || (word5[1] == wordle[3] && wordle[3] == 'C') || (word5[1] == wordle[4] && wordle[4] == 'C') || (word5[2] == wordle[1] && wordle[1] == 'C') || (word5[2] == wordle[0] && wordle[0] == 'C') || (word5[2] == wordle[3] && wordle[3] == 'C') || (word5[2] == wordle[4] && wordle[4] == 'C') || (word5[3] == wordle[1] && wordle[1] == 'C') || (word5[3] == wordle[0] && wordle[0] == 'C') || (word5[3] == wordle[2] && wordle[2] == 'C') || (word5[3] == wordle[4] && wordle[4] == 'C') || (word5[4] == wordle[1] && wordle[1] == 'C') || (word5[4] == wordle[0] && wordle[0] == 'C') || (word5[4] == wordle[3] && wordle[3] == 'C') || (word5[4] == wordle[2] && wordle[2] == 'C') || (word6[0] == wordle[1] && wordle[1] == 'C') || (word6[0] == wordle[2] && wordle[2] == 'C') || (word6[0] == wordle[3] && wordle[3] == 'C') || (word6[0] == wordle[4] && wordle[4] == 'C') || (word6[1] == wordle[0] && wordle[0] == 'C') || (word6[1] == wordle[2] && wordle[2] == 'C') || (word6[1] == wordle[3] && wordle[3] == 'C') || (word6[1] == wordle[4] && wordle[4] == 'C') || (word6[2] == wordle[1] && wordle[1] == 'C') || (word6[2] == wordle[0] && wordle[0] == 'C') || (word6[2] == wordle[3] && wordle[3] == 'C') || (word6[2] == wordle[4] && wordle[4] == 'C') || (word6[3] == wordle[1] && wordle[1] == 'C') || (word6[3] == wordle[0] && wordle[0] == 'C') || (word6[3] == wordle[2] && wordle[2] == 'C') || (word6[3] == wordle[4] && wordle[4] == 'C') || (word6[4] == wordle[1] && wordle[1] == 'C') || (word6[4] == wordle[0] && wordle[0] == 'C') || (word6[4] == wordle[3] && wordle[3] == 'C') || (word6[4] == wordle[2] && wordle[2] == 'C'))
  {
    c2();
    cout << " C ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'C') || (word1[0] != wordle[2] && word1[0] == 'C') || (word1[0] != wordle[3] && word1[0] == 'C') || (word1[0] != wordle[4] && word1[0] == 'C') || (word1[1] != wordle[0] && word1[1] == 'C') || (word1[1] != wordle[2] && word1[1] == 'C') || (word1[1] != wordle[3] && word1[1] == 'C') || (word1[1] != wordle[4] && word1[1] == 'C') || (word1[2] != wordle[1] && word1[2] == 'C') || (word1[2] != wordle[0] && word1[2] == 'C') || (word1[2] != wordle[3] && word1[2] == 'C') || (word1[2] != wordle[4] && word1[2] == 'C') || (word1[3] != wordle[1] && word1[3] == 'C') || (word1[3] != wordle[2] && word1[3] == 'C') || (word1[3] != wordle[0] && word1[3] == 'C') || (word1[3] != wordle[4] && word1[3] == 'C') || (word1[4] != wordle[1] && word1[4] == 'C') || (word1[4] != wordle[2] && word1[4] == 'C') || (word1[4] != wordle[3] && word1[4] == 'C') || (word1[4] != wordle[0] && word1[4] == 'C') || (word2[0] != wordle[1] && word2[0] == 'C') || (word2[0] != wordle[2] && word2[0] == 'C') || (word2[0] != wordle[3] && word2[0] == 'C') || (word2[0] != wordle[4] && word2[0] == 'C') || (word2[1] != wordle[0] && word2[1] == 'C') || (word2[1] != wordle[2] && word2[1] == 'C') || (word2[1] != wordle[3] && word2[1] == 'C') || (word2[1] != wordle[4] && word2[1] == 'C') || (word2[2] != wordle[1] && word2[2] == 'C') || (word2[2] != wordle[0] && word2[2] == 'C') || (word2[2] != wordle[3] && word2[2] == 'C') || (word2[2] != wordle[4] && word2[2] == 'C') || (word2[3] != wordle[1] && word2[3] == 'C') || (word2[3] != wordle[2] && word2[3] == 'C') || (word2[3] != wordle[0] && word2[3] == 'C') || (word2[3] != wordle[4] && word2[3] == 'C') || (word2[4] != wordle[1] && word2[4] == 'C') || (word2[4] != wordle[2] && word2[4] == 'C') || (word2[4] != wordle[3] && word2[4] == 'C') || (word2[4] != wordle[0] && word2[4] == 'C') || (word3[0] != wordle[1] && word3[0] == 'C') || (word3[0] != wordle[2] && word3[0] == 'C') || (word3[0] != wordle[3] && word3[0] == 'C') || (word3[0] != wordle[4] && word3[0] == 'C') || (word3[1] != wordle[0] && word3[1] == 'C') || (word3[1] != wordle[2] && word3[1] == 'C') || (word3[1] != wordle[3] && word3[1] == 'C') || (word3[1] != wordle[4] && word3[1] == 'C') || (word3[2] != wordle[1] && word3[2] == 'C') || (word3[2] != wordle[0] && word3[2] == 'C') || (word3[2] != wordle[3] && word3[2] == 'C') || (word3[2] != wordle[4] && word3[2] == 'C') || (word3[3] != wordle[1] && word3[3] == 'C') || (word3[3] != wordle[2] && word3[3] == 'C') || (word3[3] != wordle[0] && word3[3] == 'C') || (word3[3] != wordle[4] && word3[3] == 'C') || (word3[4] != wordle[1] && word3[4] == 'C') || (word3[4] != wordle[2] && word3[4] == 'C') || (word3[4] != wordle[3] && word3[4] == 'C') || (word3[4] != wordle[0] && word3[4] == 'C') || (word4[0] != wordle[1] && word4[0] == 'C') || (word4[0] != wordle[2] && word4[0] == 'C') || (word4[0] != wordle[3] && word4[0] == 'C') || (word4[0] != wordle[4] && word4[0] == 'C') || (word4[1] != wordle[0] && word4[1] == 'C') || (word4[1] != wordle[2] && word4[1] == 'C') || (word4[1] != wordle[3] && word4[1] == 'C') || (word4[1] != wordle[4] && word4[1] == 'C') || (word4[2] != wordle[1] && word4[2] == 'C') || (word4[2] != wordle[0] && word4[2] == 'C') || (word4[2] != wordle[3] && word4[2] == 'C') || (word4[2] != wordle[4] && word4[2] == 'C') || (word4[3] != wordle[1] && word4[3] == 'C') || (word4[3] != wordle[2] && word4[3] == 'C') || (word4[3] != wordle[0] && word4[3] == 'C') || (word4[3] != wordle[4] && word4[3] == 'C') || (word4[4] != wordle[1] && word4[4] == 'C') || (word4[4] != wordle[2] && word4[4] == 'C') || (word4[4] != wordle[3] && word4[4] == 'C') || (word4[4] != wordle[0] && word4[4] == 'C') || (word5[0] != wordle[1] && word5[0] == 'C') || (word5[0] != wordle[2] && word5[0] == 'C') || (word5[0] != wordle[3] && word5[0] == 'C') || (word5[0] != wordle[4] && word5[0] == 'C') || (word5[1] != wordle[0] && word5[1] == 'C') || (word5[1] != wordle[2] && word5[1] == 'C') || (word5[1] != wordle[3] && word5[1] == 'C') || (word5[1] != wordle[4] && word5[1] == 'C') || (word5[2] != wordle[1] && word5[2] == 'C') || (word5[2] != wordle[0] && word5[2] == 'C') || (word5[2] != wordle[3] && word5[2] == 'C') || (word5[2] != wordle[4] && word5[2] == 'C') || (word5[3] != wordle[1] && word5[3] == 'C') || (word5[3] != wordle[2] && word5[3] == 'C') || (word5[3] != wordle[0] && word5[3] == 'C') || (word5[3] != wordle[4] && word5[3] == 'C') || (word5[4] != wordle[1] && word5[4] == 'C') || (word5[4] != wordle[2] && word5[4] == 'C') || (word5[4] != wordle[3] && word5[4] == 'C') || (word5[4] != wordle[0] && word5[4] == 'C') || (word6[0] != wordle[1] && word6[0] == 'C') || (word6[0] != wordle[2] && word6[0] == 'C') || (word6[0] != wordle[3] && word6[0] == 'C') || (word6[0] != wordle[4] && word6[0] == 'C') || (word6[1] != wordle[0] && word6[1] == 'C') || (word6[1] != wordle[2] && word6[1] == 'C') || (word6[1] != wordle[3] && word6[1] == 'C') || (word6[1] != wordle[4] && word6[1] == 'C') || (word6[2] != wordle[1] && word6[2] == 'C') || (word6[2] != wordle[0] && word6[2] == 'C') || (word6[2] != wordle[3] && word6[2] == 'C') || (word6[2] != wordle[4] && word6[2] == 'C') || (word6[3] != wordle[1] && word6[3] == 'C') || (word6[3] != wordle[2] && word6[3] == 'C') || (word6[3] != wordle[0] && word6[3] == 'C') || (word6[3] != wordle[4] && word6[3] == 'C') || (word6[4] != wordle[1] && word6[4] == 'C') || (word6[4] != wordle[2] && word6[4] == 'C') || (word6[4] != wordle[3] && word6[4] == 'C') || (word6[4] != wordle[0] && word6[4] == 'C'))
  {
    c3();
    cout << " C ";
    cout << RESET;
  }
  else 
  {
    cout << " C ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'V') || (word1[1] == wordle[1] && word1[1] == 'V') || (word1[2] == wordle[2] && word1[2] == 'V') || (word1[3] == wordle[3] && word1[3] == 'V') || (word1[4] == wordle[4] && word1[4] == 'V') || (word2[0] == wordle[0] && word2[0] == 'V') || (word2[1] == wordle[1] && word2[1] == 'V') || (word2[2] == wordle[2] && word2[2] == 'V') || (word2[3] == wordle[3] && word2[3] == 'V') || (word2[4] == wordle[4] && word2[4] == 'V') || (word3[0] == wordle[0] && word3[0] == 'V') || (word3[1] == wordle[1] && word3[1] == 'V') || (word3[2] == wordle[2] && word3[2] == 'V') || (word3[3] == wordle[3] && word3[3] == 'V') || (word3[4] == wordle[4] && word3[4] == 'V') || (word4[0] == wordle[0] && word4[0] == 'V') || (word4[1] == wordle[1] && word4[1] == 'V') || (word4[2] == wordle[2] && word4[2] == 'V') || (word4[3] == wordle[3] && word4[3] == 'V') || (word4[4] == wordle[4] && word4[4] == 'V') || (word5[0] == wordle[0] && word5[0] == 'V') || (word5[1] == wordle[1] && word5[1] == 'V') || (word5[2] == wordle[2] && word5[2] == 'V') || (word5[3] == wordle[3] && word5[3] == 'V') || (word5[4] == wordle[4] && word5[4] == 'V') || (word6[0] == wordle[0] && word6[0] == 'V') || (word6[1] == wordle[1] && word6[1] == 'V') || (word6[2] == wordle[2] && word6[2] == 'V') || (word6[3] == wordle[3] && word6[3] == 'V') || (word6[4] == wordle[4] && word6[4] == 'V'))
  {
    c1();
    cout << " V ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'V') || (word1[0] == wordle[2] && wordle[2] == 'V') || (word1[0] == wordle[3] && wordle[3] == 'V') || (word1[0] == wordle[4] && wordle[4] == 'V') || (word1[1] == wordle[0] && wordle[0] == 'V') || (word1[1] == wordle[2] && wordle[2] == 'V') || (word1[1] == wordle[3] && wordle[3] == 'V') || (word1[1] == wordle[4] && wordle[4] == 'V') || (word1[2] == wordle[1] && wordle[1] == 'V') || (word1[2] == wordle[0] && wordle[0] == 'V') || (word1[2] == wordle[3] && wordle[3] == 'V') || (word1[2] == wordle[4] && wordle[4] == 'V') || (word1[3] == wordle[1] && wordle[1] == 'V') || (word1[3] == wordle[0] && wordle[0] == 'V') || (word1[3] == wordle[2] && wordle[2] == 'V') || (word1[3] == wordle[4] && wordle[4] == 'V') || (word1[4] == wordle[1] && wordle[1] == 'V') || (word1[4] == wordle[0] && wordle[0] == 'V') || (word1[4] == wordle[3] && wordle[3] == 'V') || (word1[4] == wordle[2] && wordle[2] == 'V') || (word2[0] == wordle[1] && wordle[1] == 'V') || (word2[0] == wordle[2] && wordle[2] == 'V') || (word2[0] == wordle[3] && wordle[3] == 'V') || (word2[0] == wordle[4] && wordle[4] == 'V') || (word2[1] == wordle[0] && wordle[0] == 'V') || (word2[1] == wordle[2] && wordle[2] == 'V') || (word2[1] == wordle[3] && wordle[3] == 'V') || (word2[1] == wordle[4] && wordle[4] == 'V') || (word2[2] == wordle[1] && wordle[1] == 'V') || (word2[2] == wordle[0] && wordle[0] == 'V') || (word2[2] == wordle[3] && wordle[3] == 'V') || (word2[2] == wordle[4] && wordle[4] == 'V') || (word2[3] == wordle[1] && wordle[1] == 'V') || (word2[3] == wordle[0] && wordle[0] == 'V') || (word2[3] == wordle[2] && wordle[2] == 'V') || (word2[3] == wordle[4] && wordle[4] == 'V') || (word2[4] == wordle[1] && wordle[1] == 'V') || (word2[4] == wordle[0] && wordle[0] == 'V') || (word2[4] == wordle[3] && wordle[3] == 'V') || (word2[4] == wordle[2] && wordle[2] == 'V') || (word3[0] == wordle[1] && wordle[1] == 'V') || (word3[0] == wordle[2] && wordle[2] == 'V') || (word3[0] == wordle[3] && wordle[3] == 'V') || (word3[0] == wordle[4] && wordle[4] == 'V') || (word3[1] == wordle[0] && wordle[0] == 'V') || (word3[1] == wordle[2] && wordle[2] == 'V') || (word3[1] == wordle[3] && wordle[3] == 'V') || (word3[1] == wordle[4] && wordle[4] == 'V') || (word3[2] == wordle[1] && wordle[1] == 'V') || (word3[2] == wordle[0] && wordle[0] == 'V') || (word3[2] == wordle[3] && wordle[3] == 'V') || (word3[2] == wordle[4] && wordle[4] == 'V') || (word3[3] == wordle[1] && wordle[1] == 'V') || (word3[3] == wordle[0] && wordle[0] == 'V') || (word3[3] == wordle[2] && wordle[2] == 'V') || (word3[3] == wordle[4] && wordle[4] == 'V') || (word3[4] == wordle[1] && wordle[1] == 'V') || (word3[4] == wordle[0] && wordle[0] == 'V') || (word3[4] == wordle[3] && wordle[3] == 'V') || (word3[4] == wordle[2] && wordle[2] == 'V') || (word4[0] == wordle[1] && wordle[1] == 'V') || (word4[0] == wordle[2] && wordle[2] == 'V') || (word4[0] == wordle[3] && wordle[3] == 'V') || (word4[0] == wordle[4] && wordle[4] == 'V') || (word4[1] == wordle[0] && wordle[0] == 'V') || (word4[1] == wordle[2] && wordle[2] == 'V') || (word4[1] == wordle[3] && wordle[3] == 'V') || (word4[1] == wordle[4] && wordle[4] == 'V') || (word4[2] == wordle[1] && wordle[1] == 'V') || (word4[2] == wordle[0] && wordle[0] == 'V') || (word4[2] == wordle[3] && wordle[3] == 'V') || (word4[2] == wordle[4] && wordle[4] == 'V') || (word4[3] == wordle[1] && wordle[1] == 'V') || (word4[3] == wordle[0] && wordle[0] == 'V') || (word4[3] == wordle[2] && wordle[2] == 'V') || (word4[3] == wordle[4] && wordle[4] == 'V') || (word4[4] == wordle[1] && wordle[1] == 'V') || (word4[4] == wordle[0] && wordle[0] == 'V') || (word4[4] == wordle[3] && wordle[3] == 'V') || (word4[4] == wordle[2] && wordle[2] == 'V') || (word5[0] == wordle[1] && wordle[1] == 'V') || (word5[0] == wordle[2] && wordle[2] == 'V') || (word5[0] == wordle[3] && wordle[3] == 'V') || (word5[0] == wordle[4] && wordle[4] == 'V') || (word5[1] == wordle[0] && wordle[0] == 'V') || (word5[1] == wordle[2] && wordle[2] == 'V') || (word5[1] == wordle[3] && wordle[3] == 'V') || (word5[1] == wordle[4] && wordle[4] == 'V') || (word5[2] == wordle[1] && wordle[1] == 'V') || (word5[2] == wordle[0] && wordle[0] == 'V') || (word5[2] == wordle[3] && wordle[3] == 'V') || (word5[2] == wordle[4] && wordle[4] == 'V') || (word5[3] == wordle[1] && wordle[1] == 'V') || (word5[3] == wordle[0] && wordle[0] == 'V') || (word5[3] == wordle[2] && wordle[2] == 'V') || (word5[3] == wordle[4] && wordle[4] == 'V') || (word5[4] == wordle[1] && wordle[1] == 'V') || (word5[4] == wordle[0] && wordle[0] == 'V') || (word5[4] == wordle[3] && wordle[3] == 'V') || (word5[4] == wordle[2] && wordle[2] == 'V') || (word6[0] == wordle[1] && wordle[1] == 'V') || (word6[0] == wordle[2] && wordle[2] == 'V') || (word6[0] == wordle[3] && wordle[3] == 'V') || (word6[0] == wordle[4] && wordle[4] == 'V') || (word6[1] == wordle[0] && wordle[0] == 'V') || (word6[1] == wordle[2] && wordle[2] == 'V') || (word6[1] == wordle[3] && wordle[3] == 'V') || (word6[1] == wordle[4] && wordle[4] == 'V') || (word6[2] == wordle[1] && wordle[1] == 'V') || (word6[2] == wordle[0] && wordle[0] == 'V') || (word6[2] == wordle[3] && wordle[3] == 'V') || (word6[2] == wordle[4] && wordle[4] == 'V') || (word6[3] == wordle[1] && wordle[1] == 'V') || (word6[3] == wordle[0] && wordle[0] == 'V') || (word6[3] == wordle[2] && wordle[2] == 'V') || (word6[3] == wordle[4] && wordle[4] == 'V') || (word6[4] == wordle[1] && wordle[1] == 'V') || (word6[4] == wordle[0] && wordle[0] == 'V') || (word6[4] == wordle[3] && wordle[3] == 'V') || (word6[4] == wordle[2] && wordle[2] == 'V'))
  {
    c2();
    cout << " V ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'V') || (word1[0] != wordle[2] && word1[0] == 'V') || (word1[0] != wordle[3] && word1[0] == 'V') || (word1[0] != wordle[4] && word1[0] == 'V') || (word1[1] != wordle[0] && word1[1] == 'V') || (word1[1] != wordle[2] && word1[1] == 'V') || (word1[1] != wordle[3] && word1[1] == 'V') || (word1[1] != wordle[4] && word1[1] == 'V') || (word1[2] != wordle[1] && word1[2] == 'V') || (word1[2] != wordle[0] && word1[2] == 'V') || (word1[2] != wordle[3] && word1[2] == 'V') || (word1[2] != wordle[4] && word1[2] == 'V') || (word1[3] != wordle[1] && word1[3] == 'V') || (word1[3] != wordle[2] && word1[3] == 'V') || (word1[3] != wordle[0] && word1[3] == 'V') || (word1[3] != wordle[4] && word1[3] == 'V') || (word1[4] != wordle[1] && word1[4] == 'V') || (word1[4] != wordle[2] && word1[4] == 'V') || (word1[4] != wordle[3] && word1[4] == 'V') || (word1[4] != wordle[0] && word1[4] == 'V') || (word2[0] != wordle[1] && word2[0] == 'V') || (word2[0] != wordle[2] && word2[0] == 'V') || (word2[0] != wordle[3] && word2[0] == 'V') || (word2[0] != wordle[4] && word2[0] == 'V') || (word2[1] != wordle[0] && word2[1] == 'V') || (word2[1] != wordle[2] && word2[1] == 'V') || (word2[1] != wordle[3] && word2[1] == 'V') || (word2[1] != wordle[4] && word2[1] == 'V') || (word2[2] != wordle[1] && word2[2] == 'V') || (word2[2] != wordle[0] && word2[2] == 'V') || (word2[2] != wordle[3] && word2[2] == 'V') || (word2[2] != wordle[4] && word2[2] == 'V') || (word2[3] != wordle[1] && word2[3] == 'V') || (word2[3] != wordle[2] && word2[3] == 'V') || (word2[3] != wordle[0] && word2[3] == 'V') || (word2[3] != wordle[4] && word2[3] == 'V') || (word2[4] != wordle[1] && word2[4] == 'V') || (word2[4] != wordle[2] && word2[4] == 'V') || (word2[4] != wordle[3] && word2[4] == 'V') || (word2[4] != wordle[0] && word2[4] == 'V') || (word3[0] != wordle[1] && word3[0] == 'V') || (word3[0] != wordle[2] && word3[0] == 'V') || (word3[0] != wordle[3] && word3[0] == 'V') || (word3[0] != wordle[4] && word3[0] == 'V') || (word3[1] != wordle[0] && word3[1] == 'V') || (word3[1] != wordle[2] && word3[1] == 'V') || (word3[1] != wordle[3] && word3[1] == 'V') || (word3[1] != wordle[4] && word3[1] == 'V') || (word3[2] != wordle[1] && word3[2] == 'V') || (word3[2] != wordle[0] && word3[2] == 'V') || (word3[2] != wordle[3] && word3[2] == 'V') || (word3[2] != wordle[4] && word3[2] == 'V') || (word3[3] != wordle[1] && word3[3] == 'V') || (word3[3] != wordle[2] && word3[3] == 'V') || (word3[3] != wordle[0] && word3[3] == 'V') || (word3[3] != wordle[4] && word3[3] == 'V') || (word3[4] != wordle[1] && word3[4] == 'V') || (word3[4] != wordle[2] && word3[4] == 'V') || (word3[4] != wordle[3] && word3[4] == 'V') || (word3[4] != wordle[0] && word3[4] == 'V') || (word4[0] != wordle[1] && word4[0] == 'V') || (word4[0] != wordle[2] && word4[0] == 'V') || (word4[0] != wordle[3] && word4[0] == 'V') || (word4[0] != wordle[4] && word4[0] == 'V') || (word4[1] != wordle[0] && word4[1] == 'V') || (word4[1] != wordle[2] && word4[1] == 'V') || (word4[1] != wordle[3] && word4[1] == 'V') || (word4[1] != wordle[4] && word4[1] == 'V') || (word4[2] != wordle[1] && word4[2] == 'V') || (word4[2] != wordle[0] && word4[2] == 'V') || (word4[2] != wordle[3] && word4[2] == 'V') || (word4[2] != wordle[4] && word4[2] == 'V') || (word4[3] != wordle[1] && word4[3] == 'V') || (word4[3] != wordle[2] && word4[3] == 'V') || (word4[3] != wordle[0] && word4[3] == 'V') || (word4[3] != wordle[4] && word4[3] == 'V') || (word4[4] != wordle[1] && word4[4] == 'V') || (word4[4] != wordle[2] && word4[4] == 'V') || (word4[4] != wordle[3] && word4[4] == 'V') || (word4[4] != wordle[0] && word4[4] == 'V') || (word5[0] != wordle[1] && word5[0] == 'V') || (word5[0] != wordle[2] && word5[0] == 'V') || (word5[0] != wordle[3] && word5[0] == 'V') || (word5[0] != wordle[4] && word5[0] == 'V') || (word5[1] != wordle[0] && word5[1] == 'V') || (word5[1] != wordle[2] && word5[1] == 'V') || (word5[1] != wordle[3] && word5[1] == 'V') || (word5[1] != wordle[4] && word5[1] == 'V') || (word5[2] != wordle[1] && word5[2] == 'V') || (word5[2] != wordle[0] && word5[2] == 'V') || (word5[2] != wordle[3] && word5[2] == 'V') || (word5[2] != wordle[4] && word5[2] == 'V') || (word5[3] != wordle[1] && word5[3] == 'V') || (word5[3] != wordle[2] && word5[3] == 'V') || (word5[3] != wordle[0] && word5[3] == 'V') || (word5[3] != wordle[4] && word5[3] == 'V') || (word5[4] != wordle[1] && word5[4] == 'V') || (word5[4] != wordle[2] && word5[4] == 'V') || (word5[4] != wordle[3] && word5[4] == 'V') || (word5[4] != wordle[0] && word5[4] == 'V') || (word6[0] != wordle[1] && word6[0] == 'V') || (word6[0] != wordle[2] && word6[0] == 'V') || (word6[0] != wordle[3] && word6[0] == 'V') || (word6[0] != wordle[4] && word6[0] == 'V') || (word6[1] != wordle[0] && word6[1] == 'V') || (word6[1] != wordle[2] && word6[1] == 'V') || (word6[1] != wordle[3] && word6[1] == 'V') || (word6[1] != wordle[4] && word6[1] == 'V') || (word6[2] != wordle[1] && word6[2] == 'V') || (word6[2] != wordle[0] && word6[2] == 'V') || (word6[2] != wordle[3] && word6[2] == 'V') || (word6[2] != wordle[4] && word6[2] == 'V') || (word6[3] != wordle[1] && word6[3] == 'V') || (word6[3] != wordle[2] && word6[3] == 'V') || (word6[3] != wordle[0] && word6[3] == 'V') || (word6[3] != wordle[4] && word6[3] == 'V') || (word6[4] != wordle[1] && word6[4] == 'V') || (word6[4] != wordle[2] && word6[4] == 'V') || (word6[4] != wordle[3] && word6[4] == 'V') || (word6[4] != wordle[0] && word6[4] == 'V'))
  {
    c3();
    cout << " V ";
    cout << RESET;
  }
  else 
  {
    cout << " V ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'B') || (word1[1] == wordle[1] && word1[1] == 'B') || (word1[2] == wordle[2] && word1[2] == 'B') || (word1[3] == wordle[3] && word1[3] == 'B') || (word1[4] == wordle[4] && word1[4] == 'B') || (word2[0] == wordle[0] && word2[0] == 'B') || (word2[1] == wordle[1] && word2[1] == 'B') || (word2[2] == wordle[2] && word2[2] == 'B') || (word2[3] == wordle[3] && word2[3] == 'B') || (word2[4] == wordle[4] && word2[4] == 'B') || (word3[0] == wordle[0] && word3[0] == 'B') || (word3[1] == wordle[1] && word3[1] == 'B') || (word3[2] == wordle[2] && word3[2] == 'B') || (word3[3] == wordle[3] && word3[3] == 'B') || (word3[4] == wordle[4] && word3[4] == 'B') || (word4[0] == wordle[0] && word4[0] == 'B') || (word4[1] == wordle[1] && word4[1] == 'B') || (word4[2] == wordle[2] && word4[2] == 'B') || (word4[3] == wordle[3] && word4[3] == 'B') || (word4[4] == wordle[4] && word4[4] == 'B') || (word5[0] == wordle[0] && word5[0] == 'B') || (word5[1] == wordle[1] && word5[1] == 'B') || (word5[2] == wordle[2] && word5[2] == 'B') || (word5[3] == wordle[3] && word5[3] == 'B') || (word5[4] == wordle[4] && word5[4] == 'B') || (word6[0] == wordle[0] && word6[0] == 'B') || (word6[1] == wordle[1] && word6[1] == 'B') || (word6[2] == wordle[2] && word6[2] == 'B') || (word6[3] == wordle[3] && word6[3] == 'B') || (word6[4] == wordle[4] && word6[4] == 'B'))
  {
    c1();
    cout << " B ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'B') || (word1[0] == wordle[2] && wordle[2] == 'B') || (word1[0] == wordle[3] && wordle[3] == 'B') || (word1[0] == wordle[4] && wordle[4] == 'B') || (word1[1] == wordle[0] && wordle[0] == 'B') || (word1[1] == wordle[2] && wordle[2] == 'B') || (word1[1] == wordle[3] && wordle[3] == 'B') || (word1[1] == wordle[4] && wordle[4] == 'B') || (word1[2] == wordle[1] && wordle[1] == 'B') || (word1[2] == wordle[0] && wordle[0] == 'B') || (word1[2] == wordle[3] && wordle[3] == 'B') || (word1[2] == wordle[4] && wordle[4] == 'B') || (word1[3] == wordle[1] && wordle[1] == 'B') || (word1[3] == wordle[0] && wordle[0] == 'B') || (word1[3] == wordle[2] && wordle[2] == 'B') || (word1[3] == wordle[4] && wordle[4] == 'B') || (word1[4] == wordle[1] && wordle[1] == 'B') || (word1[4] == wordle[0] && wordle[0] == 'B') || (word1[4] == wordle[3] && wordle[3] == 'B') || (word1[4] == wordle[2] && wordle[2] == 'B') || (word2[0] == wordle[1] && wordle[1] == 'B') || (word2[0] == wordle[2] && wordle[2] == 'B') || (word2[0] == wordle[3] && wordle[3] == 'B') || (word2[0] == wordle[4] && wordle[4] == 'B') || (word2[1] == wordle[0] && wordle[0] == 'B') || (word2[1] == wordle[2] && wordle[2] == 'B') || (word2[1] == wordle[3] && wordle[3] == 'B') || (word2[1] == wordle[4] && wordle[4] == 'B') || (word2[2] == wordle[1] && wordle[1] == 'B') || (word2[2] == wordle[0] && wordle[0] == 'B') || (word2[2] == wordle[3] && wordle[3] == 'B') || (word2[2] == wordle[4] && wordle[4] == 'B') || (word2[3] == wordle[1] && wordle[1] == 'B') || (word2[3] == wordle[0] && wordle[0] == 'B') || (word2[3] == wordle[2] && wordle[2] == 'B') || (word2[3] == wordle[4] && wordle[4] == 'B') || (word2[4] == wordle[1] && wordle[1] == 'B') || (word2[4] == wordle[0] && wordle[0] == 'B') || (word2[4] == wordle[3] && wordle[3] == 'B') || (word2[4] == wordle[2] && wordle[2] == 'B') || (word3[0] == wordle[1] && wordle[1] == 'B') || (word3[0] == wordle[2] && wordle[2] == 'B') || (word3[0] == wordle[3] && wordle[3] == 'B') || (word3[0] == wordle[4] && wordle[4] == 'B') || (word3[1] == wordle[0] && wordle[0] == 'B') || (word3[1] == wordle[2] && wordle[2] == 'B') || (word3[1] == wordle[3] && wordle[3] == 'B') || (word3[1] == wordle[4] && wordle[4] == 'B') || (word3[2] == wordle[1] && wordle[1] == 'B') || (word3[2] == wordle[0] && wordle[0] == 'B') || (word3[2] == wordle[3] && wordle[3] == 'B') || (word3[2] == wordle[4] && wordle[4] == 'B') || (word3[3] == wordle[1] && wordle[1] == 'B') || (word3[3] == wordle[0] && wordle[0] == 'B') || (word3[3] == wordle[2] && wordle[2] == 'B') || (word3[3] == wordle[4] && wordle[4] == 'B') || (word3[4] == wordle[1] && wordle[1] == 'B') || (word3[4] == wordle[0] && wordle[0] == 'B') || (word3[4] == wordle[3] && wordle[3] == 'B') || (word3[4] == wordle[2] && wordle[2] == 'B') || (word4[0] == wordle[1] && wordle[1] == 'B') || (word4[0] == wordle[2] && wordle[2] == 'B') || (word4[0] == wordle[3] && wordle[3] == 'B') || (word4[0] == wordle[4] && wordle[4] == 'B') || (word4[1] == wordle[0] && wordle[0] == 'B') || (word4[1] == wordle[2] && wordle[2] == 'B') || (word4[1] == wordle[3] && wordle[3] == 'B') || (word4[1] == wordle[4] && wordle[4] == 'B') || (word4[2] == wordle[1] && wordle[1] == 'B') || (word4[2] == wordle[0] && wordle[0] == 'B') || (word4[2] == wordle[3] && wordle[3] == 'B') || (word4[2] == wordle[4] && wordle[4] == 'B') || (word4[3] == wordle[1] && wordle[1] == 'B') || (word4[3] == wordle[0] && wordle[0] == 'B') || (word4[3] == wordle[2] && wordle[2] == 'B') || (word4[3] == wordle[4] && wordle[4] == 'B') || (word4[4] == wordle[1] && wordle[1] == 'B') || (word4[4] == wordle[0] && wordle[0] == 'B') || (word4[4] == wordle[3] && wordle[3] == 'B') || (word4[4] == wordle[2] && wordle[2] == 'B') || (word5[0] == wordle[1] && wordle[1] == 'B') || (word5[0] == wordle[2] && wordle[2] == 'B') || (word5[0] == wordle[3] && wordle[3] == 'B') || (word5[0] == wordle[4] && wordle[4] == 'B') || (word5[1] == wordle[0] && wordle[0] == 'B') || (word5[1] == wordle[2] && wordle[2] == 'B') || (word5[1] == wordle[3] && wordle[3] == 'B') || (word5[1] == wordle[4] && wordle[4] == 'B') || (word5[2] == wordle[1] && wordle[1] == 'B') || (word5[2] == wordle[0] && wordle[0] == 'B') || (word5[2] == wordle[3] && wordle[3] == 'B') || (word5[2] == wordle[4] && wordle[4] == 'B') || (word5[3] == wordle[1] && wordle[1] == 'B') || (word5[3] == wordle[0] && wordle[0] == 'B') || (word5[3] == wordle[2] && wordle[2] == 'B') || (word5[3] == wordle[4] && wordle[4] == 'B') || (word5[4] == wordle[1] && wordle[1] == 'B') || (word5[4] == wordle[0] && wordle[0] == 'B') || (word5[4] == wordle[3] && wordle[3] == 'B') || (word5[4] == wordle[2] && wordle[2] == 'B') || (word6[0] == wordle[1] && wordle[1] == 'B') || (word6[0] == wordle[2] && wordle[2] == 'B') || (word6[0] == wordle[3] && wordle[3] == 'B') || (word6[0] == wordle[4] && wordle[4] == 'B') || (word6[1] == wordle[0] && wordle[0] == 'B') || (word6[1] == wordle[2] && wordle[2] == 'B') || (word6[1] == wordle[3] && wordle[3] == 'B') || (word6[1] == wordle[4] && wordle[4] == 'B') || (word6[2] == wordle[1] && wordle[1] == 'B') || (word6[2] == wordle[0] && wordle[0] == 'B') || (word6[2] == wordle[3] && wordle[3] == 'B') || (word6[2] == wordle[4] && wordle[4] == 'B') || (word6[3] == wordle[1] && wordle[1] == 'B') || (word6[3] == wordle[0] && wordle[0] == 'B') || (word6[3] == wordle[2] && wordle[2] == 'B') || (word6[3] == wordle[4] && wordle[4] == 'B') || (word6[4] == wordle[1] && wordle[1] == 'B') || (word6[4] == wordle[0] && wordle[0] == 'B') || (word6[4] == wordle[3] && wordle[3] == 'B') || (word6[4] == wordle[2] && wordle[2] == 'B'))
  {
    c2();
    cout << " B ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'B') || (word1[0] != wordle[2] && word1[0] == 'B') || (word1[0] != wordle[3] && word1[0] == 'B') || (word1[0] != wordle[4] && word1[0] == 'B') || (word1[1] != wordle[0] && word1[1] == 'B') || (word1[1] != wordle[2] && word1[1] == 'B') || (word1[1] != wordle[3] && word1[1] == 'B') || (word1[1] != wordle[4] && word1[1] == 'B') || (word1[2] != wordle[1] && word1[2] == 'B') || (word1[2] != wordle[0] && word1[2] == 'B') || (word1[2] != wordle[3] && word1[2] == 'B') || (word1[2] != wordle[4] && word1[2] == 'B') || (word1[3] != wordle[1] && word1[3] == 'B') || (word1[3] != wordle[2] && word1[3] == 'B') || (word1[3] != wordle[0] && word1[3] == 'B') || (word1[3] != wordle[4] && word1[3] == 'B') || (word1[4] != wordle[1] && word1[4] == 'B') || (word1[4] != wordle[2] && word1[4] == 'B') || (word1[4] != wordle[3] && word1[4] == 'B') || (word1[4] != wordle[0] && word1[4] == 'B') || (word2[0] != wordle[1] && word2[0] == 'B') || (word2[0] != wordle[2] && word2[0] == 'B') || (word2[0] != wordle[3] && word2[0] == 'B') || (word2[0] != wordle[4] && word2[0] == 'B') || (word2[1] != wordle[0] && word2[1] == 'B') || (word2[1] != wordle[2] && word2[1] == 'B') || (word2[1] != wordle[3] && word2[1] == 'B') || (word2[1] != wordle[4] && word2[1] == 'B') || (word2[2] != wordle[1] && word2[2] == 'B') || (word2[2] != wordle[0] && word2[2] == 'B') || (word2[2] != wordle[3] && word2[2] == 'B') || (word2[2] != wordle[4] && word2[2] == 'B') || (word2[3] != wordle[1] && word2[3] == 'B') || (word2[3] != wordle[2] && word2[3] == 'B') || (word2[3] != wordle[0] && word2[3] == 'B') || (word2[3] != wordle[4] && word2[3] == 'B') || (word2[4] != wordle[1] && word2[4] == 'B') || (word2[4] != wordle[2] && word2[4] == 'B') || (word2[4] != wordle[3] && word2[4] == 'B') || (word2[4] != wordle[0] && word2[4] == 'B') || (word3[0] != wordle[1] && word3[0] == 'B') || (word3[0] != wordle[2] && word3[0] == 'B') || (word3[0] != wordle[3] && word3[0] == 'B') || (word3[0] != wordle[4] && word3[0] == 'B') || (word3[1] != wordle[0] && word3[1] == 'B') || (word3[1] != wordle[2] && word3[1] == 'B') || (word3[1] != wordle[3] && word3[1] == 'B') || (word3[1] != wordle[4] && word3[1] == 'B') || (word3[2] != wordle[1] && word3[2] == 'B') || (word3[2] != wordle[0] && word3[2] == 'B') || (word3[2] != wordle[3] && word3[2] == 'B') || (word3[2] != wordle[4] && word3[2] == 'B') || (word3[3] != wordle[1] && word3[3] == 'B') || (word3[3] != wordle[2] && word3[3] == 'B') || (word3[3] != wordle[0] && word3[3] == 'B') || (word3[3] != wordle[4] && word3[3] == 'B') || (word3[4] != wordle[1] && word3[4] == 'B') || (word3[4] != wordle[2] && word3[4] == 'B') || (word3[4] != wordle[3] && word3[4] == 'B') || (word3[4] != wordle[0] && word3[4] == 'B') || (word4[0] != wordle[1] && word4[0] == 'B') || (word4[0] != wordle[2] && word4[0] == 'B') || (word4[0] != wordle[3] && word4[0] == 'B') || (word4[0] != wordle[4] && word4[0] == 'B') || (word4[1] != wordle[0] && word4[1] == 'B') || (word4[1] != wordle[2] && word4[1] == 'B') || (word4[1] != wordle[3] && word4[1] == 'B') || (word4[1] != wordle[4] && word4[1] == 'B') || (word4[2] != wordle[1] && word4[2] == 'B') || (word4[2] != wordle[0] && word4[2] == 'B') || (word4[2] != wordle[3] && word4[2] == 'B') || (word4[2] != wordle[4] && word4[2] == 'B') || (word4[3] != wordle[1] && word4[3] == 'B') || (word4[3] != wordle[2] && word4[3] == 'B') || (word4[3] != wordle[0] && word4[3] == 'B') || (word4[3] != wordle[4] && word4[3] == 'B') || (word4[4] != wordle[1] && word4[4] == 'B') || (word4[4] != wordle[2] && word4[4] == 'B') || (word4[4] != wordle[3] && word4[4] == 'B') || (word4[4] != wordle[0] && word4[4] == 'B') || (word5[0] != wordle[1] && word5[0] == 'B') || (word5[0] != wordle[2] && word5[0] == 'B') || (word5[0] != wordle[3] && word5[0] == 'B') || (word5[0] != wordle[4] && word5[0] == 'B') || (word5[1] != wordle[0] && word5[1] == 'B') || (word5[1] != wordle[2] && word5[1] == 'B') || (word5[1] != wordle[3] && word5[1] == 'B') || (word5[1] != wordle[4] && word5[1] == 'B') || (word5[2] != wordle[1] && word5[2] == 'B') || (word5[2] != wordle[0] && word5[2] == 'B') || (word5[2] != wordle[3] && word5[2] == 'B') || (word5[2] != wordle[4] && word5[2] == 'B') || (word5[3] != wordle[1] && word5[3] == 'B') || (word5[3] != wordle[2] && word5[3] == 'B') || (word5[3] != wordle[0] && word5[3] == 'B') || (word5[3] != wordle[4] && word5[3] == 'B') || (word5[4] != wordle[1] && word5[4] == 'B') || (word5[4] != wordle[2] && word5[4] == 'B') || (word5[4] != wordle[3] && word5[4] == 'B') || (word5[4] != wordle[0] && word5[4] == 'B') || (word6[0] != wordle[1] && word6[0] == 'B') || (word6[0] != wordle[2] && word6[0] == 'B') || (word6[0] != wordle[3] && word6[0] == 'B') || (word6[0] != wordle[4] && word6[0] == 'B') || (word6[1] != wordle[0] && word6[1] == 'B') || (word6[1] != wordle[2] && word6[1] == 'B') || (word6[1] != wordle[3] && word6[1] == 'B') || (word6[1] != wordle[4] && word6[1] == 'B') || (word6[2] != wordle[1] && word6[2] == 'B') || (word6[2] != wordle[0] && word6[2] == 'B') || (word6[2] != wordle[3] && word6[2] == 'B') || (word6[2] != wordle[4] && word6[2] == 'B') || (word6[3] != wordle[1] && word6[3] == 'B') || (word6[3] != wordle[2] && word6[3] == 'B') || (word6[3] != wordle[0] && word6[3] == 'B') || (word6[3] != wordle[4] && word6[3] == 'B') || (word6[4] != wordle[1] && word6[4] == 'B') || (word6[4] != wordle[2] && word6[4] == 'B') || (word6[4] != wordle[3] && word6[4] == 'B') || (word6[4] != wordle[0] && word6[4] == 'B'))
  {
    c3();
    cout << " B ";
    cout << RESET;
  }
  else 
  {
    cout << " B ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'N') || (word1[1] == wordle[1] && word1[1] == 'N') || (word1[2] == wordle[2] && word1[2] == 'N') || (word1[3] == wordle[3] && word1[3] == 'N') || (word1[4] == wordle[4] && word1[4] == 'N') || (word2[0] == wordle[0] && word2[0] == 'N') || (word2[1] == wordle[1] && word2[1] == 'N') || (word2[2] == wordle[2] && word2[2] == 'N') || (word2[3] == wordle[3] && word2[3] == 'N') || (word2[4] == wordle[4] && word2[4] == 'N') || (word3[0] == wordle[0] && word3[0] == 'N') || (word3[1] == wordle[1] && word3[1] == 'N') || (word3[2] == wordle[2] && word3[2] == 'N') || (word3[3] == wordle[3] && word3[3] == 'N') || (word3[4] == wordle[4] && word3[4] == 'N') || (word4[0] == wordle[0] && word4[0] == 'N') || (word4[1] == wordle[1] && word4[1] == 'N') || (word4[2] == wordle[2] && word4[2] == 'N') || (word4[3] == wordle[3] && word4[3] == 'N') || (word4[4] == wordle[4] && word4[4] == 'N') || (word5[0] == wordle[0] && word5[0] == 'N') || (word5[1] == wordle[1] && word5[1] == 'N') || (word5[2] == wordle[2] && word5[2] == 'N') || (word5[3] == wordle[3] && word5[3] == 'N') || (word5[4] == wordle[4] && word5[4] == 'N') || (word6[0] == wordle[0] && word6[0] == 'N') || (word6[1] == wordle[1] && word6[1] == 'N') || (word6[2] == wordle[2] && word6[2] == 'N') || (word6[3] == wordle[3] && word6[3] == 'N') || (word6[4] == wordle[4] && word6[4] == 'N'))
  {
    c1();
    cout << " N ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'N') || (word1[0] == wordle[2] && wordle[2] == 'N') || (word1[0] == wordle[3] && wordle[3] == 'N') || (word1[0] == wordle[4] && wordle[4] == 'N') || (word1[1] == wordle[0] && wordle[0] == 'N') || (word1[1] == wordle[2] && wordle[2] == 'N') || (word1[1] == wordle[3] && wordle[3] == 'N') || (word1[1] == wordle[4] && wordle[4] == 'N') || (word1[2] == wordle[1] && wordle[1] == 'N') || (word1[2] == wordle[0] && wordle[0] == 'N') || (word1[2] == wordle[3] && wordle[3] == 'N') || (word1[2] == wordle[4] && wordle[4] == 'N') || (word1[3] == wordle[1] && wordle[1] == 'N') || (word1[3] == wordle[0] && wordle[0] == 'N') || (word1[3] == wordle[2] && wordle[2] == 'N') || (word1[3] == wordle[4] && wordle[4] == 'N') || (word1[4] == wordle[1] && wordle[1] == 'N') || (word1[4] == wordle[0] && wordle[0] == 'N') || (word1[4] == wordle[3] && wordle[3] == 'N') || (word1[4] == wordle[2] && wordle[2] == 'N') || (word2[0] == wordle[1] && wordle[1] == 'N') || (word2[0] == wordle[2] && wordle[2] == 'N') || (word2[0] == wordle[3] && wordle[3] == 'N') || (word2[0] == wordle[4] && wordle[4] == 'N') || (word2[1] == wordle[0] && wordle[0] == 'N') || (word2[1] == wordle[2] && wordle[2] == 'N') || (word2[1] == wordle[3] && wordle[3] == 'N') || (word2[1] == wordle[4] && wordle[4] == 'N') || (word2[2] == wordle[1] && wordle[1] == 'N') || (word2[2] == wordle[0] && wordle[0] == 'N') || (word2[2] == wordle[3] && wordle[3] == 'N') || (word2[2] == wordle[4] && wordle[4] == 'N') || (word2[3] == wordle[1] && wordle[1] == 'N') || (word2[3] == wordle[0] && wordle[0] == 'N') || (word2[3] == wordle[2] && wordle[2] == 'N') || (word2[3] == wordle[4] && wordle[4] == 'N') || (word2[4] == wordle[1] && wordle[1] == 'N') || (word2[4] == wordle[0] && wordle[0] == 'N') || (word2[4] == wordle[3] && wordle[3] == 'N') || (word2[4] == wordle[2] && wordle[2] == 'N') || (word3[0] == wordle[1] && wordle[1] == 'N') || (word3[0] == wordle[2] && wordle[2] == 'N') || (word3[0] == wordle[3] && wordle[3] == 'N') || (word3[0] == wordle[4] && wordle[4] == 'N') || (word3[1] == wordle[0] && wordle[0] == 'N') || (word3[1] == wordle[2] && wordle[2] == 'N') || (word3[1] == wordle[3] && wordle[3] == 'N') || (word3[1] == wordle[4] && wordle[4] == 'N') || (word3[2] == wordle[1] && wordle[1] == 'N') || (word3[2] == wordle[0] && wordle[0] == 'N') || (word3[2] == wordle[3] && wordle[3] == 'N') || (word3[2] == wordle[4] && wordle[4] == 'N') || (word3[3] == wordle[1] && wordle[1] == 'N') || (word3[3] == wordle[0] && wordle[0] == 'N') || (word3[3] == wordle[2] && wordle[2] == 'N') || (word3[3] == wordle[4] && wordle[4] == 'N') || (word3[4] == wordle[1] && wordle[1] == 'N') || (word3[4] == wordle[0] && wordle[0] == 'N') || (word3[4] == wordle[3] && wordle[3] == 'N') || (word3[4] == wordle[2] && wordle[2] == 'N') || (word4[0] == wordle[1] && wordle[1] == 'N') || (word4[0] == wordle[2] && wordle[2] == 'N') || (word4[0] == wordle[3] && wordle[3] == 'N') || (word4[0] == wordle[4] && wordle[4] == 'N') || (word4[1] == wordle[0] && wordle[0] == 'N') || (word4[1] == wordle[2] && wordle[2] == 'N') || (word4[1] == wordle[3] && wordle[3] == 'N') || (word4[1] == wordle[4] && wordle[4] == 'N') || (word4[2] == wordle[1] && wordle[1] == 'N') || (word4[2] == wordle[0] && wordle[0] == 'N') || (word4[2] == wordle[3] && wordle[3] == 'N') || (word4[2] == wordle[4] && wordle[4] == 'N') || (word4[3] == wordle[1] && wordle[1] == 'N') || (word4[3] == wordle[0] && wordle[0] == 'N') || (word4[3] == wordle[2] && wordle[2] == 'N') || (word4[3] == wordle[4] && wordle[4] == 'N') || (word4[4] == wordle[1] && wordle[1] == 'N') || (word4[4] == wordle[0] && wordle[0] == 'N') || (word4[4] == wordle[3] && wordle[3] == 'N') || (word4[4] == wordle[2] && wordle[2] == 'N') || (word5[0] == wordle[1] && wordle[1] == 'N') || (word5[0] == wordle[2] && wordle[2] == 'N') || (word5[0] == wordle[3] && wordle[3] == 'N') || (word5[0] == wordle[4] && wordle[4] == 'N') || (word5[1] == wordle[0] && wordle[0] == 'N') || (word5[1] == wordle[2] && wordle[2] == 'N') || (word5[1] == wordle[3] && wordle[3] == 'N') || (word5[1] == wordle[4] && wordle[4] == 'N') || (word5[2] == wordle[1] && wordle[1] == 'N') || (word5[2] == wordle[0] && wordle[0] == 'N') || (word5[2] == wordle[3] && wordle[3] == 'N') || (word5[2] == wordle[4] && wordle[4] == 'N') || (word5[3] == wordle[1] && wordle[1] == 'N') || (word5[3] == wordle[0] && wordle[0] == 'N') || (word5[3] == wordle[2] && wordle[2] == 'N') || (word5[3] == wordle[4] && wordle[4] == 'N') || (word5[4] == wordle[1] && wordle[1] == 'N') || (word5[4] == wordle[0] && wordle[0] == 'N') || (word5[4] == wordle[3] && wordle[3] == 'N') || (word5[4] == wordle[2] && wordle[2] == 'N') || (word6[0] == wordle[1] && wordle[1] == 'N') || (word6[0] == wordle[2] && wordle[2] == 'N') || (word6[0] == wordle[3] && wordle[3] == 'N') || (word6[0] == wordle[4] && wordle[4] == 'N') || (word6[1] == wordle[0] && wordle[0] == 'N') || (word6[1] == wordle[2] && wordle[2] == 'N') || (word6[1] == wordle[3] && wordle[3] == 'N') || (word6[1] == wordle[4] && wordle[4] == 'N') || (word6[2] == wordle[1] && wordle[1] == 'N') || (word6[2] == wordle[0] && wordle[0] == 'N') || (word6[2] == wordle[3] && wordle[3] == 'N') || (word6[2] == wordle[4] && wordle[4] == 'N') || (word6[3] == wordle[1] && wordle[1] == 'N') || (word6[3] == wordle[0] && wordle[0] == 'N') || (word6[3] == wordle[2] && wordle[2] == 'N') || (word6[3] == wordle[4] && wordle[4] == 'N') || (word6[4] == wordle[1] && wordle[1] == 'N') || (word6[4] == wordle[0] && wordle[0] == 'N') || (word6[4] == wordle[3] && wordle[3] == 'N') || (word6[4] == wordle[2] && wordle[2] == 'N'))
  {
    c2();
    cout << " N ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'N') || (word1[0] != wordle[2] && word1[0] == 'N') || (word1[0] != wordle[3] && word1[0] == 'N') || (word1[0] != wordle[4] && word1[0] == 'N') || (word1[1] != wordle[0] && word1[1] == 'N') || (word1[1] != wordle[2] && word1[1] == 'N') || (word1[1] != wordle[3] && word1[1] == 'N') || (word1[1] != wordle[4] && word1[1] == 'N') || (word1[2] != wordle[1] && word1[2] == 'N') || (word1[2] != wordle[0] && word1[2] == 'N') || (word1[2] != wordle[3] && word1[2] == 'N') || (word1[2] != wordle[4] && word1[2] == 'N') || (word1[3] != wordle[1] && word1[3] == 'N') || (word1[3] != wordle[2] && word1[3] == 'N') || (word1[3] != wordle[0] && word1[3] == 'N') || (word1[3] != wordle[4] && word1[3] == 'N') || (word1[4] != wordle[1] && word1[4] == 'N') || (word1[4] != wordle[2] && word1[4] == 'N') || (word1[4] != wordle[3] && word1[4] == 'N') || (word1[4] != wordle[0] && word1[4] == 'N') || (word2[0] != wordle[1] && word2[0] == 'N') || (word2[0] != wordle[2] && word2[0] == 'N') || (word2[0] != wordle[3] && word2[0] == 'N') || (word2[0] != wordle[4] && word2[0] == 'N') || (word2[1] != wordle[0] && word2[1] == 'N') || (word2[1] != wordle[2] && word2[1] == 'N') || (word2[1] != wordle[3] && word2[1] == 'N') || (word2[1] != wordle[4] && word2[1] == 'N') || (word2[2] != wordle[1] && word2[2] == 'N') || (word2[2] != wordle[0] && word2[2] == 'N') || (word2[2] != wordle[3] && word2[2] == 'N') || (word2[2] != wordle[4] && word2[2] == 'N') || (word2[3] != wordle[1] && word2[3] == 'N') || (word2[3] != wordle[2] && word2[3] == 'N') || (word2[3] != wordle[0] && word2[3] == 'N') || (word2[3] != wordle[4] && word2[3] == 'N') || (word2[4] != wordle[1] && word2[4] == 'N') || (word2[4] != wordle[2] && word2[4] == 'N') || (word2[4] != wordle[3] && word2[4] == 'N') || (word2[4] != wordle[0] && word2[4] == 'N') || (word3[0] != wordle[1] && word3[0] == 'N') || (word3[0] != wordle[2] && word3[0] == 'N') || (word3[0] != wordle[3] && word3[0] == 'N') || (word3[0] != wordle[4] && word3[0] == 'N') || (word3[1] != wordle[0] && word3[1] == 'N') || (word3[1] != wordle[2] && word3[1] == 'N') || (word3[1] != wordle[3] && word3[1] == 'N') || (word3[1] != wordle[4] && word3[1] == 'N') || (word3[2] != wordle[1] && word3[2] == 'N') || (word3[2] != wordle[0] && word3[2] == 'N') || (word3[2] != wordle[3] && word3[2] == 'N') || (word3[2] != wordle[4] && word3[2] == 'N') || (word3[3] != wordle[1] && word3[3] == 'N') || (word3[3] != wordle[2] && word3[3] == 'N') || (word3[3] != wordle[0] && word3[3] == 'N') || (word3[3] != wordle[4] && word3[3] == 'N') || (word3[4] != wordle[1] && word3[4] == 'N') || (word3[4] != wordle[2] && word3[4] == 'N') || (word3[4] != wordle[3] && word3[4] == 'N') || (word3[4] != wordle[0] && word3[4] == 'N') || (word4[0] != wordle[1] && word4[0] == 'N') || (word4[0] != wordle[2] && word4[0] == 'N') || (word4[0] != wordle[3] && word4[0] == 'N') || (word4[0] != wordle[4] && word4[0] == 'N') || (word4[1] != wordle[0] && word4[1] == 'N') || (word4[1] != wordle[2] && word4[1] == 'N') || (word4[1] != wordle[3] && word4[1] == 'N') || (word4[1] != wordle[4] && word4[1] == 'N') || (word4[2] != wordle[1] && word4[2] == 'N') || (word4[2] != wordle[0] && word4[2] == 'N') || (word4[2] != wordle[3] && word4[2] == 'N') || (word4[2] != wordle[4] && word4[2] == 'N') || (word4[3] != wordle[1] && word4[3] == 'N') || (word4[3] != wordle[2] && word4[3] == 'N') || (word4[3] != wordle[0] && word4[3] == 'N') || (word4[3] != wordle[4] && word4[3] == 'N') || (word4[4] != wordle[1] && word4[4] == 'N') || (word4[4] != wordle[2] && word4[4] == 'N') || (word4[4] != wordle[3] && word4[4] == 'N') || (word4[4] != wordle[0] && word4[4] == 'N') || (word5[0] != wordle[1] && word5[0] == 'N') || (word5[0] != wordle[2] && word5[0] == 'N') || (word5[0] != wordle[3] && word5[0] == 'N') || (word5[0] != wordle[4] && word5[0] == 'N') || (word5[1] != wordle[0] && word5[1] == 'N') || (word5[1] != wordle[2] && word5[1] == 'N') || (word5[1] != wordle[3] && word5[1] == 'N') || (word5[1] != wordle[4] && word5[1] == 'N') || (word5[2] != wordle[1] && word5[2] == 'N') || (word5[2] != wordle[0] && word5[2] == 'N') || (word5[2] != wordle[3] && word5[2] == 'N') || (word5[2] != wordle[4] && word5[2] == 'N') || (word5[3] != wordle[1] && word5[3] == 'N') || (word5[3] != wordle[2] && word5[3] == 'N') || (word5[3] != wordle[0] && word5[3] == 'N') || (word5[3] != wordle[4] && word5[3] == 'N') || (word5[4] != wordle[1] && word5[4] == 'N') || (word5[4] != wordle[2] && word5[4] == 'N') || (word5[4] != wordle[3] && word5[4] == 'N') || (word5[4] != wordle[0] && word5[4] == 'N') || (word6[0] != wordle[1] && word6[0] == 'N') || (word6[0] != wordle[2] && word6[0] == 'N') || (word6[0] != wordle[3] && word6[0] == 'N') || (word6[0] != wordle[4] && word6[0] == 'N') || (word6[1] != wordle[0] && word6[1] == 'N') || (word6[1] != wordle[2] && word6[1] == 'N') || (word6[1] != wordle[3] && word6[1] == 'N') || (word6[1] != wordle[4] && word6[1] == 'N') || (word6[2] != wordle[1] && word6[2] == 'N') || (word6[2] != wordle[0] && word6[2] == 'N') || (word6[2] != wordle[3] && word6[2] == 'N') || (word6[2] != wordle[4] && word6[2] == 'N') || (word6[3] != wordle[1] && word6[3] == 'N') || (word6[3] != wordle[2] && word6[3] == 'N') || (word6[3] != wordle[0] && word6[3] == 'N') || (word6[3] != wordle[4] && word6[3] == 'N') || (word6[4] != wordle[1] && word6[4] == 'N') || (word6[4] != wordle[2] && word6[4] == 'N') || (word6[4] != wordle[3] && word6[4] == 'N') || (word6[4] != wordle[0] && word6[4] == 'N'))
  {
    c3();
    cout << " N ";
    cout << RESET;
  }
  else 
  {
    cout << " N ";
  }
  if ((word1[0] == wordle[0] && word1[0] == 'M') || (word1[1] == wordle[1] && word1[1] == 'M') || (word1[2] == wordle[2] && word1[2] == 'M') || (word1[3] == wordle[3] && word1[3] == 'M') || (word1[4] == wordle[4] && word1[4] == 'M') || (word2[0] == wordle[0] && word2[0] == 'M') || (word2[1] == wordle[1] && word2[1] == 'M') || (word2[2] == wordle[2] && word2[2] == 'M') || (word2[3] == wordle[3] && word2[3] == 'M') || (word2[4] == wordle[4] && word2[4] == 'M') || (word3[0] == wordle[0] && word3[0] == 'M') || (word3[1] == wordle[1] && word3[1] == 'M') || (word3[2] == wordle[2] && word3[2] == 'M') || (word3[3] == wordle[3] && word3[3] == 'M') || (word3[4] == wordle[4] && word3[4] == 'M') || (word4[0] == wordle[0] && word4[0] == 'M') || (word4[1] == wordle[1] && word4[1] == 'M') || (word4[2] == wordle[2] && word4[2] == 'M') || (word4[3] == wordle[3] && word4[3] == 'M') || (word4[4] == wordle[4] && word4[4] == 'M') || (word5[0] == wordle[0] && word5[0] == 'M') || (word5[1] == wordle[1] && word5[1] == 'M') || (word5[2] == wordle[2] && word5[2] == 'M') || (word5[3] == wordle[3] && word5[3] == 'M') || (word5[4] == wordle[4] && word5[4] == 'M') || (word6[0] == wordle[0] && word6[0] == 'M') || (word6[1] == wordle[1] && word6[1] == 'M') || (word6[2] == wordle[2] && word6[2] == 'M') || (word6[3] == wordle[3] && word6[3] == 'M') || (word6[4] == wordle[4] && word6[4] == 'M'))
  {
    c1();
    cout << " M ";
    cout << RESET;
  }
  else if ((word1[0] == wordle[1] && wordle[1] == 'M') || (word1[0] == wordle[2] && wordle[2] == 'M') || (word1[0] == wordle[3] && wordle[3] == 'M') || (word1[0] == wordle[4] && wordle[4] == 'M') || (word1[1] == wordle[0] && wordle[0] == 'M') || (word1[1] == wordle[2] && wordle[2] == 'M') || (word1[1] == wordle[3] && wordle[3] == 'M') || (word1[1] == wordle[4] && wordle[4] == 'M') || (word1[2] == wordle[1] && wordle[1] == 'M') || (word1[2] == wordle[0] && wordle[0] == 'M') || (word1[2] == wordle[3] && wordle[3] == 'M') || (word1[2] == wordle[4] && wordle[4] == 'M') || (word1[3] == wordle[1] && wordle[1] == 'M') || (word1[3] == wordle[0] && wordle[0] == 'M') || (word1[3] == wordle[2] && wordle[2] == 'M') || (word1[3] == wordle[4] && wordle[4] == 'M') || (word1[4] == wordle[1] && wordle[1] == 'M') || (word1[4] == wordle[0] && wordle[0] == 'M') || (word1[4] == wordle[3] && wordle[3] == 'M') || (word1[4] == wordle[2] && wordle[2] == 'M') || (word2[0] == wordle[1] && wordle[1] == 'M') || (word2[0] == wordle[2] && wordle[2] == 'M') || (word2[0] == wordle[3] && wordle[3] == 'M') || (word2[0] == wordle[4] && wordle[4] == 'M') || (word2[1] == wordle[0] && wordle[0] == 'M') || (word2[1] == wordle[2] && wordle[2] == 'M') || (word2[1] == wordle[3] && wordle[3] == 'M') || (word2[1] == wordle[4] && wordle[4] == 'M') || (word2[2] == wordle[1] && wordle[1] == 'M') || (word2[2] == wordle[0] && wordle[0] == 'M') || (word2[2] == wordle[3] && wordle[3] == 'M') || (word2[2] == wordle[4] && wordle[4] == 'M') || (word2[3] == wordle[1] && wordle[1] == 'M') || (word2[3] == wordle[0] && wordle[0] == 'M') || (word2[3] == wordle[2] && wordle[2] == 'M') || (word2[3] == wordle[4] && wordle[4] == 'M') || (word2[4] == wordle[1] && wordle[1] == 'M') || (word2[4] == wordle[0] && wordle[0] == 'M') || (word2[4] == wordle[3] && wordle[3] == 'M') || (word2[4] == wordle[2] && wordle[2] == 'M') || (word3[0] == wordle[1] && wordle[1] == 'M') || (word3[0] == wordle[2] && wordle[2] == 'M') || (word3[0] == wordle[3] && wordle[3] == 'M') || (word3[0] == wordle[4] && wordle[4] == 'M') || (word3[1] == wordle[0] && wordle[0] == 'M') || (word3[1] == wordle[2] && wordle[2] == 'M') || (word3[1] == wordle[3] && wordle[3] == 'M') || (word3[1] == wordle[4] && wordle[4] == 'M') || (word3[2] == wordle[1] && wordle[1] == 'M') || (word3[2] == wordle[0] && wordle[0] == 'M') || (word3[2] == wordle[3] && wordle[3] == 'M') || (word3[2] == wordle[4] && wordle[4] == 'M') || (word3[3] == wordle[1] && wordle[1] == 'M') || (word3[3] == wordle[0] && wordle[0] == 'M') || (word3[3] == wordle[2] && wordle[2] == 'M') || (word3[3] == wordle[4] && wordle[4] == 'M') || (word3[4] == wordle[1] && wordle[1] == 'M') || (word3[4] == wordle[0] && wordle[0] == 'M') || (word3[4] == wordle[3] && wordle[3] == 'M') || (word3[4] == wordle[2] && wordle[2] == 'M') || (word4[0] == wordle[1] && wordle[1] == 'M') || (word4[0] == wordle[2] && wordle[2] == 'M') || (word4[0] == wordle[3] && wordle[3] == 'M') || (word4[0] == wordle[4] && wordle[4] == 'M') || (word4[1] == wordle[0] && wordle[0] == 'M') || (word4[1] == wordle[2] && wordle[2] == 'M') || (word4[1] == wordle[3] && wordle[3] == 'M') || (word4[1] == wordle[4] && wordle[4] == 'M') || (word4[2] == wordle[1] && wordle[1] == 'M') || (word4[2] == wordle[0] && wordle[0] == 'M') || (word4[2] == wordle[3] && wordle[3] == 'M') || (word4[2] == wordle[4] && wordle[4] == 'M') || (word4[3] == wordle[1] && wordle[1] == 'M') || (word4[3] == wordle[0] && wordle[0] == 'M') || (word4[3] == wordle[2] && wordle[2] == 'M') || (word4[3] == wordle[4] && wordle[4] == 'M') || (word4[4] == wordle[1] && wordle[1] == 'M') || (word4[4] == wordle[0] && wordle[0] == 'M') || (word4[4] == wordle[3] && wordle[3] == 'M') || (word4[4] == wordle[2] && wordle[2] == 'M') || (word5[0] == wordle[1] && wordle[1] == 'M') || (word5[0] == wordle[2] && wordle[2] == 'M') || (word5[0] == wordle[3] && wordle[3] == 'M') || (word5[0] == wordle[4] && wordle[4] == 'M') || (word5[1] == wordle[0] && wordle[0] == 'M') || (word5[1] == wordle[2] && wordle[2] == 'M') || (word5[1] == wordle[3] && wordle[3] == 'M') || (word5[1] == wordle[4] && wordle[4] == 'M') || (word5[2] == wordle[1] && wordle[1] == 'M') || (word5[2] == wordle[0] && wordle[0] == 'M') || (word5[2] == wordle[3] && wordle[3] == 'M') || (word5[2] == wordle[4] && wordle[4] == 'M') || (word5[3] == wordle[1] && wordle[1] == 'M') || (word5[3] == wordle[0] && wordle[0] == 'M') || (word5[3] == wordle[2] && wordle[2] == 'M') || (word5[3] == wordle[4] && wordle[4] == 'M') || (word5[4] == wordle[1] && wordle[1] == 'M') || (word5[4] == wordle[0] && wordle[0] == 'M') || (word5[4] == wordle[3] && wordle[3] == 'M') || (word5[4] == wordle[2] && wordle[2] == 'M') || (word6[0] == wordle[1] && wordle[1] == 'M') || (word6[0] == wordle[2] && wordle[2] == 'M') || (word6[0] == wordle[3] && wordle[3] == 'M') || (word6[0] == wordle[4] && wordle[4] == 'M') || (word6[1] == wordle[0] && wordle[0] == 'M') || (word6[1] == wordle[2] && wordle[2] == 'M') || (word6[1] == wordle[3] && wordle[3] == 'M') || (word6[1] == wordle[4] && wordle[4] == 'M') || (word6[2] == wordle[1] && wordle[1] == 'M') || (word6[2] == wordle[0] && wordle[0] == 'M') || (word6[2] == wordle[3] && wordle[3] == 'M') || (word6[2] == wordle[4] && wordle[4] == 'M') || (word6[3] == wordle[1] && wordle[1] == 'M') || (word6[3] == wordle[0] && wordle[0] == 'M') || (word6[3] == wordle[2] && wordle[2] == 'M') || (word6[3] == wordle[4] && wordle[4] == 'M') || (word6[4] == wordle[1] && wordle[1] == 'M') || (word6[4] == wordle[0] && wordle[0] == 'M') || (word6[4] == wordle[3] && wordle[3] == 'M') || (word6[4] == wordle[2] && wordle[2] == 'M'))
  {
    c2();
    cout << " M ";
    cout << RESET;
  }
  else if ((word1[0] != wordle[1] && word1[0] == 'M') || (word1[0] != wordle[2] && word1[0] == 'M') || (word1[0] != wordle[3] && word1[0] == 'M') || (word1[0] != wordle[4] && word1[0] == 'M') || (word1[1] != wordle[0] && word1[1] == 'M') || (word1[1] != wordle[2] && word1[1] == 'M') || (word1[1] != wordle[3] && word1[1] == 'M') || (word1[1] != wordle[4] && word1[1] == 'M') || (word1[2] != wordle[1] && word1[2] == 'M') || (word1[2] != wordle[0] && word1[2] == 'M') || (word1[2] != wordle[3] && word1[2] == 'M') || (word1[2] != wordle[4] && word1[2] == 'M') || (word1[3] != wordle[1] && word1[3] == 'M') || (word1[3] != wordle[2] && word1[3] == 'M') || (word1[3] != wordle[0] && word1[3] == 'M') || (word1[3] != wordle[4] && word1[3] == 'M') || (word1[4] != wordle[1] && word1[4] == 'M') || (word1[4] != wordle[2] && word1[4] == 'M') || (word1[4] != wordle[3] && word1[4] == 'M') || (word1[4] != wordle[0] && word1[4] == 'M') || (word2[0] != wordle[1] && word2[0] == 'M') || (word2[0] != wordle[2] && word2[0] == 'M') || (word2[0] != wordle[3] && word2[0] == 'M') || (word2[0] != wordle[4] && word2[0] == 'M') || (word2[1] != wordle[0] && word2[1] == 'M') || (word2[1] != wordle[2] && word2[1] == 'M') || (word2[1] != wordle[3] && word2[1] == 'M') || (word2[1] != wordle[4] && word2[1] == 'M') || (word2[2] != wordle[1] && word2[2] == 'M') || (word2[2] != wordle[0] && word2[2] == 'M') || (word2[2] != wordle[3] && word2[2] == 'M') || (word2[2] != wordle[4] && word2[2] == 'M') || (word2[3] != wordle[1] && word2[3] == 'M') || (word2[3] != wordle[2] && word2[3] == 'M') || (word2[3] != wordle[0] && word2[3] == 'M') || (word2[3] != wordle[4] && word2[3] == 'M') || (word2[4] != wordle[1] && word2[4] == 'M') || (word2[4] != wordle[2] && word2[4] == 'M') || (word2[4] != wordle[3] && word2[4] == 'M') || (word2[4] != wordle[0] && word2[4] == 'M') || (word3[0] != wordle[1] && word3[0] == 'M') || (word3[0] != wordle[2] && word3[0] == 'M') || (word3[0] != wordle[3] && word3[0] == 'M') || (word3[0] != wordle[4] && word3[0] == 'M') || (word3[1] != wordle[0] && word3[1] == 'M') || (word3[1] != wordle[2] && word3[1] == 'M') || (word3[1] != wordle[3] && word3[1] == 'M') || (word3[1] != wordle[4] && word3[1] == 'M') || (word3[2] != wordle[1] && word3[2] == 'M') || (word3[2] != wordle[0] && word3[2] == 'M') || (word3[2] != wordle[3] && word3[2] == 'M') || (word3[2] != wordle[4] && word3[2] == 'M') || (word3[3] != wordle[1] && word3[3] == 'M') || (word3[3] != wordle[2] && word3[3] == 'M') || (word3[3] != wordle[0] && word3[3] == 'M') || (word3[3] != wordle[4] && word3[3] == 'M') || (word3[4] != wordle[1] && word3[4] == 'M') || (word3[4] != wordle[2] && word3[4] == 'M') || (word3[4] != wordle[3] && word3[4] == 'M') || (word3[4] != wordle[0] && word3[4] == 'M') || (word4[0] != wordle[1] && word4[0] == 'M') || (word4[0] != wordle[2] && word4[0] == 'M') || (word4[0] != wordle[3] && word4[0] == 'M') || (word4[0] != wordle[4] && word4[0] == 'M') || (word4[1] != wordle[0] && word4[1] == 'M') || (word4[1] != wordle[2] && word4[1] == 'M') || (word4[1] != wordle[3] && word4[1] == 'M') || (word4[1] != wordle[4] && word4[1] == 'M') || (word4[2] != wordle[1] && word4[2] == 'M') || (word4[2] != wordle[0] && word4[2] == 'M') || (word4[2] != wordle[3] && word4[2] == 'M') || (word4[2] != wordle[4] && word4[2] == 'M') || (word4[3] != wordle[1] && word4[3] == 'M') || (word4[3] != wordle[2] && word4[3] == 'M') || (word4[3] != wordle[0] && word4[3] == 'M') || (word4[3] != wordle[4] && word4[3] == 'M') || (word4[4] != wordle[1] && word4[4] == 'M') || (word4[4] != wordle[2] && word4[4] == 'M') || (word4[4] != wordle[3] && word4[4] == 'M') || (word4[4] != wordle[0] && word4[4] == 'M') || (word5[0] != wordle[1] && word5[0] == 'M') || (word5[0] != wordle[2] && word5[0] == 'M') || (word5[0] != wordle[3] && word5[0] == 'M') || (word5[0] != wordle[4] && word5[0] == 'M') || (word5[1] != wordle[0] && word5[1] == 'M') || (word5[1] != wordle[2] && word5[1] == 'M') || (word5[1] != wordle[3] && word5[1] == 'M') || (word5[1] != wordle[4] && word5[1] == 'M') || (word5[2] != wordle[1] && word5[2] == 'M') || (word5[2] != wordle[0] && word5[2] == 'M') || (word5[2] != wordle[3] && word5[2] == 'M') || (word5[2] != wordle[4] && word5[2] == 'M') || (word5[3] != wordle[1] && word5[3] == 'M') || (word5[3] != wordle[2] && word5[3] == 'M') || (word5[3] != wordle[0] && word5[3] == 'M') || (word5[3] != wordle[4] && word5[3] == 'M') || (word5[4] != wordle[1] && word5[4] == 'M') || (word5[4] != wordle[2] && word5[4] == 'M') || (word5[4] != wordle[3] && word5[4] == 'M') || (word5[4] != wordle[0] && word5[4] == 'M') || (word6[0] != wordle[1] && word6[0] == 'M') || (word6[0] != wordle[2] && word6[0] == 'M') || (word6[0] != wordle[3] && word6[0] == 'M') || (word6[0] != wordle[4] && word6[0] == 'M') || (word6[1] != wordle[0] && word6[1] == 'M') || (word6[1] != wordle[2] && word6[1] == 'M') || (word6[1] != wordle[3] && word6[1] == 'M') || (word6[1] != wordle[4] && word6[1] == 'M') || (word6[2] != wordle[1] && word6[2] == 'M') || (word6[2] != wordle[0] && word6[2] == 'M') || (word6[2] != wordle[3] && word6[2] == 'M') || (word6[2] != wordle[4] && word6[2] == 'M') || (word6[3] != wordle[1] && word6[3] == 'M') || (word6[3] != wordle[2] && word6[3] == 'M') || (word6[3] != wordle[0] && word6[3] == 'M') || (word6[3] != wordle[4] && word6[3] == 'M') || (word6[4] != wordle[1] && word6[4] == 'M') || (word6[4] != wordle[2] && word6[4] == 'M') || (word6[4] != wordle[3] && word6[4] == 'M') || (word6[4] != wordle[0] && word6[4] == 'M'))
  {
    c3();
    cout << " M ";
    cout << RESET;
  }
  else 
  {
    cout << " M ";
  }

}

// Show keyboard
void keyboard()
{
  cout << endl;
  cout << " Q ";
  cout << " W ";
  cout << " E ";
  cout << " R ";
  cout << " T ";
  cout << " Y ";
  cout << " U ";
  cout << " I ";
  cout << " O ";
  cout << " P ";
  cout << endl;
  cout << endl;
  cout << "  ";
  cout << " A ";
  cout << " S ";
  cout << " D ";
  cout << " F ";
  cout << " G ";
  cout << " H ";
  cout << " J ";
  cout << " K ";
  cout << " L ";
  cout << endl;
  cout << endl;
  cout << "     ";
  cout << " Z ";
  cout << " X ";
  cout << " C ";
  cout << " V ";
  cout << " B ";
  cout << " N ";
  cout << " M ";
}

int main() {
    // Title
    // title1();
    // cout << endl;
    // cout << endl;
    // sleep(1);
    // title2();
    // cout << endl;
    // cout << endl;
    // sleep(1);
    // title3();
    // cout << endl;
    // cout << endl;
    // sleep(1);
    // title4();
    // cout << endl;
    // cout << endl;
    // sleep(1);
    // title5();
    // cout << endl;
    // cout << endl;
    // sleep(1);
    // title6();
    // cout << endl;
    // cout << endl;
    // sleep(1);
    // title6();
    // cout << endl;
    // cout << endl;
    // title7();
    // cout << endl;
    // cout << endl;
    // sleep(1);
    // title8();
    // cout << endl;
    // cout << endl;
    // sleep(1);

    titleanim();
    cout << endl;
    cout << endl;

    // Theme
    theme();

    // Instructions
    char ready = 'n';
    
    // Load instructions until they are ready
    while (ready != 'Y')
    {
      system("clear");
      title8();
      cout << endl;
      cout << endl;
      instructions();
      cout << "Ready? (Y) ";
      cin >> ready;
      ready = toupper(ready);
    }
    
    if (ready == 'Y')
    {
      system("clear");
      title8();
      cout << endl;
      cout << endl;

      // Variables
      int random;
      srand(time(NULL));
      random = rand() % 50 + 1;
      
      // Words
      if (random == 1)
      {
        wordle[0] = 'C';
        wordle[1] = 'L';
        wordle[2] = 'O';
        wordle[3] = 'U';
        wordle[4] = 'T';
      }
      else if (random == 2)
      {
        wordle[0] = 'P';
        wordle[1] = 'O';
        wordle[2] = 'K';
        wordle[3] = 'E';
        wordle[4] = 'R';
      }  
      else if (random == 3)
      {
        wordle[0] = 'V';
        wordle[1] = 'I';
        wordle[2] = 'S';
        wordle[3] = 'T';
        wordle[4] = 'A';
      }
      else if (random == 4)
      {
        wordle[0] = 'P';
        wordle[1] = 'I';
        wordle[2] = 'A';
        wordle[3] = 'N';
        wordle[4] = 'O';
      }
      else if (random == 5)
      {
        wordle[0] = 'B';
        wordle[1] = 'A';
        wordle[2] = 'C';
        wordle[3] = 'O';
        wordle[4] = 'N';
      }
      else if (random == 6)
      {
        wordle[0] = 'S';
        wordle[1] = 'P';
        wordle[2] = 'I';
        wordle[3] = 'C';
        wordle[4] = 'Y';
      }
      else if (random == 7)
      {
        wordle[0] = 'S';
        wordle[1] = 'O';
        wordle[2] = 'L';
        wordle[3] = 'I';
        wordle[4] = 'D';
      }
      else if (random == 8)
      {
        wordle[0] = 'R';
        wordle[1] = 'A';
        wordle[2] = 'N';
        wordle[3] = 'G';
        wordle[4] = 'E';
      }
      else if (random == 9)
      {
        wordle[0] = 'P';
        wordle[1] = 'O';
        wordle[2] = 'W';
        wordle[3] = 'E';
        wordle[4] = 'R';
      }
      else if (random == 10)
      {
        wordle[0] = 'C';
        wordle[1] = 'H';
        wordle[2] = 'I';
        wordle[3] = 'P';
        wordle[4] = 'S';
      }
      else if (random == 11)
      {
        wordle[0] = 'Z';
        wordle[1] = 'E';
        wordle[2] = 'B';
        wordle[3] = 'R';
        wordle[4] = 'A';
      }
      else if (random == 12)
      {
        wordle[0] = 'J';
        wordle[1] = 'U';
        wordle[2] = 'M';
        wordle[3] = 'B';
        wordle[4] = 'O';
      }
      else if (random == 13)
      {
        wordle[0] = 'S';
        wordle[1] = 'L';
        wordle[2] = 'I';
        wordle[3] = 'M';
        wordle[4] = 'E';
      }
      else if (random == 14)
      {
        wordle[0] = 'E';
        wordle[1] = 'N';
        wordle[2] = 'J';
        wordle[3] = 'O';
        wordle[4] = 'Y';
      }
      else if (random == 15)
      {
        wordle[0] = 'M';
        wordle[1] = 'A';
        wordle[2] = 'N';
        wordle[3] = 'G';
        wordle[4] = 'O';
      }
      else if (random == 16)
      {
        wordle[0] = 'F';
        wordle[1] = 'U';
        wordle[2] = 'N';
        wordle[3] = 'K';
        wordle[4] = 'Y';
      }
      else if (random == 17)
      {
        wordle[0] = 'C';
        wordle[1] = 'R';
        wordle[2] = 'U';
        wordle[3] = 'M';
        wordle[4] = 'B';
      }
      else if (random == 18)
      {
        wordle[0] = 'B';
        wordle[1] = 'L';
        wordle[2] = 'O';
        wordle[3] = 'C';
        wordle[4] = 'K';
      }
      else if (random == 19)
      {
        wordle[0] = 'B';
        wordle[1] = 'E';
        wordle[2] = 'A';
        wordle[3] = 'C';
        wordle[4] = 'H';
      }
      else if (random == 20)
      {
        wordle[0] = 'R';
        wordle[1] = 'A';
        wordle[2] = 'I';
        wordle[3] = 'S';
        wordle[4] = 'E';
      }
      else if (random == 21)
      {
        wordle[0] = 'P';
        wordle[1] = 'H';
        wordle[2] = 'O';
        wordle[3] = 'N';
        wordle[4] = 'E';
      }
      else if (random == 22)
      {
        wordle[0] = 'F';
        wordle[1] = 'O';
        wordle[2] = 'R';
        wordle[3] = 'T';
        wordle[4] = 'Y';
      }
      else if (random == 23)
      {
        wordle[0] = 'H';
        wordle[1] = 'O';
        wordle[2] = 'R';
        wordle[3] = 'S';
        wordle[4] = 'E';
      }
      else if (random == 24)
      {
        wordle[0] = 'A';
        wordle[1] = 'B';
        wordle[2] = 'O';
        wordle[3] = 'R';
        wordle[4] = 'T';
      }
      else if (random == 25)
      {
        wordle[0] = 'L';
        wordle[1] = 'A';
        wordle[2] = 'S';
        wordle[3] = 'E';
        wordle[4] = 'R';
      }
      else if (random == 26)
      {
        wordle[0] = 'F';
        wordle[1] = 'A';
        wordle[2] = 'N';
        wordle[3] = 'C';
        wordle[4] = 'Y';
      }
      else if (random == 27)
      {
        wordle[0] = 'W';
        wordle[1] = 'O';
        wordle[2] = 'R';
        wordle[3] = 'L';
        wordle[4] = 'D';
      }
      else if (random == 28)
      {
        wordle[0] = 'T';
        wordle[1] = 'H';
        wordle[2] = 'A';
        wordle[3] = 'N';
        wordle[4] = 'K';
      }
      else if (random == 29)
      {
        wordle[0] = 'P';
        wordle[1] = 'I';
        wordle[2] = 'X';
        wordle[3] = 'E';
        wordle[4] = 'L';
      }
      else if (random == 30)
      {
        wordle[0] = 'S';
        wordle[1] = 'H';
        wordle[2] = 'I';
        wordle[3] = 'F';
        wordle[4] = 'T';
      }
      else if (random == 31)
      {
        wordle[0] = 'B';
        wordle[1] = 'R';
        wordle[2] = 'E';
        wordle[3] = 'A';
        wordle[4] = 'D';
      }
      else if (random == 32)
      {
        wordle[0] = 'P';
        wordle[1] = 'L';
        wordle[2] = 'A';
        wordle[3] = 'N';
        wordle[4] = 'E';
      }
      else if (random == 33)
      {
        wordle[0] = 'V';
        wordle[1] = 'E';
        wordle[2] = 'N';
        wordle[3] = 'O';
        wordle[4] = 'M';
      }
      else if (random == 34)
      {
        wordle[0] = 'V';
        wordle[1] = 'I';
        wordle[2] = 'S';
        wordle[3] = 'T';
        wordle[4] = 'A';
      }
      else if (random == 35)
      {
        wordle[0] = 'B';
        wordle[1] = 'L';
        wordle[2] = 'A';
        wordle[3] = 'D';
        wordle[4] = 'E';
      }
      else if (random == 36)
      {
        wordle[0] = 'S';
        wordle[1] = 'H';
        wordle[2] = 'A';
        wordle[3] = 'R';
        wordle[4] = 'D';
      }
      else if (random == 37)
      {
        wordle[0] = 'S';
        wordle[1] = 'Q';
        wordle[2] = 'U';
        wordle[3] = 'I';
        wordle[4] = 'D';
      }
      else if (random == 38)
      {
        wordle[0] = 'D';
        wordle[1] = 'R';
        wordle[2] = 'E';
        wordle[3] = 'A';
        wordle[4] = 'M';
      }
      else if (random == 39)
      {
        wordle[0] = 'P';
        wordle[1] = 'I';
        wordle[2] = 'Q';
        wordle[3] = 'U';
        wordle[4] = 'E';
      }
      else if (random == 40)
      {
        wordle[0] = 'G';
        wordle[1] = 'N';
        wordle[2] = 'O';
        wordle[3] = 'M';
        wordle[4] = 'E';
      }
      else if (random == 41)
      {
        wordle[0] = 'Y';
        wordle[1] = 'A';
        wordle[2] = 'C';
        wordle[3] = 'H';
        wordle[4] = 'T';
      }
      else if (random == 42)
      {
        wordle[0] = 'F';
        wordle[1] = 'L';
        wordle[2] = 'A';
        wordle[3] = 'N';
        wordle[4] = 'K';
      }
      else if (random == 43)
      {
        wordle[0] = 'A';
        wordle[1] = 'N';
        wordle[2] = 'G';
        wordle[3] = 'E';
        wordle[4] = 'L';
      }
      else if (random == 44)
      {
        wordle[0] = 'B';
        wordle[1] = 'L';
        wordle[2] = 'I';
        wordle[3] = 'M';
        wordle[4] = 'P';
      }
      else if (random == 45)
      {
        wordle[0] = 'S';
        wordle[1] = 'M';
        wordle[2] = 'I';
        wordle[3] = 'T';
        wordle[4] = 'E';
      }
      else if (random == 46)
      {
        wordle[0] = 'R';
        wordle[1] = 'O';
        wordle[2] = 'G';
        wordle[3] = 'U';
        wordle[4] = 'E';
      }
      else if (random == 47)
      {
        wordle[0] = 'M';
        wordle[1] = 'O';
        wordle[2] = 'C';
        wordle[3] = 'H';
        wordle[4] = 'A';
      }
      else if (random == 48)
      {
        wordle[0] = 'B';
        wordle[1] = 'I';
        wordle[2] = 'N';
        wordle[3] = 'G';
        wordle[4] = 'E';
      }
      else if (random == 49)
      {
        wordle[0] = 'A';
        wordle[1] = 'N';
        wordle[2] = 'V';
        wordle[3] = 'I';
        wordle[4] = 'L';
      }
      else if (random == 50)
      {
        wordle[0] = 'E';
        wordle[1] = 'Q';
        wordle[2] = 'U';
        wordle[3] = 'I';
        wordle[4] = 'P';
      }

      // Display title
      title8();
      cout << endl;
      cout << endl;
      cout << endl;

      // Word matrix
      matrix(6);

      // Keyboard
      keyboard();

      // Guess
      cout << endl;
      cout << endl;
      cout << "Guess: ";
      cin >> word1;

      system("clear");

      title8();
      cout << endl;
      cout << endl;
      cout << endl;

      word1c();
          
      if (win == 'n')
      {
        matrix(5);
        cout << endl;
        alphabet();
        cout << endl;
        cout << endl;
        cout << "Guess: ";
        cin >> word2;

        system("clear");

        title8();
        cout << endl;
        cout << endl;
        cout << endl;

        word1c();
        word2c();
      }

      if (win == 'n')
      {
        matrix(4);
        cout << endl;
        alphabet();
        cout << endl;
        cout << endl;
        cout << "Guess: ";
        cin >> word3;

        system("clear");

        title8();
        cout << endl;
        cout << endl;
        cout << endl;

        word1c();
        word2c();
        word3c();
      }

      if (win == 'n')
      {      
        matrix(3);
        cout << endl;
        alphabet();
        cout << endl;
        cout << endl;
        cout << "Guess: ";
        cin >> word4;

        system("clear");

        title8();
        cout << endl;
        cout << endl;
        cout << endl;

        word1c();
        word2c();
        word3c();
        word4c();
      }

      if (win == 'n')
      {
        matrix(2);
        cout << endl;
        alphabet();
        cout << endl;
        cout << endl;
        cout << "Guess: ";
        cin >> word5;

        system("clear");

        title8();
        cout << endl;
        cout << endl;
        cout << endl;

        word1c();
        word2c();
        word3c();
        word4c();
        word5c();
      }

      if (win == 'n')
      { 
        matrix(1);
        cout << endl;
        alphabet();
        cout << endl;
        cout << endl;
        cout << "Guess: ";
        cin >> word6;

        system("clear");

        title8();
        cout << endl;
        cout << endl;
        cout << endl;

        word1c();
        word2c();
        word3c();
        word4c();
        word5c();
        word6c();
      }
  }
  ready = toupper(ready);
} 
