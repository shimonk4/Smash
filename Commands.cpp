#include <unistd.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <sys/wait.h>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <forward_list>
#include "Commands.h"


using std::cin;
using std::cout;
using std::endl;

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
        memset(*(args+i), 0, intermediate.length()+1);
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

bool checkIfPwd(string toCheck){
    return (toCheck[0] == 'p' && toCheck[1] == 'w' && toCheck[2] == 'd' && string(toCheck).size() == 3) ||
           (toCheck[0] == 'p' && toCheck[1] == 'w' && toCheck[2] == 'd' && toCheck[3] == ' ');
}

bool checkIfCd(string toCheck){
    char** args = new char*[30];
    _parseCommandLine(toCheck.c_str(),args);
    if((toCheck[0] == 'c' && toCheck[1] == 'd' && toCheck[2] == ' ') &&
         (args[1] != NULL) && (*args[1] != '-')&& (args[2] == NULL)) {
        delete[] args;
        return true;
    }
    if((toCheck[0] == 'c' && toCheck[1] == 'd' && toCheck[2] == ' ') &&
       (args[1] != NULL)&& (args[2] != NULL)) {
        cout << "smash error: cd: too many arguments" << endl;
    }
    delete[] args;
    return false;
}

bool checkIfCd_(string toCheck){
    char** args = new char*[30];
    _parseCommandLine(toCheck.c_str(),args);
    if((toCheck[0] == 'c' && toCheck[1] == 'd' && toCheck[2] == ' ' && toCheck[3]== '-')
       && (args[2] == NULL)){
        delete[] args;
        return true;
    }
    delete[] args;
    return false;
}

bool checkIfHistory(string toCheck){
    return (toCheck[0] == 'h' && toCheck[1] == 'i' && toCheck[2] == 's' && toCheck[3] == 't'
            && toCheck[4] == 'o' && toCheck[5] == 'r' && toCheck[6] == 'y') ||
           (toCheck[0] == 'h' && toCheck[1] == 'i' && toCheck[2] == 's' && toCheck[3] == 't'
           && toCheck[4] == 'o' && toCheck[5] == 'r' && toCheck[6] == 'y' && toCheck[7] == ' ');
}

bool checkIfShowPid(string toCheck) {
    return (toCheck[0] == 's' && toCheck[1] == 'h' && toCheck[2] == 'o' && toCheck[3] == 'w'
            && toCheck[4] == 'p' && toCheck[5] == 'i' && toCheck[6] == 'd') ||
           (toCheck[0] == 's' && toCheck[1] == 'h' && toCheck[2] == 'o' && toCheck[3] == 'w'
            && toCheck[4] == 'p' && toCheck[5] == 'i' && toCheck[6] == 'd' && toCheck[7] == ' ');
}

void removeExtraSpaces(string &s)
{
    // n is length of the original string
    int n = s.length();

    //pointer i to keep trackof next position and j to traverse
    int i = 0, j = -1;

    // flag that sets to true is space is found
    bool spaceFound = false;

    // Handles leading spaces
    while (++j < n && s[j] == ' ');

    // read all characters of original string
    while (j <= n)
    {
        // if current characters is non-space
        if (s[j] != ' ')
        {
            //if any preceeding space before ,.and ?
            if ((s[j] == '.' || s[j] == ',' ||
                 s[j] == '?') && i - 1 >= 0 &&
                s[i - 1] == ' ')
                s[i - 1] = s[j++];

            else
                // copy current character to index i
                // and increment both i and j
                s[i++] = s[j++];

            // set space flag to false when any
            // non-space character is found
            spaceFound = false;
        }
            // if current character is a space
        else if (s[j++] == ' ')
        {
            // If space is seen first time after a word
            if (!spaceFound)
            {
                s[i++] = ' ';
                spaceFound = true;
            }
        }
    }

    // Remove trailing spaces
    if (i <= 1)
        s.erase(s.begin() + i, s.end());
    else
        s.erase(s.begin() + i - 1, s.end());
}

Command * SmallShell::CreateCommand(const char* cmd_line) {

  string cmd_s = string(cmd_line);
  removeExtraSpaces(cmd_s);
  char wd[512];
  if(isFirstCmd) {
      Node command(string(cmd_line),1);
      isFirstCmd = false;
      history->push_front(command);
  } else {
      if(history->front().getCommand() == string(cmd_line)){
        history->front().incGetId();
      } else {
          Node command(string(cmd_line), history->front().getSeqId() + 1);
          if (history->size() == 50) {
              history->pop_back();
              history->push_front(command);
          } else {
              history->push_front(command);
          }
      }
  }
    cout << "From Here: " << endl;

    cout << history->begin()->getSeqId();
    cout << " ";
    cout << history->begin()->getCommand() << endl;
    cout << "Untill Here!" << endl;
  if (checkIfPwd(cmd_s) && cmd_line) {
      return new GetCurrDirCommand(cmd_line);
  } else if(checkIfCd(cmd_s) && (cmd_line) ) {
      char** args = new char*[30];
      _parseCommandLine(cmd_s.c_str(),args);
      if(getwd(wd) == NULL) {
          perror("smash error: getwd failed");
      }
      setLastPwd(wd);
      if(chdir(args[1]) == -1){
          perror("smash error: chdir failed");
      }
      delete[] args;
      return new ChangeDirCommand();
  } else if(checkIfCd_(cmd_s)){
      if(getwd(wd) == NULL) {
          perror("smash error: getwd failed");
      }
      if(getLastPwd() == nullptr){
          cout << "smash error: cd: OLDPWD not set" << endl;
      } else {
          if(chdir(getLastPwd()) == -1){
              perror("smash error: chdir failed");
          }
          setLastPwd(wd);
          return new ChangeDirCommand();
      }
  } else if(checkIfHistory(cmd_s)) {
      history->reverse();
      for (auto it=history->begin(); it!= history->end(); it++){
          cout << right << setw(5) << " " << (*it).getSeqId() << " " << (*it).getCommand() << endl;
      }
      history->reverse();
      return new HistoryCommand();
  } else if(checkIfShowPid(cmd_s)) {
      cout << "smash pid is " << getpid() << endl;
  } else if() {

      return nullptr;
  }
}

void SmallShell::executeCommand(const char *cmd_line) {
    // TODO: Add your implementation here
    // for example:
    Command* cmd = CreateCommand(cmd_line);
    if(!cmd){
        std::cout << "smash error: > ";
        std::cout << "\"" << cmd_line << "\"" << std::endl ;
    } else {
        cmd->execute();
        delete cmd;
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

void ChangeDirCommand::execute() {

}

void HistoryCommand::execute() {
}
