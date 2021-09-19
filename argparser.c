#include <stdio.h>
#include <string.h>
#include "argparser.h"
#include "option.h"

int argIndex = 1;

//void argOptionParameterProcess (int optIndex) {
//  if (argIndex) {
//
//  }
//}

// 0 - long option, 1 - short option, 2 - parameter 
int argCheckType (char* arg) {
  if (arg[0] == '-') {
    if (arg[1] == '-') {
      return 0; 
    } else {
      return 1;
    }
  } else {
    return 2;
  }
}

void argProcess (char* arg)  {
  int optIsFound = 0;
  int argType = argCheckType(arg);

  switch (argType) {
    case 0: {
      char optLongName[(int)strlen(arg) - 2]; 
       
      for (int i = 2; i < strlen(arg); ++i) {
        optLongName[i - 2] = arg[i]; 
      }

      for (int i = 0; i < optionsAmount; ++i) {
        if (strcmp(options[i].longName, optLongName) == 0) {
          (*options[i].flag) = 1; 
          optIsFound = 1;

          //if (options[i].parameterRequired == 1) {
          //  return 1; 
          //}
          break;
        }
      }

      break;
    }
    
    case 1: {
      char optShortName = arg[1];

      for (int i = 0; i < optionsAmount; ++i) {
        if (options[i].shortName == optShortName) {
          (*options[i].flag) = 1; 
          optIsFound = 1;
          break;
        }
      }

      break;
    }

    case 2: {
        // not implemented yet :(
      break;
    }
  }

  if (optIsFound == 0) {
    printf("Option %s was not specified", arg);
  }
}


void argvParse (int argc, char** argv) {
  for (; argIndex < argc; ++argIndex) {
    char* arg = argv[argIndex];      
    
    argProcess(arg);
  }
}
