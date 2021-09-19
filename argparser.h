#ifndef ARGPARSER_H
#define ARGPARSER_H

#include "option.h"

extern struct Option options[];
extern int optionsAmount;
extern char** parameters;
extern int argIndex;

int argCheckType (char* arg);

void argProcess (char* arg);

void argvParse (int argc, char** argv);

//void argOptionParameterProcess (int optIndex);

#endif
