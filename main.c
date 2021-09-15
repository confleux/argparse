#include <stdio.h>
#include <string.h>
#include "optParse.h"

int flagLines, flagBytes, flagWords;

struct Option options[] = 
{
  {"lines", 'l', &flagLines, 0, NULL},
  {"bytes", 'c', &flagBytes, 0, NULL},
  {"words", 'w', &flagWords, 0, NULL}
};

//const char* shortOptions

int main (int argc, char** argv) {
  optParse(argc, argv, options, 3); 

  printf("%d %d %d", *options[0].flag, *options[1].flag,*options[2].flag);  
  return 0;
}
