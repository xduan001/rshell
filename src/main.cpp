#include <iostream>
#include <boost/tokenizer.hpp>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

using namespace std;
using namespace boost;

void Parse(char* cmnd, char* cmd[], char input[]);
void Clear(char* cmd[]);
void Execute(char* cmd[]);



int main() {
/*  
    string s = "ls -a; echo hello && mkdir test || echo world; git status";
    tokenizer<> tok(s);
    
    for (tokenizer<>::iterator beg=tok.begin(); beg != tok.end(); ++beg) {
        cout << *beg << "\n";
    }     
*/
    char* cmnd;
    char* cmd[40];
    char input[50];

    while(cmd[0] != NULL) {
        Clear(cmd);
        Parse(cmnd, cmd, input);
        if(strcmp(cmd[0], "exit" == 0)) {
            break;
        }    
        else {
            Execute(cmd);
        }    
    }    
}

void Parse(char* cmnd, char* cmd[], char input[]) {
    cout << "$ ";
    cin.getline(input, 50);
    cmnd = strtok(input, " ");
    int i = 0;

    while (cmnd != NULL) {
        cmd[i] = cmnd;
        i++;
        cmnd = strtok(NULL, " ");
    }
}    

void Clear(char* cmd[]) {
    for (int i = 0; i < 40; i++) {
        cmd[i] = NULL;
    }
} 

void Execute(char* cmd[]) {
    pid_t pid;
    pid = fork();
    switch(pid) {
        case -1:
            cout << "Fork Failure" << endl;
            exit(-1);
        case 0:
            execvp(cmd[0], cmd);

            if (execvp(cmd[0], cmd) == -1) {
                cout << "Invalid command" << endl;
                exit(0);
            }    
        default: 
            wait(NULL);
            cout << "Child Finished" << endl;
    }    
}
