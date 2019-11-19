#include <unistd.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <sys/wait.h>
#include <iomanip>
#include "Commands.h"

using namespace std;

#if 0
#define FUNC_ENTRY()  \
  cout << __PRETTY_FUNCTION__ << " --> " << endl;

#define FUNC_EXIT()  \
  cout << __PRETTY_FUNCTION__ << " <-- " << endl;
#else
#define FUNC_ENTRY()
#define FUNC_EXIT()
#endif

int _parseCommandLine(const char* cmd_line, char** args) {
    FUNC_ENTRY()
    stringstream check1(cmd_line);
    string intermediate;
    int i = 0;
    while(getline(check1, intermediate, ' '))
    {
        args[i] = (char*)malloc(intermediate.length()+1);
        memset(args[i], 0, intermediate.length()+1);
        strcpy(args[i], intermediate.c_str());
        args[++i] = NULL;
    }
    return i;

    FUNC_EXIT()
}

bool _isBackgroundComamnd(const char* cmd_line) {
    const string whitespace = " \t\n";
    const string str(cmd_line);
    return str[str.find_last_not_of(whitespace)] == '&';
}

void _removeBackgroundSign(char* cmd_line) {
    const string whitespace = " \t\n";
    const string str(cmd_line);
    // find last character other than spaces
    size_t idx = str.find_last_not_of(whitespace);
    // if all characters are spaces then return
    if (idx == string::npos) {
        return;
    }
    // if the command line does not end with & then return
    if (cmd_line[idx] != '&') {
        return;
    }
    // replace the & (background sign) with space and then remove all tailing spaces.
    cmd_line[idx] = ' ';
    // truncate the command line string up to the last non-space character
    cmd_line[str.find_last_not_of(whitespace, idx-1) + 1] = 0;
}

// TODO: Add your implementation for classes in Commands.h

SmallShell::SmallShell() {
// TODO: add your implementation
}

SmallShell::~SmallShell() {
// TODO: add your implementation
}

/**
* Creates and returns a pointer to Command class which matches the given command line (cmd_line)
*/

bool checkIfPwd(char* toCheck){
    return (toCheck[0] == 'p' && toCheck[1] == 'w' && toCheck[2] == 'd' && string(toCheck).size() == 3) ||
           (toCheck[0] == 'p' && toCheck[1] == 'w' && toCheck[2] == 'd' && toCheck[3] == ' ');
}

Command * SmallShell::CreateCommand(const char* cmd_line) {

  string cmd_s = string(cmd_line);
  int i = 0;
  char whiteSpace = ' ';
  while(cmd_s[i] == whiteSpace) {
      i++;
  }
  char* cmdWithoutSpaces = new char[cmd_s.size()-i];
  for (int j = i,k=0; j < cmd_s.size() ; ++j,k++) {
        cmdWithoutSpaces[k] = cmd_s[j];
  }
  if (checkIfPwd(cmdWithoutSpaces)) {
      delete[] cmdWithoutSpaces;
      return new GetCurrDirCommand(cmd_line);
  }





  /* else if ...
  .....
  else {
    return new ExternalCommand(cmd_line);
  }
  */
    return nullptr;
}

void SmallShell::executeCommand(const char *cmd_line) {
    // TODO: Add your implementation here
    // for example:
    Command* cmd = CreateCommand(cmd_line);
    if(!cmd){
        std::cout << "smash error: > ";
        std::cout << "\"";
        std::cout << cmd_line;
        std::cout << "\"" << std::endl;
    } else {
        cmd->execute();
    }
    // Please note that you must fork smash process for some commands (e.g., external commands....)
}

void GetCurrDirCommand::execute() {
    char wd[512];
    if(getwd(wd) == NULL) {
        perror("smash error: getwd failed");
    } else {
            std::cout << wd << std::endl;
    }
}