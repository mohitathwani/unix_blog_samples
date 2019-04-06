#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define N 2

using namespace std;
void longTask()
{
    pid_t pid = getpid();
    cout << "Child(" << pid << "): Hello, I am the child." << endl;
    cout << "Child(" << pid << "): I am about to start some long task." << endl;
    sleep(10);
    cout << "Child(" << pid <<"): I am done executing the long task" << endl;
    exit(0);
}

int main()
{
    pid_t children[N];
    for (int i = 0; i < N; i++)
    {
        pid_t pid;
        if ((pid = fork()) == 0)
        { //Child
            longTask();
        } else {
            children[i] = pid;
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << "Parent: Hello, I am the parent. My child at " << i << " is pid = " << children[i] << endl;
    }

    cout << "Parent: I am going to wait for my children to finish execution" << endl;
    int status;
    pid_t child_pid;
    while ((child_pid = waitpid(-1, &status, 0)) > 0)
    {
        cout << "Parent: Child " << child_pid << " finished execution." << endl;
    }
    cout << "Parent: All my children finished execution." << endl;
}
