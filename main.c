#include <stdio.h>
#include <string.h>
#include "option.h"
#include "argparser.h"

int flagLines, flagBytes, flagWords;

struct Option options[] = 
{
  {"lines", 'l', &flagLines, 0, NULL},
  {"bytes", 'c', &flagBytes, 0, NULL},
  {"words", 'w', &flagWords, 0, NULL}
};

int optionsAmount = 3;

int main (int argc, char** argv) {
  argvParse(argc, argv); 

  printf("%d %d %d", *options[0].flag, *options[1].flag,*options[2].flag);  
  return 0;
}
