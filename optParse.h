#ifndef OPTPARSE_H_
#define OPTPARSE_H_

char** argParameters;
extern int argIndex;

struct Option {
  char* longName;
  char shortName;

  int* flag;

  int parameterRequired;
  char* parameter; 
};

void argOptionParameterProcess (int optIndex) {
  if (argIndex) {

  }
}

void argProcess (char* arg, struct Option* opts, int optsAmount, int argType)  {
  int optIsFound = 0;

  switch (argType) {
    case 0: {
      char optLongName[(int)strlen(arg) - 2]; 
       
      for (int i = 2; i < strlen(arg); ++i) {
        optLongName[i - 2] = arg[i]; 
      }

      for (int i = 0; i < optsAmount; ++i) {
        if (strcmp(opts[i].longName, optLongName) == 0) {
          (*opts[i].flag) = 1; 
          optIsFound = 1;

          if (opts[i].parameterRequired == 1) {

          }
          break;
        }
      }

      break;
    }
    
    case 1: {
      char optShortName = arg[1];

      for (int i = 0; i < optsAmount; ++i) {
        if (opts[i].shortName == optShortName) {
          (*opts[i].flag) = 1; 
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

void optParse (int argc, char** argv, struct Option* opts, int optsAmount) {
  for (argIndex = 1; argIndex < argc; ++argIndex) {
    char* arg = argv[argIndex];      
    int argType = argCheckType(arg);
    
    argProcess(arg, opts, optsAmount, argType);
  }
}

#endif 
