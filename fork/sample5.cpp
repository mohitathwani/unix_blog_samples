#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *const argv[], char *const envp[])
{
    if (argc < 2)
    {
        cout << "Please enter a command to execute with an optional parameter" << endl;
        cout << "For example: " << endl;
        cout << "ls" << endl;
        cout << "OR" << endl;
        cout << "ls -l" << endl; 
        exit(1);
    }

    //Get all the environment paths in the PATH variable
    char *environmentPaths = getenv("PATH");

    char *const command = argv[1];
    char *const parameter = (argv[2] != NULL) ? argv[2] : NULL;

    pid_t pid;

    if ((pid = fork()) == 0)
    {
        //Child

        //Ensuring args is always NULL terminated.
        //Doesn't matter even if parameter = NULL from above.
        char *const args[3] = {command, parameter, NULL};

        char *token;
        token = strtok(environmentPaths, ":");

        //Iterate through all the paths in the PATH variable.
        //Append the entered command to each path
        //and see if the executable exists at that path.
        while (token != NULL)
        {
            stringstream ss;
            ss << token << "/" << command;

            string fullyQualifiedPath = ss.str();

            execve(fullyQualifiedPath.c_str(), args, envp);
            token = strtok(NULL, ":");
        }

        //If you reached here, the command was not found
        //at any of the sub paths in the PATH variable.
        //Perhaps the user wants to execute a binary
        //in the current folder?
        if (strncmp("./", command, 2) == 0)
        {
            execve(command, args, envp);
        }

        //If none of the execve above have executed,
        //that means the binary has not been found anywhere!
        cout << "Error: " << command << " not found." << endl;
        exit(1);
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);
        if (WEXITSTATUS(status) == 0)
        {
            cout << "Child terminated successfully" << endl;
        }
        else
        {
            cout << "Child did not terminate successfully" << endl;
        }
    }
}
