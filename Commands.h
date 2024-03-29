#ifndef SMASH_COMMAND_H_
#define SMASH_COMMAND_H_


#include <vector>
#include <cstring>
#include <list>

using namespace std;

#define COMMAND_ARGS_MAX_LENGTH (200)
#define COMMAND_MAX_ARGS (20)
#define HISTORY_MAX_RECORDS (50)

class Command {
// TODO: Add your data members

public:
    const char* cmd_line;

    Command() = default;
    Command(const char* cmd_line) : cmd_line(cmd_line){}

    virtual ~Command() {}

    virtual void execute() = 0;
    //virtual void prepare();
    //virtual void cleanup();
    // TODO: Add your extra methods if needed
};

class BuiltInCommand : public Command {
public:
    BuiltInCommand() = default;
    BuiltInCommand(const char* cmd_line) : Command(cmd_line){}
    virtual ~BuiltInCommand() {}
};

class ExternalCommand : public Command {
public:
    ExternalCommand(const char* cmd_line);
    virtual ~ExternalCommand() {}
    void execute() override;
};

class PipeCommand : public Command {
    // TODO: Add your data members
public:
    PipeCommand(const char* cmd_line);
    virtual ~PipeCommand() {}
    void execute() override;
};

class RedirectionCommand : public Command {
    // TODO: Add your data members
public:
    explicit RedirectionCommand(const char* cmd_line);
    virtual ~RedirectionCommand() {}
    void execute() override;
    //void prepare() override;
    //void cleanup() override;
};

class ChangeDirCommand : public BuiltInCommand {
// TODO: Add your data members public:
public:
    ChangeDirCommand() = default;
    ChangeDirCommand(const char* cmd_line, char** plastPwd) : BuiltInCommand(cmd_line){}
    virtual ~ChangeDirCommand() {}
    void execute() override;
};

class GetCurrDirCommand : public BuiltInCommand {

public:
    GetCurrDirCommand() = default;
    GetCurrDirCommand(const char* cmd_line) : BuiltInCommand(cmd_line){}
    virtual ~GetCurrDirCommand() {}
    void execute() override;
};

class ShowPidCommand : public BuiltInCommand {
public:
    ShowPidCommand(const char* cmd_line);
    virtual ~ShowPidCommand() {}
    void execute() override;
};

class JobsList;
class QuitCommand : public BuiltInCommand {
// TODO: Add your data members public:
    QuitCommand(const char* cmd_line, JobsList* jobs);
    virtual ~QuitCommand() {}
    void execute() override;
};

class CommandsHistory {
protected:
    class CommandHistoryEntry {
        // TODO: Add your data members
    };
    // TODO: Add your data members
public:
    CommandsHistory();
    ~CommandsHistory() {}
    void addRecord(const char* cmd_line);
    void printHistory();
};

class HistoryCommand : public BuiltInCommand {
    // TODO: Add your data members
public:
    HistoryCommand() = default;
    HistoryCommand(const char* cmd_line, CommandsHistory* history);
    virtual ~HistoryCommand() {}
    void execute() override;
};

class JobsList {
public:
    class JobEntry {
        // TODO: Add your data members
    };
    // TODO: Add your data members
public:
    JobsList();
    ~JobsList();
    void addJob(Command* cmd, bool isStopped = false);
    void printJobsList();
    void killAllJobs();
    void removeFinishedJobs();
    JobEntry * getJobById(int jobId);
    void removeJobById(int jobId);
    JobEntry * getLastJob(int* lastJobId);
    JobEntry *getLastStoppedJob(int *jobId);
    // TODO: Add extra methods or modify exisitng ones as needed
};

class JobsCommand : public BuiltInCommand {
    // TODO: Add your data members
public:
    JobsCommand(const char* cmd_line, JobsList* jobs);
    virtual ~JobsCommand() {}
    void execute() override;
};

class KillCommand : public BuiltInCommand {
    // TODO: Add your data members
public:
    KillCommand(const char* cmd_line, JobsList* jobs);
    virtual ~KillCommand() {}
    void execute() override;
};

class ForegroundCommand : public BuiltInCommand {
    // TODO: Add your data members
public:
    ForegroundCommand(const char* cmd_line, JobsList* jobs);
    virtual ~ForegroundCommand() {}
    void execute() override;
};

class BackgroundCommand : public BuiltInCommand {
    // TODO: Add your data members
public:
    BackgroundCommand(const char* cmd_line, JobsList* jobs);
    virtual ~BackgroundCommand() {}
    void execute() override;
};

class CopyCommand : public BuiltInCommand {
public:
    CopyCommand(const char* cmd_line);
    virtual ~CopyCommand() {}
    void execute() override;
};

class Node{
    string cmd_line;
    int seqId;
public:
    Node(string cmd) :seqId(1) {}
    Node(string cmd,int seqId) : cmd_line(cmd),seqId(seqId) {}

    string getCommand(){
        return cmd_line;
    }
    int getSeqId(){
        return seqId;
    }
    void incGetId(){
        seqId++;
    }


};

class SmallShell {
private:
    // TODO: Add your data members

    SmallShell() {
        history = new list<Node>;
        lastPwd = new char[1024];
        flagForFirstPwd = 0;
        isFirstCmd = true;
    };
    std::list<Node>* history;
    char* lastPwd; // pwd before we entered cd
    bool flagForFirstPwd;
    bool isFirstCmd;
public:

    char* getLastPwd(){
        if(!flagForFirstPwd){
            return nullptr;
        } else {
            return lastPwd;
        }
    }

    void setLastPwd(char* toSet){
            int i = 0;
            while(toSet[i]) {
                lastPwd[i] = toSet[i];
                i++;
            }
            lastPwd[i] = '\0';
            flagForFirstPwd = true;
    }

    Command *CreateCommand(const char* cmd_line);
    SmallShell(SmallShell const&)      = delete; // disable copy ctor
    void operator=(SmallShell const&)  = delete; // disable = operator
    static SmallShell& getInstance() // make SmallShell singleton
    {
        static SmallShell instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }

    ~SmallShell(){
        delete history;
        delete[] lastPwd;
    };

    void executeCommand(const char* cmd_line);
    // TODO: add extra methods as needed
};



#endif //SMASH_COMMAND_H_
