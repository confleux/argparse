#ifndef OPTION_H
#define OPTION_H

struct Option {
  char* longName;
  char shortName;

  int* flag;

  int parameterRequired;
  char* parameter; 
};

#endif
